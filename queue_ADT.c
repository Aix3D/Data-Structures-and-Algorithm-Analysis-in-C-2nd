/*	queue_ADT.c -- 队列模型实现文件	*/
#include <stdio.h>
#include <stdlib.h>
#include "queue_ADT.h"

/*	局部函数声明	*/

static Queue_Node * Make_Queue_Node (const Queue_Item * const pqueue_item) ;

/*	接口函数定义	*/

int InitializeQueue (Queue * const pqueue)
{
	*pqueue = (struct queue *) malloc (sizeof (struct queue)) ;
	if (*pqueue)
	{
		(*pqueue) -> front = (*pqueue) -> rear = NULL ;
		return 1 ;
	}
	else
		return 0 ;
}

int QueueIsEmpty (const Queue * const pqueue)
{
	return NULL == (*pqueue) -> front ;
}

int EnQueue (Queue * const pqueue, const Queue_Item * const pqueue_item)
{
	Queue_Node * new_queue_node ;

	new_queue_node = Make_Queue_Node (pqueue_item) ;
	if (NULL == new_queue_node)
		return 0 ;
	if (QueueIsEmpty (pqueue))
		(*pqueue) -> front = (*pqueue) -> rear = new_queue_node ;
	else
		(*pqueue) -> rear = (*pqueue) -> rear -> next = new_queue_node ;

	return 1 ;
}

int DeQueue (Queue * const pqueue, Queue_Item * const pqueue_item)
{
	Queue_Node * temp ;

	if (QueueIsEmpty (pqueue))
		return 0 ;
	*pqueue_item = (*pqueue) -> front -> queue_item ;
	if ((*pqueue) -> front == (*pqueue) -> rear)
	{
		free ((*pqueue) -> front) ;
		(*pqueue) -> front = (*pqueue) -> rear = NULL ;
	}
	else
	{
		temp = (*pqueue) -> front ;
		(*pqueue) -> front = (*pqueue) -> front -> next ;
		free (temp) ;
	}

	return 1 ;
}

void ReleaseQueue (Queue * const pqueue)
{
	Queue_Node * temp, * scan = (*pqueue) -> front ;

	while (scan)
	{
		temp = scan ;
		scan = scan -> next ;
		free (temp) ;
	}
	free (*pqueue) ;
}

/*	局部函数定义	*/

static Queue_Node * Make_Queue_Node (const Queue_Item * const pqueue_item)
{
	Queue_Node * new_queue_node ;

	new_queue_node = (Queue_Node *) malloc (sizeof (Queue_Node)) ;
	if (new_queue_node)
	{
		new_queue_node -> queue_item = *pqueue_item ;
		new_queue_node -> next = NULL ;
	}

	return new_queue_node ;
}