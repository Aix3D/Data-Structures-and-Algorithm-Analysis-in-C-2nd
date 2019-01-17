/*	10-35-11-02-08-20.11.c -- 第十章第三十五题	*/
#include <stdio.h>

#define FALSE (0)
#define TRUE (1)
#define A (48271L)
#define M (2147486647L)
#define Q (M / A)
#define R (M % A)

unsigned long int Seed ;

int main (void) ;
int eatEnter (void) ;
void initialize (unsigned long int initial_value) ;
double random (void) ;

int main (void)
{
	unsigned long int initial_value ;
	char ch ;

	printf ("Please input a initial value (>= 0, enter 'q' to quit.):") ;
	while (scanf ("%lu", &initial_value) != 0)
	{
		printf ("Initial value has been initialized is : %lu\n", initial_value) ;
		eatEnter () ;
		initialize (initial_value) ;
		puts ("Enter 'q' to input a new initial value and enter any key else to generate a random value again.") ;
		while ((ch = getchar ()) != 'q')
		{
			if (TRUE == eatEnter ())
				break ;
			printf ("It is %lf.\n", random ()) ;
		}
		printf ("Please input a initial value (>= 0, enter 'q' to quit.):") ;
	}
			
	return 0 ;
}

int eatEnter (void)
{
	if ('q' == getchar ())
		return TRUE ;
	else
		return FALSE ;
}

void initialize (unsigned long int initial_value)
{
	Seed = initial_value ;
}

double random (void)
{
	unsigned long int temp_seed ;

	temp_seed = A * (Seed % Q) - R * (Seed / Q) ;
	if (temp_seed >= 0)
		Seed = temp_seed ;
	else
		Seed = temp_seed + M ;

	return (double) Seed / M ;
}