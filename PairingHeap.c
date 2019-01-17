/*	PairingHeap.c -- 配对堆实现文件	*/
#include "PairingHeap.h"

/*	全局变量声明	*/

static Node * NullNode = NULL ;

/*	局部函数声明	*/

static Node * compareAndLink_P (Node * const first, Node * const second) ;
static Node * makeNode_P (const Item item) ;
static Node * combineSiblings_P (Node * firstSibling) ;
static void release_P (Node * const pn) ;

/*	接口函数定义	*/

BOOL Initialize_P (PairingHeap * const pph)
{
	if (NULL == NullNode)
	{
		NullNode = (Node *) malloc (sizeof (Node)) ;
		if (NULL == NullNode)
		{
			puts ("Out of space.") ;
			return FALSE ;
		}
		*pph = (struct pairingHeap *) malloc (sizeof (struct pairingHeap)) ;
		if (NULL == *pph)
		{
			puts ("Out of space.") ;
			free (NullNode) ;
			NullNode = NULL ;
			return FALSE ;
		}
		NullNode -> left = NullNode -> previous = NullNode -> nextSibling = NullNode ;
		(*pph) -> root = NullNode ;
		(*pph) -> current = 0 ;
	}
	
	return TRUE ;
}

BOOL IsEmpty_P (const PairingHeap * const pph)
{
	switch ((*pph) -> current)
	{
		case 0	:	return TRUE ;
		default	:	return FALSE ;
	}
}

BOOL Insert_P (const PairingHeap * const pph, const Item item, const Node * * const localizer)
{
	Node * newNode ;

	newNode = makeNode_P (item) ;
	if (NULL == newNode)
	{
		puts ("Out of space.") ;
		return FALSE ;
	}
	*localizer = newNode ;
	if (TRUE == IsEmpty_P (pph))
		(*pph) -> root = newNode ;
	else
		(*pph) -> root = compareAndLink_P ((*pph) -> root, newNode) ;
	(*pph) -> current++ ;

	return TRUE ;
}

BOOL DecreaseKey_P (const PairingHeap * const pph, Node * const position, const Item delta)
{
	if (delta <= 0)
		return FALSE ;
	position -> item -= delta ;
	if (position == (*pph) -> root)
		return TRUE ;
	position -> nextSibling -> previous = position -> previous ;
	if (position -> previous -> left == position)
		position -> previous -> left = position -> nextSibling ;
	else
		position -> previous -> nextSibling = position -> nextSibling ;

	position -> nextSibling = NullNode ;
	(*pph) -> root = compareAndLink_P ((*pph) -> root, position) ;

	return TRUE ;
}

BOOL DeleteMin_P (const PairingHeap * const pph, Item * const pmin)
{
	Node * newRoot ;

	if (IsEmpty_P (pph))
		return FALSE ;
	else
	{
		newRoot = NullNode ;
		*pmin = (*pph) -> root -> item ;
		if ((*pph) -> root -> left != NullNode)
			newRoot = combineSiblings_P ((*pph) -> root -> left) ;
		free ((*pph) -> root) ;
		(*pph) -> root = newRoot ;
		(*pph) -> current-- ;
		return TRUE ;
	}
}

void Release_P (PairingHeap * const pph)
{
	release_P ((*pph) -> root) ;
	free (*pph) ;
	free (NullNode) ;
	NullNode = NULL ;
}

/*	局部函数定义	*/

static Node * compareAndLink_P (Node * const first, Node * const second)
{
	if (NullNode == second)
		return first ;
	else if (first -> item <= second -> item)
	{
		/*	Attch second as the leftmost child of first.	*/
		second -> previous = first ;
		first -> nextSibling = second -> nextSibling ;
		first -> nextSibling -> previous = first ;
		second -> nextSibling = first -> left ;
		second -> nextSibling -> previous = second ;
		first -> left = second ;
		return first ;
	}
	else
	{
		/*	Attch first as the leftmost child of second.	*/
		second -> previous = first -> previous ;
		first -> previous = second ;
		first -> nextSibling = second -> left ;
		first -> nextSibling -> previous = first ;
		second -> left = first ;
		return second ;
	}
}

static Node * makeNode_P (const Item item)
{
	Node * newNode ;

	newNode = (Node *) malloc (sizeof (Node)) ;
	if (NULL == newNode)
		return NULL ;
	newNode -> item = item ;
	newNode -> left = newNode -> nextSibling = newNode -> previous = NullNode ;

	return newNode ;
}

static Node * combineSiblings_P (Node * firstSibling)
{
	static Node * treeArray[MAXSIBLINGS] ;
	int i, j, numSiblings ;

	/*	If only one tree, return it.	*/
	if (firstSibling -> nextSibling == NullNode)
		return firstSibling ;
	/*	Place each subtree in treeArray.	*/
	for (numSiblings = 0; firstSibling != NullNode; numSiblings++)
	{
		treeArray[numSiblings] = firstSibling ;
		/*	Break links.	*/
		firstSibling -> previous -> nextSibling = NullNode ;
		firstSibling = firstSibling -> nextSibling ;
	}
	treeArray[numSiblings] = NullNode ;
	/*	Combine the subtree two at a time, going left to right.	*/
	for (i = 0; i + 1 < numSiblings; i += 2)
		treeArray[i] = compareAndLink_P (treeArray[i], treeArray[i + 1]) ;
	/*	j has the result of the last compareAndLink_P ().	*/
	/*	If an odd number of trees, get the last one.	*/
	j = i - 2 ;
	if (j == numSiblings - 3)
		treeArray[j] = compareAndLink_P (treeArray[j], treeArray[j + 2]) ;
	/*	Now go right to left, merging last tree with next to last.	*/
	/*	The result becomes the new last.	*/
	while (j >= 2)
	{
		treeArray[j - 2] = compareAndLink_P (treeArray[j - 2], treeArray[j]) ;
		j -= 2 ;
	}

	return treeArray[0] ;
}

static void release_P (Node * const pn)
{
	if (pn != NullNode)
	{
		release_P (pn -> left) ;
		release_P (pn -> nextSibling) ;
		free (pn) ;
	}
}