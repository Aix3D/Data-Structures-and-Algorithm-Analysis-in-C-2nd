/*	9-9-12-10-18.43.c -- µÚ¾ÅÕÂµÚ¾ÅÌâ	*/
#include <stdio.h>
#include "queue_ADT.h"

int main (void) ;
void Unweightd (Adjacent_List * const padj) ;
int get_index (const Adjacent_List * const padj, const Name name) ;

int main (void)
{
	Adjacent_List adj ;
	int capacity = 9 ;

	CreateAdjacent_List (&adj, capacity) ;
    InitializeALineOfAdjacent_List (&adj, 0, 's', 0, 3, 'a', 'd', 'g') ;   
    InitializeALineOfAdjacent_List (&adj, 1, 'a', 1, 2, 'b', 'e') ;   
    InitializeALineOfAdjacent_List (&adj, 2, 'b', 1, 1, 'c') ;   
    InitializeALineOfAdjacent_List (&adj, 3, 'c', 3, 1, 't') ;   
    InitializeALineOfAdjacent_List (&adj, 4, 'd', 2, 2, 'a', 'e') ;   
    InitializeALineOfAdjacent_List (&adj, 5, 'e', 4, 3, 'c', 'f', 'i') ;   
    InitializeALineOfAdjacent_List (&adj, 6, 'f', 2, 2, 'c', 't') ;   
    InitializeALineOfAdjacent_List (&adj, 7, 'g', 1, 3, 'd', 'e', 'h') ;   
    InitializeALineOfAdjacent_List (&adj, 8, 'h', 1, 2, 'e', 'i') ;   
    InitializeALineOfAdjacent_List (&adj, 9, 'i', 2, 2, 'f', 't') ;   
    InitializeALineOfAdjacent_List (&adj, 10, 't', 3, 0) ;   
	PrintAdjacent_List (&adj) ;
	putchar ('\n') ;
	Unweightd (&adj) ;
	PrintAdjacent_List (&adj) ;
	ReleaseAdjacent_List (&adj) ;

	return 1 ;
}

void Unweightd (Adjacent_List * const padj)
{
	Queue queue ;
	Vertex * v, *w, * scan ;

	InitializeQueue (&queue) ;
	v = &(*padj) -> list[0] ;
	EnQueue (&queue, &v) ;

	while (!QueueIsEmpty (&queue))
	{
		DeQueue (&queue, &v) ;
		v -> known = KNOWN ;
		scan = v -> next ;
		while (scan)
		{
			w = &(*padj) -> list[get_index (padj, scan -> name)] ;
			if (INFINITY == w -> dist)
			{
				w -> dist = v -> dist + 1 ;
				w -> path = v -> name ;
				EnQueue (&queue, &w) ;
			}
			scan = scan -> next ;
		}
	}
	ReleaseQueue (&queue) ;
}

int get_index (const Adjacent_List * const padj, const Name name)
{
	Vertex * temp = (*padj) -> list ;

	if (name == temp[0].name)
		return 0 ;
	else if (name == temp[1].name)
		return 1 ;
	else if (name == temp[2].name)
		return 2 ;
	else if (name == temp[3].name)
		return 3 ;
	else if (name == temp[4].name)
		return 4 ;
	else if (name == temp[5].name)
		return 5 ;
	else if (name == temp[6].name)
		return 6 ;
	else if (name == temp[7].name)
		return 7 ;
	else if (name == temp[8].name)
		return 8 ;
	else if (name == temp[9].name)
		return 9 ;
	else
		return 10 ;
}