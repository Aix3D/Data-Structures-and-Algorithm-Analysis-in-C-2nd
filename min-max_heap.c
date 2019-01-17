/*	min-max_heap.c -- 最小-最大堆实现文件	*/
#include <stdio.h>
#include <stdlib.h>
#include "min-max_heap.h"

/*	局部函数声明	*/

static int Percolate_Up (const Heap * const pheap, const Item item, const int position) ;
/*	下滤函数有问题, 先不研究了	*/
static int Percolate_Down (const Heap * const pheap, const Item item, const int position) ;
static int Pow_Base_On_Two (const int power) ;

/*	接口函数定义	*/

int InitializeHeap (Heap * const pheap, const int capacity)
{
	if (capacity <= 0)
		return 0 ;
	*pheap = (struct heap *) malloc (sizeof (struct heap)) ;
	if (NULL == *pheap)
		return 0 ;
	(*pheap) -> array = (Item *) malloc (sizeof (Item) * (capacity + 1)) ;
	if (NULL == (*pheap) -> array)
	{
		free (*pheap) ;
		return 0 ;
	}
	(*pheap) -> array[0].element = DATA ;
	(*pheap) -> capacity = capacity ;
	(*pheap) -> size = 0 ;
	(*pheap) -> layer = 0 ;

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

int Insert (const Heap * const pheap, const int element)
{
	int i ;

	if (HeapIsFull (pheap))
		return 0 ;
	if (HeapIsEmpty (pheap))
	{
		(*pheap) -> array[++(*pheap) -> size].index = EVEN ;
		(*pheap) -> array[(*pheap) -> size].element = element ;
		(*pheap) -> layer++ ;
		return 1 ;
	}
	else if (1 == (*pheap) -> size)
	{
		(*pheap) -> array[++(*pheap) -> size].index = ODD ;
		(*pheap) -> array[(*pheap) -> size].element = element ;
		(*pheap) -> layer++ ;
		return 1 ;
	}
	else if (EVEN == (*pheap) -> array[(*pheap) -> size / 2].index)
	{
		if ((*pheap) -> size == Pow_Base_On_Two ((*pheap) -> layer) - 1)
		{
			if (1 == (*pheap) -> size)
				(*pheap) -> array[++(*pheap) -> size].index = ODD ;
			else
				(*pheap) -> array[++(*pheap) -> size].index = EVEN ;
			(*pheap) -> layer++ ;
		}
		else
			(*pheap) -> array[++(*pheap) -> size].index = ODD ;
	}
	else if (ODD == (*pheap) -> array[(*pheap) -> size / 2].index)
	{
		if ((*pheap) -> size == Pow_Base_On_Two ((*pheap) -> layer) - 1)
		{
			(*pheap) -> array[++(*pheap) -> size].index = ODD ;
			(*pheap) -> layer++ ;
		}
		else
			(*pheap) -> array[++(*pheap) -> size].index = EVEN ;
	}
	(*pheap) -> array[(*pheap) -> size].element = element ;
	i = Percolate_Up (pheap, (*pheap) -> array[(*pheap) -> size], (*pheap) -> size) ;
	(*pheap) -> array[i].element = element ;

	return 1 ;
}

Item DeleteMin (const Heap * const pheap)
{
	Item min, item ;
	int i, position = 1 ;

	if (HeapIsEmpty (pheap))
		return (*pheap) -> array[0] ;
	min = (*pheap) -> array[1] ;
	if ((*pheap) -> size - 1 == Pow_Base_On_Two ((*pheap) -> layer - 1))
		(*pheap) -> layer-- ;
	item = (*pheap) -> array[(*pheap) -> size--] ;
	i = Percolate_Down (pheap, item, position) ;
	(*pheap) -> array[i] = item ;

	return min ;
}

void Traversal (const Heap * const pheap, void (* pfun) (const Item item))
{
	int ct, size ;

	for (ct = 1, size = (*pheap) -> size; ct <= size; ct++)
		(* pfun) ((*pheap) -> array[ct]) ;
}

/*	局部函数定义	*/

static int Percolate_Up (const Heap * const pheap, const Item item, const int position)
{
	int i ;

	for (i = position; i / 2 > 0; i /= 2)
	{
		if (ODD == (*pheap) -> array[i].index)
		{
			//	存储在奇数层上的关键字应大于其父亲, 小于其祖父
			if (item.element < (*pheap) -> array[i / 2].element)
				(*pheap) -> array[i].element = (*pheap) -> array[i / 2].element ;
			else if (i / 4 != 0 && item.element > (*pheap) -> array[i / 4].element)
				(*pheap) -> array[i].element = (*pheap) -> array[i / 2].element ;
			else
				break ;
		}
		else
		{
			//	存储在偶数层上的关键字应小于其父亲, 大于其祖父
			if (item.element > (*pheap) -> array[i / 2].element)
				(*pheap) -> array[i].element = (*pheap) -> array[i / 2].element ;
			else if (i / 4 != 0 && item.element < (*pheap) -> array[i / 4].element)
				(*pheap) -> array[i].element = (*pheap) -> array[i / 2].element ;
			else
				break ;
		}
	}

	return i ;
}

static int Percolate_Down (const Heap * const pheap, const Item item, const int position)
{
	int i, child, grandson ;

	for (i = position; i * 2 <= (*pheap) -> size; i = child)
	{
		child = i * 2 ;
		if (ODD == (*pheap) -> array[i].index)
		{
			//	存储在奇数层上的关键字应大于其父亲, 小于其祖父
			if (child != (*pheap) -> size && (*pheap) -> array[child + 1].element < (*pheap) -> array[child].element)
				child++ ;
			if ((*pheap) -> array[child].element < item.element)
				(*pheap) -> array[i].element = (*pheap) -> array[child].element ;
			else if (child * 2 <= (*pheap) -> size && (*pheap) -> array[child * 2].element > item.element)
				(*pheap) -> array[i].element = (*pheap) -> array[child].element ;
			else
				break ;
		}
		else
		{
			//	存储在偶数层上的关键字应小于其父亲, 大于其祖父
			if (child != (*pheap) -> size && (*pheap) -> array[child + 1].element > (*pheap) -> array[child].element)
				child++ ;
			if ((*pheap) -> array[child].element > item.element)
				(*pheap) -> array[i].element = (*pheap) -> array[child].element ;
			else if (child * 2 <= (*pheap) -> size && (*pheap) -> array[child * 2].element < item.element)
				(*pheap) -> array[i].element = (*pheap) -> array[child].element ;
			else
				break ;
		}
	}

	return 1 ;
}

static int Pow_Base_On_Two (const int power)
{
	int i, value ;

	for (i = 0, value = 1; i < power; i++)
		value *= 2 ;

	return value ;
}