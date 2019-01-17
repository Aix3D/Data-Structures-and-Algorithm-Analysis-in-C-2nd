/*	threaded_tree.c --  线索树实现文件	*/
#include <stdio.h>
#include <stdlib.h>
#include "threaded_tree.h"

/*	局部函数声明	*/
static Node * Make_Node (const Item * const pitem) ;
static int Left_Is_Greater_Than_Right (const Item left, const Item right) ;
static int Left_Is_Lesser_Than_Right (const Item left, const Item right) ;
static int Left_Is_Equal_To_Right (const Item left, const Item right) ;
static Node * Find_Predecessor (const Tree * const ptree, Node * const parent, const Node * const pnode) ;
static Node * Find_Successor (const Tree * const ptree, Node * const parent, const Node * const pnode) ;
static Node * The_Parent_Of (const Tree * const ptree, const Node * const pnode) ;
static void Preorder_Threading (Tree * const ptree, Node * * const previous) ;
static void Inorder_Threading (Tree * const ptree, Node * * const previous) ;
static void Postorder_Threading (Tree * const ptree, Node * * const previous) ;
static void A_Recursive_Function_For_Postorder_Threaded (const Tree * const ptree, const Node * const pnode) ;

/*	接口函数定义	*/

void InitializeTree (Tree * const ptree)
{
	*ptree = NULL ;
}

int TreeIsEmpty (const Tree * const ptree)
{
	return NULL == *ptree ;
}

int Insert (Tree * const ptree, const Item * const pitem)
{
	Node * new_node ;
	Node * parent, * scan = *ptree ;

	if (NULL == (new_node = Make_Node (pitem)))
		return 0 ;
	if (TreeIsEmpty (ptree))
	{
		*ptree = new_node ;
		(*ptree) -> left = NULL ;
		(*ptree) -> right = NULL ;
		return 1 ;
	}
	while (scan != NULL)
	{
		parent = scan ;
		if (Left_Is_Greater_Than_Right (*pitem, scan -> item))
		{
			if (THREAD == scan -> right_tag)
			{
				parent = scan ;
				break ;
			}
			else
				scan = scan -> right ;
		}
		else if (Left_Is_Lesser_Than_Right (*pitem, scan -> item))
		{
			if (THREAD == scan -> left_tag)
			{
				parent = scan ;
				break ;
			}
			else
				scan = scan -> left ;
		}
		/*	出现重复数据	*/
		else
		{
			free (new_node) ;
			return 0 ;
		}
	}
	if (Left_Is_Greater_Than_Right (*pitem, parent -> item))
	{
		parent -> right_tag = LINK ;
		parent -> right = new_node ;
		/*	此处用来完成在添加结点时自动完成中序线索化.当前线索化函数无法对已线索化的树进行线索化	*/
/*		parent -> right -> left = Find_Predecessor (ptree, parent, parent -> right) ;
		parent -> right -> right = Find_Successor (ptree, parent, parent -> right) ;	*/
	}
	else
	{
		parent -> left_tag = LINK ;
		parent -> left = new_node ;
/*		parent -> left -> left = Find_Predecessor (ptree, parent, parent -> left) ;
		parent -> left -> right = Find_Successor (ptree, parent, parent -> left) ;	*/
	}

	return 1 ;
}

Node * FindMin (const Tree * const ptree)
{
	Node * parent = *ptree , * scan = *ptree ;

	while (scan != NULL)
	{
		parent = scan ;
		if (LINK == scan -> left_tag)
			scan = scan -> left ;
		else
			break ;
	}

	return parent ;
}

Node * FindMax (const Tree * const ptree)
{
	Node * parent = NULL, * scan = *ptree ;

	while (scan != NULL)
	{
		parent = scan ;
		if (LINK == scan -> right_tag)
			scan = scan -> right ;
		else
			break ;
	}

	return parent ;
}

/*	此函数无法完成删除结点后维持树的线索化	*/
Tree Delete (Tree tree, const Item item)
{
	Node * temp ;

	if (NULL == tree)
		return NULL ;
	if (Left_Is_Greater_Than_Right (item, tree -> item))
		tree -> right = Delete (tree -> right, item) ;
	else if (Left_Is_Lesser_Than_Right (item, tree -> item))
		tree -> left = Delete (tree -> left, item) ;
	else
	{
		if (LINK == tree -> left_tag && LINK == tree -> right_tag && tree -> left != NULL && tree -> right != NULL)
		{
			temp = FindMin (&tree -> right) ;
			tree -> item = temp -> item ;
			tree -> right = Delete (tree -> right, temp -> item) ;
		}
		else
		{
			temp = tree ;
			if (LINK == tree -> left_tag && NULL == tree -> left)
				tree = tree -> right ;
			else if (LINK == tree -> right_tag && NULL == tree -> right)
				tree = tree -> left ;
			else
				tree = NULL ;
			free (temp) ;
		}
	}

	return tree ;
}

void PreorderThreadedTraversal (const Tree tree, void (* pfun) (const Item item))
{
	Node * scan = tree ;

	while (scan != NULL)
	{
		while (LINK == scan -> left_tag)
		{
			(* pfun) (scan -> item) ;
			scan = scan -> left ;
		}
		while (scan != NULL && THREAD == scan -> right_tag)
		{
			(* pfun) (scan -> item) ;
			scan = scan -> right ;
		}
	}
}

void InorderThreadedTraversal (const Tree tree, void (* pfun) (const Item item))
{
	Node * scan = tree ;

	while (scan != NULL)
	{
		while (LINK == scan -> left_tag)
			scan = scan -> left ;
		while (THREAD == scan -> right_tag && scan -> right != NULL)
		{
			(* pfun) (scan -> item) ;
			scan = scan -> right ;
		}
		(* pfun) (scan -> item) ;
		scan = scan -> right ;
	}
}
void PostorderThreadedTraversal (const Tree tree, void (* pfun) (const Item item))
{
	Node * scan = tree ;

	while (LINK == scan -> left_tag)
		scan = scan -> left ;
	while (THREAD == scan -> right_tag)
	{
		(* pfun) (scan -> item) ;
		scan = scan -> right ;
	}
	(* pfun) (scan -> item) ;
	scan = FindMin (&tree -> right) ;
	while (THREAD == scan -> right_tag)
	{
		(* pfun) (scan -> item) ;
		scan = scan -> right ;
	}
	A_Recursive_Function_For_Postorder_Threaded (&tree, scan -> right) ;
}


	
void InorderTraversal (const Tree tree, void (* pfun) (const Item item))
{
	if (tree != NULL)
	{
		if (LINK == tree -> left_tag)
			InorderTraversal (tree -> left, pfun) ;
		(* pfun) (tree -> item) ;
		if (LINK == tree -> right_tag)
			InorderTraversal (tree -> right, pfun) ;
	}
}

void PreorderThreading (Tree * const ptree)
{
	Node * previous = NULL ;
	
	Preorder_Threading (ptree, &previous) ;
}

void InorderThreading (Tree * const ptree)
{
	Node * previous = NULL ;

	Inorder_Threading (ptree, &previous) ;
}
void PostorderThreading (Tree * const ptree)
{
	Node * previous = NULL ;

	Postorder_Threading (ptree, &previous) ;
}

/*	局部函数定义	*/

static Node * Make_Node (const Item * const pitem)
{
	Node * new_node ;

	new_node = (Node *) malloc (sizeof (Node)) ;
	if (NULL == new_node)
		return NULL ;
	else
	{
		new_node -> item = *pitem ;
		new_node -> left = NULL ;
		new_node -> right = NULL ;
		new_node -> left_tag = LINK ;
		new_node -> right_tag = LINK ;
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

static Node * Find_Predecessor (const Tree * const ptree, Node * const parent, const Node * const pnode)
{
	Node * predecessor ;
	
	if (pnode == parent -> left)
	{
		if (pnode == FindMin (ptree))
			predecessor = NULL ;
		else
			predecessor = The_Parent_Of (ptree, parent) ;
	}
	else if (pnode == parent -> right)
		predecessor = parent ;

	return predecessor ;
}

static Node * Find_Successor (const Tree * const ptree, Node * const parent, const Node * const pnode)
{
	Node * successor ;

	if (pnode == parent -> left)
		successor = parent ;
	else if (pnode == parent -> right)
	{
		if (pnode == FindMax (ptree))
			successor = NULL ;
		else
			successor = The_Parent_Of (ptree, parent) ;
	}

	return successor ;
}

static Node * The_Parent_Of (const Tree * const ptree, const Node * const pnode)
{
	Node * parent = NULL, * scan = *ptree ;

	while (scan != NULL)
	{
		parent = scan ;
		if (Left_Is_Greater_Than_Right (pnode -> item, scan -> item))
		{
			if (scan -> right != NULL)
				if (Left_Is_Equal_To_Right (pnode -> item, scan -> right -> item))
					break ;
			scan = scan -> right ;
		}
		else if (Left_Is_Lesser_Than_Right (pnode -> item, scan -> item))
		{
			if (scan -> left != NULL)
				if (Left_Is_Equal_To_Right (pnode -> item, scan -> left -> item))
					break ;
			scan = scan -> left ;
		}
		else
		{
			if (*ptree == scan)
				parent = NULL ;
			break ;
		}
	}

	return parent ;
}

static void Preorder_Threading (Tree * const ptree, Node * * const previous)
{
	if (*ptree != NULL)
	{
		if (NULL == (*ptree) -> left)
		{
			(*ptree) -> left_tag = THREAD ;
			(*ptree) -> left = *previous ;
		}
		if (*previous != NULL)
		{
			if (NULL == (*previous) -> right)
			{
				(*previous) -> right_tag = THREAD ;
				(*previous) -> right = *ptree ;
			}
		}
		*previous = *ptree ;
		if (NULL == (*previous) -> right && LINK == (*previous) -> right_tag)
			(*previous) -> right_tag = THREAD ;
		if (LINK == (*ptree) -> left_tag)
			Preorder_Threading (&(*ptree) -> left, previous) ;
		if (LINK == (*ptree) -> right_tag)
			Preorder_Threading (&(*ptree) -> right, previous) ;
	}
}

static void Inorder_Threading (Tree * const ptree, Node * * const previous)
{
	if (*ptree != NULL)
	{
		Inorder_Threading (&(*ptree) -> left, previous) ;
		if (NULL == (*ptree) -> left)
		{
			(*ptree) -> left_tag = THREAD ;
			(*ptree) -> left = *previous ;
		}
		if (*previous != NULL)
			if (NULL == (*previous) -> right)
			{
				(*previous) -> right_tag = THREAD ;
				(*previous) -> right = *ptree ;
			}
		*previous = * ptree ;
		Inorder_Threading (&(*ptree) -> right, previous) ;
	}
}

static void Postorder_Threading (Tree * const ptree, Node * * const previous)
{
	if (*ptree != NULL)
	{
		Postorder_Threading (&(*ptree) -> left, previous) ;
		Postorder_Threading (&(*ptree) -> right, previous) ;
		if (NULL == (*ptree) -> left)
		{
			(*ptree) -> left_tag = THREAD ;
			(*ptree) -> left = *previous ;
		}
		if (*previous != NULL)
			if (NULL == (*previous) -> right)
			{
				(*previous) -> right_tag = THREAD ;
				(*previous) -> right = *ptree ;
			}
		*previous = *ptree ;
	}
}

static void A_Recursive_Function_For_Postorder_Threaded (const Tree * const ptree, const Node * const pnode)
{
	if (*ptree != pnode)
	{
		A_Recursive_Function_For_Postorder_Threaded (&(*ptree) -> right, pnode) ;
		printf ("%d ", (*ptree) -> item) ;
	}
}
