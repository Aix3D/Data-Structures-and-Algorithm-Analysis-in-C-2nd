/*	9-27-12-23-22.26.c -- 第九章第二十七题	*/
#include <stdio.h>
#include "new_adjacenty_list.h"

#define SIZE (7)

int visited[SIZE], postorder[SIZE] ;
int count = 0, kind = 1 ;

int mian (void) ;
void initialize_graph (Adjacenty_List * const padj, Hash_Table * const pht) ;
void initialize_array (int * const array, const int size, const int value) ;
void search_all (const Adjacenty_List * const padj, const Hash_Table * const pht) ;
void depth_first_search (const Adjacenty_List * const padj, const Hash_Table * const pht, const int index) ;
void depth_first_search_without_number (const Adjacenty_List * const padj, const Hash_Table * const pht, const int index) ;
void invert_graph (Adjacenty_List * const padj, const Hash_Table * const pht) ;
void find_connected (const Adjacenty_List * const padj, const Hash_Table * const pht) ;
void print_result (const Adjacenty_List * const padj, const Hash_Table * const pht) ;

int main (void)
{
	Adjacenty_List adj ;
	Hash_Table ht ;
	int capacity = SIZE ;

	Initialize_A (&adj, capacity) ;
	Initialize_H (&ht, capacity * 2) ;

	initialize_array (visited, capacity, FALSE) ;
	/*	Initialize the graph	*/
	initialize_graph (&adj, &ht) ;
	/*	Reverse the graph	*/
	Reverse_A (&adj, &ht) ;
	/*	Number it	*/
	search_all (&adj, &ht) ;
	initialize_array (visited, capacity, FALSE) ;
	find_connected (&adj, &ht) ;
	print_result (&adj, &ht) ;

	Release_A (&adj) ;
	Release_H (&ht) ;

	return 0 ;
}

void initialize_graph (Adjacenty_List * const padj, Hash_Table * const pht)
{
	InitializeALine_A (padj, pht, 0, 'a', 0, 4, 'b', 0, 'c', 0) ;
	InitializeALine_A (padj, pht, 1, 'b', 0, 6, 'c', 0, 'e', 0, 'g', 0) ;
	InitializeALine_A (padj, pht, 2, 'c', 0, 4, 'd', 0, 'e', 0) ;
	InitializeALine_A (padj, pht, 3, 'd', 0, 4, 'a', 0, 'f', 0) ;
	InitializeALine_A (padj, pht, 4, 'e', 0, 4, 'd', 0, 'f', 0) ;
	InitializeALine_A (padj, pht, 5, 'f', 0, 0) ;
	InitializeALine_A (padj, pht, 6, 'g', 0, 2, 'e', 0) ;
}

void initialize_array (int * const array, const int size, const int value)
{
	int i ;

	for (i = 0; i < size; i++)
		array[i] = value ;
}

void search_all (const Adjacenty_List * const padj, const Hash_Table * const pht)
{
	int i, size ;

	for (i = 0, size = (*padj) -> capacity; i < size; i++)
	{
		if (FALSE == visited[i])
			depth_first_search (padj, pht, i) ;
	}
}

void depth_first_search (const Adjacenty_List * const padj, const Hash_Table * const pht, const int index)
{
	Adjoin_To_Vertex * scan ;
	int w ;

	visited[index] = TRUE ;
	scan = (*padj) -> list[index].adjoin_to ;
	while (scan)
	{
		w = (*pht) -> lists[scan -> hash_value].index_in_adjacenty_list ;
		if (FALSE == visited[w])
			depth_first_search (padj, pht, w) ;
		scan = scan -> next ;
	}
	postorder[count++] = (*padj) -> list[index].hash_value ;
}

void depth_first_search_without_number (const Adjacenty_List * const padj, const Hash_Table * const pht, const int index)
{
	Adjoin_To_Vertex * scan ;
	int w ;

	visited[index] = kind ;
	scan = (*padj) -> list[index].adjoin_to ;
	while (scan)
	{
		w = (*pht) -> lists[scan -> hash_value].index_in_adjacenty_list ;
		if (FALSE == visited[w])
			depth_first_search_without_number (padj, pht, w) ;
		scan = scan -> next ;
	}
}

void find_connected (const Adjacenty_List * const padj, const Hash_Table * const pht)
{
	int i, size ;

	/*	The first element in the array is visited in the end	*/
	for (i = 0, size = (*padj) -> capacity; i < size; i++)
	{
		if (FALSE == visited[(*pht) -> lists[postorder[i]].index_in_adjacenty_list])
		{
			depth_first_search_without_number (padj, pht, (*pht) -> lists[postorder[i]].index_in_adjacenty_list) ;
			kind++ ;
		}
	}
}

void print_result (const Adjacenty_List * const padj, const Hash_Table * const pht)
{
	int i, size ;

	for (i = 0, size = (*padj) -> capacity; i < size; i++)
		printf ("%c is in gather %d.\n", (*pht) -> lists[(*padj) -> list[i].hash_value].name, visited[i]) ;
}