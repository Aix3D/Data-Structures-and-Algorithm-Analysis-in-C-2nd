/*  3-13-09-19-13.47.c -- �����µ�ʮ����  */
#include <stdio.h>
#include "unidirectional_linked_list.h"
#define ISIZE 20
#define LSIZE 1000

int main (void) ;
List radix_sort (int * arr_student) ;
void print_list (const Item * pitem) ;
int power (const int bits) ;
int resolve_figure (const int num, const int bits) ;

int main (void)
{
	List list ;
	int arr_student[ISIZE] = {0, 1, 841, 1, 0, 487, 48748765, 9999, 77777777, 48748769, 9, 99999, 8887454, 4444444, 88887573, 1666666, 71111111, 9, 15, 55555} ;
	InitializeList (&list) ;
	list = radix_sort (arr_student) ;
	Traverse (&list, print_list) ;

	return 0 ;
}

void print_list (const Item * pitem)
{
	printf ("%d ", *pitem) ;
}

List radix_sort (int * arr_student)
{
	/*	����3����������	*/
	List layer_1[LSIZE], layer_2[LSIZE], layer_3[LSIZE], reasult ;
	int i, radix ;

	/*	��ʼ����һ��Ͱ����������	*/
	for (i = 0; i < LSIZE; i++)
		InitializeList (&layer_1[i]) ;
	/*	�������е����ݷ����һ���Ͱ	*/
	for (i = 0; i < ISIZE; i++)
	{
		radix = resolve_figure (arr_student[i], 3) ;
		AddItem (&layer_1[radix], &arr_student[i]) ;
	}
	/*	��ʼ���ڶ���Ͱ����������	*/
	for (i = 0; i < LSIZE; i++)
		InitializeList (&layer_2[i]) ;
	/*	�ѵ�һ��Ͱ�����ݷ���ڶ����Ͱ	*/
	for (i = 0; i < LSIZE; i++)
	{
		/*	���Ͱ��������	*/
		if (layer_1[i] != NULL)
			while (layer_1[i] != NULL)
			{
				/*	ȡ��������4,5,6λ����ֵ	*/
				radix = (resolve_figure (layer_1[i] -> item , 6) - resolve_figure (layer_1[i] -> item, 3)) / power (3) ;
				AddItem (&layer_2[radix], &layer_1[i] -> item) ;
				layer_1[i] = layer_1[i] -> next ;
			}
	}
	/*	��յ�һ���Ͱ	*/
	for (i = 0; i < LSIZE; i++)
		DeleteList (&layer_1[i]) ;
	/*	��ʼ��������Ͱ	*/
	for (i = 0; i < LSIZE; i++)
		InitializeList (&layer_3[i]) ;
	/*	�ѵڶ���Ͱ�����ݷ��������Ͱ	*/
	for (i = 0; i < LSIZE; i++)
		if (layer_2[i] != NULL)
			while (layer_2[i] != NULL)
			{
				/*	ȡ��������7,8,9λ����ֵ	*/
				radix = (layer_2[i] -> item - resolve_figure (layer_2[i] -> item, 6)) / power (6) ;
				AddItem (&layer_3[radix], &layer_2[i] -> item) ;
				layer_2[i] = layer_2[i] -> next ;
			}
	/*	��յڶ����Ͱ	*/
	for (i = 0; i < LSIZE; i++)
		DeleteList (&layer_2[i]) ;
	InitializeList (&reasult) ;
	/*	ȡ��������Ͱ�е����ݵ�Ҫ���ص�������	*/
	for (i = 0; i < LSIZE; i++)
		if (layer_3[i] != NULL)
			while (layer_3[i] != NULL)
			{
				AddItem (&reasult, &layer_3[i] -> item) ;
				layer_3[i] = layer_3[i] -> next ;
			}
	/*	��յ������Ͱ	*/
	for (i = 0; i < LSIZE; i++)
		DeleteList (&layer_3[i]) ;

	return reasult ;
}

int resolve_figure (const int num, const int bits)
{
	int reasult, radix = 1, i;

	for (i = 0; i < bits; i++)
		radix *= 10 ;
	reasult = num % radix ;

	return reasult ;
}

int power (const int bits)
{
	int reasult = 1, i = 0 ;

	while (i < bits)
	{
		reasult *= 10 ;
		i++ ;
	}

	return reasult ;
}