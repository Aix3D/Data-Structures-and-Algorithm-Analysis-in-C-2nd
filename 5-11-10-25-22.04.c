/*	5-11-10-25-22.04.c -- 第五章第十一题	*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUL '\0'
#define TABLESIZE 887

int main (void) ;
int get_key (char * const s, const int lenth) ;
int hash (const int key, const int size) ;
int get_ansi_value (const char c) ;
int discover_target (const char * const part, const char * const target) ;

int main (void)
{
	char * source, * target, * part ;
	int count, lenth_source, lenth_target, key, value_test, value_target ;

	source = "My name is Palmer Chen.My ideal is that I can write code everyday." ;
	target = "nam" ;

	lenth_source = strlen (source) ;
	lenth_target = strlen (target) ;
	key = get_key (target, lenth_target) ;
	value_target = hash (key, TABLESIZE) ;
	for (count = 0; count < lenth_source; count++)
	{
		key = get_key (source + count, lenth_target) ;
		value_test = hash (key, TABLESIZE) ;
		if (value_test == value_target)
		{
			part = (char *) malloc (sizeof (char) * (lenth_target + 1)) ;
			strncpy (part, source + count, lenth_target) ;
			part[lenth_target] = NUL ;
			if (discover_target (part, target))
			{
				puts (source + count) ;
				break ;
			}
		}
	}

	return 0 ;
}

int get_key (char * const s, const int lenth)
{
	char * scan = s ;
	int count, key ;

	for (count = 0, key = 0; count < lenth; count++)
		key += get_ansi_value (scan[count]) ;

	return key ;
}

int hash (const int key, const int size)
{
	return key % size ;
}

int get_ansi_value (const char c)
{
	int ansi_value = c ;

	return ansi_value ;
}

int discover_target (const char * const part, const char * const target)
{
	int lenth_part, lenth_target, count ;

	lenth_part = strlen (part) ;
	lenth_target = strlen (target) ;
	if (lenth_part == lenth_target)
	{
		for (count = 0; count <= lenth_part; count++)
			if (part[count] != target[count])
				return 0 ;
		return 1 ;
	}

	return 0 ;
}