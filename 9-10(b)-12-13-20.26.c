/*	9-10(b)-12-13-20.26.c -- 第九章第十题(b)	*/
#include <stdio.h>
#include <stdlib.h>
#include "binary_heap.h"

int main (void) ;
int new_dijkstra (const Adjacenty_List * padj, const Hash_Table * const pht, const int start) ;

int main (void)
{
	Adjacenty_List adj ;
	Hash_Table ht ;
	int capacity = 5 ;

	Initialize_H (&ht, capacity * 2) ;
	Initialize_A (&adj, capacity) ;

	InitializeALine_A (&adj, &ht, 0, 's', 0, 4, 'a', 2, 'd', 3) ;
	InitializeALine_A (&adj, &ht, 1, 'a', 0, 2, 'b', 2) ;
	InitializeALine_A (&adj, &ht, 2, 'b', 0, 2, 'c', 2) ;
	InitializeALine_A (&adj, &ht, 3, 'c', 0, 2, 'd', 2) ;
	InitializeALine_A (&adj, &ht, 4, 'd', 0, 2, 'c', 3) ;

	new_dijkstra (&adj, &ht, 0) ;
	PrintAdjacenty_List_A (&adj, &ht) ;

	Release_H (&ht) ;
	Release_A (&adj) ;

	return 0 ;
}

int new_dijkstra (const Adjacenty_List * padj, const Hash_Table * const pht, const int start)
{
	Binary_Heap bh ;
	Vertex * v ;
	Adjoin_To_Vertex * w ;
	int capacity = (*padj) -> capacity, i, v_index, w_index ;
	int * count ;

	count = (int *) calloc (sizeof (int), capacity) ;
	if (NULL == count)
		return 0 ;
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
		v_index = (*pht) -> lists[v -> hash_value].index_in_adjacenty_list ;
		while (w)
		{
			w_index = (*pht) -> lists[w -> hash_value].index_in_adjacenty_list ;
			if (FALSE == (*padj) -> list[w_index].known)
			{
				if (v -> dist + w -> cvw < (*padj) -> list[w_index].dist)
				{
					count[w_index] = count[v_index] + 1 ;
					(*padj) -> list[w_index].dist = v -> dist + w -> cvw ;
					Insert_B (&bh, (*padj) -> list + w_index) ;
					(*padj) -> list[w_index].path = (*pht) -> lists[v -> hash_value].name ;
				}
				else if (v -> dist + w -> cvw == (*padj) -> list[w_index].dist)
				{
					if (count[v_index] + 1 < count[w_index])
					{
						count[w_index] = count[v_index] + 1 ;
						(*padj) -> list[w_index].path = (*pht) -> lists[v -> hash_value].name ;
					}
				}
			}
			w = w -> next ;
		}
	}
	free (count) ;
	Release_B (&bh) ;

	return 1 ;
}