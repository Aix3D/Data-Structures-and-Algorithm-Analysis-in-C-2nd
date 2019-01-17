/*	9-18(b)-12-19-00.49.c -- 第九章第十八题	*/
#include <stdio.h>
#include <stdlib.h>
#include "binary_heap_for_kruskal.h"
#include "disjiont_set.h"

#define SIZE (10)

int main (void) ;
void kruskal (const Adjacenty_List * const padj, const Hash_Table * const pht, const int start, char (* const result)[2], int * const weight) ;
void print_result (const char (* const result)[2], const int * const weight, const int size) ;

int main (void)
{
	Adjacenty_List adj ;
	Hash_Table ht ;
	int capacity = 10 ;
	char result[SIZE][2] ;
	int weight[SIZE], size = SIZE ;

	Initialize_H (&ht, capacity * 2) ;
	Initialize_A (&adj, capacity) ;

	/*	Initialize the adjacenty list	*/
	InitializeALine_A (&adj, &ht, 0, 'a', 0, 6, 'd', 4, 'e', 4, 'b', 3) ;
	InitializeALine_A (&adj, &ht, 1, 'b', 0, 8, 'a', 3, 'e', 2, 'f', 3, 'c', 10) ;
	InitializeALine_A (&adj, &ht, 2, 'c', 0, 6, 'b', 10, 'f', 6, 'g', 1) ;
	InitializeALine_A (&adj, &ht, 3, 'd', 0, 6, 'a', 4, 'e', 5, 'h', 6) ;
	InitializeALine_A (&adj, &ht, 4, 'e', 0, 12, 'd', 5, 'a', 4, 'b', 2, 'f', 11, 'i', 1, 'h', 2) ;
	InitializeALine_A (&adj, &ht, 5, 'f', 0, 12, 'e', 11, 'b', 3, 'c', 6, 'g', 2, 'j', 11, 'i', 3) ;
	InitializeALine_A (&adj, &ht, 6, 'g', 0, 6, 'f', 2, 'c', 1, 'j', 8) ;
	InitializeALine_A (&adj, &ht, 7, 'h', 0, 6, 'd', 6, 'e', 2, 'i', 4) ;
	InitializeALine_A (&adj, &ht, 8, 'i', 0, 8, 'h', 4, 'e', 1, 'f', 3, 'j', 7) ;
	InitializeALine_A (&adj, &ht, 9, 'j', 0, 6, 'i', 7, 'f', 11, 'g', 8) ;
	
	kruskal (&adj, &ht, 0, result, weight) ;
	print_result (result, weight, size - 1) ;

	Release_H (&ht) ;
	Release_A (&adj) ;

	return 0 ;
}

void kruskal (const Adjacenty_List * const padj, const Hash_Table * const pht, const int start, char (* const result)[2], int * const weight)
{
	Adjoin_To_Vertex * scan ;
	Disjiont d ;
	SetType vset, wset ;
	Binary_Heap bh ;
	Edge edge ;
	int capacity = (*padj) -> capacity, vertex_sub = capacity, i ;

	d = (int *) malloc (sizeof (int) * ((*pht) -> capacity + 1)) ;
	if (NULL == d)
		return ;
	/*	Make sure the size of Disjiont is enough large.	*/
	Initialize_D (d, (*pht) -> capacity) ;
	/*	Every edge has two vertexs and every edge will enqueueing twice.	*/
	Initialize_B (&bh, capacity * 4) ;
	
	for (i = 0; i < capacity; i++)
	{
		edge.v_hash_value = (*padj) -> list[i].hash_value ;
		scan = (*padj) -> list[i].adjoin_to ;
		while (scan)
		{
			edge.w_hash_value = scan -> hash_value ;
			edge.weight = scan -> cvw ;
			Insert_B (&bh, &edge) ;
			scan = scan -> next ;
		}
	}
	i = 0 ;
	while  (i < vertex_sub - 1)
	{
		DeleteMin_B (&bh, &edge) ;
		vset = Find_D (d, edge.v_hash_value) ;
		wset = Find_D (d, edge.w_hash_value) ;
		if (vset != wset)
		{
			Union_D (d, vset, wset) ;
			result[i][0] = (*pht) -> lists[edge.v_hash_value].name ;
			result[i][1] = (*pht) -> lists[edge.w_hash_value].name ;
			weight[i] = edge.weight ;
			i++ ;
		}
	}
	free (d) ;
	Release_B (&bh) ;
}

void print_result (const char (* const result)[2], const int * const weight, const int size)
{
	int i ;

	for (i = 0; i < size; i++)
		printf ("%c to %c is %d\n", result[i][0], result[i][1], weight[i]) ;
}