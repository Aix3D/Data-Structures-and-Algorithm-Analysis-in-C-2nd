/*	3-19-09-24-20.19.c -- �����µ�ʮ����	*/
#include <stdio.h>
#include <ctype.h>
#include "stack.h"
#define SIZE 20

int main (void) ;
int is_operator (const Item item) ;
int char_to_int (const char num) ;
char int_to_char (const int num) ;
Item calculate (Item operation, Item l_num, Item r_num) ;

int main (void)
{
	Stack stack ;
	Item arr[SIZE], reasult, l_num, r_num ;
	int i ;

	InitializeStack (&stack) ;
	gets (arr) ;
	for (i = 0; arr[i] != '\0'; i++)
	{
		/*	���������,���ջ	*/
		if (isdigit (arr[i]))
			Push (&stack, arr + i) ;
		/*	����Ƿ���	*/
		else if (is_operator (arr[i]))
		{
			r_num = Top (&stack) ;
			Pop (&stack) ;
			l_num = Top (&stack) ;
			Pop (&stack) ;
			reasult = calculate (arr[i], l_num, r_num) ;
			Push (&stack, &reasult) ;
		}
	}
	
	reasult = char_to_int (Top (&stack)) ;
	printf ("����:%d\n", reasult) ;

	return 0 ;
}

int is_operator (const char item)
{
	if ('+' == item || '-' == item || '*' == item || '/' == item)
		return 1 ;
	else
		return 0 ;
}

int char_to_int (const Item num)
{
	int reasult ;

	reasult = num - 48 ;

	return reasult ;
}

char int_to_char (const int num)
{
	char reasult ;

	reasult = num + 48 ;

	return reasult ;
}

Item calculate (Item operation, Item l_num, Item r_num)
{
	Item reasult ; 
	int reasult_i, l_num_i, r_num_i ;

	l_num_i = char_to_int (l_num) ;
	r_num_i = char_to_int (r_num) ;

	switch (operation)
	{
		case '+' :	reasult_i = l_num_i + r_num_i ;
			/*	�˴���break�ǹ̶���ʽ	*/
					break ;
		case '-' :	reasult_i = l_num_i - r_num_i ;
					break ;
		case '*' :	reasult_i = l_num_i * r_num_i ;
					break ;
		case '/' :	reasult_i = l_num_i / r_num_i ;
	}
	reasult = int_to_char (reasult_i) ;

	return reasult ;
}
	
