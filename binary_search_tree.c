/*  binary_search_tree.c -- 二叉搜索树实现文件	*/
#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"

/*	局部函数声明	*/

static Node * Make_Node (const Item item) ;
static int Left_Is_Greater_Than_Right (const Item left, const Item right) ;
static int Left_Is_Lesser_Than_Right (const Item left, const Item right) ;
static int Left_Is_Equal_To_Right (const Item left, const Item right) ;
void Copy_Item_To_Node (const Item * const pitem, Node * * const pnode) ;

/*	接口函数定义	*/

void InitializeTree (Tree * const ptree)
{
	(*ptree) = NULL ;
}

int TreeIsEmpty (const Tree * const ptree)
{
	return NULL == (*ptree) ;
}

int Insert (Tree * const ptree, const Item * const pitem)
{
	Node * new_node, * parent, * scan = *ptree ;
/*	int depth =  0 ;	*/
	
	new_node = Make_Node (*pitem) ;
	if (NULL == new_node)
		return 0 ;
	if (TreeIsEmpty (ptree))
	{
		*ptree = new_node ;
		return 1 ;
	}
	while (scan != NULL)
	{
		parent = scan ;
		if (Left_Is_Greater_Than_Right (*pitem, scan -> item))
			scan = scan -> right ;
		else if (Left_Is_Lesser_Than_Right (*pitem, scan -> item))
			scan = scan -> left ;
		else
			return 0 ;
/*		depth++ ;		决定通过函数统一设置深度,逃避了删除节点时更新深度的问题	*/
	}
	if (Left_Is_Greater_Than_Right (*pitem, parent -> item))
		parent -> right = new_node ;
	else
		parent -> left = new_node ;
/*	new_node -> depth = depth ;		*/

	return 1 ;
}

Tree Delete (Tree tree, const Item item)
{
	Node * temp ;

	if (NULL == tree)
		return NULL ;
	else if (Left_Is_Greater_Than_Right (item, tree -> item))
		tree -> right = Delete (tree -> right, item) ;
	else if (Left_Is_Lesser_Than_Right (item, tree -> item))
		tree -> left = Delete (tree -> left, item) ;
	else
	{
		if (tree -> left != NULL && tree -> right != NULL)
		{
			temp = FindMin (&tree -> right) ;
			Copy_Item_To_Node (&temp -> item, &tree) ;
			tree -> right = Delete (tree -> right, temp -> item) ;
		}
		else
		{
			temp = tree ;
			if (NULL == tree -> left)
				tree = tree -> right ;
			else if (NULL == tree -> right)
				tree = tree -> left ;
			free (temp) ;
		}
	}

	return tree ;
}

Node * FindMin (const Tree * const ptree)
{
	Node * scan = *ptree ;

	if (TreeIsEmpty (ptree))
		return NULL ;
	while (scan -> left != NULL)
		scan = scan -> left ;

	return scan ;
}

Node * FindMax (const Tree * const ptree)
{
	if (NULL == *ptree)
		return NULL ;
	else if (NULL == (*ptree) -> right)
		return *ptree ;
	else
		return FindMax (&(*ptree) -> right) ;
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


void EmptyTheTree (const Tree tree)
{
	if (tree != NULL)
	{
		EmptyTheTree (tree -> left) ;
		EmptyTheTree (tree -> right) ;
		free (tree) ;
	}
}

/*	局部函数定义	*/

static Node * Make_Node (const Item item)
{
	Node * new_node ;

	new_node = (Node *) malloc (sizeof (Node)) ;
	if (NULL == new_node)
	{
		puts ("Out of space") ;
		return NULL ;
	}
	else
	{
		new_node -> item = item ;
		new_node -> depth = 0 ;
		new_node -> x_coordinate = 0 ;
		new_node -> y_coordinate = 0 ;
		new_node -> left = NULL ;
		new_node -> right = NULL ;
		return new_node ;
	}
}

static int Left_Is_Greater_Than_Right (const Item left, const Item right)
{
	return left > right ;
}
static int Left_Is_Lesser_Than_Right (const Item left, const Item right)
{
	return left < right ;
}

static int Left_Is_Equal_To_Right (const Item left, const Item right)
{
	return left == right ;
}

void Copy_Item_To_Node (const Item * const pitem, Node * * const pnode)
{
	(*pnode) -> item = *pitem ;
}