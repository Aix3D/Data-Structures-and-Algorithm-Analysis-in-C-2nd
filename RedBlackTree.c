/*	RedBlackTree.c -- 红黑树实现文件	*/
#include "RedBlackTree.h"

/*	全局变量引用	*/

extern Node * NullNode ;
extern Node * Current, * Sibling, * Parent, * GrParent, * GrGrParent ;

/*	局部函数声明	*/

static Node * singleRotateWithLeft (Node * const parent) ;
static Node * singleRotateWithRight (Node * const parent) ;
static Node * rotate (Node * const parent, const Item item) ;
static void handleReorient (RedBlackTree * const prbt, const Item item) ;
static void changeColor (void) ;
static void traversal (const Node * const pn, void (* pfun) (const Node * const pn)) ;
static void release (Node * const pn) ;

/*	接口函数定义	*/

/*	(*prbt) -> root -> right is the real root instead of (*prbt) -> root.	*/
BOOL Create_R (RedBlackTree * const prbt)
{
	NullNode = (Node *) malloc (sizeof (Node)) ;
	if (NULL == NullNode)
		return FALSE ;
	*prbt = (struct redBlackTree *) malloc (sizeof (struct redBlackTree)) ;
	if (NULL == *prbt)
	{
		free (NullNode) ;
		NullNode = NULL ;
		return FALSE ;
	}
	(*prbt) -> root = (Node *) malloc (sizeof (Node)) ;
	if (NULL == (*prbt) -> root)
	{
		free (NullNode) ;
		NullNode = NULL ;
		free (*prbt) ;
	}
	NullNode -> item = INFINITY ;
	NullNode -> left = NullNode -> right = NullNode ;
	NullNode -> color = Black ;

	(*prbt) -> root -> item = NEGATIVE_INFINITY ;
	(*prbt) -> root -> left = (*prbt) -> root -> right = NullNode ;
	(*prbt) -> root -> color = Black ;

	(*prbt) -> current = 0 ;

	return TRUE ;
}

BOOL IsEmpty_R (const RedBlackTree * const prbt)
{
	if (0 == (*prbt) -> current)
		return TRUE ;
	else
		return FALSE ;
}

BOOL Insert_R (RedBlackTree * const prbt, const Item item)
{
	Node * newNode ;

	GrParent = Parent = Current = (*prbt) -> root ;
	NullNode -> item = item ;

	while (Current -> item != item)
	{
		GrGrParent = GrParent ;
		GrParent = Parent ;
		Parent = Current ;
		if (item < Current -> item)
			Current = Current -> left ;
		else
			Current = Current -> right ;
		if (Red == Current -> left -> color && Red == Current -> right -> color)
			handleReorient (prbt, item) ;
	}
	if (Current != NullNode)
		return FALSE ;
	newNode = (Node *) malloc (sizeof (Node)) ;
	if (NULL == newNode)
		return FALSE ;
	newNode -> item = item ;
	newNode -> left = newNode -> right = NullNode ;

	if (item < Parent -> item)
		Parent -> left = newNode ;
	else
		Parent -> right = newNode ;
	Current = newNode ;
	handleReorient (prbt, item) ;

	(*prbt) -> current++ ;
	
	return TRUE ;
}

/*	The central idea is go to delete a red leaf.	*/
BOOL Delete_R (RedBlackTree * const prbt, const Item item)
{
	BOOL found = FALSE ;
	Node * record ;
	Item scapegoat ;
	int temp ;

	if (IsEmpty_R (prbt))
		return FALSE ;
	Current = (*prbt) -> root ;
	/*	First, look for it.	*/
	while (Current != NullNode)
	{
		if (item == Current -> item)
		{
			found = TRUE ;
			record = Current ;
			break ;
		}
		else if (item < Current -> item)
		{
			Parent = Current ;
			Current = Current -> left ;
		}
		else
		{
			Parent = Current ;
			Current = Current -> right ;
		}
	}
	/*	If not found.	*/
	if (FALSE == found)
		return FALSE ;
	if (Current -> right != NullNode)
	{
		Parent = Current ;
		Current = Parent -> right ;
		scapegoat = Current -> item ;
		/*	Without optimizing it.	*/
		while (Current -> left != NullNode)
		{
			Parent = Current ;
			Current = Current -> left ;
			scapegoat = Current -> item ;
		}
		/*	Make it be a lead.	*/
		if (Current -> right != NullNode)
		{
			temp = Current -> color ;
			Current -> color = Current -> right -> color ;
			Current -> right -> color = temp ;
			Parent -> left = singleRotateWithRight (Current) ;
		}
	}
	else if (Current -> left != NullNode)
	{
		Parent = Current ;
		Current = Parent -> left ;
		scapegoat = Current -> item ;
		while (Current -> right != NullNode)
		{
			Parent = Current ;
			Current = Current -> right ;
			scapegoat = Current -> item ;
		}
		if (Current -> left != NullNode)
		{
			temp = Current -> color ;
			Current -> color = Current -> left -> color ;
			Current -> left -> color = temp ;
			Parent -> right = singleRotateWithLeft (Current) ;
		}
	}
	/*	If Current is a leaf.	*/
	else
	{
		/*	If current is a red leaf.	*/
		if (Red == Current -> color)
		{
			if (Current == Parent -> left)
				Parent -> left = NullNode ;
			else
				Parent -> right = NullNode ;
			free (Current) ;
			(*prbt) -> current-- ;
			return TRUE ;
		}
		else
			scapegoat = Current -> item ;
	}
	/*	Next hasn't be integrated.	*/
	(*prbt) -> root -> color = Red ;
	Current = (*prbt) -> root ;
	/*	Make sure NullNode -> item hasn't appear in the tree.	*/
	NullNode -> item = (*prbt) -> root -> item ;
	/*	Core loop.	*/
	while (Current -> item != scapegoat)
	{
		if (scapegoat < Current -> item)
		{
			/*	Updata node.	*/
			GrParent = Parent ;
			Parent = Current ;
			Current = Parent -> left ;
			Sibling = Parent -> right ;
			/*	If Current has a leaf at least.	*/
			if (Red == Current -> left -> color || Red == Current -> right -> color)
			{
				if (scapegoat < Current -> item)
				{
					/*	If Current drops onto a black node.	*/
					if (Black == Current -> left -> color)
					{
						Current -> color = Red ;
						Current -> right -> color = Black ;
						Parent -> left = singleRotateWithRight (Current) ;
					}
					/*	If Current drops on to a red node, update node and continue.	*/
					else
					{
						GrParent = Parent ;
						Parent = Current ;
						Current = Parent -> left ;
						Sibling = Parent -> right ;
						continue ;
					}
				}
				else
				{
					/*	If Current drops onto a black node.	*/
					if (Black == Current -> right -> color)
					{
						Current -> color = Red ;
						Current -> left -> color = Black ;
						Parent -> left = singleRotateWithLeft (Current) ;
					}
					/*	If Current drops on to a red node, update node and continue.	*/
					else
					{
						GrParent = Parent ;
						Parent = Current ;
						Current = Parent -> right ;
						Sibling = Parent -> left ;
						continue ;
					}
				}
			}
			/*	If Current has two black children.	*/
			if (Black == Current -> left -> color && Black == Current -> right -> color)
			{
				/*	If Sibling's left child is red.	*/
				if (Red == Sibling -> left -> color)
				{
					Parent -> right = singleRotateWithLeft (Sibling) ;
					Parent -> color = Black ;
					Current -> color = Red ;
					if (Parent == GrParent -> left)
						GrParent -> left = singleRotateWithRight (Parent) ;
					else
						GrParent -> right = singleRotateWithRight (Parent) ;
				}
				/*	If Sibling's right child is red.	*/
				else if (Red == Sibling -> right -> color)
				{
					Parent -> color = Black ;
					Sibling -> right -> color = Black ;
					Sibling -> color = Red ;
					Current -> color = Red ;
					if (Parent == GrParent -> left)
						GrParent -> left = singleRotateWithRight (Parent) ;
					else
						GrParent -> right = singleRotateWithRight (Parent) ;
				}
				/*	If Sibling has two black children.	*/
				else
					changeColor () ;
			}
		}
		/*	The circumstances of whirling has a little strange.	*/
		else
		{
			GrParent = Parent ;
			Parent = Current ;
			Current = Parent -> right ;
			Sibling = Parent -> left ;
			if (Red == Current -> left -> color || Red == Current -> right -> color)
			{
				if (scapegoat < Current -> item)
				{
					if (Black == Current -> left -> color)
					{
						Current -> color = Red ;
						Current -> right -> color = Black ;
						Parent -> right = singleRotateWithRight (Current) ;
					}
					else
					{
						GrParent = Parent ;
						Parent = Current ;
						Current = Parent -> left ;
						Sibling = Parent -> right ;
						continue ;
					}
				}
				else
				{
					if (Black == Current -> right -> color)
					{
						Current -> color = Red ;
						Current -> left -> color = Black ;
						Parent -> left = singleRotateWithLeft (Current) ;
					}
					else
					{
						GrParent = Parent ;
						Parent = Current ;
						Current = Parent -> right ;
						Sibling = Parent -> left ;
						continue ;
					}
				}
			}
			if (Black == Current -> left -> color && Black == Current -> right -> color)
			{
				if (Red == Sibling -> left -> color)
				{
					Parent -> color = Black ;
					Sibling -> left -> color = Black ;
					Sibling -> color = Red ;
					Current -> color = Red ;
					if (Parent == GrParent -> left)
						GrParent -> left = singleRotateWithLeft (Parent) ;
					else
						GrParent -> right = singleRotateWithLeft (Parent) ;
				}
				else if (Red == Sibling -> right -> color)
				{
					Parent -> left = singleRotateWithRight (Sibling) ;
					Parent -> color = Black ;
					Current -> color = Red ;
					if (Parent == GrParent -> left)
						GrParent -> left = singleRotateWithLeft (Parent) ;
					else
						GrParent -> right = singleRotateWithLeft (Parent) ;
				}
				else
				{
					changeColor () ;
					if (Red == NullNode -> color)
					{
						putchar ('\a') ;
						NullNode -> color = Black ;
					}
				}
			}
		}
	}
	/*	Replace.	*/
	record -> item = scapegoat ;
	if (scapegoat == Parent -> left -> item)
		Parent -> left = NullNode ;
	else
		Parent -> right = NullNode ;
	free (Current) ;
	(*prbt) -> root -> color = Black ;
	(*prbt) -> root -> right -> color = Black ;

	(*prbt) -> current-- ;
	
	return TRUE ;
}

void Traversal_R (const RedBlackTree * const prbt, void (* pfun) (const Node * const pn))
{
	traversal ((*prbt) -> root -> right, pfun) ;
	putchar ('\n') ;
}

void Release_R (const RedBlackTree * const prbt)
{
	release ((*prbt) -> root -> right) ;
	free ((*prbt) -> root) ;
	free (*prbt) ;
	free (NullNode) ;
}

/*	局部函数定义	*/

/*	child will become the new root of the subtree.	*/
static Node * singleRotateWithLeft (Node * const parent)
{
	Node * child ;
	
	child = parent -> left ;
	parent -> left = child -> right ;
	child -> right = parent ;

	return child ;
}

static Node * singleRotateWithRight (Node * const parent)
{
	Node * child ;

	child = parent -> right ;
	parent -> right = child -> left ;
	child -> left = parent ;

	return child ;
}

static Node * rotate (Node * const parent, const Item item)
{
	if (item < parent -> item)
	{
		return parent -> left = item < parent -> left -> item ?
			singleRotateWithLeft (parent -> left)
			: singleRotateWithRight (parent -> left) ;
	}
	else
	{
		return parent -> right = item < parent -> right -> item ?
			singleRotateWithLeft (parent -> right)
			: singleRotateWithRight (parent -> right) ;
	}
}

static void handleReorient (RedBlackTree * const prbt, const Item item)
{
	Current -> color = Red ;
	Current -> left -> color = Current -> right -> color = Black ;

	if (Red == Parent -> color)
	{
		GrParent -> color = Red ;
		if ((item < GrParent -> item) != (item < Parent -> item))
			Parent = rotate (GrParent, item) ;
		Current = rotate (GrGrParent, item) ;
		Current -> color = Black ;
	}
	(*prbt) -> root -> right -> color = Black ;
}

/*	Won't change NullNode's color.	*/
static void changeColor (void)
{
	if (Parent -> left != NullNode)
		Parent -> left -> color = Red ;
	Parent -> color = Black ;
	Parent -> right -> color = Red ;
}

static void traversal (const Node * const pn, void (* pfun) (const Node * const pn))
{
	if (pn != NullNode)
	{
		traversal (pn -> left, pfun) ;
		(* pfun) (pn) ;
		traversal (pn -> right, pfun) ;
	}
}

static void release (Node * const pn)
{
	if (pn != NullNode)
	{
		release (pn -> left) ;
		release (pn -> right) ;
		free (pn) ;
	}
}