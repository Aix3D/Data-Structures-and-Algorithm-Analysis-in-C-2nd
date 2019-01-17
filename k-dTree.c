/*	k-dTree.c -- k-d树实现文件	*/
#include "k-dTree.h"

/*	局部函数声明	*/

/*	队列部分	*/
static QueueNode * makeNode_Q (Node * const pn, const int index) ;

/*	k-d树部分	*/
static Node * makeNode_K (const Item * const pi, const int k) ;
static BOOL within_K (const Item * const pi, const Item * const low, const Item * const high, const int k) ;
static BOOL equal_K (const Item * const piS, const Item * const pi, const int k) ;
static void release_K (Node * const pn) ;

/*	接口函数定义	*/

/*	队列部分	*/
BOOL Initialize_Q (Queue * const pq)
{
	*pq = (struct queue *) malloc (sizeof (struct queue)) ;
	if (NULL == *pq)
		return FALSE ;
	(*pq) -> front = (*pq) -> rear = NULL ;
	(*pq) -> current = 0 ;

	return TRUE ;
}

BOOL IsEmpty_Q (const Queue * const pq)
{
	switch ((*pq) -> current)
	{
		case 0	:	return TRUE ;
		default	:	return FALSE ;
	}
}

BOOL EnQueue_Q (const Queue * const pq, Node * const pn, const int index)
{
	QueueNode * newQNode ;

	newQNode = makeNode_Q (pn, index) ;
	if (NULL == newQNode)
		return FALSE ;
	if (IsEmpty_Q (pq))
		(*pq) -> front = (*pq) -> rear = newQNode ;
	else
	{
		(*pq) -> rear -> next = newQNode ;
		(*pq) -> rear = newQNode ;
	}
	(*pq) -> current++ ;

	return TRUE ;
}

BOOL DeQueue_Q (const Queue * const pq, QueueNode * const pqn)
{
	QueueNode * record ;

	if (IsEmpty_Q (pq))
		return FALSE ;
	record = (*pq) -> front ;
	*pqn = *record ;
	(*pq) -> front = record -> next ;
	if (NULL == (*pq) -> front)
		(*pq) -> rear = NULL ;
	free (record) ;
	(*pq) -> current-- ;

	return TRUE ;
}

void Release_Q (const Queue * const pq)
{
	QueueNode * record, * scan ;

	scan = (*pq) -> front ;
	while (scan != NULL)
	{
		record = scan ;
		scan = scan -> next ;
		free (record) ;
	}
	free (*pq) ;
}

/*	k-d树部分	*/
BOOL Initialize_K (KDTree * const pt, const int k)
{
	*pt = (struct kDTree *) malloc (sizeof (struct kDTree)) ;
	if (NULL == *pt)
		return FALSE ;
	(*pt) -> root = NULL ;
	(*pt) -> current = 0 ;
	(*pt) -> k = k ;

	return TRUE ;
}

BOOL IsEmpty_K (const KDTree * const pt)
{
	switch ((*pt) -> current)
	{
		case 0	:	return TRUE ;
		default	:	return FALSE ;
	}
}

BOOL Insert_K (const KDTree * const pt, const Item * const pi)
{
	Node * newNode, * scan, * parent ;
	int index ;

	newNode = makeNode_K (pi, (*pt) -> k) ;
	if (NULL == newNode)
		return FALSE ;
	if (IsEmpty_K (pt))
		(*pt) -> root = newNode ;
	else
	{
		scan = (*pt) -> root ;
		index = 0 ;
		while (scan != NULL)
		{
			parent = scan ;
			if (pi[index] < scan -> item[index])
				scan = scan -> left ;
			else
				scan = scan -> right ;
			index = ADD_INDEX ((*pt) -> k, index) ;
		}
		index = SUBTRACT_INDEX ((*pt) -> k, index) ;
		if (pi[index] < parent -> item[index])
			parent -> left = newNode ;
		else
			parent -> right = newNode ;
	}
	(*pt) -> current++ ;

	return TRUE ;
}

int Find_K (const KDTree * const pt, const Item * const low, const Item * const high, void (* pfun) (const Node * const pn, const int k))
{
	Queue queue ;
	QueueNode * qNode ;
	Node * scan ;
	int index, count ;

	if (IsEmpty_K (pt))
		return 0 ;
	if (FALSE == Initialize_Q (&queue))
	{
		puts ("Out of space.") ;
		return 0 ;
	}
	qNode = (QueueNode *) malloc (sizeof (QueueNode)) ;
	if (NULL == qNode)
	{
		Release_Q (&queue) ;
		puts ("Out of space.") ;
		return 0 ;
	}
	scan = (*pt) -> root ;
	count = 0 ;
	EnQueue_Q (&queue, scan, 0) ;
	while (!IsEmpty_Q (&queue))
	{
		DeQueue_Q (&queue, qNode) ;
		scan = qNode -> node ;
		index = qNode -> index ;
		if (TRUE == within_K (scan -> item, low, high, (*pt) -> k) && FALSE == scan -> deleted)
		{
			(* pfun) (scan, (*pt) -> k) ;
			count++ ;
		}
		if (low[index] <= scan -> item[index] && scan -> left != NULL)
			EnQueue_Q (&queue, scan -> left, ADD_INDEX ((*pt) -> k, index)) ;
		if (scan -> item[index] <= high[index] && scan -> right != NULL)
			EnQueue_Q (&queue, scan -> right, ADD_INDEX ((*pt) -> k, index)) ;
	}
	Release_Q (&queue) ;
	free (qNode) ;

	return count ;
}

int Delete_K (const KDTree * const pt, const Item * const pi)
{
	Node * scan ;
	int index, count ;

	if (IsEmpty_K (pt))
		return 0 ;
	scan = (*pt) -> root ;
	index = 0 ;
	count = 0 ;
	while (scan != NULL)
	{
		if (pi[index] < scan -> item[index])
			scan = scan -> left ;
		else if (pi[index] > scan -> item[index])
			scan = scan -> right ;
		else
		{
			if (TRUE == equal_K (scan -> item, pi, (*pt) -> k) && FALSE == scan -> deleted)
			{
				scan -> deleted = TRUE ;
				count++ ;
			}
			scan = scan -> right ;
		}
		index = ADD_INDEX ((*pt) -> k, index) ;
	}
	(*pt) -> current -= count ;

	return count ;
}

void Release_K (const KDTree * const pt)
{
	release_K ((*pt) -> root) ;
	free (*pt) ;
}

/*	局部函数定义	*/

/*	队列部分	*/
static QueueNode * makeNode_Q (Node * const pn, const int index)
{
	QueueNode * newQNode ;

	newQNode = (struct queueNode *) malloc (sizeof (struct queueNode)) ;
	if (NULL == newQNode)
		return NULL ;
	newQNode -> node = pn ;
	newQNode -> next = NULL ;
	newQNode -> index = index ;

	return newQNode ;
}

/*	k-d树部分	*/
static Node * makeNode_K (const Item * const pi, const int k)
{
	Node * newNode ;
	int i ;

	newNode = (Node *) malloc (sizeof (Node)) ;
	if (NULL == newNode)
		return NULL ;
	newNode -> item = (Item *) malloc (sizeof (Item) * k) ;
	if (NULL == newNode -> item)
	{
		free (newNode) ;
		return NULL ;
	}
	for (i = 0; i < k; i++)
		newNode -> item[i] = pi[i] ;
	newNode -> deleted = FALSE ;
	newNode -> left = newNode -> right = NULL ;

	return newNode ;
}

static BOOL within_K (const Item * const pi, const Item * const low, const Item * const high, const int k)
{
	int i ;

	for (i = 0; i < k; i++)
	{
		if (low[i] > pi[i] || high[i] < pi[i])
			return FALSE ;
	}

	return TRUE ;
}

static BOOL equal_K (const Item * const piS, const Item * const pi, const int k)
{
	int i ;

	for (i = 0; i < k; i++)
	{
		if (piS[i] != pi[i])
			return FALSE ;
	}

	return TRUE ;
}

static void release_K (Node * const pn)
{
	if (pn != NULL)
	{
		release_K (pn -> left) ;
		release_K (pn -> right) ;
		free (pn -> item) ;
		free (pn) ;
	}
}