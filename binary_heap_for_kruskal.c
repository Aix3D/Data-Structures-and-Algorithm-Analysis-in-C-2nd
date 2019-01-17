/*	binary_heap_for_kruskal.c -- 二叉堆实现文件	*/
#include <stdio.h>
#include <stdlib.h>
#include "binary_heap_for_kruskal.h"

/*	局部函数声明	*/

static int Percolate_Up (const Binary_Heap * const pbh, const int index) ;
static int Percolate_Down (const Binary_Heap * const pbh, const int index) ;

/*	接口函数定义	*/

int Initialize_B (Binary_Heap * const pbh, const int capacity)
{
	*pbh = (struct binary_heap *) malloc (sizeof (struct binary_heap)) ;
	if (NULL == *pbh)
		return 0 ;
	(*pbh) -> heap = (Edge *) malloc (sizeof (Edge) * (capacity + 1)) ;
	if (NULL == (*pbh) -> heap)
	{
		free (*pbh) ;
		return 0 ;
	}
	(*pbh) -> heap[0].weight = NEGATIVEINFINITY ;
	(*pbh) -> current = 0 ;
	(*pbh) -> capacity = capacity ;

	return 1 ;
}

int Insert_B (const Binary_Heap * const pbh, const Edge * const pd)
{
	int current ;

	if ((*pbh) -> current == (*pbh) -> capacity)
		return 0 ;
	current = ++(*pbh) -> current ;
	(*pbh) -> heap[current].v_hash_value = pd -> v_hash_value ;
	(*pbh) -> heap[current].w_hash_value = pd -> w_hash_value ;
	(*pbh) -> heap[current].weight = pd -> weight ;
	Percolate_Up (pbh, current) ;

	return 1 ;
}

int DeleteMin_B (const Binary_Heap * const pbh, Edge * const pd)
{
	if ((*pbh) -> current <= 0)
		return 0 ;
	*pd = (*pbh) -> heap[1] ;
	Percolate_Down (pbh, (*pbh) -> current) ;
	(*pbh) -> current-- ;

	return 1 ;
}

void Release_B (const Binary_Heap * const pbh)
{
	free ((*pbh) -> heap) ;
	free (*pbh) ;
}

/*	局部函数定义	*/

static int Percolate_Up (const Binary_Heap * const pbh, const int index)
{
	Edge temp = (*pbh) -> heap[index] ;
	int i ;

	if (index <= 0 || index > (*pbh) -> current)
		return 0 ;
	for (i = index; i / 2 > 0; i /= 2)
	{
		if (temp.weight < (*pbh) -> heap[i / 2].weight)
			(*pbh) -> heap[i] = (*pbh) -> heap[i / 2] ;
		else
			break ;
	}
	(*pbh) -> heap[i] = temp ;

	return 1 ;
}

static int Percolate_Down (const Binary_Heap * const pbh, const int index)
{
	int current = (*pbh) -> current ;
	Edge temp = (*pbh) -> heap[current] ;
	int i, child ;

	if (index <= 0 || index > (*pbh) -> current)
		return 0 ;
	for (i = 1; i * 2 <= current; i = child)
	{
		child = i * 2 ;
		if (child != current && (*pbh) -> heap[child].weight > (*pbh) -> heap[child + 1].weight)
			child++ ;
		if (temp.weight > (*pbh) -> heap[child].weight)
			(*pbh) -> heap[i] = (*pbh) -> heap[child] ;
		else
			break ;
	}
	(*pbh) -> heap[i] = temp ;

	return 1 ;
}