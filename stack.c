/*	stack.c -- 栈实现文件	*/
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/*	局部函数声明	*/
Node * Make_Node (const Item * pitem) ;

/*	接口函数定义	*/

void InitializeStack (Stack * pstack)
{
	*pstack = NULL ;
}

int StackIsEmpty (const Stack * pstack)
{
	return NULL == *pstack ? 1 : 0 ;
}

int StackIsFull (const Stack * pstack)
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

int StackItemCount (const Stack * pstack)
{
	Node * scan = *pstack ;
	int count = 0 ;

	while (scan != NULL)
	{
		count++ ;
		scan = scan -> next ;
	}

	return count ;
}

int Push (Stack * pstack, const Item * pitem)
{
	Node * new_node ;

	if (StackIsFull (pstack))
		return 0 ;
	new_node = Make_Node (pitem) ;
	if (NULL == new_node)
		return 0 ;
	else
	{
		if (StackIsEmpty (pstack))
		{
			new_node -> next = NULL ;
			(*pstack) = new_node ;
		}
		else
		{
			new_node -> next = *pstack ;
			*pstack = new_node ;
		}
		return 1 ;
	}
}

Item Top (const Stack * pstack)
{
	if (StackIsEmpty (pstack))
		return NUL ;
	else
		return (*pstack) -> item ;
}

int Pop (Stack * pstack)
{
	Node * temp ;

	if (StackIsEmpty (pstack))
		return 0 ;
	else
	{
		temp = *pstack ;
		*pstack = (*pstack) -> next ;
		free (temp) ;
		return 1 ;
	}
}

void Traverse (const Stack * pstack, void (* pfun)(const Item item))
{
	Node * scan ;
	
	scan = *pstack ;
	while (scan != NULL)
	{
		(* pfun) (scan -> item) ;
		scan = scan -> next ;
	}
	putchar ('\n') ;
}

void DeleteStack (Stack * pstack)
{
	Node * temp ;

	while (*pstack != NULL)
	{
		temp = *pstack ;
		*pstack = (*pstack) -> next ;
		free (temp) ;
	}
}

/*	局部函数定义	*/
Node * Make_Node (const Item * pitem)
{
	Node * new_node ;

	new_node = (Node *) malloc (sizeof (Node)) ;
	new_node -> item = *pitem ;

	return new_node ;
}