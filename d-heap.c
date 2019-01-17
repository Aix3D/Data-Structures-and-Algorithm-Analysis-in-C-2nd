/*	d-heap.c -- d-堆实现文件	*/
#include <stdio.h>
#include <stdlib.h>
#include "d-heap.h"

/*	局部函数声明	*/

static int Percolate_Up (const Heap * const pheap, const Item item, const int position) ;
static int Percolate_Down (const Heap * const pheap, const Item item, const int position) ;

/*	接口函数定义	*/

int InitializeHeap (Heap * const pheap, const int capacity, const int d)
{
	if (capacity < 0)
		return 0 ;
	*pheap = (struct heap *) malloc (sizeof (struct heap) * (capacity + 1)) ;
	if (NULL == *pheap)
	{
		puts ("Out of space.[1]") ;
		return 0 ;
	}
	(*pheap) -> array = (Item *) malloc (sizeof (Item) * capacity) ;
	if (NULL == (*pheap) -> array)
	{
		puts ("Out of space.[2]") ;
		return 0 ;
	}
	(*pheap) -> capacity = capacity ;
	(*pheap) -> size = 0 ;
	(*pheap) -> d = d ;
	(*pheap) -> array[0] = MINDATA ;

	return 1 ;
}

int HeapIsEmpty (const Heap * const pheap)
{
	return 0 == (*pheap) -> size ;
}

int HeapIsFull (const Heap * const pheap)
{
	return (*pheap) -> capacity == (*pheap) -> size ;
}

int Insert (const Heap * const pheap, const Item item)
{
	int i ;

	if (HeapIsFull (pheap))
		return 0 ;
	//	变量作为参数在函数间传递时后缀自增、自减不改变变量的值
	i = Percolate_Up (pheap, item, ++(*pheap) -> size) ;
	(*pheap) -> array[i] = item ;

	return 1 ;
}

Item DeleteMin (const Heap * const pheap)
{
	Item min, item ;
	int i, position;

	if (HeapIsEmpty (pheap))
		return (*pheap) -> array[0] ;
	min = (*pheap) -> array[1] ;
	item = (*pheap) -> array[(*pheap) -> size] ;
	(*pheap) -> size-- ;
	position = 1 ;
	i = Percolate_Down (pheap, item, position) ;
	(*pheap) -> array[i] = item ;

	return min ;
}

int DecreaseKey (const Heap * const pheap, const int position, const int triangle)
{
	Item item ;
	int i ;

	if (position > 0 && position <= (*pheap) -> size && triangle > 0)
	{
		item = (*pheap) -> array[position] -= triangle ;
		i = Percolate_Up (pheap, item, position) ;
		(*pheap) -> array[i] = item ;
		return 1 ;
	}
	else
		return 0 ;
}

int IncreaseKey (const Heap * const pheap, const int position, const int triangle)
{
	Item item ;
	int i ;

	if (position > 0 && position <= (*pheap) -> size && triangle > 0)
	{
		item = (*pheap) -> array[position] += triangle ;
		i = Percolate_Down (pheap, item, position) ;
		(*pheap) -> array[i] = item ;
		return 1 ;
	}
	else
		return 0 ;
}

int BuildHeap (const Heap * const pheap, const Item * parray, const int size)
{
	Item item ;
	int i, d, ct ;

	if (!HeapIsEmpty (pheap) || size <= 0)
		return 0 ;
	for (i = 0; i < size; i++)
		(*pheap) -> array[i + 1] = parray[i] ;
	(*pheap) -> size = size ;
	for (d = (*pheap) -> d, ct = (size + d - 2) / d; ct > 0; ct--)
	{
		item = (*pheap) -> array[ct] ;
		i = Percolate_Down (pheap, item, ct) ;
		(*pheap) -> array[i] = item ;
	}

	return 1 ;
}

int Delete (const Heap * const pheap, const int position)
{
	int triangle ;

	if (position < 0 || position > (*pheap) -> size)
		return 0 ;
	triangle = (*pheap) -> array[position] - (*pheap) -> array[1] + 1 ;
	DecreaseKey (pheap, position, triangle) ;
	DeleteMin (pheap) ;

	return 1 ;
}

void Traversal (const Heap * const pheap, void (* pfun) (const Item item))
{
	int i, size ;

	for (i = 1, size = (*pheap) -> size; i <= size; i++)
		(* pfun) ((*pheap) -> array[i]) ;
}

void Release (const Heap * const pheap)
{
	free ((*pheap) -> array) ;
	free (*pheap) ;
}

/*	局部函数定义	*/

static int Percolate_Up (const Heap * const pheap, const Item item, const int position)
{
	int i, d ;

	for (i = position, d = (*pheap) -> d; (*pheap) -> array[(i + d - 2) / d] > item; i = (i + d - 2) / d)
		(*pheap) -> array[i] = (*pheap) -> array [(i + d - 2) / d] ;

	return i ;
}

static int Percolate_Down (const Heap * const pheap, const Item item, const int position)
{
	Item item_record ;
	int i, j, d, child, int_record;

	for (i = position, d = (*pheap) -> d; (i - 1) * d + 2 <= (*pheap) -> size; i = child)
	{
		child = (i - 1) * d + 2 ;
		for (j = 1, int_record = child, item_record = (*pheap) -> array[child]; int_record + j != (*pheap) -> size + 1 && j < d; j++)
		{
			if ((*pheap) -> array[int_record + j] < item_record)
			{
					item_record = (*pheap) -> array[int_record + j] ;
					child = j + int_record ;
			}
		}
		if (item > (*pheap) -> array[child])
			(*pheap) -> array[i] = (*pheap) -> array[child] ;
		else
			break ;
	}

	return i ;
}