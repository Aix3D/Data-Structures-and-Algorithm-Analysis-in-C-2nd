/*  unidirectional_linked_list_realization.c -- kinked_list实现文件  */
#include <stdio.h>
#include <stdlib.h>
#include "unidirectional_linked_list.h"

/*	局部数据类型	*/
typedef struct pair
{
	Position parrent ;
	Position child ;
} Pair ;

/*	局部函数声明	*/
Node * MakeNode (const Item * pitem) ;
Pair RecursiveSeekItem (const Position * pposition, const Item * pitem) ;
int SeekItem (const Position * pposition, const Item * pitem) ;

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
	if (NULL == scan)
		*plist = new_node ;
	else
	{
		while (scan -> next != NULL)
			scan = scan -> next ;
		scan -> next = new_node ;
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
		position_2 -> next = position_1 ;
		return 1 ;
	}
}

int RecursiveDeleteItem (List * plist, const Item * pitem)
{
	Pair pair ;
	Position temp ;
	
	/*	如果链表为空	*/
	if (ListIsEmpty (plist))
		return 0 ;
	/*	如果链表只有一个节点	*/
	else if (NULL == (*plist) -> next)
	{
		temp = *plist ;
		InitializeList (plist) ;
		free (temp) ;
		return 1 ;
	}
	/*	如果有多于一个节点,并且要删除掉第一个节点	*/
	else if (*pitem == (*plist) -> item)
	{
		temp = *plist ;
		*plist = (*plist) -> next ;
		free (temp) ;
		return 1 ;
	}
	pair.parrent = RecursiveSeekItem (plist, pitem).parrent ;
	pair.child = pair.parrent -> next ;
	if (NULL == pair.child)
		return 0 ;
	else
	{
		pair.parrent -> next = pair.child -> next ;
		free (pair.child) ;
		return 1 ;
	}
}

int DeleteItem (List * plist, const Item * pitem)
{
	Position temp, scan ;

	if (ListIsEmpty (plist))
		return 0 ;
	else if (0 == SeekItem (plist, pitem))
		return 0 ;
	else if (NULL == (*plist) -> next)
	{
		temp = *plist ;
		InitializeList (plist) ;
		free (temp) ;
		return 1 ;
	}
	else
	{
		scan = *plist ;
		while (scan -> next != NULL && scan -> next -> item != *pitem)
			scan = scan -> next ;
		if (NULL == scan)
			return 0 ;
		else
		{
			temp = scan -> next ;
			scan -> next = scan -> next -> next ;
			free (temp) ;
			return 1 ;
		}
	}
}

int DeleteCircularListItem (List * plist, const Item * pitem)
{
	List scan = *plist ;
	Position temp ;

	while (scan -> next -> item != *pitem && scan -> next != *plist)
		scan = scan -> next ;
	if (scan -> next != *plist)
	{
		temp = scan -> next ;
		scan -> next = scan -> next -> next ;
		free (temp) ;
		return 1 ;
	}
	else
		return 0 ;
}

int MakeACircularList (List * plist, const Item * pitem)
{
	Position scan = *plist, new_node ;

	if (NULL == (new_node = MakeNode (pitem)))
		return 0 ;
	new_node -> next = *plist ;
	if (NULL == scan)
		scan = new_node ;
	else
	{
		while (scan -> next != NULL)
			scan = scan -> next ;
		scan -> next = new_node ;
	}

	return 1 ;
}

void InverseList (List * plist)
{
	Position PreviousPos, CurrentPos, NextPos ;

	PreviousPos = NULL ;
	CurrentPos = *plist ;
	NextPos = (*plist) -> next ;

	while (NextPos != NULL)
	{
		CurrentPos -> next = PreviousPos ;
		PreviousPos = CurrentPos ;
		CurrentPos = NextPos ;
		NextPos = NextPos -> next ;
	}
	CurrentPos -> next = PreviousPos ;
	(*plist) = CurrentPos ;
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
		new_node -> next = NULL ;
		return new_node ;
	}
}

Pair RecursiveSeekItem (const Position * pposition, const Item * pitem)
{
	Pair pair ;
	pair.parrent = *pposition ;
	pair.child = (*pposition) -> next ;


	if (pair.child != NULL)
	{
		if (*pitem == pair.child -> item)
			return pair ;
		else
		{
			RecursiveSeekItem (&pair.child, pitem) ;
		}
	}
/*	此处使用的是尾递归,所以递归后面不能有语句	
	return pair ;	*/
}

int SeekItem (const Position * pposition, const Item * pitem)
{
	Position scan = *pposition ;

	while (scan != NULL)
	{
		if (*pitem == scan -> item)
			return 1 ;
		else
			scan = scan -> next ;
	}

	return 0 ;
}