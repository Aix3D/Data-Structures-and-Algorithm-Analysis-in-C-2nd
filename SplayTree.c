/*	SplayTree.c -- 自顶向下伸展树实现文件	*/
#include "SplayTree.h"

/*	外部变量引用	*/

extern Node * NullNode ;

/*	局部函数声明	*/

static Node * singleRotateWithLeft (Node * const position) ;
static Node * singleRotateWithRight (Node * const position) ;
static void upDataLeftSubTreeCount (Node * const headerRight) ;
static void upDataRightSubTreeCount (Node * const headerLeft) ;
static Node * splay (Node * root, const Item * const pi) ;
static void release (Node * const root) ;

/*	接口函数定义	*/

BOOL Create_S (SplayTree * const pst)
{
	NullNode = (Node *) malloc (sizeof (Node)) ;
	if (NULL == NullNode)
		return FALSE ;
	*pst = (struct splayTree *) malloc (sizeof (struct splayTree)) ;
	if (NULL == *pst)
	{
		free (NullNode) ;
		NullNode = NULL ;
		return FALSE ;
	}
	else
	{
		NullNode -> left = NullNode -> right = NullNode ;
		NullNode -> leftSubTreeCount = NullNode -> rightSubTreeCount = 0 ;
		(*pst) -> root = NullNode ;
		(*pst) -> current = 0 ;
		return TRUE ;
	}
}

BOOL IsEmpty_S (const SplayTree * const pst)
{
	if (NullNode == (*pst) -> root)
		return TRUE ;
	else
		return FALSE ;
}

BOOL Insert_S (const SplayTree * const pst, const Item * const pi)
{
	static Node * newNode = NULL ;
	Node * root ;

	/*	If it had tried to insert a item that has been inserted to the tree just now,	*/
	/*	it won't need allocate memory space.	*/
	if (NULL == newNode)
	{
		newNode = (Node *) malloc (sizeof (Node)) ;
		if (NULL == newNode)
			return FALSE ;
	}
	newNode -> item = *pi ;
	
	if (NullNode == (*pst) -> root)
	{
		newNode -> left = newNode -> right = NullNode ;
		newNode -> leftSubTreeCount = newNode -> rightSubTreeCount = 0 ;
		(*pst) -> root = newNode ;
	}
	else
	{
		(*pst) -> root = splay ((*pst) -> root, pi) ;
		root = (*pst) -> root ;
		if (*pi < root -> item)
		{
			newNode -> leftSubTreeCount = root -> leftSubTreeCount ;
			newNode -> left = root -> left ;
			root -> leftSubTreeCount = 0 ;
			root -> left = NullNode ;
			newNode -> rightSubTreeCount = root -> rightSubTreeCount + 1 ;
			newNode -> right = root ;
			(*pst) -> root = newNode ;
		}
		else if (*pi > (*pst) -> root -> item)
		{
			newNode -> rightSubTreeCount = root -> rightSubTreeCount ;
			newNode -> right = root -> right ;
			root -> rightSubTreeCount = 0 ;
			root -> right = NullNode ;
			newNode -> leftSubTreeCount = root -> leftSubTreeCount + 1 ;
			newNode -> left = root ;
			(*pst) -> root = newNode ;
		}
		else
			/*	Already in the tree.	*/
			return FALSE ;
	}

	/*	So next insert will call malloc.	*/
	newNode = NULL ;

	(*pst) -> current++ ;
	return TRUE ;
}

Node * Retrieve_S (const SplayTree * const pst)
{
	if (IsEmpty_S (pst))
		return NULL ;
	else
		return (*pst) -> root ;
}

BOOL Find_S (const SplayTree * const pst, const Item * const pi)
{
	splay ((*pst) -> root, pi) ;
	if (*pi == (*pst) -> root -> item)
		return TRUE ;
	else
		return FALSE ;
}

Node * FindKthMin_S (const SplayTree * const pst, int k)
{
	Node * scan ;

	if (k > (*pst) -> current || k <= 0)
		return NULL ;
	scan = (*pst) -> root ;

	while (1)
	{
		if (scan -> leftSubTreeCount + 1 == k)
			break ;
		else if (scan -> leftSubTreeCount >= k)
			scan = scan -> left ;
		else
		{
			k = k - scan -> leftSubTreeCount - 1 ;
			scan = scan -> right ;
		}
	}
	/*	Not must to do.	*/
	(*pst) -> root = splay ((*pst) -> root, &scan -> item) ;
	
	return scan ;
}

Node * FindKthMax_S (const SplayTree * const pst, int k)
{
	Node * scan ;

	if (k > (*pst) -> current || k <= 0)
		return NULL ;
	scan = (*pst) -> root ;

	while (1)
	{
		if (scan -> rightSubTreeCount + 1 == k)
			break ;
		else if (scan -> rightSubTreeCount >= k)
			scan = scan -> right ;
		else
		{
			k = k - scan -> rightSubTreeCount - 1 ;
			scan = scan -> left ;
		}
	}
	(*pst) -> root = splay ((*pst) -> root, &scan -> item) ;

	return scan ;
}

Node * FindMin_S (const SplayTree * const pst)
{
	Node * scan = (*pst) -> root ;
	
	while (scan -> left != NullNode)
		scan = scan -> left ;

	return scan ;
}

Node * FindMax_S (const SplayTree * const pst)
{
	Node * scan = (*pst) -> root ;

	while (scan -> right != NullNode)
		scan = scan -> right ;

	return scan ;
}

BOOL Delete_S (const SplayTree * const pst, const Item * const pi)
{
	Node * root ;

	if (IsEmpty_S (pst))
		return FALSE ;
	(*pst) -> root = splay ((*pst) -> root, pi) ;
	root = (*pst) -> root ;
	if (*pi == root -> item)
	{
		/*	Found it!	*/
		if (NullNode == root -> left)
			(*pst) -> root = root -> right ;
		else
		{
			(*pst) -> root = root -> left ;
			/*	To set (*pst) -> root -> right = NullNode.	*/
			(*pst) -> root = splay ((*pst) -> root, pi) ;
			(*pst) -> root -> right = root -> right ;
		}
		free (root) ;
		(*pst) -> current-- ;
		return TRUE ;
	}
	else
		return FALSE ;
}

void Traversal_S (const Node * const pr, void (* pfun) (const Node * const pn))
{
	if (pr != NullNode)
	{
		Traversal_S (pr -> left, pfun) ;
		(* pfun) (pr) ;
		Traversal_S (pr -> right, pfun) ;
	}
}

void Release_S (const SplayTree * const pst)
{
	release ((*pst) -> root) ;
	free (*pst) ;
	free (NullNode) ;
}

/*	局部函数定义	*/

static Node * singleRotateWithLeft (Node * const position)
{
	Node * child ;

	child = position -> left ;
	position -> leftSubTreeCount = child -> rightSubTreeCount ;
	position -> left = child -> right ;
	child -> rightSubTreeCount = position -> leftSubTreeCount + position -> rightSubTreeCount + 1 ;
	child -> right = position ;

	return child ;
}

static Node * singleRotateWithRight (Node * const position)
{
	Node * child ;
	
	child = position -> right ;
	position -> rightSubTreeCount = child -> leftSubTreeCount ;
	position -> right = child -> left ;
	child -> leftSubTreeCount = position -> leftSubTreeCount + position -> rightSubTreeCount + 1 ;
	child -> left = position ;

	return child ;
}

static void upDataLeftSubTreeCount (Node * const headerRight)
{
	if (headerRight != NullNode)
	{
		if (headerRight -> left != NullNode)
		{
			upDataLeftSubTreeCount (headerRight -> left) ;
			headerRight -> leftSubTreeCount = headerRight -> left -> leftSubTreeCount + headerRight -> left -> rightSubTreeCount + 1 ;
		}
		else
			headerRight -> leftSubTreeCount = 0 ;
	}
}

static void upDataRightSubTreeCount (Node * const headerLeft)
{
	if (headerLeft != NullNode)
	{
		if (headerLeft -> right != NullNode)
		{
			upDataRightSubTreeCount (headerLeft -> right) ;
			headerLeft -> rightSubTreeCount = headerLeft -> right -> leftSubTreeCount + headerLeft -> right -> rightSubTreeCount + 1 ;
		}
		else
			headerLeft -> rightSubTreeCount = 0 ;
	}
}

/*	NullNode -> leftSubTreeCount = NullNode -> rightSubTreeCount = 0.	*/
static Node * splay (Node * root, const Item * const pi)
{
	Node header ;
	Node * left_tree_max, * right_tree_min ;

	header.left = header.right = NullNode ;
	left_tree_max = right_tree_min = &header ;
	NullNode -> item = *pi ;

	while (*pi != root -> item)
	{
		if (*pi < root -> item)
		{
			if (*pi < root -> left -> item)
				root = singleRotateWithLeft (root) ;
			if (NullNode == root -> left)
				break ;
			/*	Link right.	*/
			right_tree_min -> left = root ;
			right_tree_min = root ;
			root = root -> left ;
		}
		else
		{
			if (*pi > root -> right -> item)
				root = singleRotateWithRight (root) ;
			if (NullNode == root -> right)
				break ;
			/*	Link left.	*/
			left_tree_max -> right = root ;
			left_tree_max = root ;
			root = root -> right ;
		}
	}
	/*	Reassemble.	*/
	left_tree_max -> right = root -> left ;
	right_tree_min -> left = root -> right ;
	root -> left = header.right ;
	root -> right = header.left ;
	upDataLeftSubTreeCount (root -> right) ;
	upDataRightSubTreeCount (root -> left) ;
	if (root -> left != NullNode)
		root -> leftSubTreeCount = root -> left -> leftSubTreeCount + root -> left -> rightSubTreeCount + 1 ;
	else
		root -> leftSubTreeCount = 0 ;
	if (root -> right != NullNode)
		root -> rightSubTreeCount = root -> right -> leftSubTreeCount + root -> right -> rightSubTreeCount + 1 ;
	else
		root -> rightSubTreeCount = 0 ;

	return root ;
}

static void release (Node * const root)
{
	if (root != NullNode)
	{
		release (root -> left) ;
		release (root -> right) ;
		free (root) ;
	}
}