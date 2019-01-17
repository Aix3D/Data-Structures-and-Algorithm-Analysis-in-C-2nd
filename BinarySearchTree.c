/*  BinarySearchTree.c -- 二叉搜索树实现文件	*/
#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

/*	局部函数声明	*/
int Left_Is_Less_Than_Right (const Item left, const Item right) ;
int Left_Is_More_Than_Right (const Item left, const Item right) ;
Position Make_Node (const Item item) ;
void Copy_Item_To_Node (Node * * pnode, const Item * pitem) ;

/*	接口函数声明	*/

void InitializeTree (Tree * ptree)
{
	*ptree = NULL ;
}

int TreeIsEmpty (const Tree tree)
{
	return NULL == tree ;
}

Position Find (const Tree tree, const Item item)
{
	if (TreeIsEmpty (tree))
		return NULL ;
	if (Left_Is_Less_Than_Right (item, tree -> item))
		return Find (tree -> left, item) ;
	else if (Left_Is_More_Than_Right (item, tree -> item))
		return Find (tree -> right, item) ;
	else
		return tree ;
}

Position FindMin (const Tree tree)
{
	if (TreeIsEmpty (tree))
		return NULL ;
	else if (NULL == tree -> left)
		return tree ;
	else
		return FindMin (tree -> left) ;
}

Position FindMax (const Tree tree)
{
	if (TreeIsEmpty (tree))
		return NULL ;
	else if (NULL == tree -> right)
		return tree ;
	else
		return FindMax (tree -> right) ;
}

Tree Insert (Tree tree, const Item item) 
{
	if (NULL == tree)
	{
		tree = Make_Node (item) ;
		if (NULL == tree)
			return NULL ;
	}
	else if (Left_Is_Less_Than_Right (item, tree -> item))
		tree -> left = Insert (tree -> left, item) ;
	else if (Left_Is_More_Than_Right (item, tree -> item))
		tree -> right = Insert (tree -> right, item) ;
	/*	Else item is in the tree already; We'll do nothing	*/

	return tree ;
}

Tree Delete (Tree tree, const Item item)
{
	Position temp ;

	if (NULL == tree)
		return NULL ;
	else if (Left_Is_Less_Than_Right (item, tree -> item))
		tree -> left = Delete (tree -> left, item) ;
	else if (Left_Is_More_Than_Right (item, tree -> item))
		tree -> right = Delete (tree -> right, item) ;
	/*	Found element to be deleted	*/
	else if (tree -> left && tree -> right)
	{
		temp = FindMin (tree) ;
		Copy_Item_To_Node (&tree, &temp -> item) ;
		tree -> right = Delete (tree -> right, tree -> item) ;
	}
	/*	one or zero children	<- 我感觉是child, 不过不自信	*/
	else
	{
		temp = tree ;
		if (NULL == tree -> left)
			tree = tree -> right ;
		else if (NULL == tree -> right)
			tree = tree -> left ;
		free (temp) ;
	}

	return tree ;
}

void InorderTraversal (const Tree tree, void (* pfun) (const Item item))
{
	if (tree != NULL)
	{
		InorderTraversal (tree -> left, pfun) ;
		(* pfun) (tree -> item) ;
		InorderTraversal (tree -> right, pfun) ;
	}
}

void EmptyTheTree (Tree tree)
{
	if (tree != NULL)
	{
		EmptyTheTree (tree -> left) ;
		EmptyTheTree (tree -> right) ;
		free (tree) ;
	}
}

/*	局部函数定义	*/
int Left_Is_Less_Than_Right (const Item left, const Item right)
{
	return left < right ;
}

int Left_Is_More_Than_Right (const Item left, const Item right)
{
	return left > right ;
}

Position Make_Node (const Item item)
{
	Node * new_node ;

	new_node = (Node *) malloc (sizeof (Node)) ;
	if (NULL == new_node)
		return NULL ;
	else
	{
		Copy_Item_To_Node (&new_node, &item) ;
		new_node -> left = NULL ;
		new_node -> right = NULL ;
		return new_node ;
	}
}

void Copy_Item_To_Node (Node * * pnode, const Item * pitem)
{
	(*pnode) -> item = *pitem ;
}