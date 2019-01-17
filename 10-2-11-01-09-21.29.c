/*	10-2-11-01-09-21.29.c -- 第十章第二题	*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE (5)

typedef struct element
{
	int number ;
	int value ;
	int time ;
} Element ;

int main (void) ;
void processInput (Element * const input, const int size, const int max_value) ;
int earnMaxMenoy (Element * const input, const int size) ;
void printTurn (const Element * const input, const int size) ;
void insertSort (Element * const input, const int size) ;
int getRandomValue (const int max) ;

int main (void)
{
	Element input[SIZE] ;
	int size = SIZE, max_value = 5 ;

	/*	Get the element	*/
	processInput (input, size, max_value) ;
	printf ("The earnings is :$%-4d.\n", earnMaxMenoy (input, size)) ;
	printTurn (input, size) ;

	return 0 ;
}

void processInput (Element * const input, const int size, const int max_value)
{
	int i ;

	srand ((unsigned int) time (NULL)) ;
	for (i = 0; i < size; i++)
	{
		input[i].number = i + 1 ;
		input[i].value = getRandomValue (max_value) ;
		input[i].time = input[i].value ;
	}
	insertSort (input, size) ;

}

int earnMaxMenoy (Element * const input, const int size)
{
	int time = 0, money = 0 ;
	int i ;

	for (i = 0; i < size; i++)	/*	";" Fuck!	*/
	{
		/*	Preformative!	*/
		if (++time <= input[i].time)
			money += input[i].value ;
	}

	return money ;
}

void printTurn (const Element * const input, const int size)
{
	int i ;

	puts ("For earn maximum money as possible, the order is:") ;
	for (i = 0; i < size; i++)
		printf ("%-4d", input[i].number) ;
	putchar ('\n') ;

}

/*	I've forgot it!	*/
void insertSort (Element * const input, const int size)
{
	Element temp ;
	int i, j ;

	for (i = 1; i < size; i++)
	{
		temp = input[i] ;
		for (j = i; j > 0 && input[j - 1].value > temp.value; j--)
			input[j] = input[j - 1] ;
		input[j] = temp ;
	}
}

int getRandomValue (const int max)
{
	return rand () % max + 1 ;
}