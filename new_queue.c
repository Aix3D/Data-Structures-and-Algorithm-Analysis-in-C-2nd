/*  new_queue.c -- 队列实现文件	*/
#include <stdio.h>
#include <stdlib.h>
#include "new_queue.h"

/*	局部函数声明	*/
static QueueNode * Make_Node (const QueueItem * const pitem) ;
static void Copy_Item_To_Node (const QueueItem * const pitem, QueueNode * * const pnode) ;

/*	接口函数定义	*/

void InitializeQueue (Queue * const pqueue)
{
	(*pqueue).front = (*pqueue).rear = NULL ;
}

int QueueIsEmpty (const Queue * const pqueue)
{
	return NULL == (*pqueue).rear ;
}

int EnQueue (Queue * const pqueue, const QueueItem * const pitem)
{
	QueueNode * new_node ;
	
	new_node = Make_Node (pitem) ;
	if (NULL == new_node)
		return 0 ;
	if (QueueIsEmpty (pqueue))
		(*pqueue).front = (*pqueue).rear = new_node ;
	else
	{
		(*pqueue).rear -> next = new_node ;
		(*pqueue).rear = (*pqueue).rear -> next ;
	}

	return  1 ;
}

QueueItem DeQueue (Queue * const pqueue)
{
	QueueNode * temp ;
	QueueItem return_value ;

	if (QueueIsEmpty (pqueue))
		return NULL ;
	temp = (*pqueue).front ;
	return_value = (*pqueue).front -> item ;
	if ((*pqueue).front == (*pqueue).rear)
		InitializeQueue (pqueue) ;
	else
		(*pqueue).front = (*pqueue).front -> next ;

	free (temp) ;

	return return_value ;
}

void Traversal (const Queue * const pqueue, void (* pfun) (const QueueItem item))
{
	QueueNode * scan = (*pqueue).front ;

	while (scan != NULL)
	{
		(* pfun) (scan -> item) ;
		scan = scan -> next ;
	}
}

void EmptyTheQueue (Queue * const pqueue)
{
	QueueNode * scan = (*pqueue).front, * temp ;

	while (scan != NULL)
	{
		temp = scan ;
		scan = scan -> next ;
		free (temp) ;
	}
}

/*	局部函数定义	*/

static QueueNode * Make_Node (const QueueItem * const pitem)
{
	QueueNode * new_node ;

	new_node = (QueueNode *) malloc (sizeof (QueueNode)) ;
	if (NULL == new_node)
		return NULL ;
	else
	{
		Copy_Item_To_Node (pitem, &new_node) ;
		new_node -> next = NULL ;
		return new_node ;
	}
}

static void Copy_Item_To_Node (const QueueItem * const pitem, QueueNode * * const pnode)
{
	(*pnode) -> item = *pitem ;
}