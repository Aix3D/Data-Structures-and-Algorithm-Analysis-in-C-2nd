/*	3-18-09-24-10.41.c -- 第三章第十八题	*/
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main (void) ;
void print_stack (const Item item) ;

int main (void)
{
	Stack stack ;
	Item item ;
	FILE * fp ;

	InitializeStack (&stack) ;
	if (NULL == (fp = fopen ("try.txt", "r")))
	{
		printf ("文件:%s打开失败\n", "try.txt") ;
		exit (EXIT_FAILURE) ;
	}
	while ((item = getc (fp)) != EOF)
	{
		switch (item)
		{
		case '(' :	Push (&stack, &item) ;
					continue ;
		case '[' :	Push (&stack, &item) ;
					continue ;
		case '{' :	Push (&stack, &item) ;
					continue ;
		case '/' :	if ('*' == getc (fp))
					{
						Push (&stack, &item) ;
						item = '*' ;
						Push (&stack, &item) ;
					}
					else
						fseek (fp, -1L, SEEK_CUR) ;
					continue ;
		case ')' :	if (Top (&stack) != '(')
						puts ("')'无对应的开口符号'('") ;
					else
						Pop (&stack) ;
					continue ;
		case ']' :	if (Top (&stack) != '[')
						puts ("]无对应的开口符号[") ;
					else
						Pop (&stack) ;
					continue ;
		case '}' :	if (Top (&stack) != '{')
						puts ("'}'无对应的开口括号'{'") ;
					else
						Pop (&stack) ;
					continue ;
		case '*' :	if ('/' == getc (fp))
					{
						while ((item = Top (&stack)) != '*')
						{
							if (NUL == item)
							{
								printf ("%s无对应的开口符号%s\n", "'/*'", "'*/'") ;
								break ;
							}
							else
								Pop (&stack) ;
						}
						if (0 == Pop (&stack))
							continue ;
						if (Top (&stack) != '/')
							printf ("%s无对应的开口符号%s\n", "'/*'", "'*/'") ;
						else
							Pop (&stack) ;
					}
					else
						fseek (fp, -1L, SEEK_CUR) ;
					continue ;
		}
	}
	if (!StackIsEmpty (&stack))
		printf ("'['或'('无匹配封闭符号\n") ;
	if (fclose (fp) != 0)
		printf ("文件:%s关闭失败\n", "try.txt") ;

	return 0 ;
}

void print_stack (const Item item)
{
	printf ("%c ", item) ;
}
