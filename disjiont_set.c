/*	disjiont_set.c -- 不相交集合实现文件	*/
#include <stdio.h>
#include <stdlib.h>
#include "disjiont_set.h"

/*	接口函数定义	*/

int Initialize_D (Disjiont d, const int capacity)
{
	int i ;

	if (capacity <= 0)
		return 0 ;
	d[0] = capacity ;
	for (i = 1 ; i <= capacity; i++)
		d[i] = HEIGHT ;
	
	return 1 ;
}

int Find_D (Disjiont d, const SetItem si)
{
	if (si > d[0])
		return OOS ;
	else if (d[si] <= 0)
		return si ;
	else
		return d[si] = Find_D (d, d[si]) ;
}

int Union_D (Disjiont d, const SetType st1, const SetType st2)
{
	if (st1 > d[0] || st2 > d[0])
		return 0 ;
	else if (d[st1] > 0 || d[st2] > 0)
		return 0 ;
	else if (d[st1] < d[st2])
	{
		d[st2] = st1 ;
		return 1 ;
	}
	else if (d[st1] > d[st2])
	{
		d[st1] = st2 ;
		return 1 ;
	}
	else /* if (d[st1] == d[st2])	*/
	{
		d[st1]-- ;
		d[st2] = st1 ;
		return 1 ;
	}
}