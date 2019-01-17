/*  doubly_queue.c -- 双端队列实现文件  */
#include <stdio.h>
#include <stdlib.h>
#include "doubly_queue.h"

/*	局部函数声明	*/
static Node * Make_Node (const Item * pitem) ;
static Node * Seek_The_Node_Before_The_Rear (const Queue * pqueue) ;

/*	接口函数定义	*/

void InitializeDoublyQueue (Queue * pqueue)
{
	pqueue -> front = pqueue -> rear = NULL ;
	pqueue -> items = 0 ;
}

int DoublyQueueIsEmpty (const Queue * pqueue)
{
	return 0 == pqueue -> items ;
}

int DoublyQueueIsFull (const Queue * pqueue)
{
	Node * temp ;

	temp = (Node *) malloc (sizeof (Node)) ;
	if (NULL == temp)
		return 1 ;
	else
	{
		free (temp) ;
		if (MAXDOUBLYQUEUE == pqueue -> items)
			return 1 ;
		else
			return 0 ;
	}
}

int DoublyQueueItemCount (const Queue * pqueue)
{
	return pqueue -> items ;
}

int Push (Queue * pqueue, const Item * pitem)
{
	Node * new_node ;

	if (DoublyQueueIsFull (pqueue))
		return 0 ;
	new_node = Make_Node (pitem) ;
	if (NULL == new_node)
		return 0 ;
	if (DoublyQueueIsEmpty (pqueue))
		pqueue -> front = pqueue -> rear = new_node ;
	else
	{
		new_node -> next = pqueue -> front ;
		pqueue -> front = new_node ;
	}
	pqueue -> items++ ;

	return 1 ;	
}

int Inject (Queue * pqueue, const Item * pitem)
{
	Node * new_node ;

	if (DoublyQueueIsFull (pqueue))
		return 0 ;
	new_node = Make_Node (pitem) ;
	if (NULL == new_node)
		return 0 ;
	if (DoublyQueueIsEmpty (pqueue))
		pqueue -> front = pqueue -> rear = new_node ;
	else
	{
		pqueue -> rear -> next = new_node ;
		pqueue -> rear = new_node ;
	}
	pqueue -> items++ ;

	return 1 ;
}

Item Pop (Queue * pqueue)
{
	Item return_value ;
	Node * temp ;

	if (DoublyQueueIsEmpty (pqueue))
		return NUL ;
	temp = pqueue -> front ;
	return_value = pqueue -> front -> item ;
	if (1 == DoublyQueueItemCount (pqueue))
		InitializeDoublyQueue (pqueue) ;
	else
		pqueue -> front = pqueue -> front -> next ;
	pqueue -> items-- ;
	free (temp) ;

	return return_value ;
}

Item Eject (Queue * pqueue)
{
	Item return_value ;
	Node * temp ;
	
	if (DoublyQueueIsEmpty (pqueue))
		return NUL ;
	temp = pqueue -> rear ;
	return_value = pqueue -> rear -> item ;
	if (1 == DoublyQueueItemCount (pqueue))
		InitializeDoublyQueue (pqueue) ;
	else
	{
		pqueue -> rear = Seek_The_Node_Before_The_Rear (pqueue) ;
		pqueue -> rear -> next = NULL ;
	}
	pqueue -> items-- ;
	free (temp) ;

	return return_value ;
}

void Traverse (const Queue * pqueue, void (* pfun) (const Item item))
{
	Node * scan = pqueue -> front ;

	while (scan != NULL)
	{
		(* pfun) (scan -> item) ;
		scan = scan -> next ;
	}
	putchar ('\n') ;
}

void EmptyTheDoublyQueue (Queue * pqueue)
{
	Node * temp ;

	while (pqueue -> front != NULL)
	{
		pqueue -> items-- ;
		temp = pqueue -> front ;
		pqueue -> front = pqueue -> front -> next ;
		free (temp) ;
	}
	pqueue -> rear = NULL ;
}

/*	局部函数定义	*/

static Node * Make_Node (const Item * pitem)
{
	Node * new_node ;

	new_node = (Node *) malloc (sizeof (Node)) ;
	if (NULL == new_node)
		return NULL ;
	new_node -> item = *pitem ;
	new_node -> next = NULL ;

	return new_node ;
}

static Node * Seek_The_Node_Before_The_Rear (const Queue * pqueue)
{
	Node * scan ;

	scan = pqueue -> front ;
	while (scan -> next -> next != NULL)
		scan = scan -> next ;

	return scan ;
}