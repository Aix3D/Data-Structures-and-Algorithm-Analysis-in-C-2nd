/*	new_adjacenty_list.c -- 邻接表实现文件	*/
#include <stdio.h>
#include <stdlib.h>
#include "new_adjacenty_list.h"

/*	局部函数声明	*/

static Adjoin_To_Vertex * Make_Adjoin_To_Vertex (const Hash_Table * const pht, const Name name, const int cvw) ;
static Adjoin_To_Vertex * * Find_End (Adjoin_To_Vertex * * scan) ;

/*	接口函数定义	*/

int Initialize_A (Adjacenty_List * const padj, const int capacity)
{
	if (capacity <= 0)
		return 0 ;
	*padj = (struct adjacenty_list *) malloc (sizeof (struct adjacenty_list)) ;
	if (NULL == *padj)
		return 0 ;
	(*padj) -> list = (Vertex *) malloc (sizeof (Vertex) * capacity) ;
	if (NULL == (*padj) -> list)
	{
		free (*padj) ;
		return 0 ;
	}
	(*padj) -> indegree = (int *) malloc (sizeof (int) * capacity) ;
	if (NULL == (*padj) -> indegree)
	{
		free ((*padj) -> list) ;
		free (*padj) ;
		return 0 ;
	}
	(*padj) -> capacity = capacity ;

	return 1 ;
}

int InitializeALine_A (Adjacenty_List * const padj, const Hash_Table * const pht, const int index, const Name name, const int indegree, const int sub, ...)
{
	va_list ap ;
	Adjoin_To_Vertex * temp ;
	Name others ;
	int i, cvw ;

	if (index > (*padj) -> capacity || indegree < 0 || sub < 0)
		return 0 ;
	if (FAILED == Insert_H (pht, &name, index))
		return 0 ;
	va_start (ap, sub) ;
	/*	Suppose the function will not generate a iterant return value	*/
	(*padj) -> list[index].hash_value = Hash (pht, &name) ;
	(*padj) -> list[index].known = FALSE ; 
	(*padj) -> list[index].dist = INFINITY ;
	(*padj) -> list[index].path = NUL ;
	(*padj) -> indegree[index] = indegree ;
	if (0 == sub)
	{
		(*padj) -> list[index].adjoin_to = NULL ;
		va_end (ap) ;
		return 1 ;
	}
	else if (sub % 2)
	{
		(*padj) -> list[index].adjoin_to = NULL ;
		va_end (ap) ;
		return 0 ;
	}
	else
	{
		others = va_arg (ap, Name) ;
		cvw = va_arg (ap, int) ;
		temp = (*padj) -> list[index].adjoin_to = Make_Adjoin_To_Vertex (pht, others, cvw) ;
		if (NULL == temp)
		{
			va_end (ap) ;
			return 0 ;
		}
		for (i = 2; i < sub; i += 2)
		{
			others = va_arg (ap, Name) ;
			cvw = va_arg (ap, int) ;
			temp -> next = Make_Adjoin_To_Vertex (pht, others, cvw) ;
			temp = temp -> next ;
		}
		va_end (ap) ;
		return 1 ;
	}
}

int Reverse_A (Adjacenty_List * const padj, const Hash_Table * const pht)
{
	Name name ;
	Adjoin_To_Vertex * scan, * new_vertex, * temp_1, * * temp_2 ;
	int w, i, capacity = (*padj) -> capacity ;

	for (i = 0; i < capacity; i++)
	{
		scan = (*padj) -> list[i].adjoin_to ;
		name = (*pht) -> lists[(*padj) -> list[i].hash_value].name ;
		while (scan)
		{
			w = (*pht) -> lists[scan -> hash_value].index_in_adjacenty_list ;
			/*	The incipient value of cvw is FALSE	*/
			if (FALSE == scan -> cvw)
			{
				/*	Create a new vertex	*/
				new_vertex = Make_Adjoin_To_Vertex (pht, name, 0) ;
				/*	Borrow the territory of cvw to target	*/
				new_vertex -> cvw = TRUE ;
				if (NULL == new_vertex)
					return 0 ;
				if (NULL == (*padj) -> list[w].adjoin_to)
					(*padj) -> list[w].adjoin_to = new_vertex ;
				else
				{
					temp_2 = Find_End (&(*padj) -> list[w].adjoin_to) ;
					(*temp_2) -> next = new_vertex ;
				}
				temp_1 = scan ;
				(*padj) -> list[i].adjoin_to = scan -> next ;
				scan = scan -> next ;
				free (temp_1) ;
			}
			else
				scan = scan -> next ;
		}
	}

	return 1 ;
}

void PrintAdjacenty_List_A (const Adjacenty_List * const padj, const Hash_Table * const pht)
{
	Adjoin_To_Vertex * scan ;
	int i, capacity ;

	for (i = 0, capacity = (*padj) -> capacity; i < capacity; i++)
	{
		printf ("Vertex Name:%-3c ", (*pht) -> lists[(*padj) -> list[i].hash_value].name) ;
		scan = (*padj) -> list[i].adjoin_to ;
		while (scan)
		{
			printf ("->%-3c", (*pht) -> lists[scan -> hash_value].name) ;
			scan = scan -> next ;
		}
		putchar ('\n') ;
	}
}

void Release_A (const Adjacenty_List * const padj)
{
	Adjoin_To_Vertex * scan, * temp;
	int i, capacity ;

	for (i = 0, capacity = (*padj) -> capacity; i < capacity; i++)
	{
		scan = (*padj) -> list[i].adjoin_to ;
		while (scan)
		{
			temp = scan ;
			scan = scan -> next ;
			free (temp) ;
		}
	}
	free ((*padj) -> list) ;
	free ((*padj) -> indegree) ;
	free (*padj) ;
}

/*	局部函数定义	*/

static Adjoin_To_Vertex * Make_Adjoin_To_Vertex (const Hash_Table * const pht, const Name name, const int cvw)
{
	Adjoin_To_Vertex * new_vertex ;

	new_vertex = (Adjoin_To_Vertex *) malloc (sizeof (Adjoin_To_Vertex)) ;
	if (new_vertex)
	{
		/*	Suppose the function will not generate a iterant return value	*/
		new_vertex -> hash_value = Hash (pht, &name) ;
		new_vertex -> cvw = cvw ;
		new_vertex -> next = NULL ;
	}

	return new_vertex ;
}

static Adjoin_To_Vertex * * Find_End (Adjoin_To_Vertex * * scan)
{
	if (NULL == *scan)
	{
		puts ("Gat a null point.") ;
		return NULL ;
	}
	else if ((*scan) -> next)
		return Find_End (&(*scan) -> next) ;
	else
		return scan ;
}