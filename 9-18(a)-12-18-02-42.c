/*	9-18(a)-12-18-02-42.c -- 第九章第十八题	*/
#include <stdio.h>
#include <stdlib.h>
#include "binary_heap.h"

int main (void) ;
int prim (const Adjacenty_List * padj, const Hash_Table * const pht, const int start) ;

int main (void)
{
	Adjacenty_List adj ;
	Hash_Table ht ;
	int capacity = 10 ;

	Initialize_H (&ht, capacity * 2) ;
	Initialize_A (&adj, capacity) ;
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
	prim (&adj, &ht, 0) ;
	PrintAdjacenty_List_A (&adj, &ht) ;

	Release_H (&ht) ;
	Release_A (&adj) ;

	return 0 ;
}

int prim (const Adjacenty_List * padj, const Hash_Table * const pht, const int start)
{
	Binary_Heap bh ;
	Vertex * v ;
	Adjoin_To_Vertex * w ;
	int capacity = (*padj) -> capacity, i ;

	Initialize_B (&bh, capacity * 2) ;
	(*padj) -> list[start].dist = 0 ;
	for (i = 0; i < capacity; i++)
		Insert_B (&bh, (*padj) -> list + i) ;
	while (1)
	{
		do
		{
			v = DeleteMin_B (&bh) ;
			if (NEGATIVEINFINITY == v -> dist)
				break ;
		}
		while (TRUE == (*pht) -> lists[v -> hash_value].be_deleted)
			;
		if (NEGATIVEINFINITY == v -> dist)
			break ;
		(*pht) -> lists[v -> hash_value].be_deleted = TRUE ;
		v -> known = TRUE ;
		w = v -> adjoin_to ;
		while (w)
		{
			if (FALSE == (*padj) -> list[(*pht) -> lists[w -> hash_value].index_in_adjacenty_list].known)
			{
				if (w -> cvw < (*padj) -> list[(*pht) -> lists[w ->hash_value].index_in_adjacenty_list].dist)
				{
					(*padj) -> list[(*pht) -> lists[w -> hash_value].index_in_adjacenty_list].dist = w -> cvw ;
					(*padj) -> list[(*pht) -> lists[w -> hash_value].index_in_adjacenty_list].path = (*pht) -> lists[v -> hash_value].name ;
				}
				Insert_B (&bh, (*padj) -> list + (*pht) -> lists[w -> hash_value].index_in_adjacenty_list) ;
			}
			w = w -> next ;
		}
	}
	Release_B (&bh) ;

	return 1 ;
}