/*	rqueue.c -- 队列实现文件	*/
#include <stdio.h>
#include <stdlib.h>
#include "rqueue.h"

/*	局部函数声明	*/

static Rqueue_Node * Make_Node (const Item_R index) ;

/*	接口函数定义	*/

int Initialize_R (Rqueue * const prq)
{
	*prq = (struct rqueue *) malloc (sizeof (struct rqueue)) ;
	if (NULL == *prq)
		return 0 ;
	(*prq) -> front = (*prq) -> rear = NULL ;
	(*prq) -> current = 0 ;

	return 1 ;
}

int IsEmpty_R (const Rqueue * const prq)
{
	return 0 == (*prq) -> current ;
}

int Insert_R (const Rqueue * const prq, const Item_R index)
{
	Rqueue_Node * new_node ;

	new_node = Make_Node (index) ;
	if (NULL == new_node)
		return 0 ;
	if (IsEmpty_R (prq))
		(*prq) -> front = (*prq) -> rear = new_node ;
	else
	{
		(*prq) -> rear -> next = new_node ;
		(*prq) -> rear = (*prq) -> rear -> next ;
	}
	(*prq) -> current++ ;

	return 1 ;
}

int Delete_R (const Rqueue * const prq, Item_R * const pindex)
{
	Rqueue_Node * temp ;

	if (IsEmpty_R (prq))
		return 0 ;
	*pindex = (*prq) -> front -> index_in_adjacenty_list ;
	temp = (*prq) -> front ;
	(*prq) -> front = (*prq) -> front -> next ;
	free (temp) ;
	(*prq) -> current-- ;
	if (IsEmpty_R (prq))
		(*prq) -> rear = NULL ;

	return 1 ;
}

void Release_R (const Rqueue * const prq)
{
	Rqueue_Node * scan, * temp ;

	scan = (*prq) -> front ;
	while (scan)
	{
		temp = scan ;
		scan = scan -> next ;
		free (temp) ;
	}
	free (*prq) ;
}

/*	局部函数定义	*/

static Rqueue_Node * Make_Node (const Item_R index)
{
	Rqueue_Node * new_node ;

	new_node = (Rqueue_Node *) malloc (sizeof (Rqueue_Node)) ;
	if (NULL == new_node)
		return NULL ;
	new_node -> index_in_adjacenty_list = index ;
	new_node -> next = NULL ;

	return new_node ;
}
