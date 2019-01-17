/*	5-12-10-26-22.52.c -- �����µ�ʮ����	*/
/*	��B���⻨����1Сʱ,�Ҳ�����������뿼��ʲô����.�ҶԻ����������˼�,�е��ھ�	*/
#include <stdio.h>
#include <limits.h>

#define ENTER '\n'

int main (void) ;
void create_file (FILE * const source, const int linage) ;
void rejigger_file (FILE * const source, FILE * const target, const int linage, const long int f, const long int d) ;

int main (void)
{
	FILE * source, * target ;
	long int f = 50, d = 7;
	int linage = 500 ;
	
	source = fopen ("try.txt", "r") ;
	target = fopen ("target.txt", "w") ;
	create_file (source, linage) ;
	rejigger_file (source, target, linage, f, d) ;
	fclose (source) ;
	fclose (target) ;

	return 0 ;
}

void create_file (FILE * const source, const int linage)
{
	int count ;

	for (count = 1; count <= linage; count++)
		fprintf (source, "%d\n", count) ;
}

void rejigger_file (FILE * const source, FILE * const target, const int linage, const long int f, const long int d)
{
	int count, record, enter = ENTER ;
	char ch ;

	/*	����ǰf��	*/
	for (count = 1; count < f; count++)
	{
		while ((ch = getc (source)) != ENTER)
			if (EOF == ch)
				break ;
	}
	/*	�����һ��	*/
	record = 1 ;
	fprintf (target, "%d%c", record, enter) ;
	/*	��������	*/
	while (count <= linage)
	{
		record = record + d ;
		fprintf (target, "%d%c", record, enter) ;
		count++ ;
	}
}