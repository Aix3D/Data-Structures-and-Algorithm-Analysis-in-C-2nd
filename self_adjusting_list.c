/*  self_adjusting_list.c -- 接口实现文件  */
#include <stdio.h>
#include <stdlib.h>
#include "self_adjusting_list.h"

/*	局部数据类型	*/
typedef struct pair
{
	Position previous ;
	Position current ;
	int index ;
} Pair ;

/*	局部函数声明	*/
Position MakeNewNode (const Item * pitem) ;
Pair SeekItem (const List * plist, const Item * pitem) ;


/*	接口函数定义	*/
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

	/*	新定义的数据类型,需加上括号.也许是编译器内部机制的原因,暂时解释不清楚	*/
	temp = (Position) malloc (sizeof (Node)) ;

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
	Position new_node ;

	if (ListIsFull (plist))
		return 0 ;
	if (NULL == (new_node = MakeNewNode (pitem)))
		return 0 ;
	if (ListIsEmpty (plist))
	{
		*plist = new_node ;
		return 1 ;
	}
	new_node -> next = *plist ;
	*plist = new_node ;

	return 1 ;
}

int FindItem (List * plist, const Item * pitem)
{
	Pair pair ;

	/*	如果链表为空	*/
	if (ListIsEmpty (plist))
		return 0 ;
	/*	如果链表只有1个结点	*/
	if (NULL == (*plist) -> next)
	{
		if (*pitem == (*plist) -> item)
			return 1 ;
		else
			return 0 ;
	}
	pair = SeekItem (plist, pitem) ;
	/*	如果未找到	*/
	if (0 == pair.index)
		return 0 ;
	/*	如果被找到的元素不是第一个元素	*/
	if (pair.previous != NULL)
	{
		pair.previous -> next = pair.current -> next ;
		pair.current -> next = *plist ;
		*plist = pair.current ;
	}

	return 1 ;
}

void Traverse (const List * plist, void (* pfun)(const Item item))
{
	Position scan ;

	scan = *plist ;
	while (scan != NULL)
	{
		(* pfun) (scan -> item) ;
		scan = scan -> next ;
	}
	putchar ('\n') ;
}

void DeleteAll (List * plist)
{
	Position scan, temp ;
	
	scan = *plist ;
	while (scan != NULL)
	{
		temp = scan ;
		scan = scan -> next ;
		free (temp) ;
	}
}

/*	局部函数定义	*/
Position MakeNewNode (const Item * pitem)
{
	Position new_node ;

	if (NULL == (new_node = (Position) malloc (sizeof (Node))))
		return NULL ;
	new_node -> item = *pitem ;
	new_node -> next = NULL ;

	return new_node ;
}

Pair SeekItem (const List * plist, const Item * pitem)
{
	Pair pair ;
	pair.previous = NULL ;
	pair.current = *plist ;
	pair.index = 0 ;

	if (ListIsEmpty (plist))
		return pair ;
	while (pair.current != NULL)
	{
		if (*pitem == pair.current -> item)
		{
			pair.index = 1 ;
			return pair ;
		}
		else
		{
			pair.previous = pair.current ;
			pair.current = pair.current -> next ;
		}
	}

	return pair ;
}