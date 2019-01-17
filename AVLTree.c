/*  AVLTree.c -- AVL树实现文件	*/
#include <stdio.h>
#include <stdlib.h>
#include "AVLTree.h"

/*	局部数据类型定义	*/

typedef Position Stack_Item ;
typedef struct stack_node
{
	Stack_Item item ;
	struct stack_node * next ;
} Stack_Node ;
typedef Stack_Node * Stack ;

/*	局部函数声明	*/
static int Left_Above_And_Beyond_Right (const Item left, const Item right) ;
static int Left_Is_Less_Than_Right (const Item left, const Item right) ;
static Position Make_Node (const Item item) ;
static void Copy_Item_To_Node (Node * * pnode, const Item * const pitem) ;
static int Height_Count (Position position) ;
static int Height_Calculate (Position position) ;
static Position Single_Rotate_With_Left (Position K2) ;
static Position Single_Rotate_With_Right (Position K2) ;
static Position Double_Rotate_With_Left (Position K3) ;
static Position Double_Rotate_With_Right (Position K3) ;
static Position New_Double_Rotate_With_Left (Position K3) ;
static Position New_Double_Rotate_With_Right (Position K3) ;
static Max (const int num, const int the_other_num) ;
void Initialize_Stack (Stack * pstack) ;
static int Stack_Is_Empty (const Stack * pstack) ;
static int Stack_Is_Full (void) ;
static int Push (Stack * pstack, const Stack_Item stack_item) ;
static int Pop (Stack * pstack) ;
static Stack_Item Top (Stack * pstack) ;
static void Empty_The_Stack (Stack * pstack) ;



/*	接口函数定义	*/

void InitializeAVLTree (Tree * ptree)
{
	*ptree = NULL ;
}

int AVLTreeIsEmpty (const Tree tree)
{
	return NULL == tree ;
}

Position Find (const Tree tree, const Item item)
{
	if (NULL == tree)
		return NULL ;
	else if (Left_Above_And_Beyond_Right (item, tree -> item))
		return Find (tree -> right, item) ;
	else if (Left_Is_Less_Than_Right (item, tree -> item))
		return Find (tree -> left, item) ;
	/*	找到该结点	*/
	else
		return tree ;
}

Position FindMax (const Tree tree)
{
	if (NULL == tree)
		return NULL ;
	else if (tree -> right != NULL)
		return FindMax (tree -> right) ;
	else
		return tree ;
}

Position FindMin (const Tree tree)
{
	if (NULL == tree)
		return NULL ;
	else if (tree -> left != NULL)
		return FindMin (tree -> left) ;
	else
		return tree ;
}

Tree Insert (Tree tree, const Item item)
{
	if (NULL == tree)
	{
		tree = Make_Node (item) ;
		if (NULL == tree)
			return NULL ;
	}
	else if (Left_Above_And_Beyond_Right (item, tree -> item))
	{
		tree -> right = Insert (tree -> right, item) ;
		if (2 == Height_Count (tree -> right) - Height_Count (tree -> left))
		{
			if (Left_Above_And_Beyond_Right (item, tree -> right -> item))
				tree = Single_Rotate_With_Right (tree) ;
			else
				tree = Double_Rotate_With_Right (tree) ;
		}
	}
	else if (Left_Is_Less_Than_Right (item, tree -> item))
	{
		tree -> left = Insert (tree -> left, item) ;
		if (2 == Height_Count (tree -> left) - Height_Count (tree -> right))
		{
			if (Left_Is_Less_Than_Right (item, tree -> left -> item))
				tree = Single_Rotate_With_Left (tree) ;
			else
				tree = Double_Rotate_With_Left (tree) ;
		}
	}

	tree -> height = Max (Height_Count (tree -> left), Height_Count (tree -> right)) + 1 ;

	return tree ;
}

Tree AddItem (Tree tree, const Item item)
{
	Position scan = tree ;
	Stack stack ;
	Stack_Item temp ;
	int lenth_left, lenth_right ;

	Initialize_Stack (&stack) ;
	if (AVLTreeIsEmpty (tree))
	{
		tree = Make_Node (item) ;
		return tree ;
	}
	while (scan != NULL)
	{
		/*	把当前结点地址压进栈里	*/
		Push (&stack, scan) ;
		if (Left_Above_And_Beyond_Right (item, scan -> item))
		{
			/*	此时的 scan 是新结点的父节点	*/
			if (NULL == scan -> right)
				break ;
			else
				scan = scan -> right ;
		}
		else if (Left_Is_Less_Than_Right (item, scan -> item))
		{
			/*	此时的 scan 是新结点的父节点	*/
			if (NULL == scan -> left)
				break ;
			else
				scan = scan -> left ;
		}
		/*	否则,出现了将要重复添加的情况	*/
		else
			return tree ;
	}
	/*	接下来添加结点	*/
	if (Left_Above_And_Beyond_Right (item, scan -> item))
	{
		scan -> right = Make_Node (item) ;
		/*	创建新结点失败的情况下	*/
		if (NULL == scan -> right)
			return tree ;
	}
	else if (Left_Is_Less_Than_Right (item, scan -> item))
	{
		scan -> left = Make_Node (item) ;
		if (NULL == scan -> left)
			return tree ;
	}
	while (!Stack_Is_Empty (&stack))
	{
		temp = Top (&stack) ;
		if (NULL == temp -> left)
			lenth_left = -1 ;
		else
			lenth_left = Height_Calculate (temp -> left) ;
		if (NULL == temp -> right)
			lenth_right = -1 ;
		else
			lenth_right = Height_Calculate (temp -> right) ;
		if (2 == lenth_left - lenth_right)
		{
			if (Left_Above_And_Beyond_Right (item, temp -> left -> item))
			{
				if (tree == temp)
					tree = New_Double_Rotate_With_Left (temp) ;
				else
					temp = New_Double_Rotate_With_Left (temp) ;
			}
			else
			{
				if (tree == temp)
					tree = Single_Rotate_With_Left (temp) ;
				else
					temp = Single_Rotate_With_Left (temp) ;
			}
		}
		if (2 == lenth_right - lenth_left)
		{
			if (Left_Above_And_Beyond_Right (item, temp -> right -> item))
			{
				if (tree == temp)
					tree = Single_Rotate_With_Right (temp) ;
				else
					temp = Single_Rotate_With_Right (temp) ;
			}
			else
			{
				if (tree == temp)
					tree = New_Double_Rotate_With_Right (temp) ;
				else
					temp = New_Double_Rotate_With_Right (temp) ;
			}
		}
		Pop (&stack) ;
	}
	Empty_The_Stack (&stack) ;

	return tree ;
}

void InorderTraversal (const Tree tree, void (* pfun) (const Position position))
{
	if (tree != NULL)
	{
		InorderTraversal (tree -> left, pfun) ;
		(* pfun) (tree) ;
		InorderTraversal (tree -> right, pfun) ;
	}
}

Tree Delete (Tree tree, const Item item)
{
	Position temp ;

	if (NULL == tree)
		/*	其实可以什么都不做, 因为下面有返回.这里满足条件返回为了体现思维的逻辑性	*/
		return NULL ;
	else if (Left_Above_And_Beyond_Right (item, tree -> item))
		tree -> right = Delete (tree -> right, item) ;
	else if (Left_Is_Less_Than_Right (item, tree -> item))
		tree -> left = Delete (tree -> left, item) ;
	else if (tree -> left && tree -> right)
	{
		temp = FindMin (tree -> right) ;
		Copy_Item_To_Node (&tree, &(temp -> item)) ;
		tree -> right = Delete (tree -> right, tree -> item) ;
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
	if (tree != NULL)
	{
		tree -> height = Max (Height_Count (tree -> left), Height_Count(tree -> right)) + 1 ;
		if (2 == Height_Count (tree -> left) - Height_Count (tree -> right))
		{
			if (NULL == tree -> left -> right)
				tree = Single_Rotate_With_Left (tree) ;
			else if (NULL == tree -> left -> left)
				tree = Double_Rotate_With_Left (tree) ;
			/*	左右全为不为NULL的情况下, 执行双旋转. 双旋转使树的数据分布更紧凑	*/
			else
				tree = Double_Rotate_With_Left (tree) ;
		}
		else if (2 == Height_Count (tree -> right) - Height_Count (tree -> left))
		{
			if (NULL == tree -> right -> left)
				tree = Single_Rotate_With_Right (tree) ;
			else if (NULL == tree -> right -> right)
				tree = Double_Rotate_With_Right (tree) ;
			else
				tree = Double_Rotate_With_Right (tree) ;
		}
	}

	return tree ;
}

void EmptyTheAVLTree (Tree tree)
{
	if (tree != NULL)
	{
		EmptyTheAVLTree (tree -> left) ;
		EmptyTheAVLTree (tree -> right) ;
		free (tree) ;
	}
}
	
/*	局部函数定义	*/

static int Left_Above_And_Beyond_Right (const Item left, const Item right)
{
	return left > right ;
}

static int Left_Is_Less_Than_Right (const Item left, const Item right)
{
	return left < right ;
}

static Position Make_Node (const Item item)
{
	Position new_node ;

	new_node = (Position) malloc (sizeof (Node)) ;
	if (NULL == new_node)
		return NULL ;
	else
	{
		Copy_Item_To_Node (&new_node, &item) ;
		new_node -> height = 0 ;
		new_node -> left = new_node -> right = NULL ;
		return new_node ;
	}
}

static void Copy_Item_To_Node (Node * * pnode, const Item * const pitem)
{
	(*pnode) -> item = *pitem ;
}

static int Height_Count (Position position)
{
	if (NULL == position)
		return -1 ;
	else
		return position -> height ;
}

static int Height_Calculate (Position position)
{
	int count_left, count_right ;

	count_left = count_right = 0 ;

	if (position != NULL)
	{
		count_left = Height_Calculate (position -> left) ;
		count_right = Height_Calculate (position -> right) ;
		if (position -> left != NULL)
			count_left++ ;
		if (position -> right != NULL)
			count_right++ ;
	}

	return count_left >= count_right ? count_left : count_right ;
}

static Position Single_Rotate_With_Left (Position K2)
{
	Position K1 ;

	K1 = K2 -> left ;
	K2 -> left = K1 -> right ;
	K1 -> right = K2 ;

	K2 -> height = Max (Height_Count (K2 -> left), Height_Count (K2 -> right)) + 1 ;
	K1 -> height = Max (Height_Count (K1 -> left), K2 -> height) + 1 ;

	return K1 ;
}

static Position Single_Rotate_With_Right (Position K2)
{
	Position K1 ;

	K1 = K2 -> right ;
	K2 -> right = K1 -> left ;
	K1 -> left = K2 ;

	K2 -> height = Max (Height_Count (K2 -> left), Height_Count (K2 -> right)) + 1 ;
	K1 -> height = Max (Height_Count (K1 -> right), K2 -> height) + 1 ;

	return K1 ;
}

static Position Double_Rotate_With_Left (Position K3)
{
	K3 -> left = Single_Rotate_With_Right (K3 -> left) ;

	return Single_Rotate_With_Left (K3) ;
}

static Position Double_Rotate_With_Right (Position K3)
{
	K3 -> right = Single_Rotate_With_Left (K3 -> right) ;

	return Single_Rotate_With_Right (K3) ;
}

static Position New_Double_Rotate_With_Left (Position K3)
{
	Position K2, K1 ;

	K2 = K3 -> left ;
	K1 = K2 -> right ;

	K2 -> right = K1 -> left ;
	K1 -> left = K2 ;
	K3 -> left = K1 -> right ;
	K1 -> right = K3 ;

	return K1 ;
}

static Position New_Double_Rotate_With_Right (Position K3)
{
	Position K2, K1 ;

	K2 = K3 -> right ;
	K1 = K2 -> left ;

	K2 -> left = K1 -> right ;
	K1 -> right = K2 ;
	K3 -> right = K1 -> left ;
	K1 -> left = K3 ;

	return K1 ;
}

static Max (const int num, const int the_other_num)
{
	return num >= the_other_num ? num : the_other_num ;
}

/*	栈部分函数定义	*/
static void Initialize_Stack (Stack * pstack)
{
	*pstack = NULL ;
}

int Stack_Is_Empty (const Stack * pstack)
{
	return NULL == *pstack ;
}

static int Stack_Is_Full (void)
{
	Stack_Node * temp ;

	temp = (Stack_Node *) malloc (sizeof (Stack_Node)) ;
	if (NULL == temp)
		return 1 ;
	else
	{
		free (temp) ;
		return 0 ;
	}
}

static int Push (Stack * pstack, const Stack_Item stack_item)
{
	Stack_Node * new_node ;

	if (Stack_Is_Full ())
		return 0 ;
	new_node = (Stack_Node *) malloc (sizeof (Stack_Node)) ;
	if (NULL == new_node)
		return 0 ;
	new_node -> item = stack_item ;
	if (Stack_Is_Empty (pstack))
		new_node -> next = NULL ;
	else
		new_node -> next = *pstack ;
	*pstack = new_node ;

	return 1 ;
}

static int Pop (Stack * pstack)
{
	Stack_Node * temp ;

	if (Stack_Is_Empty (pstack))
		return 0 ;
	temp = *pstack ;
	*pstack = (*pstack) -> next ;
	free (temp) ;

	return 1 ;
}

static Stack_Item Top (Stack * pstack)
{
	return Stack_Is_Empty (pstack) ? NULL : (*pstack) -> item ;
}

static void Empty_The_Stack (Stack * pstack)
{
	Stack_Node * temp ;

	while (!Stack_Is_Empty (pstack))
	{
		temp = *pstack ;
		*pstack = (*pstack) -> next ;
		free (temp) ;
	}
}