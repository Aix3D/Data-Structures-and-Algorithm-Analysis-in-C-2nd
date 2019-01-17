/*	3-18-09-24-10.41.c -- �����µ�ʮ����	*/
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
		printf ("�ļ�:%s��ʧ��\n", "try.txt") ;
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
						puts ("')'�޶�Ӧ�Ŀ��ڷ���'('") ;
					else
						Pop (&stack) ;
					continue ;
		case ']' :	if (Top (&stack) != '[')
						puts ("]�޶�Ӧ�Ŀ��ڷ���[") ;
					else
						Pop (&stack) ;
					continue ;
		case '}' :	if (Top (&stack) != '{')
						puts ("'}'�޶�Ӧ�Ŀ�������'{'") ;
					else
						Pop (&stack) ;
					continue ;
		case '*' :	if ('/' == getc (fp))
					{
						while ((item = Top (&stack)) != '*')
						{
							if (NUL == item)
							{
								printf ("%s�޶�Ӧ�Ŀ��ڷ���%s\n", "'/*'", "'*/'") ;
								break ;
							}
							else
								Pop (&stack) ;
						}
						if (0 == Pop (&stack))
							continue ;
						if (Top (&stack) != '/')
							printf ("%s�޶�Ӧ�Ŀ��ڷ���%s\n", "'/*'", "'*/'") ;
						else
							Pop (&stack) ;
					}
					else
						fseek (fp, -1L, SEEK_CUR) ;
					continue ;
		}
	}
	if (!StackIsEmpty (&stack))
		printf ("'['��'('��ƥ���շ���\n") ;
	if (fclose (fp) != 0)
		printf ("�ļ�:%s�ر�ʧ��\n", "try.txt") ;

	return 0 ;
}

void print_stack (const Item item)
{
	printf ("%c ", item) ;
}
