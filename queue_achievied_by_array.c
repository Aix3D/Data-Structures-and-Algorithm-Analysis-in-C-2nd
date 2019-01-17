/*	queue_achievied_by_array.c -- 队列实现文件	*/
#include <stdio.h>
#include <stdlib.h>
#include "queue_achievied_by_array.h"

/*	局部函数声明	*/
static void Make_Empty (Queue queue) ;
static int The_Index_of_Rear (int index, const Queue queue) ;

/*	接口函数定义	*/
Queue CreateQueue (const int size)
{
	Queue queue ;

	if (size < MINQUEUESIZE)
		return NULL ;
	if (NULL == (queue = (Record *) malloc (sizeof (Record))))
		return NULL ;
	if (NULL == (queue -> array = (Item *) malloc (sizeof (Item) * size)))
	{
		free (queue) ;
		return NULL ;
	}
	queue -> capacity = size ;
	Make_Empty (queue) ;

	return queue ;
}

int QueueIsEmpty (const Queue queue)
{
	/*	返回表达式的值	*/
	return 0 == queue -> size ;
}

int QueueIsFull (const Queue queue)
{
	return queue -> capacity == queue -> size ;
}

int QueueItemCount (const Queue queue)
{
	return queue -> size ;
}

int EnQueue (Queue queue, const Item item)
{
	if (QueueIsFull (queue))
		return 0 ;
	else
	{
		queue -> size++ ;
		queue -> rear = The_Index_of_Rear (queue -> rear, queue) ;
		queue -> array[queue -> rear] = item ;
		return 1 ;
	}
}
/*	 Item * const pitem表示pitem指针本身是不能改变的,指向的值可以改变	*/
int DeQueue (Queue queue, Item * const pitem)
{
	if (QueueIsEmpty (queue))
		return 0 ;
	*pitem = queue -> array[queue -> front] ;
//	pitem = queue -> array + queue -> front ;
	queue -> size-- ;
	queue -> front++ ;
	return 1 ;
}

void Traverse (const Queue queue, void (* pfun) (const Item item))
{
	int count = queue -> front ;

	if (QueueIsEmpty (queue))
		return ;
	while (count != queue -> rear)
	{
		if (queue -> capacity - 1 == count)
			count = 0 ;
		(* pfun) (queue -> array[count++]) ;
	}
	(* pfun) (queue -> array[count]) ;
	putchar ('\n') ;
}

void EmptyTheQueue (Queue queue)
{
	free (queue -> array) ;
	free (queue) ;
}

/*	局部函数定义	*/
static void Make_Empty (Queue queue)
{
	queue -> size = 0 ;
	queue -> front = 0 ;
	queue -> rear = -1 ;
}

static int The_Index_of_Rear (int index, const Queue queue)
{
	if (queue -> capacity == ++index)
		index = 0 ;
	return index ;
}