/*	9-32(a)-12-29-21.48.c -- 第九章第三十二题	*/
#include <stdio.h>
#include <stdlib.h>
#include "new_adjacenty_list.h"
#include "rqueue.h"

#define SIZE (12)

int g_last_path = INFINITY ;

int main (void) ;
void buildGraph (Adjacenty_List * const padj, Hash_Table * const pht) ;
int eulerCircuit (Adjacenty_List * const padj, const Hash_Table * const pht, const int start) ;
void depthFirstSearch (Adjacenty_List * const padj, const Hash_Table * const pht, Rqueue * const prq, const int index) ;
int isAnOddExpectZero (const int num) ;
void changeVisited (Adjoin_To_Vertex * const * const vertex, const int hash_value) ;
int splice (Rqueue_Node * const * const scan_1st, Rqueue * const prq_2nd) ;

int main (void)
{
	Adjacenty_List adj ;
	Hash_Table ht ;
	int capacity = SIZE, start = 0 ;

	Initialize_A (&adj, capacity) ;
	Initialize_H (&ht, capacity * 2) ;
	
	buildGraph (&adj, &ht) ;
	eulerCircuit (&adj, &ht, start) ;

	Release_A (&adj) ;
	Release_H (&ht) ;

	return 0 ;
}

void buildGraph (Adjacenty_List * const padj, Hash_Table * const pht)
{
	InitializeALine_A (padj, pht, 0, 'a', 2, 4, 'c', 0, 'd', 0) ;
	InitializeALine_A (padj, pht, 1, 'b', 2, 4, 'c', 0, 'h', 0) ;
	InitializeALine_A (padj, pht, 2, 'c', 6, 12, 'a', 0, 'b', 0, 'd', 0, 'f', 0, 'g', 0, 'i', 0) ;
	InitializeALine_A (padj, pht, 3, 'd', 6, 12, 'a', 0, 'c', 0, 'e', 0, 'g', 0, 'j', 0, 'k', 0) ;
	InitializeALine_A (padj, pht, 4, 'e', 2, 4, 'd', 0, 'j', 0) ;
	InitializeALine_A (padj, pht, 5, 'f', 2, 4, 'c', 0, 'i', 0) ;
	InitializeALine_A (padj, pht, 6, 'g', 4, 8, 'c', 0, 'd', 0, 'i', 0, 'j', 0) ;
	InitializeALine_A (padj, pht, 7, 'h', 2, 4, 'b', 0, 'i', 0) ;
	InitializeALine_A (padj, pht, 8, 'i', 6, 12, 'c', 0, 'f', 0, 'g', 0, 'h', 0, 'j', 0, 'l', 0) ;
	InitializeALine_A (padj, pht, 9, 'j', 6, 12, 'd', 0, 'e', 0, 'g', 0, 'i', 0, 'k', 0, 'l', 0) ;
	InitializeALine_A (padj, pht, 10, 'k', 2, 4, 'd', 0, 'j', 0) ;
	InitializeALine_A (padj, pht, 11, 'l', 2, 4, 'i', 0, 'j', 0) ;
}

int eulerCircuit (Adjacenty_List * const padj, const Hash_Table * const pht, const int start)
{
	Rqueue rq_1st, rq_2nd ;
	Rqueue_Node * scan ;
	int capacity = (*padj) -> capacity, i ;

	if (start < 0 || start >= capacity)
		return 0 ;
	if (!Initialize_R (&rq_1st) || !Initialize_R (&rq_2nd))
		return 0 ;
	/*	Test	*/
	for (i = 0; i < capacity; i++)
	{
		if (isAnOddExpectZero ((*padj) -> indegree[i]))
			return 0 ;
	}
	depthFirstSearch (padj, pht, &rq_1st, start) ;
	scan = rq_1st -> front ;
	while (scan)
	{
		if ((*padj) -> indegree[scan -> index_in_adjacenty_list])
		{
			g_last_path = INFINITY ;
			depthFirstSearch (padj, pht, &rq_2nd, scan -> index_in_adjacenty_list) ;
			scan = scan -> next ;
			/*	Splicing these two queues	*/
			splice (&(rq_1st -> front), &rq_2nd) ;
			rq_1st -> current = rq_1st -> current + rq_2nd -> current - 1 ;
			rq_2nd -> front = rq_2nd -> rear = NULL ;
			rq_2nd -> current = 0 ;
		}
		else
			scan = scan -> next ;
	}
	/*	Print the result	*/
	for (scan = rq_1st -> front; scan; scan = scan -> next)
		printf ("%c\n", (*pht) -> lists[(*padj) -> list[scan -> index_in_adjacenty_list].hash_value].name) ;

	Release_R (&rq_1st) ;
	if (!IsEmpty_R (&rq_2nd))
		Release_R (&rq_2nd) ;

	return 1 ;
}

void depthFirstSearch (Adjacenty_List * const padj, const Hash_Table * const pht, Rqueue * const prq, const int index)
{
	Adjoin_To_Vertex * scan ;
	int w ;

	//	 The degree of current vertex--
	if (g_last_path != INFINITY)
	{
		(*padj) -> indegree[index]-- ;
		//	The path of from Current vertex to previous vertex should be deleted	*/
		changeVisited (&(*padj) -> list[index].adjoin_to, (*padj) -> list[g_last_path].hash_value) ;
	}
	Insert_R (prq, index) ;
	scan = (*padj) -> list[index].adjoin_to ;
	while (scan)
	{
		/*	If he degree of current vertex is 0	*/
		if (0 == (*padj) -> indegree[(*pht) -> lists[scan -> hash_value].index_in_adjacenty_list])
			scan = scan -> next ;
		//	Else if current vertex is previous vertex	*/
		else if (g_last_path == (*pht) -> lists[scan -> hash_value].index_in_adjacenty_list)
			scan = scan -> next ;
		//	Else if current vertex has been visited	*/
		else if (TRUE == scan -> visited)
			scan = scan -> next ;
		else
			break ;
	}
	if (NULL == scan)
		return ;
	/*	The degree of current vertex--	*/
	(*padj) -> indegree[index]-- ;
	/*	The path of from Current vertex to objective vertex should be deleted	*/
	changeVisited (&(*padj) -> list[index].adjoin_to, scan -> hash_value) ;
	g_last_path = index ;
	w = (*pht) -> lists[scan -> hash_value].index_in_adjacenty_list ;
	depthFirstSearch (padj, pht, prq, w) ;
}

int isAnOddExpectZero (const int num)
{
	return 0 != num && num % 2 != 0 ;
}

void changeVisited (Adjoin_To_Vertex * const * const vertex, const int hash_value)
{
	if ((*vertex) -> hash_value == hash_value)
		(*vertex) -> visited = TRUE ;
	else
		changeVisited (&(*vertex) -> next, hash_value) ;
}

int splice (Rqueue_Node * const * const scan_1st, Rqueue * const prq_2nd)
{
	Rqueue_Node * temp ;

	if (*scan_1st)
	{
		if ((*scan_1st) -> next -> index_in_adjacenty_list == (*prq_2nd) -> front -> index_in_adjacenty_list)
		{
			temp = (*scan_1st) -> next ;
			(*scan_1st) -> next = (*prq_2nd) -> front ;
			(*prq_2nd) -> rear -> next = temp -> next ;
			free (temp) ;
			return 1 ;
		}
		else
			splice (&(*scan_1st) -> next, prq_2nd) ;
	}
	else
		return 0 ;
}