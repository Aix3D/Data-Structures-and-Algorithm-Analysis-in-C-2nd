/*	queue_achievied_by_linked_list.c -- 队列实现文件	*/
#include <stdio.h>
#include <stdlib.h>
#include "queue_achievied_by_linked_list.h"

/*	局部函数声明	*/
Node * Make_Node (const Item * pitem) ;

/*	接口函数定义	*/

void InitializeQueue (Queue * pqueue)
{
	pqueue -> front = pqueue -> rear = NULL ;
	pqueue -> items = 0 ;
}

int QueueIsEmpty (const Queue * pqueue)
{
	return 0 == pqueue -> items ? 1: 0 ;
}

int QueueIsFull (const Queue * pqueue)
{
	Node * temp ;

	temp = (Node *) malloc (sizeof (Node)) ;
	if (NULL == temp)
		return 1 ;
	else
	{
		free (temp) ;
		return 0 ;
	}
}

int QueueItemCount( const Queue * pqueue)
{
	return pqueue -> items ;
}

int EnQueue (Queue * pqueue, const Item * pitem)
{
	Node * new_node ;

	if (QueueIsFull (pqueue))
		return 0 ;
	if (NULL == (new_node = Make_Node (pitem)))
		return 0 ;
	if (QueueIsEmpty (pqueue))
		pqueue -> front = new_node ;
	else
		pqueue -> rear -> next = new_node ;
	pqueue -> rear = new_node ;
	pqueue -> items++ ;

	return 1 ;
}

int DeQueue (Queue * pqueue, Item * pitem)
{
	Node * temp ;

	if (QueueIsEmpty (pqueue))
		return 0 ;
	*pitem = pqueue -> front -> item ;
	temp = pqueue -> front ;
	if (1 == QueueItemCount (pqueue))
		InitializeQueue (pqueue) ;
	else
	{
		pqueue -> front = pqueue -> front -> next ;
		pqueue -> items-- ;
	}
	free (temp) ;
	
	return 1 ;
}

void Traverse (const Queue * pqueue, void (* pfun) (const Item item))
{
	Node * scan ;

	scan = pqueue -> front ;
	while (scan != NULL)
	{
		(* pfun) (scan -> item) ;
		scan = scan -> next ;
	}
	putchar ('\n') ;
}

void EmptyTheQueue (Queue * pqueue)
{
	Item dummy ;

	while (!QueueIsEmpty (pqueue))
		DeQueue (pqueue, &dummy) ;
}

/*	局部函数定义	*/

Node * Make_Node (const Item * pitem)
{
	Node * new_node ;

	new_node = (Node *) malloc (sizeof (Node)) ;
	if (NULL == new_node)
		return NULL ;
	else
	{
		new_node -> item = *pitem ;
		new_node -> next = NULL ;
		return new_node ;
	}
}