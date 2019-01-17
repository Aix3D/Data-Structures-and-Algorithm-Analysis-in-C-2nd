/*  3-15-09-20-20.13(a).c -- 第三章第十五题  */
#include <stdio.h>
#define SIZE 10
enum {add = 0, find = 1} ;

int main (void) ;
void show_menu (void) ;
void initialize_list (int * plist, const int size) ;
void print_list (const int * plist, const int size) ;
int get_value (int mode) ;
int get_size (const int * plist) ;
int add_item (int * plist, const int size, const int * pitem) ;
int find_item (int * plist, const int size, const int * pitem) ;

int main (void)
{
	int list[SIZE] ;
	int choice, temp ;

	initialize_list (list, SIZE) ;
	show_menu () ;
	while (1 == scanf ("%d", &choice))
	{
		switch (choice)
		{
			case 1:		temp = get_value (add) ;
						if (1 == add_item (list, SIZE, &temp))
							puts ("[添加完毕]") ;
						else
							puts ("[表已满无法添加]") ;
						break ;
			case 2:		temp = get_value (find) ;
						if (1 == find_item (list, get_size (list), &temp))
							puts ("[已找到]") ;
						else
							puts ("[未找到]") ;
						break ;
			case 3:		print_list (list, SIZE) ;
						break ;
			default:	puts ("[无效的选项,请重新输入]") ;	
		}
		show_menu () ;
	}
	puts ("Bye") ;
					
	return 0 ;
}

void show_menu (void)
{
	puts ("请选择操作类型:") ;
	puts ("1).添加元素") ;
	puts ("2).查找元素") ;
	puts ("3).显示当前自调整表数据") ;
	puts ("q).退出程序") ;
	printf ("( )\b\b") ;
}

void initialize_list (int * plist, const int size)
{
	int count ;

	for (count = 0; count < size; count++)
		*(plist + count) = 0 ;
}

void print_list (const int * plist, const int size)
{
	int count ;

	for (count = 0; count < size; count++)
		printf ("%-2d ", *(plist + count)) ;
	putchar ('\n') ;
}

int get_value (int mode)
{
	int reasult ;

	printf ("请输入%s元素的数值:", mode == add ? "添加" : "查找") ;
	while (scanf ("%d", &reasult) != 1)
	{
		while (getchar () != '\n')
			continue ;
		fputs ("输入有误,请重新输入:", stdout) ;
	}

	return reasult ;
}

int get_size (const int * plist)
{
	int count = 0 ;

	while (*(plist + count) != 0)
		count++ ;

	return count ;
}

int add_item (int * plist, const int size, const int * pitem)
{
	int count, record, previous, temp ;

	for (count = 0; count < size; count++)
		if (0 == *(plist + count))
			break ;
	if (size == count)
		return 0 ;
	else
	{
		record = count + 1 ;
		previous = *(plist + 0) ;
		*(plist + 0) = *pitem ;
		for (count = 1; count < record; count++)
		{
			temp = *(plist + count) ;
			*(plist + count) = previous ;
			previous = temp ;
		}
		return 1 ;
	}
}

int find_item (int * plist, const int size, const int * pitem)
{
	int count, temp, previous, index = 0 ;

	if (0 == size)
		return 0 ;
	for (count = 0; count < size; count++)
	{
		if (*pitem == *(plist + count))
		{
			index = 1 ;
			break ;
		}
	}
	if (0 == index)
		return 0 ;
	if (*pitem == *(plist + 0))
		return 1 ;
	temp = *(plist + 0) ;
	*(plist + 0) = *pitem ;
	previous = temp ;

	for (count = 1; count < size; count++)
	{
		if (*(plist + count) != *pitem)
		{
			temp = *(plist + count) ;
			*(plist + count) = previous ;
			previous = temp ;
		}
		else if (*pitem == *(plist + count))
		{
			temp = *(plist + count) ;
			*(plist + count) = previous ;
			previous = temp ;
			break ;
		}
	}

	return 1 ;
}