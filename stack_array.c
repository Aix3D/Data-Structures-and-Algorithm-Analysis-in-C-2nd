/*  stack_array.c -- 栈数组实现文件	*/
#include <stdio.h>
#include <stdlib.h>
#include "stack_array.h"

/*	接口函数定义	*/

Stack CreateStack (const int maxelements)
{
	Stack stack ;

	if (maxelements < MINSTACKSIZE)
	{
		puts ("指定栈容量小于栈的最小容量") ;
		return NULL ;
	}
	stack = (StackRecord *) malloc (sizeof (StackRecord)) ;
	if (NULL == stack)
	{
		puts ("创建栈失败[1]") ;
		return NULL ;
	}
	stack -> array = (Item *) malloc (sizeof (Item) * maxelements) ;
	if (NULL == stack -> array)
	{
		puts ("创建栈失败[2]") ;
		return NULL ;
	}
	stack -> capacity = maxelements ;
	stack -> topofstack = EMPTYTOPOFSTACK ;

	return stack ;
}

int StackIsEmpty (const Stack stack)
{
	return EMPTYTOPOFSTACK == stack -> topofstack ? 1 : 0 ;
}

int StackIsFull (const Stack stack)
{
	return stack -> capacity - 1 == stack -> topofstack ? 1 : 0 ;
}

int Push (const Item item, Stack stack)
{
	if (StackIsFull (stack))
		return 0 ;
	else
	{
		stack -> array[++stack -> topofstack] = item ;	/*	前缀++优先级低于->优先级	*/
		return 1 ;
	}
}

Item Top (const Stack stack)
{
	return stack -> array[stack -> topofstack] ;
}

int Pop (Stack stack)
{
	if (StackIsEmpty (stack))
		return 0 ;
	else
	{
		stack -> topofstack-- ;							/*	后缀--优先级同->优先级,从左到右结合性	*/
		return 1 ;
	}
}

void Traverse (const Stack stack, void (* pfun)(const Item item))
{
	int count ;

	for (count = stack -> topofstack; count >= 0; count--)
		(* pfun) (stack -> array[count]) ;
	putchar ('\n') ;
}

void DisposeStack (Stack stack)
{
	if (stack != NULL)
	{
		free (stack -> array) ;
		free (stack) ;
	}
}