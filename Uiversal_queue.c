/*	Uiversal_queue.c -- 队列实现文件	*/
#include "Uiversal_queue.h"

/*	Proclaim local functions	*/

static Node * makeNode (const Item * const pi) ;

/*	Define interface functions	*/

Bool Initialize_Q (Queue * const pq)
{
	*pq =  (struct queue *) malloc (sizeof (struct queue)) ;
	if (NULL == *pq)
		return FALSE ;
	(*pq) -> front = (*pq) -> rear = NULL ;
	(*pq) -> current = 0 ;

	return TRUE ;
}

Bool IsEmpty_Q (const Queue * const pq)
{
	return 0 == (*pq) -> current ;
}

Bool Insert_Q (Queue * const pq, const Item * const pi)
{
	Node * new_node ;

	new_node = makeNode (pi) ;
	if (NULL == new_node)
		return FALSE ;
	else
	{
		if (IsEmpty_Q (pq))
			(*pq) -> front = (*pq) -> rear = new_node ;
		else
		{
			(*pq) -> rear -> next = new_node ;
			(*pq) -> rear = (*pq) -> rear -> next ;
		}
		(*pq) -> current++ ;

		return TRUE ;
	}
}

Bool Delete_Q (Queue * const pq, Item * const pi)
{
	Node * scan, * temp ;

	if (IsEmpty_Q (pq))
		return FALSE ;
	else if (1 == (*pq) -> current)
	{
		*pi = (*pq) -> front -> item ;
		free ((*pq) -> front) ;
		(*pq) -> front = (*pq) -> rear = NULL ;
		(*pq) -> current-- ;

		return TRUE ;
	}
	else
	{
		scan = (*pq) -> front ;
		if (pi -> leavings == scan -> item.leavings)
		{
			*pi = (*pq) -> front -> item ;
			(*pq) -> front = (*pq) -> front -> next ;
			free (scan) ;
			(*pq) -> current-- ;

			return TRUE ;
		}
		else
		{
			while (scan)
			{
				if (pi -> leavings == scan -> next -> item.leavings)
					break ;
				else
					scan = scan -> next ;
			}
			if (pi -> leavings == scan -> next -> item.leavings)
			{
				temp = scan -> next ;
				scan -> next = scan -> next -> next ;
				free (temp) ;
				(*pq) -> current-- ;

				return TRUE ;
			}
			else
				return FALSE ;
		}
	}
}

void Traversal_Q (const Queue * const pq, void (* pfun) (const Item * const pi))
{
	Node * scan ;

	scan = (*pq) -> front ;
	while (scan)
	{
		(* pfun) (&scan -> item) ;
		scan = scan -> next ;
	}
}

void Release_Q (const Queue * const pq)
{
	Node * scan, * temp ;

	scan = (*pq) -> front ;
	while (scan)
	{
		temp = scan ;
		scan = scan -> next ;
		free (temp) ;
	}
}

/*	Define local functions	*/

static Node * makeNode (const Item * const pi)
{
	Node * new_node ;

	new_node = (Node *) malloc (sizeof (Node)) ;
	if (NULL == new_node)
		return NULL ;
	else
	{
		new_node -> item = *pi ;
		new_node -> next = NULL ;
		return new_node ;
	}
}