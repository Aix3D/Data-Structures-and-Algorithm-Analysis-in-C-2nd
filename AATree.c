/*	AATree.c -- AA树实现文件	*/
#include "AATree.h"

/*	全局变量声明	*/

static Node * NullNode = NULL ;

/*	局部函数声明	*/

static Node * singleRotateWithLeft (Node * const pn) ;
static Node * singleRotateWithRight (Node * const pn) ;
static Node * skew (Node * pn) ;
static Node * split (Node * pn) ;
static void release (AATree aat) ;

/*	接口函数定义	*/

Node * Initialize_A (void)
{
	if (NULL == NullNode)
	{
		NullNode = (Node *) malloc (sizeof (Node)) ;
		if (NULL == NullNode)
			return NULL ;
		NullNode -> left = NullNode -> right = NullNode ;
		NullNode -> level = 0 ;
	}

	return NullNode ;
}

AATree Insert_A (AATree aat, const Item item)
{
	if (aat == NullNode)
	{
		/*	Create and return a one-node tree.	*/
		aat = (Node *) malloc (sizeof (Node)) ;
		if (NULL == aat)
			puts ("Out of space.") ;
		else
		{
			aat -> item = item ;
			aat -> level = 1 ;
			aat -> left = aat -> right = NullNode ;
		}
		return aat ;
	}
	else if (item < aat -> item)
		aat -> left = Insert_A (aat -> left, item) ;
	else if (item > aat -> item)
		aat -> right = Insert_A (aat -> right, item) ;
	/*	Otherwise it's a duplicate; do nothint.	*/

	aat = skew (aat) ;
	aat = split (aat) ;

	return aat ;
}

BOOL Find_A (AATree aat, const Item item)
{
	Node * scan = aat ;

	while (scan != NullNode)
	{
		if (item < scan -> item)
			scan = scan -> left ;
		else if (item > scan -> item)
			scan = scan -> right ;
		else
			return TRUE ;
	}

	return FALSE ;
}

int Count_A (AATree aat)
{
	static count = 0 ;

	if (aat != NullNode)
	{
		Count_A (aat -> left) ;
		Count_A (aat -> right) ;
		count++ ;
		return count ;
	}
	else
		return 0 ;
}

AATree Delete_A (AATree aat, const Item item)
{
	static Node * deletePtr, * lastPtr ;

	if (aat != NullNode)
	{
		/*	Step 1:	Search down tree.	*/
		/*			Set lastPtr and deletePtr.	*/
		lastPtr = aat ;
		if (item < aat -> item)
			aat -> left = Delete_A (aat -> left, item) ;
		else
		{
			deletePtr = aat ;
			aat -> right = Delete_A (aat -> right, item) ;
		}
		/*	Step 2:	If at the bottom of the tree and	*/
		/*			item is present, we delete it.	*/
		if (aat == lastPtr)
		{
			if (deletePtr != NullNode && item == deletePtr -> item)
			{
				deletePtr -> item = aat -> item ;
				deletePtr = NullNode ;
				aat = aat -> right ;
				free (lastPtr) ;
			}
		}
		/*	Step 3:	Otherwise, we are not at the bottom.	*/
		/*			Rebalance.	*/
		else
		{
			if (aat -> left -> level < aat -> level - 1 ||
				aat -> right -> level < aat -> level - 1)
			{
				if (aat -> right -> level > --aat -> level)
					aat -> right -> level = aat -> level ;
				aat = skew (aat) ;
				aat -> right = skew (aat -> right) ;
				aat -> right -> right = skew (aat -> right -> right) ;
				aat = split (aat) ;
				aat -> right = split (aat -> right) ;
			}
		}
	}

	return aat ;
}

void Release_A (AATree aat)
{
	Release_A (aat) ;
	free (NullNode) ;
}

/*	局部函数定义	*/

static Node * singleRotateWithLeft (Node * const pn)
{
	Node * left ;

	left = pn -> left ;
	pn -> left = left -> right ;
	left -> right = pn ;

	return left ;
}

static Node * singleRotateWithRight (Node * const pn)
{
	Node * right ;

	right = pn -> right ;
	pn -> right = right -> left ;
	right -> left = pn ;

	return right ;
}

static Node * skew (Node * pn)
{
	if (pn -> left -> level == pn -> level)
		pn = singleRotateWithLeft (pn) ;

	return pn ;
}

static Node * split (Node * pn)
{
	if (pn -> right -> right -> level == pn -> level)
	{
		pn = singleRotateWithRight (pn) ;
		pn -> level++ ;
	}

	return pn ;
}

static void release (AATree aat)
{
	if (aat != NullNode)
	{
		release (aat -> left) ;
		release (aat -> right) ;
		free (aat) ;
	}
}