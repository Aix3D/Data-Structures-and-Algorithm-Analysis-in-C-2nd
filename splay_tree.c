/*  splay_tree.c -- 伸展树实现文件	*/
#include <stdio.h>
#include <stdlib.h>
#include "splay_tree.h"

/*	局部数据类型定义	*/
typedef Position Stack_Item ;
typedef struct stack_node
{
	Stack_Item item ;
	struct stack_node * next ;
} Stack_Node ;
typedef Stack_Node * Stack ;

/*	局部函数声明	*/
Position Make_Node (const Item item) ;
int Left_Is_Greater_Than_Right (const Item left, const Item right) ;
int Left_Is_Lesser_Than_Right (const Item left, const Item right) ;
void Copy_Item_To_Node (const Item * const pitem, Position * const pnew_node) ;
Position Discover_Item (const SplayTree tree, const Item item) ;
Position The_Parent_Of (const SplayTree tree, const Position target) ;
Position Single_Rotate_With_Left (Position K2) ;
Position Single_Rotate_With_Right (Position K2) ;
Position Zig_Zig_Rotate_With_Left (Position K3) ;
Position Zig_Zig_Rotate_With_Right (Position K3) ;
Position Zig_Zag_Rotate_With_Left (Position K3) ;
Position Zig_Zag_Rotate_With_Right (Position K3) ;
void Initialize_Stack (Stack * pstack) ;
int Stack_Is_Empty (const Stack * const pstack) ;
int Stack_Is_Full (void) ;
int Push (Stack * pstack, const Stack_Item item) ;
Stack_Item Top (const Stack * const pstack, const int number) ;
int Stack_Item_Count (const Stack * const pstack) ;
int Pop (Stack * pstack, const int number) ;
void Empty_The_Stack (Stack * pstack) ;
Stack Discover_Item_By_Use_Stack (const SplayTree tree, const Item item) ;

/*	接口函数定义	*/
 
void IintializeSplayTree (SplayTree * ptree)
{
	(*ptree) = NULL ;
}

int SplayTreeIsEmpty (const SplayTree tree)
{
	return NULL == tree ;
}

int SplayTreeIsFull (void)
{
	Position temp ;

	temp = (Node *) malloc (sizeof (Node)) ;
	if (NULL == temp)
		return 1 ;
	else
	{
		free (temp) ;
		return 0 ;
	}
}

SplayTree AddItem (SplayTree tree, const Item item)
{
	Position new_node, scan = tree ;

	new_node = Make_Node (item) ;
	if (NULL == new_node)
		return tree ;
	if (SplayTreeIsEmpty (tree))
		return tree = new_node ;
	while (scan != NULL)
	{
		if (Left_Is_Greater_Than_Right (item, scan -> item))
		{
			if (NULL == scan -> right)
				break ;
			else
				scan = scan -> right ;
		}
		else if (Left_Is_Lesser_Than_Right (item, scan -> item))
		{
			if (NULL == scan -> left)
				break ;
			else
				scan = scan -> left ;
		}
		/*	发生需要重复添加的情况	*/
		else
			return tree ;
	}
	if (Left_Is_Greater_Than_Right (item, scan -> item))
		scan -> right = new_node ;
	else if (Left_Is_Lesser_Than_Right (item, scan -> item))
		scan -> left = new_node ;

	return tree ;
}

SplayTree Insert (SplayTree tree, const Item item)
{
	Position new_node ;

	if (NULL == tree)
	{
		new_node = Make_Node (item) ;
		return new_node ;
	}
	if (Left_Is_Greater_Than_Right (item, tree -> item))
		tree -> right = Insert (tree -> right, item) ;
	else if (Left_Is_Lesser_Than_Right (item, tree -> item))
		tree -> left = Insert (tree -> left, item) ;
	/*	发生需要重复添加的情况	*/
	else
		return tree ;

	return tree ;
}

Position FindMax (const SplayTree tree)
{
	Position scan = tree ;

	if (NULL == scan)
		return NULL ;
	while (scan -> right != NULL)
		scan = scan -> right ;

	return scan ;
}

Position FindMin (const SplayTree tree)
{
	Position scan = tree ;

	if (NULL == scan)
		return NULL ;
	while (scan -> left != NULL)
		scan = scan -> left ;

	return scan ;
}

SplayTree Find (SplayTree tree, const Item item)
{
	Position target, parent, grandfather, greatgrandfather ;

	target = Discover_Item (tree, item) ;
	/*	如果未找到	*/
	if (NULL == target)
		return tree ;
	/*	循环条件:当前结点不是根节点	*/
	while ((parent = The_Parent_Of (tree, target)) != NULL)
	{
		/*	如果父节点是根节点	*/
		if (tree == parent)
		{
			if (Left_Is_Greater_Than_Right (item, parent -> item))
				target = Single_Rotate_With_Right (parent) ;
			else
				target = Single_Rotate_With_Left (parent) ;
		}
		else
		{
			grandfather = The_Parent_Of (tree, parent) ;
			/*	如果在父结点左侧	*/
			if (Left_Is_Lesser_Than_Right (target -> item, parent -> item))
			{
				if (Left_Is_Greater_Than_Right (parent -> item, grandfather -> item))
					target = Zig_Zag_Rotate_With_Right (grandfather) ;			/*	右之字形旋转	*/
				else
					target = Zig_Zig_Rotate_With_Left (grandfather) ;			/*	左一字形旋转	*/
			}
			/*	如果在父结点右侧	*/
			else
			{
				if (Left_Is_Greater_Than_Right (parent -> item, grandfather -> item))
					target = Zig_Zig_Rotate_With_Right (grandfather) ;			/*	右一字形旋转	*/
				else
					target = Zig_Zag_Rotate_With_Left (grandfather) ;			/*	左之字形旋转	*/
			}
			/*	如果爷结点之上才是根节点	*/
			if (grandfather != tree)
			{
				greatgrandfather = The_Parent_Of (tree, grandfather) ;
				if (Left_Is_Greater_Than_Right (grandfather -> item, greatgrandfather -> item))
					greatgrandfather -> right = target ;
				else
					greatgrandfather -> left = target ;
				/*	更新循环条件.即目标结点在树中位置	*/
				target = Discover_Item (tree, item) ;
			}
		}
	}
	
	return target ;
}

SplayTree Find_By_Use_Stack (SplayTree tree, const Item item)
{
	Stack stack ;
	Position target, parent, grandfather, greatgrandfather ;

	target = Discover_Item (tree, item) ;
	if (NULL == target)
		return tree ;
	stack = Discover_Item_By_Use_Stack (tree, item) ;
	while (!Stack_Is_Empty (&stack))
	{
		parent = Top (&stack, 1) ;
		/*	如果父结点是根节点(即栈中只有一个结点)	*/
		if (1 == Stack_Item_Count (&stack))
		{
			if (Left_Is_Greater_Than_Right (item, parent -> item))
				target = Single_Rotate_With_Right (parent) ;
			else
				target = Single_Rotate_With_Left (parent) ;
			Pop (&stack, 1) ;
		}
		else
		{
			grandfather = Top (&stack, 2) ;
			/*	如果在父结点左侧	*/
			if (Left_Is_Lesser_Than_Right (target -> item, parent -> item))
			{
				if (Left_Is_Greater_Than_Right (parent -> item, grandfather -> item))
					target = Zig_Zag_Rotate_With_Right (grandfather) ;			/*	右之字形旋转	*/
				else
					target = Zig_Zig_Rotate_With_Left (grandfather) ;			/*	左一字形旋转	*/
			}
			/*	如果在父结点右侧	*/
			else
			{
				if (Left_Is_Greater_Than_Right (parent -> item, grandfather -> item))
					target = Zig_Zig_Rotate_With_Right (grandfather) ;			/*	右一字形旋转	*/
				else
					target = Zig_Zag_Rotate_With_Left (grandfather) ;			/*	左之字形旋转	*/
			}
			if (Stack_Item_Count (&stack) > 2)
			{
				greatgrandfather = Top (&stack, 3) ;
				if (Left_Is_Greater_Than_Right (grandfather -> item, greatgrandfather -> item))
					greatgrandfather -> right = target ;
				else
					greatgrandfather -> left = target ;
			}
			Pop (&stack, 2) ;
		}
	}

	return target ;
}


SplayTree Delete (SplayTree tree, const Item item)
{
	SplayTree left_subtree, right_subtree ;
	Position new_root, temp ;

	/*	如果未找到	*/
	if (NULL == Discover_Item (tree, item))
		return tree ;
	tree = Find_By_Use_Stack (tree, item) ;
	left_subtree = tree -> left ;
	right_subtree = tree -> right ;
	temp = tree ;
	if (NULL == left_subtree && NULL == right_subtree)
		tree = NULL ;
	/*	如果左子树为空,右子树不为空	*/
	else if (NULL == tree -> left)
	{
		new_root = FindMin (right_subtree) ;
		tree = Find_By_Use_Stack (right_subtree, new_root -> item) ;
	}
	/*	否则左子树不为空,则当前正在处理理想情况.右子树是否为空无关紧要	*/
	else
	{
		new_root = FindMax (left_subtree) ;
		left_subtree = Find_By_Use_Stack (left_subtree, new_root -> item) ;
		/*	左子树中最大数据的结点被旋转到根结点的位置,它一定没有右子树	*/
		left_subtree -> right = right_subtree ;
		tree = left_subtree ;
	}
	free (temp) ;

	return tree ;
}

void InorderTraversal (const SplayTree tree, void (* pfun) (const Item item))
{
	if (tree != NULL)
	{
		InorderTraversal (tree -> left, pfun) ;
		(*pfun) (tree -> item) ;
		InorderTraversal (tree -> right, pfun) ;
	}
}

/*	局部函数定义	*/

Position Make_Node (const Item item)
{
	Position new_node ;

	new_node = (Node *) malloc (sizeof (Node)) ;
	if (NULL == new_node)
		return NULL ;
	else
	{
		Copy_Item_To_Node (&item, &new_node) ;
		new_node -> left = NULL ;
		new_node -> right = NULL ;
		return new_node ;
	}
}
int Left_Is_Greater_Than_Right (const Item left, const Item right)
{
	return left > right ;
}

int Left_Is_Lesser_Than_Right (const Item left, const Item right)
{
	return left < right ;
}

void Copy_Item_To_Node (const Item * const pitem, Position * const pnew_node)
{
	(*pnew_node) -> item = *pitem ;
}

Position Discover_Item (const SplayTree tree, const Item item)
{
	Position scan = tree ;

	while (scan != NULL)
	{
		if (Left_Is_Greater_Than_Right (item, scan -> item))
			scan = scan -> right ;
		else if (Left_Is_Lesser_Than_Right (item, scan -> item))
			scan = scan -> left ;
		/*	接下来找到了,返回该结点的指针	*/
		else
			return scan ;
	}

	return NULL ;
}

Position The_Parent_Of (const SplayTree tree, const Position target)
{
	Position parent = tree, scan = tree ;

	if (tree == target)
		return NULL ;
	while (scan != NULL)
	{
		if (Left_Is_Greater_Than_Right (target -> item, scan -> item))
		{
			parent = scan ;
			scan = scan -> right ;
		}
		else if (Left_Is_Lesser_Than_Right (target -> item, scan -> item))
		{
			parent = scan ;
			scan = scan -> left ;
		}
		else
			return parent ;
	}

	return NULL ;
}

Position Single_Rotate_With_Left (Position K2)
{
	Position K1 = K2 -> left ;

	K2 -> left = K1 -> right ;
	K1 -> right = K2 ;

	return K1 ;
}
Position Single_Rotate_With_Right (Position K2)
{
	Position K1 = K2 -> right ;

	K2 -> right = K1 -> left ;
	K1 -> left = K2 ;

	return K1 ;
}

/*	一字型旋转是从K3 - K2 - K1	*/
Position Zig_Zig_Rotate_With_Left (Position K3)
{
	Position K2 = K3 -> left ;
	Position K1 = K2 -> left ;

	K3 -> left = K2 -> right ;
	K2 -> right = K3 ;
	K2 -> left = K1 -> right ;
	K1 -> right = K2 ;

	return K1 ;
}
Position Zig_Zig_Rotate_With_Right (Position K3)
{
	Position K2 = K3 -> right ;
	Position K1 = K2 -> right ;

	K3 -> right = K2 -> left ;
	K2 -> left = K3 ;
	K2 -> right = K1 -> left ;
	K1 -> left = K2 ;

	return K1 ;
}

/*	之字形旋转是从K1 - K2 - K3	*/
Position Zig_Zag_Rotate_With_Left (Position K3)
{
	Position K2 = K3 -> left ;
	Position K1 = K2 -> right ;

	K2 -> right = K1 -> left ;
	K1 -> left = K2 ;
	K3 -> left = K1 -> right ;
	K1 -> right = K3 ;

	return K1 ;
}
Position Zig_Zag_Rotate_With_Right (Position K3)
{
	Position K2 = K3 -> right ;
	Position K1 = K2 -> left ;

	K2 -> left = K1 -> right ;
	K1 -> right = K2 ;
	K3 -> right = K1 -> left ;
	K1 -> left = K3 ;
	
	return K1 ;
}

/*	栈部分函数定义	*/
void Initialize_Stack (Stack * pstack)
{
	*pstack = NULL ;
}

int Stack_Is_Empty (const Stack * const pstack)
{
	return NULL == *pstack ;
}

int Stack_Is_Full (void)
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

int Push (Stack * pstack, const Stack_Item item)
{
	Stack_Node * new_node ;

	new_node = (Stack_Node *) malloc (sizeof (Stack_Node)) ;
	if (NULL == new_node)
		return 0 ;
	new_node -> item = item ;
	if (Stack_Is_Empty (pstack))
	{
		new_node -> next = NULL ;
		*pstack = new_node ;
	}
	else
	{
		new_node -> next = *pstack ;
		*pstack = new_node ;
	}

	return 1 ;
}

Stack_Item Top (const Stack * const pstack, const int number)
{
	Stack_Node * scan = *pstack ;
	int count = 1 ;
	
	while (count < number)
	{
		if (NULL == scan)
			return NULL ;
		scan = scan -> next ;
		/*	Don't forgrt this line!!!	*/
		count++ ;
	}

	return scan -> item ;
}

int Stack_Item_Count (const Stack * const pstack)
{
	Stack_Node * temp = *pstack ;
	int count = 0 ;
	
	while (temp != NULL)
	{
		temp = temp -> next ;
		/*	Don't forget this line!!!	*/
		count++ ;
	}

	return count ;
}

int Pop (Stack * pstack, const int number)
{
	Stack_Node * temp ;
	int count = 0 ;

	while (count < number)
	{
		if (NULL == *pstack)
			return 0 ;
		temp = *pstack ;
		*pstack = (*pstack) -> next ;
		free (temp) ;
		/*	Don't forget this line!!!	*/
		count++ ;
	}

	return 1 ;
}

void Empty_The_Stack (Stack * pstack)
{
	Stack_Node * temp ;

	while (*pstack != NULL)
	{
		temp = *pstack ;
		*pstack = (*pstack) -> next ;
		free (temp) ;
	}
}

Stack Discover_Item_By_Use_Stack (const SplayTree tree, const Item item)
{
	Stack stack ;
	Position scan = tree ;

	Initialize_Stack (&stack) ;
	while (scan != NULL)
	{
		Push (&stack, scan) ;
		if (Left_Is_Greater_Than_Right (item, scan -> item))
			scan = scan -> right ;
		else if (Left_Is_Lesser_Than_Right (item, scan -> item))
			scan = scan -> left ;
		else
		{
			/*	弹出目标找到的结点	*/
			Pop (&stack, 1) ;
			return stack ;
		}
	}
	Empty_The_Stack (&stack) ;

	return NULL ;
}