/*	LinkedList.c -- 双向循环链表实现文件	*/
#include "LinkedList.h"

/*	局部函数声明	*/

static Node * makeNode (const Item * const pi) ;

/*	接口函数定义	*/

BOOL Create_B (LinkedList * const pl)
{
	*pl = (struct linkedlist *) malloc (sizeof (struct linkedlist)) ;
	if (NULL == *pl)
		return FALSE ;
	(*pl) -> list = NULL ;
	(*pl) -> current = 0 ;

	return TRUE ;
}

BOOL IsEmpty_B (const LinkedList * const pl)
{
	if (0 == (*pl) -> current)
		return TRUE ;
	else
		return FALSE ;
}

BOOL Insert_B (const LinkedList * const pl, const Item * const pi)
{
	Node * new_node ;

	new_node = makeNode (pi) ;
	if (NULL == new_node)
		return FALSE ;
	if (IsEmpty_B (pl))
	{
		new_node -> left = new_node -> right = new_node ;
		(*pl) -> list = new_node ;
	}
	else
	{
		(*pl) -> list -> right -> left = new_node ;
		new_node -> left = (*pl) -> list ;
		new_node -> right = (*pl) -> list -> right ;
		(*pl) -> list -> right = new_node ;
	}
	(*pl) -> current++ ;

	return TRUE ;
}

Node * Find_B (const LinkedList * const pl, const Item * const pi)
{
	Node * scan ;
	int i, num ;

	if (IsEmpty_B (pl))
		return NULL ;
	for (i = 0, num = (*pl) -> current, scan = (*pl) -> list; i < num; i++)
	{
		if (scan -> item != *pi)
			scan = scan -> right ;
		else
			return scan ;
	}

	return NULL ;
}

BOOL Delete_B (const LinkedList * const pl, const Item * const pi)
{
	Node * target ;

	target = Find_B (pl, pi) ;
	if (NULL == target)
		return FALSE ;
	if (1 == (*pl) -> current)
	{
		target = (*pl) -> list ;
		(*pl) -> list = NULL ;
	}
	else
	{
		target -> left -> right = target -> right ;
		target -> right -> left = target -> left ;
		if (target == (*pl) -> list)
			(*pl) -> list = target -> right ;
	}
	free (target) ;
	(*pl) -> current-- ;

	return TRUE ;
}

void Traversal_B (const LinkedList * const pl, void (* pfun) (const Node * const pn))
{
	Node * scan ;
	int i, num ;

	for (i = 0, num = (*pl) -> current, scan = (*pl) -> list; i < num; i++)
	{
		(* pfun) (scan) ;
		scan = scan -> right ;
	}
	putchar ('\n') ;
}

void Release_B (const LinkedList * const pl)
{
	Node * scan ;
	int i, num ;

	for (i = 1, num = (*pl) -> current, scan = (*pl) -> list; i < num; i++)
	{
		scan = scan -> right ;
		free (scan -> left) ;
	}
	free (*pl) ;
}

/*	局部函数定义	*/

static Node * makeNode (const Item * const pi)
{
	Node * new_node ;

	new_node = (Node *) malloc (sizeof (Node)) ;
	if (NULL == new_node)
		return NULL ;
	new_node -> item = *pi ;

	return new_node ;
}