/*	interpret.c	*/
#include <stdio.h>

#define TRUE (1)
#define FALSE (0)
#define MASK (~(1 << 31))
#define WEIGHT (1000)
#define NEWLINE ('\n')
#define COMMA (',')
#define EXCLAMATION_MARK ('!')
#define PERIOD ('.')

int main (void) ;
int findPunctuation (const char character) ;
int process (const char left, const char right) ;

int main (void)
{
	FILE * source, * target ;
	char left, right ;
	int value, index ;

	source = fopen ("source.txt", "r") ;
	if (NULL == source)
	{
		puts ("Can't find source.") ;
		return 0 ;
	}
	target = fopen ("target.txt", "w") ;
	if (NULL == target)
	{
		puts ("Can't create target.") ;
		fclose (source) ;
		return 0 ;
	}
	while ((left = getc (source)) != EOF && (right = getc (source)) != EOF)
	{
		if (findPunctuation (left))
		{
			index = TRUE ;
			fprintf (target, "%c", left) ;
		}
		if (findPunctuation (right))
		{
			index = TRUE ;
			fprintf (target, "%c", right) ;
		}
		if (TRUE == index)
		{
			index = FALSE ;
			continue ;
		}
		value = process (left, right) ;
		fprintf (target, "%d ", value) ;
	}
	if (EOF == right)
	{
		if (TRUE == findPunctuation (left))
			fprintf (target, "%c", left) ;
		else
			fprintf (target, "%d ", process (left, EOF)) ;
	}
	value = EOF ;
	fprintf (target, "%c", value) ;

	fclose (source) ;
	fclose (target) ;

	printf ("Consummation!\nEnter any key to quit.\n") ;
	getchar () ;

	return 0 ;
}

int findPunctuation (const char character)
{
	switch (character)
	{
		case NEWLINE : return TRUE ;
		case COMMA : return TRUE ;
		case EXCLAMATION_MARK : return TRUE ;
		case PERIOD : return TRUE ;
		default : return FALSE ;
	}
}
int process (const char left, const char right)
{
	int value = (int) left + (int) right ;

	value &= MASK ;

	return value % WEIGHT ;
}