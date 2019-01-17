/*	skew-heap.c -- 斜堆实现文件	*/
#include <stdio.h>
#include <stdlib.h>
#include "skew-heap.h"

/*	局部ADT声明	*/

/*	Item1定义为指针类型在释放原空间后会造成非法的存储器引用	*/
/*	得到的经验教训是: 指针还是要慎用.没有理由的时候不要滥用	*/
typedef Node Item1 ;
typedef struct node1
{
	Item1 item1 ;
	struct node1 * next ;
} Node1 ;
typedef struct queue
{
	Node1 * front ;
	Node1 * rear ;
	int size ;
} * Queue ;

int Initialize_Queue (Queue * const pqueue) ;
int Queue_Is_Empty (const Queue * const pqueue) ;
int En_Queue (const Queue * const pqueue, const Item1 item1) ;
int De_Queue (const Queue * const pqueue, Item1 * const pitem1) ;
void Release_ (const Queue * const pqueue) ;
Node1 * Make_Node1 (const Item1 item1) ;

/*	局部函数声明	*/

static Heap Merge1 (const Heap h1, const Heap h2) ;
static Heap Swap_Children (const Heap h1) ;

/*	接口函数定义	*/

int Create (Heap * const ph)
{
	*ph = (Node *) malloc (sizeof (Node)) ;
	if (NULL == *ph)
		return 0 ;
	else
	{
		*ph = NULL ;
		return 1 ;
	}
}

int HeapIsEmpty (const Heap h)
{
	return NULL == h ;
}

Heap Merge (const Heap h1, const Heap h2)
{
	if (NULL == h1)
		return h2 ;
	else if (NULL == h2)
		return h1 ;
	else if (h1 -> item < h2 -> item)
		return Merge1 (h1, h2) ;
	else
		return Merge1 (h2, h1) ;
}

Heap Insert (Heap h, const Item item)
{
	Heap new_heap ;

	new_heap = (Node *) malloc (sizeof (Node)) ;
	if (NULL == new_heap)
		return h ;
	new_heap -> item = item ;
	new_heap -> left = new_heap -> right = NULL ;
	h = Merge (h, new_heap) ;

	return h ;
}

Heap DeleteMin (Heap h, Node * const pnode)
{
	Node * temp ;

	if (HeapIsEmpty (h))
		return h ;
	temp = h ;
	*pnode = *h ;
	h = Merge (h -> left, h -> right) ;
	free (temp) ;

	return h ;
}

Node * Find (const Heap h, const Item item)
{
	Node * temp ;

	if (NULL == h)
		return NULL ;
	else if (item == h -> item)
		return h ;
	else if ((temp = Find (h -> left, item)))
		return temp ;
	else if ((temp = Find (h -> right, item)))
		return temp ;
	else
		return NULL ;
}

Heap Build (const Item array[], const int size)
{
	Heap h1, h2 ;
	Queue q ;
	Node * arr ;
	int ct ;

	if (!Initialize_Queue (&q))
		return NULL ;
	arr = (Node *) malloc (sizeof (Node) * size) ;
	for (ct = 0; ct < size; ct++)
	{
		arr[ct].item = array[ct] ;
		arr[ct].left = arr[ct].right = NULL ;
		En_Queue (&q, arr[ct]) ;
	}
	//	养成内存不再使用之后立刻还回去的习惯
	free (arr) ;
	while (q -> size != 1)
	{
		//	此处的内存分配情况, 我只知道这么做内存够用.不清楚编译器是怎么分配的
		h1 = (Node *) malloc (sizeof (Node)) ;
		h2 = (Node *) malloc (sizeof (Node)) ;
		De_Queue (&q, h1) ;
		De_Queue (&q, h2) ;
		h1 = Merge (h1, h2) ;
		En_Queue (&q, *h1) ;
	}
	De_Queue (&q, h1) ;
	Release_ (&q) ;
	//	h1 和 h2 共同承担了斜堆所用内存的需求

	return h1 ;
}

void Release (const Heap h)
{
	if (h)
	{
		Release (h -> left) ;
		Release (h -> right) ;
		free (h) ;
	}
}

/*	局部函数定义	*/

static Heap Merge1 (const Heap h1, const Heap h2)
{
	if (NULL == h1 -> left)
		h1 -> left = h2 ;
	else
	{
		h1 -> right = Merge (h1 -> right, h2) ;
		//	同左式堆相比, 斜堆的好处是节省了空间, 而且少了一步条件检测
		Swap_Children (h1) ;
	}

	return h1 ;
}

static Heap Swap_Children (const Heap h1)
{
	Node * temp ;

	temp = h1 -> left ;
	h1 -> left = h1 -> right ;
	h1 -> right = temp ;

	return h1 ;
}

/*	局部ADT定义	*/

int Initialize_Queue (Queue * const pqueue)
{
	*pqueue = (struct queue *) malloc (sizeof (struct queue)) ;
	if (NULL == *pqueue)
		return 0 ;
	(*pqueue) -> front = (*pqueue) -> rear = NULL ;
	(*pqueue) -> size = 0 ;

	return 1 ;
}

int Queue_Is_Empty (const Queue * const pqueue)
{
	return 0 == (*pqueue) -> size ;
}

int En_Queue (const Queue * const pqueue, const Item1 item1)
{
	Node1 * new_node ;

	new_node = Make_Node1 (item1) ;
	if (NULL == new_node)
		return 0 ;
	if (Queue_Is_Empty (pqueue))
	{
		//	实际上队列是通过 front 实现的, rear 起的只是辅助作用. 所以不为其分配空间
		(*pqueue) -> front = (*pqueue) -> rear = new_node ;
	}
	else
	{
		/*	也许到现在我才明白了这段代码的含义	*/
		/*	在第二次调用的时候, (*pqueue) -> rear -> next = new_node 其实相当于 (*pqueue) -> front -> next = new_node	*/
		/*	在这步完成了队列的连接.太隐式了.我以前貌似真的是稀里糊涂的!	*/
		(*pqueue) -> rear -> next = new_node ;
		(*pqueue) -> rear = new_node ;
	}
	(*pqueue) -> size++ ;

	return 1 ;
}

int De_Queue (const Queue * const pqueue, Item1 * const pitem1)
{
	Node1 * temp ;

	if (Queue_Is_Empty (pqueue))
		return 0 ;
	*pitem1 = (*pqueue) -> front -> item1 ;
	temp = (*pqueue) -> front ;
	if ((*pqueue) -> size != 1)
		(*pqueue) -> front = (*pqueue) -> front -> next ;
	else
		(*pqueue) -> front = (*pqueue) -> rear = NULL ;
	(*pqueue) -> size-- ;
	free (temp) ;

	return 1 ;
}

void Release_ (const Queue * const pqueue)
{
	Node1 * scan, * temp ;

	scan = (*pqueue) -> front ;
	while (scan)
	{
		temp = scan ;
		scan = scan -> next ;
		free (temp) ;
	}
	free (*pqueue) ;
}

Node1 * Make_Node1 (const Item1 item1)
{
	Node1 * new_node ;

	new_node = (Node1 *) malloc (sizeof (Node1)) ;
	if (NULL == new_node)
		return NULL ;
	new_node -> item1 = item1 ;
	new_node -> next = NULL ;

	return new_node ;
}