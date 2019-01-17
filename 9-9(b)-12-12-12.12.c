/*	9-9(b)-12-12-12.12.c -- µÚ¾ÅÕÂµÚ¾ÅÌâ	*/
#include <stdio.h>
#include <stdlib.h>
#include "binary_heap.h"

int main (void) ;
int dijkstra (const Adjacenty_List * padj, const Hash_Table * const pht, const int start) ;

int main (void)
{
	Adjacenty_List adj ;
	Hash_Table ht ;
	int capacity = 11 ;

	Initialize_H (&ht, capacity * 2) ;
	Initialize_A (&adj, capacity) ;
	InitializeALine_A (&adj, &ht, 0, 's', 0, 6, 'a', 1, 'd', 4, 'g', 6) ;
	InitializeALine_A (&adj, &ht, 1, 'a', 2, 4, 'b', 2, 'e', 2) ;
	InitializeALine_A (&adj, &ht, 2, 'b', 1, 2, 'c', 2) ;
	InitializeALine_A (&adj, &ht, 3, 'c', 3, 2, 't', 4) ;
	InitializeALine_A (&adj, &ht, 4, 'd', 2, 4, 'a', 3, 'e', 3) ;
	InitializeALine_A (&adj, &ht, 5, 'e', 4, 6, 'c', 2, 'f', 3, 'i', 3) ;
	InitializeALine_A (&adj, &ht, 6, 'f', 2, 4, 'c', 1, 't', 3) ;
	InitializeALine_A (&adj, &ht, 7, 'g', 1, 6, 'd', 2, 'e', 1, 'h', 6) ;
	InitializeALine_A (&adj, &ht, 8, 'h', 1, 4, 'e', 2, 'i', 3) ;
	InitializeALine_A (&adj, &ht, 9, 'i', 2, 4, 'f', 1, 't', 4) ;
	InitializeALine_A (&adj, &ht, 10, 't', 3, 0) ;
	dijkstra (&adj, &ht, 0) ;
	PrintAdjacenty_List_A (&adj, &ht) ;

	Release_H (&ht) ;
	Release_A (&adj) ;

	return 0 ;
}

int dijkstra (const Adjacenty_List * padj, const Hash_Table * const pht, const int start)
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
				if (v -> dist + w -> cvw < (*padj) -> list[(*pht) -> lists[w -> hash_value].index_in_adjacenty_list].dist)
				{
					(*padj) -> list[(*pht) -> lists[w -> hash_value].index_in_adjacenty_list].dist = v -> dist + w -> cvw ;
					Insert_B (&bh, (*padj) -> list + (*pht) -> lists[w -> hash_value].index_in_adjacenty_list) ;
					(*padj) -> list[(*pht) -> lists[w -> hash_value].index_in_adjacenty_list].path = (*pht) -> lists[v -> hash_value].name ;
				}
			}
			w = w -> next ;
		}
	}
	Release_B (&bh) ;

	return 1 ;
}