/*  lazy_deletion_linked_list.c -- 懒惰删除链表接口实现文件	*/
#include <stdio.h>
#include <stdlib.h>
#include "lazy_deletion_linked_list.h"

/*	局部数据类型	*/
typedef struct pair
{
	Position pervious ;
	Position current ;
	unsigned int index	:	1 ;
} Pair ;

/*	局部函数声明	*/
Position Make_Node (const Item * pitem) ;
Position LookFor_Tail (const List * plist) ;
Pair SeekItem (const List * plist, const Item * pitem) ;

void InitializeList (List * plist)
{
	*plist = NULL ;
}

int ListIsEmpty (const List * plist)
{
	return NULL == *plist ? 1 : 0 ;
}

int ListIsFull (const List * plist)
{
	Position temp ;

	if (NULL == (temp = (Position) malloc (sizeof (Node))))
		return 1 ;
	else
	{
		free (temp) ;
		return 0 ;
	}
}

int AddItem (List * plist, Item * pitem)
{
	Position new_node, tail ;

	if (ListIsFull (plist))
		return 0 ;
	if (NULL == (new_node = Make_Node (pitem)))
		return 0 ;
	else
	{
		if (ListIsEmpty (plist))
			*plist = new_node ;
		else
		{
			tail = LookFor_Tail (plist) ;
			tail -> next = new_node ;
		}
		return 1 ;	
	}
}

int LazyDeleteItem (List * plist, const Item * pitem)
{
	Pair pair ;

	if (ListIsEmpty (plist))
		return 0 ;
	pair = SeekItem (plist, pitem) ;
	if (0 == pair.index)
		return 0 ;
	else
	{
		if (1 == pair.current -> item.index)
			return 0 ;
		else
		{
			pair.current -> item.index = 1 ;
			return 1 ;
		}
	}
}

int DeleteItem (List * plist, const Item * pitem)
{
	Pair pair ;
	Position temp ;

	if (ListIsEmpty (plist))
		return 0 ;
	pair = SeekItem (plist, pitem) ;
	if (0 == pair.index)
		return 0 ;
	else
	{
		if (NULL == pair.pervious)
		{
			temp = *plist ;
			*plist = (*plist) -> next ;
			free (temp) ;
		}
		else
		{
			temp = pair.current ;
			pair.pervious -> next = pair.current -> next ;
			free (temp) ;
		}
		return 1 ;
	}
}

void Traverse (const List * plist, void (* pfun)(const Item item))
{
	Position scan ;

	scan = *plist ;
	while (scan != NULL)
	{
		(*pfun) (scan -> item) ;
		scan = scan -> next ;
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

/*	局部函数定义	*/
Position Make_Node (const Item * pitem)
{
	Position new_node ;

	if (NULL == (new_node = (Position) malloc (sizeof (Node))))
		return NULL ;
	else
	{
		new_node -> item.num = (*pitem).num ;
		new_node -> next = NULL ;
		new_node -> item.index = 0 ;
		return new_node ;
	}
}

Position LookFor_Tail (const List * plist)
{
	Position scan ;

	scan = *plist ;
	while (scan -> next != NULL)
		scan = scan -> next ;
	
	return scan ;
}

Pair SeekItem (const List * plist, const Item * pitem)
{
	Pair pair ;
	pair.pervious = NULL ;
	pair.current = *plist ;
	pair.index = 0 ;

	while (pair.current != NULL)
	{
		if ((*pitem).num == pair.current -> item.num)
		{
			pair.index = 1 ;
			return pair ;
		}
		else
		{
			pair.pervious = pair.current ;
			pair.current = pair.current -> next ;
		}
	}

	return pair ;
}