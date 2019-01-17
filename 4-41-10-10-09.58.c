/*  4-41-10-10-09.58.c -- 第四章第四十一题	*/
#include <stdio.h>

int similar (const Tree t1, const Tree t2) ;

int similar (const Tree t1, const Tree t2)
{
	if (NULL == t1 || NULL == t2)
		return NULL == t1 && NULL == t2 ;

	return similar (t1 -> left, t2 -> left) && similar (t1 -> right, t2 -> right) ;
}