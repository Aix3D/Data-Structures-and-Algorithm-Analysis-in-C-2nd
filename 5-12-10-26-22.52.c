/*	5-12-10-26-22.52.c -- 第五章第十二题	*/
/*	这B玩意花了我1小时,我不明白题出的想考查什么内容.我对基本功能做了简化,感到内疚	*/
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

	/*	跳过前f行	*/
	for (count = 1; count < f; count++)
	{
		while ((ch = getc (source)) != ENTER)
			if (EOF == ch)
				break ;
	}
	/*	处理第一行	*/
	record = 1 ;
	fprintf (target, "%d%c", record, enter) ;
	/*	处理主体	*/
	while (count <= linage)
	{
		record = record + d ;
		fprintf (target, "%d%c", record, enter) ;
		count++ ;
	}
}