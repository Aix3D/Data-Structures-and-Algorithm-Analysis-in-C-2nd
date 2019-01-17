/*	Head.h -- Í·ÎÄ¼þ	*/
#include <stdio.h>
#include <stdlib.h>

#define QUIT (0)
#define IMPORT_DATA (1)
#define NEXT_FIT (2)
#define FIRST_FIT (3)
#define BEST_FIT (4)
#define FIRST_FIT_DECREASING (5)
#define BEST_FIT_DECREASING (6)
#define UNDEFINITION (7)
#define SIZE (32)

#define GROSS (100)

#define FALSE (0)
#define TRUE (1)

typedef struct item
{
	int current ;
	int leavings ;
	int gross ;
} Item ;

typedef int Bool ;