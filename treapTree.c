/*	treap.c -- treap树实现文件	*/
#include "treapTree.h"

/*	全局变量声明定义	*/

static Node * NullNode = NULL ;

/*	局部函数声明	*/

static Node * singleRotateWithLeft (Node * const pn) ;
static Node * singleRotateWithRight (Node * const pn) ;
static void release (const TreapTree tt) ;

/*	接口函数定义	*/

TreapTree Initialize_T (void)
{
	if (NULL == NullNode)
	{
		NullNode = (Node *) malloc (sizeof (Node)) ;
		if (NULL == NullNode)
			return NULL ;
		NullNode -> left = NullNode -> right = NullNode ;
		NullNode -> priority = INFINITY ;
		srand ((unsigned int) time (NULL)) ;
	}

	return NullNode ;
}

TreapTree Insert_T (TreapTree tt, const Item item)
{
	if (tt == NullNode)
	{
		/*	Create and return a one-node tree.	*/
		tt = (Node *) malloc (sizeof (Node)) ;
		if (NULL == tt)
			puts ("Out of space.") ;
		else
		{
			tt -> item = item ;
			tt -> priority = rand () ;
			tt -> left = tt -> right = NullNode ;
		}
	}
	else if (item < tt -> item)
	{
		tt -> left = Insert_T (tt -> left, item) ;
		if (tt -> left -> priority < tt -> priority)
			tt = singleRotateWithLeft (tt) ;
	}
	else if (item > tt -> item)
	{
		tt -> right = Insert_T (tt -> right, item) ;
		if (tt -> right -> priority < tt -> priority)
			tt = singleRotateWithRight (tt) ;
	}
	/*	Otherwise it's a duplicate, do nothing.	*/

	return tt ;
}

TreapTree Delete_T (TreapTree tt, const Item item)
{
	if (tt != NullNode)
	{
		if (item < tt -> item)
			tt -> left = Delete_T (tt -> left, item) ;
		else if (item > tt -> item)
			tt -> right = Delete_T (tt -> right, item) ;
		else
		{
			/*	Match found.	*/
			if (tt -> left -> priority < tt -> right -> priority)
				tt = singleRotateWithLeft (tt) ;
			else
				tt = singleRotateWithRight (tt) ;
			if (tt != NullNode)
				/*	Continue on down.	*/
				tt = Delete_T (tt, item) ;
			else
			{
				/*	At a leaf.	*/
				free (tt -> left) ;
				tt -> left = NullNode ;
			}
		}
	}

	return tt ;
}

void Release_T (const TreapTree tt)
{
	release (tt) ;
	free (NullNode) ;
	/*	For next Initialize_T ().	*/
	NullNode = NULL ;
}

/*	局部函数定义	*/

static Node * singleRotateWithLeft (Node * const pn)
{
	Node * child ;

	child = pn -> left ;
	pn -> left = child -> right ;
	child -> right = pn ;

	return child ;
}

static Node * singleRotateWithRight (Node * const pn)
{
	Node * child ;

	child = pn -> right ;
	pn -> right = child -> left ;
	child -> left = pn ;

	return child ;
}

static void release (const TreapTree tt)
{
	if (tt != NullNode)
	{
		release (tt -> left) ;
		release (tt -> right) ;
		free (tt) ;
	}
}