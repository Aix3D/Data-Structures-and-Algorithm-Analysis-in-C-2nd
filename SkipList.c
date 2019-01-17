/*	SkipList.c -- 跳跃表实现文件	*/
#include "SkipList.h"

/*	局部函数声明	*/

static int logTwo (const int value) ;
static void endow (Item * const l_value, const Item * const r_value) ;
static BOOL isEqualTo (const Item * const pil, const Item * const pir) ;
static BOOL isLesserThan (const Item * const pil, const Item * const pir) ;
static Node * makeNode (const Item * const pi, const int maximum_of_height) ;

/*	接口函数定义	*/

void InitializSeed_S (const long int initial_value)
{
#ifdef DEBUG
	assert (initial_value > 0) ;
#endif
	Seed = initial_value ;
}

BOOL Random_S (void)
{
	long int temp_seed ;
	double temp_value ;
	int return_value ;
#ifdef DEBUG
	assert (Seed > 0) ;
#endif
	temp_seed = A * (Seed % Q) - R * (Seed / Q) ;
	if (temp_seed >= 0)
		Seed = temp_seed ;
	else
		Seed = temp_seed + M ;
	temp_value = (double) Seed / M ;
	while (temp_value < 1)
		temp_value *= 100 ;
	return_value = (int) temp_value & MASK ;

	if (1 == return_value)
		return TRUE ;
	else
		return FALSE ;
}

BOOL Initialize_S (SkipList * const psl, const int capacity)
{
	Item undecided = UNDECIDED ;
	int i, height ;

#ifdef DEBUG
	assert (capacity > 0) ;
#endif
	*psl = (struct skiplist *) malloc (sizeof (struct skiplist)) ;
	if (NULL == psl)
		return FALSE ;
	(*psl) -> capacity = capacity ;
	(*psl) -> current = 0 ;
	(*psl) -> maximum_of_height = height = logTwo (capacity) ;
	(*psl) -> head = (Node *) malloc (sizeof (Node)) ;
	if (NULL == (*psl) -> head)
	{
		free (*psl) ;
		return FALSE ;
	}
	(*psl) -> head -> next = (Node * *) malloc (sizeof (Node *) * height) ;
	if (NULL == (*psl) -> head -> next)
	{
		free ((*psl) -> head) ;
		free (*psl) ;
		return FALSE ;
	}
	endow (&(*psl) -> head -> item, &undecided) ;
	(*psl) -> head -> height = height ;
	(*psl) -> head -> times = 1 ;
	for (i = 0; i < height; i++)
		(*psl) -> head -> next[i] = NULL ;

	return TRUE ;
}

BOOL IsEmpty_S (const SkipList * const psl)
{
	if (0 == (*psl) -> current)
		return TRUE ;
	else
		return FALSE ;
}

BOOL IsFull_S (const SkipList * const psl)
{
	if ((*psl) -> capacity == (*psl) -> current)
		return TRUE ;
	else
		return FALSE ;
}

BOOL Find_S (const SkipList * const psl, const Item * const pi)
{
	Node * scan ;
	int height ;

	if (IsEmpty_S (psl))
		return FALSE ;
	scan = (*psl) -> head ;
	height = scan -> height ;
	while (height > 0)
	{
		if (NULL == scan -> next[height - 1] || TRUE == isLesserThan (pi, &scan -> next[height - 1] -> item))
			height-- ;
		else if (TRUE == isEqualTo (pi, &scan -> next[height - 1] -> item))
			return TRUE ;
		else/*	if (FALSE = isLessetThan (pi, &scan -> next[height - 1] -> item))	*/
		{
			scan = scan -> next[height - 1] ;
			height = scan -> height ;
		}
	}

	return FALSE ;
}

Item * FindMax_S (const SkipList * const psl)
{
	Node * scan ;
	int height ;

	if (IsEmpty_S (psl))
		return NULL ;
	height = (*psl) -> maximum_of_height ;
	scan = (*psl) -> head ;
	while (height > 1)
	{
		if (NULL == scan -> next[height - 1])
			height-- ;
		else
		{
			scan = scan -> next[height - 1] ;
			height = scan -> height ;
		}
	}
	while (scan -> next[0] != NULL)
		scan = scan -> next[0] ;

	return &scan -> item ;
}

BOOL Insert_S (const SkipList * const psl, const Item * const pi)
{
	Node * new_node ;
	Node * scan ;
	int height, new_height, i ;

	if (IsFull_S (psl))
		return FALSE ;
	new_node = makeNode (pi, (*psl) -> maximum_of_height) ;
	if (NULL == new_node)
		return FALSE ;
	if (IsEmpty_S (psl))
	{
		new_height = new_node -> height ;
		for (i = 0 ; i < new_height; i++)
			(*psl) -> head -> next[i] = new_node ;
	}	
	else
	{
		scan = (*psl) -> head ;
		height = (*psl) -> maximum_of_height ;
		new_height = new_node -> height ;
		while (height > 0)
		{
			if (NULL == scan -> next[height - 1] || TRUE == isLesserThan (pi, &scan -> next[height - 1] -> item) || TRUE == isEqualTo (pi, &scan -> next[height - 1] -> item))
			{
				if (height <= new_height)
				{
					new_node -> next[--new_height] = scan -> next[height - 1] ;
					scan -> next[height - 1] = new_node ;
				}
				height-- ;
			}
			else/*	if (FALSE == isLesserThan (&pi -> item, &scan -> next[height - 1] -> item))	*/
			{
				scan = scan -> next[height - 1] ;
				height = scan -> height ;
			}
		}
	}
	(*psl) -> current++ ;

	return TRUE ;
}

BOOL Delete_S (const SkipList * const psl, const Item * const pi)
{
	Node * scan, * temp ;
	int height ;
	BOOL index = FALSE ;

	if (IsEmpty_S (psl))
		return FALSE ;
	scan = (*psl) -> head ;
	height = (*psl) -> maximum_of_height ;
	while (height > 0)
	{
		if (NULL == scan -> next[height -1] || TRUE == isLesserThan (pi, &scan -> next[height - 1] -> item))
			height-- ;
		else if (TRUE == isEqualTo (pi, &scan -> next[height - 1] -> item))
		{
			if (1 == height)
			{
				temp = scan -> next[height - 1] ;
				index = TRUE ;
			}
			scan -> next[height - 1] = scan -> next[height - 1] -> next[height - 1] ;
			height-- ;
		}
		else/*	if FALSE == isLeaaseThan (pi, &scan -> next[height - 1] -> item))	*/
		{
			scan = scan -> next[height - 1] ;
			height = scan -> height ;
		}
	}
	
	if (TRUE == index)
	{
		(*psl) -> current-- ;
		free (temp) ;
		return TRUE ;
	}
	else
		return FALSE ;
}

void Traversal_S (const SkipList * const psl, void (* pfun) (const Node * const pn))
{
	Node * scan ;

	scan = (*psl) -> head ;
	while (scan)
	{
		(* pfun) (scan) ;
		scan = scan -> next[0] ;
	}
}

void Release_S (const SkipList * const psl)
{
	Node * scan, * temp ;

	scan = (*psl) -> head -> next[0] ;
	while (scan)
	{
		temp = scan ;
		scan = scan -> next[0] ;
		free (temp -> next) ;
		free (temp) ;
	}
	free ((*psl) -> head -> next) ;
	free ((*psl) -> head) ;
	free (*psl) ;
}

/*	局部函数定义	*/

static int logTwo (const int value)
{
	int power = 2, i = 1 ;

	while (1)
	{
		if (value == (power *= 2))
		{
			i++ ;
			break ;
		}
		else if (power < value)
			i++ ;
		else
		{
			i++ ;
			break ;
		}
	}

	return i ;
}

static void endow (Item * const l_value, const Item * const r_value)
{
	*l_value = *r_value ;
}

static BOOL isEqualTo (const Item * const pil, const Item * const pir)
{
	if (*pil == *pir)
		return TRUE ;
	else
		return FALSE ;
}

static BOOL isLesserThan (const Item * const pil, const Item * const pir)
{
	if (*pil < *pir)
		return TRUE ;
	else
		return FALSE ;
}

static Node * makeNode (const Item * const pi, const int maximum_of_height)
{
	Node * new_node ;
	int i = 0, j ;

	new_node = (Node *) malloc (sizeof (Node)) ;
	if (NULL == new_node)
		return NULL ;
	endow (&new_node -> item, pi) ;
	new_node -> times = 1 ;
	do
		i++ ;
	while (i < maximum_of_height && TRUE == Random_S ())
		;
	new_node -> next = (Node * *) malloc (sizeof (Node *) * i) ;
	if (NULL == new_node -> next)
	{
		free (new_node) ;
		return NULL ;
	}
	new_node -> height = i ;
	new_node -> times = 1 ;
	for (j = 0; j < i; j++)
		new_node -> next[j] = NULL ;

	return new_node ;
}