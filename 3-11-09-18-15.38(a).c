/*  3-11-09-18-15.38(a).c -- �����µ�ʮһ��  */
#include <stdio.h>
#include "unidirectional_linked_list.h"

int main (void) ;
void eatline (void) ;
void print_list (const Item * pitem) ;

int main (void)
{
	List list ;
	Item item ;

	InitializeList (&list) ;
	printf ("��������ֵ,nǰ����һ��:") ;
	while (1 == scanf ("%d", &item))
	{
		eatline () ;
		AddItem (&list, &item) ;
		printf ("��������һ����ֵ:") ;
	}
	eatline () ;
	Traverse (&list, print_list) ;
	printf ("������Ҫɾ������ֵ,q�˳�����:") ;
	while (1 == scanf ("%d", &item))
	{
		eatline () ;
		if(0 == RecursiveDeleteItem (&list, &item))
			printf ("ɾ��ʧ��\n") ;
		else
			printf ("ɾ���ɹ�\n") ;
		printf ("��������һ����ֵ:") ;
	}
	Traverse (&list, print_list) ;

	return 0 ;
}

void eatline (void)
{
	while (getchar () != '\n')
		continue ;
}

void print_list (const Item * pitem)
{
	printf ("%d ", *pitem) ;
}