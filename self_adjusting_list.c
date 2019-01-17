/*  self_adjusting_list.c -- �ӿ�ʵ���ļ�  */
#include <stdio.h>
#include <stdlib.h>
#include "self_adjusting_list.h"

/*	�ֲ���������	*/
typedef struct pair
{
	Position previous ;
	Position current ;
	int index ;
} Pair ;

/*	�ֲ���������	*/
Position MakeNewNode (const Item * pitem) ;
Pair SeekItem (const List * plist, const Item * pitem) ;


/*	�ӿں�������	*/
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

	/*	�¶������������,���������.Ҳ���Ǳ������ڲ����Ƶ�ԭ��,��ʱ���Ͳ����	*/
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

	/*	�������Ϊ��	*/
	if (ListIsEmpty (plist))
		return 0 ;
	/*	�������ֻ��1�����	*/
	if (NULL == (*plist) -> next)
	{
		if (*pitem == (*plist) -> item)
			return 1 ;
		else
			return 0 ;
	}
	pair = SeekItem (plist, pitem) ;
	/*	���δ�ҵ�	*/
	if (0 == pair.index)
		return 0 ;
	/*	������ҵ���Ԫ�ز��ǵ�һ��Ԫ��	*/
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

/*	�ֲ���������	*/
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