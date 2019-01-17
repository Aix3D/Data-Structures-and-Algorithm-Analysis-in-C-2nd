/*	binary_heap.c -- 二叉堆实现文件	*/
#include <stdio.h>
#include <stdlib.h>
#include "binary_heap.h"

/*	局部函数声明	*/

static int Percolate_Up (const Binary_Heap * const pbh, const int index) ;
static int Percolate_Down (const Binary_Heap * const pbh, const int index) ;

/*	接口函数定义	*/

int Initialize_B (Binary_Heap * const pbh, const int capacity)
{
	if (capacity < 0)
		return 0 ;
	*pbh = (struct binary_heap *) malloc (sizeof (struct binary_heap)) ;
	if (NULL == *pbh)
		return 0 ;
	(*pbh) -> heap = (Heap_Item *) malloc (sizeof (Heap_Item) * (capacity + 1)) ;
	if (NULL == (*pbh) -> heap)
	{
		free (*pbh) ;
		return 0 ;
	}
	(*pbh) -> heap[0] = (Vertex *) malloc (sizeof (Vertex)) ;
	if (NULL == (*pbh) -> heap[0])
	{
		free ((*pbh) -> heap) ;
		free (*pbh) ;
		return 0 ;
	}
	(*pbh) -> heap[0] -> dist = NEGATIVEINFINITY ;
	(*pbh) -> capacity = capacity ;
	(*pbh) -> current = 0 ;

	return 1 ;
}

int Insert_B (const Binary_Heap * const pbh, const Heap_Item hi)
{
	if ((*pbh) -> current == (*pbh) -> capacity)
		return 0 ;
	(*pbh) -> heap[++(*pbh) -> current] = hi ;
	Percolate_Up (pbh, (*pbh) -> current) ;

	return 1 ;
}

Heap_Item DeleteMin_B (const Binary_Heap * const pbh)
{
	Heap_Item hi ;

	if (0 == (*pbh) -> current)
		return (*pbh) -> heap[0] ;
	hi = (*pbh) -> heap[1] ;
	Percolate_Down (pbh, 1) ;
	(*pbh) -> current-- ;

	return hi ;
}

int IncreaseKey_B (const Binary_Heap * const pbh, const int index, const int triangle)
{
	if (0 == (*pbh) -> current || index <= 0 || index > (*pbh) -> current || triangle < 0)
		return 0 ;
	(*pbh) -> heap[index] -> dist += triangle ;
	Percolate_Down (pbh, index) ;

	return 1 ;
}

int DecreaseKey_B (const Binary_Heap * const pbh, const int index, const int triangle)
{
	if (0 == (*pbh) -> current || index <= 0 || index > (*pbh) -> current || triangle < 0)
		return 0 ;
	(*pbh) -> heap[index] -> dist -= triangle ;
	Percolate_Up (pbh, index) ;

	return 1 ;
}

void Release_B (const Binary_Heap * const pbh)
{
	free ((*pbh) -> heap[0]) ;
	free ((*pbh) -> heap) ;
	free (*pbh) ;
}

/*	局部函数定义	*/

static int Percolate_Up (const Binary_Heap * const pbh, const int index)
{
	int dist, i ;

	if (index <= 0 || index > (*pbh) -> current)
		return 0 ;
	dist = (*pbh) -> heap[index] -> dist ;
	for (i = index; i / 2 > 0; i /= 2)
	{
		if (dist < (*pbh) -> heap[i / 2] -> dist)
			(*pbh) -> heap[i / 2] = (*pbh) -> heap[i] ;
		else
			break ;
	}
	(*pbh) -> heap[i] = (*pbh) -> heap[index] ;

	return 1 ;
}

static int Percolate_Down (const Binary_Heap * const pbh, const int index)
{
	int dist, i, child, current ;

	if (index <= 0 || index > (*pbh) -> current)
		return 0 ;
	current = (*pbh) -> current ;
	dist = (*pbh) -> heap[current] -> dist ;
	for (i = index; i * 2 <= current ; i = child)
	{
		child = i * 2 ;
		if (child != current && (*pbh) -> heap[child] -> dist > (*pbh) -> heap[child + 1] -> dist)
			child++ ;
		if (dist > (*pbh) -> heap[child] -> dist)
			(*pbh) -> heap[i] = (*pbh) -> heap[child] ;
		else
			break ;
	}
	(*pbh) -> heap[i] = (*pbh) -> heap[current] ;

	return 1 ;
}