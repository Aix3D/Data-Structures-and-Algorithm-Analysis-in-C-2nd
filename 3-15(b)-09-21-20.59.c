/*  3-15(b)-09-21-20.59.c -- �����µ�ʮ����  */
#include <stdio.h>
#include "self_adjusting_list.h"
enum {add = 0, find = 1} ;

int main (void) ;
void show_menu (void) ;
char get_choice (void) ;
int get_input (int mode) ;
void print_list (const Item item) ;
void eatline (void) ;

int main (void)
{
	List list ;
	int choice, input ;

	InitializeList (&list) ;
	while (1)
	{
		show_menu () ;
		choice = get_choice () ;
		switch (choice)
		{
		case 1: input = get_input (add) ;
				if (1 == AddItem (&list, &input))
					puts ("[��ӳɹ�]") ;
				else
					puts ("[���ʧ��]") ;
				break ;
		case 2:	input = get_input (find) ;
				if (1 == FindItem (&list, &input))
					puts ("[���ҵ�]") ;
				else
					puts ("[δ�ҵ�]") ;
				break ;
		case 3:	Traverse (&list, print_list) ;
				break ;
		case 0:	DeleteAll (&list) ;
				return 0 ;
		}
	}
}

void show_menu (void)
{
	puts ("��ѡ���������:") ;
	puts ("1).�������") ;
	puts ("2).��������") ;
	puts ("3).��ʾ����") ;
	puts ("q).�˳�����") ;
	printf ("( )\b\b") ;
}

char get_choice (void)
{
	char choice ;

	choice = getchar () ;
	eatline () ;
	while (choice < '1' || choice > '3')
	{
		if ('q' == choice)
			return 0 ;
		else
		{
			puts ("�����ѡ��,������ѡ��") ;
			show_menu () ;
			choice = getchar () ;
			eatline () ;
		}
	}
	switch (choice)
	{
		case '1' :	return 1 ;
		case '2' :	return 2 ;
		case '3' :	return 3 ;
	}
}

int get_input (int mode)
{
	int input ;

	printf ("������Ҫ%s����ֵ:", add == mode ? "���" : "����") ;
	while (scanf ("%d", &input) != 1)
	{
		eatline () ;
		fputs ("�Ƿ�����ֵ,����������:", stdout) ;
	}
	eatline () ;

	return input ;
}

void print_list (const Item item)
{
	printf ("%d ", item) ;
}

void eatline (void)
{
	while (getchar () != '\n')
		continue ;
}