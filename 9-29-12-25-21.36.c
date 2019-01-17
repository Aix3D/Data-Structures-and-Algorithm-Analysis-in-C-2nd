/*	9-29-12-25-21.36.c -- 第九章第二十九题	*/
#include <stdio.h>
#include "new_adjacenty_list.h"
#include "stack.h"
#include "linked_list.h"

#define SIZE (10)
#define START (0)

int visited[SIZE], low[SIZE], number[SIZE], parent[SIZE] ;
int counter = 1 ;

int main (void) ;
void initialize_array (int * const array, const int capacity) ;
void build_graph (Adjacenty_List * const padj, const Hash_Table * const pht) ;
void find_biconnected_component (const Adjacenty_List * const padj, const Hash_Table * const pht, const int index, Stack * const pst, List * const pli) ;
int min (const int val1, const int val2) ;

int main (void)
{
	Adjacenty_List adj ;
	Hash_Table ht ;
	Stack stack ;
	List list ;
	int capacity = SIZE ;

	Initialize_A (&adj, capacity) ;
	Initialize_H (&ht, capacity * 2) ;
	Initialize_S (&stack, capacity * (capacity - 1)) ;
	Initialize_L (&list) ;

	initialize_array (visited, capacity) ;
	build_graph (&adj, &ht) ;

	find_biconnected_component (&adj, &ht, START, &stack, &list) ;

	Release_A (&adj) ;
	Release_H (&ht) ;
	Release_S (&stack) ;
	Release_L (&list) ;

	return 0 ;
}

void initialize_array (int * const array, const int capacity)
{
	int i ;

	for (i = 0; i < capacity; i++)
		array[i] = FALSE ;
}

void build_graph (Adjacenty_List * const padj, const Hash_Table * const pht)
{	
	InitializeALine_A (padj, pht, 0, 'a', 0, 10, 'b', 0, 'c', 0, 'e', 0, 'h', 0, 'i', 0) ;
	InitializeALine_A (padj, pht, 1, 'b', 0, 6, 'a', 0, 'c', 0, 'd', 0) ;
	InitializeALine_A (padj, pht, 2, 'c', 0, 6, 'a', 0, 'b', 0, 'e', 0) ;
	InitializeALine_A (padj, pht, 3, 'd', 0, 2, 'b', 0) ;
	InitializeALine_A (padj, pht, 4, 'e', 0, 8, 'a', 0, 'c', 0, 'f', 0, 'g', 0) ;
	InitializeALine_A (padj, pht, 5, 'f', 0, 4, 'e', 0, 'g', 0) ;
	InitializeALine_A (padj, pht, 6, 'g', 0, 4, 'e', 0, 'f', 0) ;
	InitializeALine_A (padj, pht, 7, 'h', 0, 4, 'a', 0, 'j', 0) ;
	InitializeALine_A (padj, pht, 8, 'i', 0, 4, 'a', 0, 'j', 0) ;
	InitializeALine_A (padj, pht, 9, 'j', 0, 4, 'h', 0, 'i', 0) ;
	
	/*
	InitializeALine_A (padj, pht, 0, 'a', 0, 4, 'b', 0, 'd', 0) ;
	InitializeALine_A (padj, pht, 1, 'b', 0, 4, 'a', 0, 'c', 0) ;
	InitializeALine_A (padj, pht, 2, 'c', 0, 6, 'b', 0, 'd', 0, 'g', 0) ;
	InitializeALine_A (padj, pht, 3, 'd', 0, 8, 'a', 0, 'c', 0, 'e', 0, 'f', 0) ;
	InitializeALine_A (padj, pht, 4, 'e', 0, 4, 'd', 0, 'f', 0) ;
	InitializeALine_A (padj, pht, 5, 'f', 0, 4, 'd', 0, 'e', 0) ;
	InitializeALine_A (padj, pht, 6, 'g', 0, 2, 'c', 0) ;*/
}

void find_biconnected_component (const Adjacenty_List * const padj, const Hash_Table * const pht, const int index, Stack * const pst, List * const pli)
{
	Adjoin_To_Vertex * scan ;
	Stack_Item st1, st2 ;
	int w ;

	visited[index] = TRUE ;
	number[index] = low[index] = counter++ ;
	scan = (*padj) -> list[index].adjoin_to ;
	while (scan)
	{
		w = (*pht) -> lists[scan -> hash_value].index_in_adjacenty_list ;
		if (FALSE == visited[w])
		{
			/*	If edge (w, index) was not already processed as a back edge.	*/
			if (!Find_L (pli, w, index))
				Push_S (pst, index, w) ;
			parent[w] = index ;
			find_biconnected_component (padj, pht, w, pst, pli) ;
			/*	Don't processe the root!	*/
			if (low[w] >= number[index])
			{
				while (Pop_S (pst, &st1, &st2))
				{
					if (index == st1 && w == st2)
					{
						printf ("%c -> %c\n", (*pht) -> lists[(*padj) -> list[st1].hash_value].name, (*pht) -> lists[(*padj) -> list[st2].hash_value].name) ;
						putchar ('\n') ;
						break ;
					}
					else
						printf ("%c -> %c\n", (*pht) -> lists[(*padj) -> list[st1].hash_value].name, (*pht) -> lists[(*padj) -> list[st2].hash_value].name) ;
				}
			}
			low[index] = min (low[index], low[w]) ;
		}
		else if (parent[index] != w)
		{
			/*	Edge (index, w) is already processed as a back edge	*/
			Insert_L (pli, index, w) ;
			low[index] = min (low[index], number[w]) ;
		}
		/*	If edge (w, index) was not already processed as a back edge.	*/
		if (!Find_L (pli, w, index))
		{
			Push_S (pst, index, w) ;
			/*	Edge (index, w) is already pushed into the stack. Make sure I will not push a edge into a stack twice.	*/
			Insert_L (pli, index, w) ;
		}
		scan = scan -> next ;
	}
}

int min (const int val1, const int val2)
{
	return val1 < val2 ? val1 : val2 ;
}