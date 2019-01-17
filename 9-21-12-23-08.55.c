/*	9-21-12-23-08.55.c -- 第九章第二十一题	*/
#include <stdio.h>
#include "new_adjacenty_list.h"

#define SIZE (7)

/*	Global variable	*/

char parent[SIZE] ;
int visited[SIZE], number[SIZE], low[SIZE], counter = 1, root ;

int main (void) ;
void build_graph (Adjacenty_List * const padj, Hash_Table * const pht) ;
void find_art (const Adjacenty_List * const padj, const Hash_Table * const pht, const int v) ;
int min (const int val1, const int val2) ;

int main (void)
{
	Adjacenty_List adj ;
	Hash_Table ht ;
	int i, size = SIZE ;

	Initialize_A (&adj, size) ;
	Initialize_H (&ht, size * 2) ;
	build_graph (&adj, &ht) ;
	for (i = 0, size = SIZE; i < size; i++)
		visited[i] = FALSE ;
	root = 0 ;
	find_art (&adj, &ht, root) ;

	Release_A (&adj) ;
	Release_H (&ht) ;

	return 0 ;
}

void build_graph (Adjacenty_List * const padj, Hash_Table * const pht)
{
	InitializeALine_A (padj, pht, 0, 'a', 0, 4, 'b', 0, 'd', 0) ;
	InitializeALine_A (padj, pht, 1, 'b', 0, 4, 'a', 0, 'c', 0) ;
	InitializeALine_A (padj, pht, 2, 'c', 0, 6, 'b', 0, 'd', 0, 'g', 0) ;
	InitializeALine_A (padj, pht, 3, 'd', 0, 8, 'a', 0, 'c', 0, 'e', 0, 'f', 0) ;
	InitializeALine_A (padj, pht, 4, 'e', 0, 4, 'd', 0, 'f', 0) ;
	InitializeALine_A (padj, pht, 5, 'f', 0, 4, 'd', 0, 'e', 0) ;
	InitializeALine_A (padj, pht, 6, 'g', 0, 2, 'c', 0) ;
}

void find_art (const Adjacenty_List * const padj, const Hash_Table * const pht, const int v)
{
	Adjoin_To_Vertex * scan ;
	int w ;

	visited[v] = TRUE ;
	low[v] = number[v] = counter++ ;
	scan = (*padj) -> list[v].adjoin_to ;
	while (scan)
	{
		w = (*pht) -> lists[scan -> hash_value].index_in_adjacenty_list ;
		/*	Forward edge	*/
		if (FALSE == visited[w])
		{
			parent[w] = (*pht) -> lists[v].name ;
			find_art (padj, pht, w) ;
			if (low[w] >= number[v] && v != root)
				printf ("%c is an articulation point.\n", (*pht) -> lists[(*padj) -> list[v].hash_value].name) ;
			low[v] = min (low[v], low[w]) ;
		}
		/*	Back edge	*/
		else if (parent[v] != (*pht) ->lists[w].name)
			low[v] = min (low[v], number[w]) ;
		scan = scan -> next ;
	}
}

int min (const int val1, const int val2)
{
	return val1 > val2 ? val2 : val1 ;
}