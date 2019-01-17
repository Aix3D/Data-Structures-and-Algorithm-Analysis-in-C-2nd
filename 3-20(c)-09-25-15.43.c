/*  3-20(c)-09-25-15.43.c -- �����µڶ�ʮ��  */
/*	�о�����д���൱���ҵĴ���,˼·�о���������.�ٴο�����λ��Ѿ����Ż�������,����ô����?	*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "stack_c.h"

int main (void) ;
int is_operation (const Item item) ;
void initielize_arr (Item * pitem, int size) ;
void char_to_only_two_char_str (Item * pitem, Item input) ;			/*	��pitemָ����ַ�������Ϊ��Ԫ����input�ַ�,��Ԫ����NUL���ַ���	*/
void add_parenthesis (Item * pitem) ;								/*	��һ���ַ�����β���������������	*/
void add_char_to_str (Item * pitem, const Item sign, int size) ;	/*	��һ��������ӵ�pitemָ����ַ���β��	*/
void print_item (const Item * pitem) ;


int main (void)
{
	Stack stack ;
	Item input[SIZE], temp[2], temp_1[SIZE], temp_2[SIZE] ;
	int count ;

	InitializeStack (&stack) ;
	gets (input) ;
	for (count = 0; input[count] != NUL; count++)
	{
		/*	�������ĸ	*/
		if (isalpha (input[count]))
		{
			char_to_only_two_char_str (temp, input[count]) ;
			Push (&stack, temp) ;
		}
		else if (is_operation (input[count]))
		{
			/*	��ʼ��������ʱ����	*/
			initielize_arr (temp_1, SIZE) ;
			initielize_arr (temp_2, SIZE) ;
			strcpy (temp_1, Top (&stack)) ;
			Pop (&stack) ;
			strcpy (temp_2, Top (&stack)) ;
			Pop (&stack) ;
			/*	�������'*'����'/'	*/
			if (2 == is_operation (input[count]))
				/*	����ַ�������!=1,���ж���ַ��������	*/
				if (strlen (temp_2) != 1)
					add_parenthesis (temp_2) ;
			add_char_to_str (temp_2, input[count], SIZE) ;
			strcat (temp_2, temp_1) ;
			Push (&stack, temp_2) ;
		}
	}
	Traverse (&stack, print_item) ;

	return 0 ;
}

int is_operation (const Item item)
{
	switch (item)
	{
		case '+' :	return 1 ;
		case '-' :	return 1 ;
		case '*' :	return 2 ;
		case '/' :	return 2 ;
		default :	return 0 ;
	}
}

void initielize_arr (Item * pitem, int size)
{
	int count ;

	for (count = 0; count < size; count++)
		*(pitem + count) = NUL ;
}

void char_to_only_two_char_str (Item * pitem, Item input)
{
	pitem[0] = input ;
	pitem[1] = NUL ;
}

void add_parenthesis (Item * pitem)
{
	Item temp_left[SIZE], temp_right[2] ;

	temp_left[0] = '(' ;
	temp_left[1] = NUL ;
	temp_right[0] = ')' ;
	temp_right[1] = NUL ;

	strcat (temp_left, pitem) ;
	strcat (temp_left, temp_right) ;
	strcpy (pitem, temp_left) ;
}

void add_char_to_str (Item * pitem, const Item sign, int size)
{
	int count ;

	/*	�������Ĳ������������ַ���.������ʽ��������һ��������NUL���������Խ��	*/
	for (count = 0; count < size; count++)
		if (NUL == pitem[count])
			break ;
	/*	NUL��Ϊsign	*/
	pitem[count++] = sign ;
	pitem[count] = NUL ;
}

void print_item (const Item * pitem)
{
	fputs (pitem, stdout) ;
}