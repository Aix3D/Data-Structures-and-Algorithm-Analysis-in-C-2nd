/*	3-20(a)-09-25-09.33.c -- 第三章第二十题	*/
#include <stdio.h>
#include <ctype.h>
#include "stack.h"
#define SIZE 20
#define NUL '\0'

int main (void) ;
/*	PRI是优先级的缩写	*/
int is_operation (const Item item) ;
int PRI (const Item item) ;

int main (void)
{
	Stack stack ;
	Item input[SIZE] ;
	int count ;

	InitializeStack (&stack) ;
	gets (input) ;
	for (count = 0; input[count] != NUL; count++)
	{
		if (isdigit (input[count]) || isalpha (input[count]))
			putchar (input[count]) ;
		else if (is_operation (input[count]))
		{
			if (StackIsEmpty (&stack))
				Push (&stack, input + count) ;
			else
			{
				if (')' == input[count])
				{
					while (Top (&stack) != '(')
					{
						putchar (Top (&stack)) ;
						Pop (&stack) ;
					}
					Pop (&stack) ;
				}
				else
				{
					while (PRI (Top (&stack)) >= PRI (input[count]))
					{
						if ('(' == Top (&stack))
						{
							if (')' == input[count])
								Pop (&stack) ;
							else
								break ;
						}
						else
						{
							putchar (Top (&stack)) ;
							Pop (&stack) ;
						}
					}
				}
				if (input[count] != ')')
					Push (&stack, input + count) ;
			}
		}
	}
	while (Top (&stack) != NUL)
	{
		putchar (Top (&stack)) ;
		Pop (&stack) ;
	}

	DeleteStack (&stack) ;
	
	return 0 ;
}

int is_operation (const Item item)
{
	switch (item)
	{
		case '+' :	return 1 ;
		case '-' :	return 1 ;
		case '*' :	return 1 ;
		case '/' :	return 1 ;
		case '(' :	return 1 ;
		case ')' :	return 1 ;
		default :	return 0 ;
	}
}

int PRI (const Item item)
{
	switch (item)
	{
		case NUL :	return 0 ;
		case '+' :	return 1 ;
		case '-' :	return 1 ;
		case '*' :	return 2 ;
		case '/' :	return 2 ;
		case '(' :	return 3 ;
		case ')' :	return 3 ;
	}
}