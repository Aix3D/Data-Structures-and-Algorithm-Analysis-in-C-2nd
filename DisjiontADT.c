/*	DisjiontADT.c -- 不相交集合实现文件	*/
#include <stdio.h>
#include <stdlib.h>
#include "DisjiontADT.h"

/*	接口函数定义	*/

void InitializeAsHeight (DisjiontSet gather, const int size)
{
	int i ;

	gather[0] = size ;
	for (i = 1; i <= size; i++)
		gather[i] = HEIGHT ;
}

void InitializeAsSize (DisjiontSet gather, const int size)
{
	int i ;

	gather[0] = size ;
	for (i = 1; i <= size; i++)
		gather[i] = SIZE ;
}

int SetUnionAsHeight (DisjiontSet gather, SetType root1, SetType root2)
{
	if (gather[root1] > 0 || gather[root2] > 0)
		return 0 ;
	if (gather[root2] < gather[root1])
		gather[root1] = root2 ;
	else
	{
		if (gather[root1] == gather[root2])
			gather[root1]-- ;
		gather[root2] = root1 ;
	}

	return 1 ;
}

int SetUnionAsSize (DisjiontSet gather, SetType root1, SetType root2)
{
	if (gather[root1] > 0 || gather[root2] > 0)
		return 0 ;
	if (gather[root2] < gather[root1])
	{
		gather[root2] += gather[root1] ;
		gather[root1] = root2 ;
	}
	else
	{
		gather[root1] += gather[root2] ;
		gather[root2] = root1 ;
	}

	return 1 ;
}

SetType Find (DisjiontSet gather, const Item item)
{
	if (item > gather[0])
		return OOS ;
	else if (gather[item] <= 0)
		return item ;
	else
		return gather[item] = Find (gather, gather[item]) ;
}