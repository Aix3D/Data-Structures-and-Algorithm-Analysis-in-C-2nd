/*	4-42-10-10-10.22.c -- 第四章第四十二题	*/
#include <stdio.h>
#include "binary_search_tree.h"

int main (void) ;
int isomorphic (const Tree t1, const Tree t2) ;

int main (void)
{
	Tree t1, t2 ;
	Item item ;

	InitializeTree (&t1) ;
	InitializeTree (&t2) ;
	item = 20 ;
	Insert (&t1, &item) ;
	Insert (&t2, &item) ;
	item = 30 ;
	Insert (&t1, &item) ;
	Insert (&t2, &item) ;
	item = 10 ;
	Insert (&t1, &item) ;
	Insert (&t2, &item) ;
	item = 15 ;
	Insert (&t1, &item) ;
	Insert (&t2, &item) ;
	item = 25 ;
	Insert (&t1, &item) ;
	Insert (&t2, &item) ;
	printf ("%s\n", isomorphic (t1, t2) ? "是" : "不是") ;

	return 0 ;
}

int isomorphic (const Tree t1, const Tree t2)
{
	if (NULL == t1 || NULL == t2)
		return NULL == t1 && NULL == t2 ;
	else if (t1 -> item != t2 -> item)
		return 0 ;
	else
		return isomorphic (t1 -> left, t2 -> left) && isomorphic (t1 -> right, t2 -> right) ||
				isomorphic (t1 -> left, t2 -> right) && isomorphic (t1 -> right, t2 -> left) ;
}