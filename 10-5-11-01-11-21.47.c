/*	10-5-11-01-11-21.47.c	-- 第十章第五题	*/
#include "Uiversal_queue.h"

typedef struct data
{
	int time ;
	int count ;
} Data ;

int main (void) ;
int showMenuAndGetChoice (void) ;
void eatLine (void) ;
int getInput (int * const input, const int size) ;
Data nextFit (const int * const input, const int size) ;
Data firstFit (const int * const input, const int size) ;
Data bestFit (const int * const input, const int size) ;
Data firstFitDecreasing (const int * const input, const int size) ;
Data bestFitDecreasing (const int * const input, const int size) ;
Bool addToLastNode (const Item * const pi, Node * const pn) ;
Bool addToExistingNode (const Item * const pi, Node * const pn) ;
Bool addToBestNode (const Item * const pi, Queue * const pq) ;
void shellSort_PointToNode (Node * * const input, const int size) ;
void shellSort_Int (int * const input, const int size) ;

int main (void)
{
	Data data ;
	int choice, size, index = FALSE ;
	int input[SIZE] ;

	while ((choice = showMenuAndGetChoice ()) != QUIT)
	{
		switch (choice)
		{
			case IMPORT_DATA :
				size = SIZE ;
				if (size = getInput (input, size))
				{
					 puts ("Complete input.") ;
					 index = TRUE ;
				 }
				else
					puts ("Failed input.") ;
				break ;
			case NEXT_FIT :
				if (TRUE == index)
				{
					data = nextFit (input, size) ;
					printf ("Next fit : time : %d count : %d\n", data.time, data.count) ; 
				}
				else
					puts ("No input.") ;
				break ;
			case FIRST_FIT :
				if (TRUE == index)
				{
					data = firstFit (input, size) ;
					printf ("First fit : time : %d count : %d\n", data.time, data.count) ;
				}
				else
					puts ("No input.") ;
				break ;
			case BEST_FIT :
				if (TRUE == index)
				{
					data = bestFit (input, size) ;
					printf ("Best fit : time : %d count : %d\n", data.time, data.count) ;
				}
				else
					puts ("No input.") ;
				break ;
			case FIRST_FIT_DECREASING :
				if (TRUE == index)
				{
					data = firstFitDecreasing (input, size) ;
					printf ("FIRST_FIT_DECREASING : time : %d count : %d\n", data.time, data.count) ;
				}
				else
					puts ("No input.") ;
				break ;
			case BEST_FIT_DECREASING :
				if (TRUE == index)
				{
					data = bestFitDecreasing (input, size) ;
					printf ("BEST_FIT_DECREASING : time : %d count : %d\n", data.time, data.count) ;
				}
				else
					puts ("No input.") ;
				break ;
			case UNDEFINITION :
			 puts ("Wrong input.") ;
		}
	}

	return 0 ;
}

int showMenuAndGetChoice (void)
{
	int choice ;

	puts ("-----Please choose what you want to do.-----") ;
	puts ("1).Import data.") ;
	puts ("2).Next fit.") ;
	puts ("3).First fit.") ;
	puts ("4).Best fit.") ;
	puts ("5).First fit decreasing.") ;
	puts ("6).Best fit decreasing.") ;
	puts ("0).Quit.") ;
	printf ("( )\b\b") ;
	scanf ("%d", &choice) ;
	eatLine () ;
	switch (choice)
	{
		case QUIT :
			 return QUIT ;
		case IMPORT_DATA :
			 return IMPORT_DATA ;
		case NEXT_FIT :
			 return NEXT_FIT ;
		case FIRST_FIT :
			 return FIRST_FIT ;
		case BEST_FIT :
			 return BEST_FIT ;
		case FIRST_FIT_DECREASING :
			 return FIRST_FIT_DECREASING ;
		case BEST_FIT_DECREASING :
			 return BEST_FIT_DECREASING ;
		default	:
			 return UNDEFINITION ;
	}
}

void eatLine (void)
{
	while (getchar () != '\n')
		continue ;
}

int getInput (int * const input, const int size)
{
	int i = 0 ;

	puts ("Import data one by one please, input 'q' finishes the input.") ;
	fputs ("Please import data:", stdout) ;
	while (scanf ("%d", input + i) && i < size)
	{
		eatLine () ;
		fputs ("Please import next data:", stdout) ;
		i++ ;
	}
	eatLine () ;
	
	return i ;
}

Data nextFit (const int * const input, const int size)
{
	Queue queue ;
	Item item ;
	Data data ;
	int i, time = 0 ;

	Initialize_Q (&queue) ;
	
	for (i = 0; i < size; i++)
	{
		item.current = input[i] ;
		item.gross = GROSS ;
		item.leavings = item.gross - item.current ;
		if (TRUE == addToLastNode (&item, queue -> rear))
			time++ ;
		else
		{
			Insert_Q (&queue, &item) ;
			time += 2 ;
		}
	}
	data.time = time ;
	data.count = queue -> current ;
	Release_Q (&queue) ;

	return data ;
}

Data firstFit (const int * const input, const int size)
{
	Queue queue ;
	Item item ;
	Data data ;
	int i, time = 0 ;

	Initialize_Q (&queue) ;
	for (i = 0; i < size; i++)
	{
		item.current = input[i] ;
		item.gross = GROSS ;
		item.leavings = item.gross - item.current ;
		if (TRUE == addToExistingNode (&item, queue -> front))
			time++ ;
		else
		{
			Insert_Q (&queue, &item) ;
			time += 2 ;
		}
	}
	data.time = time ;
	data.count = queue -> current ;
	Release_Q (&queue) ;

	return data ;
}

Data bestFit (const int * const input, const int size)
{
	Queue queue ;
	Item item ;
	Data data ;
	int i, time = 0 ;

	Initialize_Q (&queue) ;
	for (i = 0; i < size; i++)
	{
		item.current = input[i] ;
		item.gross = GROSS ;
		item.leavings = item.gross - item.current ;
		if (TRUE == addToBestNode (&item, &queue))
			time++ ;
		else
		{
			Insert_Q (&queue, &item) ;
			time += 2 ;
		}
	}
	data.time = time ;
	data.count = queue -> current ;
	Release_Q (&queue) ;

	return data ;
}

Data firstFitDecreasing (const int * const input, const int size)
{
	Queue queue ;
	Item item ;
	Data data ;
	int * ordered ;
	int i, time = 0 ;

	ordered = (int *) malloc (sizeof (int) * size) ;
	if (NULL == ordered)
	{
		data.time = 0 ;
		data.count = 0 ;
		return data ;
	}
	for (i = 0; i < size; i++)
		ordered[i] = input[i] ;
	shellSort_Int (ordered, size) ;

	Initialize_Q (&queue) ;
	for (i = 0; i < size; i++)
	{
		item.current = input[i] ;
		item.gross = GROSS ;
		item.leavings = item.gross - item.current ;
		if (TRUE == addToExistingNode (&item, queue -> front))
			time++ ;
		else
		{
			Insert_Q (&queue, &item) ;
			time += 2 ;
		}
	}
	data.time = time ;
	data.count = queue -> current ;
	free (ordered) ;
	Release_Q (&queue) ;

	return data ;
}

Data bestFitDecreasing (const int * const input, const int size)
{
	Queue queue ;
	Item item ;
	Data data ;
	int * ordered ;
	int i, time = 0 ;

	ordered = (int *) malloc (sizeof (int) * size) ;
	if (NULL == ordered)
	{
		data.time = 0 ;
		data.count = 0 ;
		return data ;
	}
	for (i = 0; i < size; i++)
		ordered[i] = input[i] ;
	shellSort_Int (ordered, size) ;

	Initialize_Q (&queue) ;
	for (i = 0; i < size; i++)
	{
		item.current = input[i] ;
		item.gross = GROSS ;
		item.leavings = item.gross - item.current ;
		if (TRUE == addToBestNode (&item, &queue))
			time++ ;
		else
		{
			Insert_Q (&queue, &item) ;
			time += 2 ;
		}
	}
	data.time = time ;
	data.count = queue -> current ;
	free (ordered) ;
	Release_Q (&queue) ;

	return data ;
}

Bool addToLastNode (const Item * const pi, Node * const pn)
{
	if (NULL == pn || pn -> item.leavings < pi -> current)
		return FALSE ;
	else
	{
		pn -> item.current += pi -> current ;
		pn -> item.leavings -= pi -> current ;
		return TRUE ;
	}
}

Bool addToExistingNode (const Item * const pi, Node * const pn)
{
	if (NULL == pn)
		return FALSE ;
	else
	{
		if (pn -> item.leavings < pi -> current)
			return addToExistingNode (pi, pn -> next) ;
		else
		{
			pn -> item.current += pi -> current ;
			pn -> item.leavings -= pi -> current ;
			return TRUE ;
		}
	}
}

Bool addToBestNode (const Item * const pi, Queue * const pq)
{
	Node * * ordered, * scan ;
	int i, lenth = (*pq) -> current ;

	if (IsEmpty_Q (pq))
		return FALSE ;
	ordered = (Node * *) malloc (sizeof (Node *) * lenth) ;
	if (NULL == ordered)
		return FALSE ;
	for (i = 0, scan = (*pq) -> front; i < lenth; i++)
	{
		ordered[i] = scan ;
		scan = scan -> next ;
	}
	shellSort_PointToNode (ordered, lenth) ;
	for (i = 0; i < lenth; i++)
	{
		if (ordered[i] -> item.leavings >= pi -> current)
		{
			ordered[i] -> item.current += pi -> current ;
			ordered[i] -> item.leavings -= pi -> current ;
			free (ordered) ;
			return TRUE ;
		}
	}
	free (ordered) ;
	
	return FALSE ;
}

void shellSort_PointToNode (Node * * const input, const int size)
{
	Node * temp ;
	int i, j, increment ;

	for (increment = size / 2; increment > 0; increment /= 2)
	{
		for (i = increment; i < size; i++)
		{
			temp = input[i] ;
			for (j = i; j >= increment; j -= increment)
			{
				if (temp -> item.leavings < input[j - increment] -> item.leavings)
					input[j] = input[j - increment] ;
				else
					break ;
			}
			input[j] = temp ;
		}
	}
}

void shellSort_Int (int * const input, const int size)
{
	int temp ;
	int i, j, increment ;

	for (increment = size / 2; increment > 0; increment /= 2)
	{
		for (i = increment; i < size; i++)
		{
			temp = input[i] ;
			for (j = i ; j >= increment; j -= increment)
			{
				if (temp < input[j - increment])
					input[j] = input[j - increment] ;
				else
					break ;
			}
			input[j] = temp ;
		}
	}
}