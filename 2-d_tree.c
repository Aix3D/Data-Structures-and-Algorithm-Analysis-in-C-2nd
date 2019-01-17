/*	2-d_tree.c -- 2-d树实现文件	*/
#include <stdio.h>
#include <stdlib.h>
#include "2-d_tree.h"

/*	局部函数声明	*/

static Node * Make_Node (const Item * const pkey1, const Item * const pkey2) ;
void Copy_Key1_To_Node (const Item * const pkey1, Node * const pnode) ;
void Copy_Key2_To_Node (const Item * const pkey2, Node * const pnode) ;
int Left_Is_Greater_Than_Right (const Item * const pleft, const Item * const pright) ;
int Left_Is_Lesser_Than_Right (const Item * const pleft, const Item * const pright) ;
int Left_Is_Equal_To_Right (const Item * const pleft, const Item * const prifht) ;
int Left_Is_Equal_Or_Greater_Than_Right (const Item * const pleft, const Item * const pright) ;
int Left_Is_Equal_Or_Lesser_Than_Right (const Item * const pleft, const Item * const pright) ;
void Set_The_Layer (const Node * const pnode, Node * const new_node) ;

/*	接口函数定义	*/

void InitializeTree (Tree * const ptree)
{
	*ptree = NULL ;
}

int TreeIsEmpty (const Tree * const ptree)
{
	return NULL == *ptree ;
}

Node * FindMin (const Tree * const ptree)
{
	if (NULL == *ptree)
		return NULL ;
	else if (NULL == (*ptree) -> left)
		return *ptree ;
	else
		return FindMin (&(*ptree) -> left) ;
}

Node * FindMax (const Tree * const ptree)
{
	Node * scan = *ptree ;
	
	if (scan != NULL)
		while (scan -> right != NULL)
			scan = scan -> right ;

	return scan ;
}

int Insert (Tree * const ptree, const Item * const pkey1, const Item * const pkey2)
{
	Node * new_node, * parent = NULL, * scan = *ptree ;

	new_node = Make_Node (pkey1, pkey2) ;
	if (NULL == new_node)
		return 0 ;
	if (TreeIsEmpty (ptree))
	{
		new_node -> layer = ODD ;
		*ptree = new_node ;
		return 1 ;
	}
	while (scan != NULL)
	{
		parent = scan ;
		if (ODD == scan -> layer)
		{
			if (Left_Is_Greater_Than_Right (&new_node -> key1, &scan -> key1))
				scan = scan -> right ;
			else if (Left_Is_Lesser_Than_Right (&new_node -> key1, &scan -> key1))
				scan = scan -> left ;
			else
			{
				free (scan) ;
				return 0 ;
			}
		}
		else if (EVEN == scan -> layer)
		{
			if (Left_Is_Greater_Than_Right (&new_node -> key2, &scan -> key2))
				scan = scan -> right ;
			else if (Left_Is_Lesser_Than_Right (&new_node -> key2, &scan -> key2))
				scan = scan -> left ;
			else
			{
				free (scan) ;
				return 0 ;
			}
		}
	}
	Set_The_Layer (parent, new_node) ;
	/*	考虑到树在很丰满的情况下只用最多3次的条件检测就可以决定新结点的位置, 没有采用花花的操作.虽然代码略显臃肿, 但可读性可效率都不差	*/
	if (ODD == parent -> layer)
	{
		if (Left_Is_Greater_Than_Right (&new_node -> key1, &parent -> key1))
			parent -> right = new_node ;
		else
			parent -> left = new_node ;
	}
	else if (EVEN == parent -> layer)
	{
		if (Left_Is_Greater_Than_Right (&new_node -> key2, &parent -> key2))
			parent -> right = new_node ;
		else
			parent -> left = new_node ;
	}

	return 1 ;
}

void InorderSeekTraversal (const Tree * const ptree, const Item low1, const Item low2, const Item high1, const Item high2, void (* pfun) (const Item * const pkey1, const Item * const pejy2))
{
	if (*ptree != NULL)
	{
		InorderSeekTraversal (&(*ptree) -> left, low1, low2, high1, high2, pfun) ;
		if (Left_Is_Equal_Or_Greater_Than_Right (&(*ptree) -> key1, &low1) && Left_Is_Equal_Or_Lesser_Than_Right (&(*ptree) -> key1, &high1) &&
			Left_Is_Equal_Or_Greater_Than_Right (&(*ptree) -> key2, &low2) && Left_Is_Equal_Or_Lesser_Than_Right (&(*ptree) -> key2, &high2))
			(* pfun) (&(*ptree) -> key1, &(*ptree) -> key2) ;
		InorderSeekTraversal (&(*ptree) -> right, low1, low2, high1, high2, pfun) ;
	}
}

Tree Delete (Tree * const ptree, const Item * const pkey1, const Item * const pkey2)
{
	char index = FALSE ;
	Node * temp ;

	if (NULL == *ptree)
		return NULL ;
	if (ODD == (*ptree) -> layer)
	{
		if (Left_Is_Greater_Than_Right (pkey1, &(*ptree) -> key1))
			(*ptree) -> right = Delete (&(*ptree) -> right, pkey1, pkey2) ;
		else if (Left_Is_Lesser_Than_Right (pkey1, &(*ptree) -> key1))
			(*ptree) -> left = Delete (&(*ptree) -> left, pkey1, pkey2) ;
		else
		{
			if (Left_Is_Equal_To_Right (pkey2, &(*ptree) -> key2))
				index = TRUE ;
		}
	}
	else if (EVEN == (*ptree) -> layer)
	{
		if (Left_Is_Greater_Than_Right (pkey2, &(*ptree) -> key2))
			(*ptree) -> right = Delete (&(*ptree) -> right, pkey1, pkey2) ;
		else if (Left_Is_Lesser_Than_Right (pkey2, &(*ptree) -> key2))
			(*ptree) -> left = Delete (&(*ptree) -> left, pkey1, pkey2) ;
		else
		{
			if (Left_Is_Equal_To_Right (pkey1, &(*ptree) -> key1))
				index = TRUE ;
		}
	}
	if (index)
	{
		if ((*ptree) -> left != NULL && (*ptree) -> right != NULL)
		{
			temp = FindMin (&(*ptree) -> right) ;
			Copy_Key1_To_Node (&temp -> key1, *ptree) ;
			Copy_Key2_To_Node (&temp -> key2, *ptree) ;
			(*ptree) -> right = Delete (&(*ptree) -> right, &temp -> key1, &temp -> key2) ;
		}
		else
		{
			temp = *ptree ;
			if (NULL == (*ptree) -> left && NULL == (*ptree) -> right)
				*ptree = (*ptree) -> right ;
			else if (NULL == (*ptree) -> left)
			{
				Set_The_Layer (*ptree, (*ptree) -> right) ;
				*ptree = (*ptree) -> right ;
			}
			else if (NULL == (*ptree) -> right)
			{
				Set_The_Layer (*ptree, (*ptree) -> left) ;
				*ptree = (*ptree) -> left ;
			}
			free (temp) ;
		}
	}

	return *ptree ;
}

/*	局部函数定义	*/

static Node * Make_Node (const Item * const pkey1, const Item * const pkey2)
{
	Node * new_node ;

	new_node = (Node *) malloc (sizeof (Node)) ;
	if (NULL == new_node)
		return NULL ;
	Copy_Key1_To_Node (pkey1, new_node) ;
	Copy_Key2_To_Node (pkey2, new_node) ;
	new_node -> left = NULL ;
	new_node -> right = NULL ;
	
	return new_node ;
}

void Copy_Key1_To_Node (const Item * const pkey1, Node * const pnode)
{
	pnode -> key1 = *pkey1 ;
}

void Copy_Key2_To_Node (const Item * const pkey2, Node * const pnode)
{
	pnode -> key2 = *pkey2 ;
}

int Left_Is_Greater_Than_Right (const Item * const pleft, const Item * const pright)
{
	return *pleft > *pright ;
}

int Left_Is_Lesser_Than_Right (const Item * const pleft, const Item * const pright)
{
	return *pleft < *pright ;
}

int Left_Is_Equal_To_Right (const Item * const pleft, const Item * const pright)
{
	return *pleft == *pright ;
}

int Left_Is_Equal_Or_Greater_Than_Right (const Item * const pleft, const Item * const pright)
{
	return *pleft >= *pright ;
}

int Left_Is_Equal_Or_Lesser_Than_Right (const Item * const pleft, const Item * const pright)
{
	return *pleft <= *pright ;
}

void Set_The_Layer (const Node * const pnode, Node * const new_node)
{
	if (ODD == pnode -> layer)
		new_node -> layer = EVEN ;
	else
		new_node -> layer = ODD ;
}