/*	7-37-11-27-22.11.c -- 第七章第三十七题	*/
#include <stdio.h>

int main (void) ;

int main (void)
{
	FILE * fpa, * fpb, * fpc ;
	char cha, chb ;

	fpa = fopen ("a.txt", "r") ;
	fpb = fopen ("b.txt", "r") ;
	fpc = fopen ("c.txt", "w") ;
	if (NULL == fpa || NULL == fpb || NULL == fpc)
	{
		puts ("Open file failed.") ;
		return 0 ;
	}
	cha = getc (fpa) ;
	chb = getc (fpb) ;
	while (cha != EOF && chb != EOF)
	{
		if (cha < chb)
		{
			putc (cha, fpc) ;
			cha = getc (fpa) ;
		}
		else
		{
			putc (chb, fpc) ;
			chb = getc (fpb) ;
		}
	}
	while ((cha = getc (fpa)) != EOF)
		putc (cha, fpc) ;
	while ((chb = getc (fpb)) != EOF)
		putc (chb, fpc) ;
	fclose (fpa) ;
	fclose (fpb) ;
	fclose (fpc) ;

	return 0 ;
}
	