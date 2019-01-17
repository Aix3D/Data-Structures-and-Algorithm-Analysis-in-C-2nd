/*  3-20(b)-09-25-11.49.c -- 第三章第二十题  */
#include <stdio.h>
#include "stack.h"
#define SIZE 20
#define NUL '\0'

int main (void) ;
Item char_to_item (const char input) ;
Item fake_pow (const Item base, const Item power) ;

int main (void)
{
	Stack stack ;
	Item temp, base, power ;
	char input[SIZE] ;
	int count ;

	InitializeStack (&stack) ;
	gets (input) ;
	for (count = 0; input[count] != NUL; count++)
	{
		temp = char_to_item (input[count]) ;
		Push (&stack, &temp) ;
	}
	while (StackItemCount (&stack) != 1)
	{
		power = Top (&stack) ;
		Pop (&stack) ;
		base = Top (&stack) ;
		Pop (&stack) ;
		temp = fake_pow (base, power) ;
		Push (&stack, &temp) ;
	}
	printf ("结果是:%d\n", Top (&stack)) ;
	DeleteStack (&stack) ;

	return 0 ;
}

Item char_to_item (const char input)
{
	Item reasult ;

	reasult = input - 48 ;

	return reasult ;
}

Item fake_pow (const Item base, const Item power)
{
	Item reasult = base ;
	int count ;

	if (0 == power)
		return 1 ;
	if (0 == base)
		return 0 ;
	for (count = 1; count < power; count++)
		reasult *= base ;

	return reasult ;
}
