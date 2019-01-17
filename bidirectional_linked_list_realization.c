/*  bidirectional_linked_list_realization.c -- 双向链表实现  */
#include <stdio.h>
#include <stdlib.h>
#include "bidirectional_linked_list.h"

/*	局部函数声明	*/
Node * MakeNode (const Item * pitem) ;

/*	接口函数定义	*/

void InitializeList (List * plist)
{
	/*	头节点指向NULL	*/
	*plist = NULL ;
}

int ListIsEmpty (const List * plist)
{
	return NULL == *plist ? 1 : 0 ;
}

int ListIsFull (const List * plist)
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

int AddItem (List * plist, const Item * pitem)
{
	Node * scan, * new_node ;

	scan = *plist ;
	if (NULL == (new_node = MakeNode (pitem)))
		return 0 ;
	if (ListIsEmpty (plist))
		*plist = new_node ;
	else
	{
		while (scan -> next != NULL)
			scan = scan -> next ;
		scan -> next = new_node ;
		new_node -> previous = scan ;
	}

	return 1 ;
}

void Traverse (const List * plist, void (* pfun) (const Item * pitem))
{
	Position temp ;
	
	temp = *plist ;
	while (temp != NULL)
	{
		(* pfun) (&temp -> item) ;
		temp = temp -> next ;
	}
	putchar ('\n') ;
}

void DeleteList (List * plist)
{
	Position temp ;

	while (*plist != NULL)
	{
		temp = *plist ;
		*plist = (*plist) -> next ;
		free (temp) ;
	}
}

int SwapPosition (Position position_nowaday)
{
	Position position_1, position_2 ;

	if (NULL == (position_1 = position_nowaday -> next) ||
		NULL == (position_2 = position_1 -> next))
		return 0 ;
	else
	{
		position_nowaday -> next = position_2 ;
		position_1 -> next = position_2 -> next ;
		position_1 -> previous = position_2 ;
		position_2 -> next = position_1 ;
		position_2 -> previous = position_nowaday ;
		return 1 ;
	}
}

/*	局部函数定义	*/
Node * MakeNode (const Item * pitem)
{
	Node * new_node ;

	new_node = (Node *) malloc (sizeof (Node)) ;
	if (NULL == new_node)
		return NULL ;
	else
	{
		new_node -> item = *pitem ;
		new_node -> previous = NULL ;
		new_node -> next = NULL ;
		return new_node ;
	}
}