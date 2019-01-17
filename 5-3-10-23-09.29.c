/*	5-3-10-23-09.29.c -- �����µ�����	*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OCCUPANCY 1
#define PRIME 7
#define SIZE 20

int main (void) ;
void menu (void) ;
void eat_line (void) ;
int get_array_size (void) ;
int get_table_size (void) ;
int * generate_random_array (const int size) ;
void print_array (const int * array, const int array_size) ;
int hash (const int key, const int size) ;
int hash2 (const int key, const int prime) ;
int leaner (const int i) ;
int square (const int i) ;
int twice (const int i, const int key, const int prime) ;
int imitate_leaner (const int * array, const int array_size, const int table_size) ;
int imitate_square (const int * array, const int array_size, const int table_size) ;
int imitate_double (const int * array, const int array_size, const int table_size) ;

int main (void)
{
	int * array = NULL ;
	int array_size = 0, table_size = 0, choice ;


	menu () ;
	while (1 == scanf ("%d", &choice))
	{
		switch (choice)
		{
			case 1:	array_size = get_array_size () ;
					break ;
			case 2:	table_size = get_table_size () ;
					break ;
			case 3:	if (0 == array_size)
					{
						puts ("�������������С") ;
						break ;
					}
					array = generate_random_array (array_size) ;
					if (NULL == array)
						puts ("�����������ʧ��") ;
					else
						puts ("����������ɳɹ�") ;
					break ;
			case 4: if (NULL == array)
						puts ("����Ϊ��") ;
					else
						print_array (array, array_size) ;
					break ;
			case 5:	if (NULL == array)
						puts ("���������������") ;
					else if (0 == table_size)
						puts ("��ָ����Ĵ�С") ;
					else
						printf ("����̽�ⷨɢ�г�ͻ����Ϊ:%d\n", imitate_leaner (array, array_size, table_size)) ;
					break ;
			case 6:	if (NULL == array)
						puts ("���������������") ;
					else if (0 == table_size)
						puts ("��ָ����Ĵ�С") ;
					else
						printf ("ƽ��̽�ⷨɢ�г�ͻ����Ϊ:%d\n", imitate_square (array, array_size, table_size)) ;
					break ;
			case 7:	if (NULL == array)
						puts ("���������������") ;
					else if (0 == table_size)
						puts ("��ָ����Ĵ�С") ;
					else
						printf ("˫ɢ�г�ͻ����Ϊ:%d\n", imitate_double (array, array_size, table_size)) ;
					break ;
			default:puts ("����ѡ������") ;
		}
		menu () ;
	}
	free (array) ;

	return 0 ;
}

void menu (void)
{
	puts ("<����̽�ⷨɢ��, ƽ��̽�ⷨɢ��, ˫ɢ�г�ͻ����������>") ;
	puts ("--------------------------------") ;
	puts ("|1): �����������Ĵ�С        |") ;
	puts ("|2): �����Ĵ�С              |") ;
	puts ("|3): ����һ���µ��������      |") ;
	puts ("|4): �鿴�������              |") ;
	puts ("|5): �鿴����̽�ⷨɢ�г�ͻ����|") ;
	puts ("|6): �鿴ƽ��̽�ⷨɢ�г�ͻ����|") ;
	puts ("|7): �鿴˫ɢ�г�ͻ����        |") ;
	puts ("|Q): �˳�����                  |") ;
	puts ("--------------------------------") ;
	printf ("( )\b\b") ;
}

void eat_line (void)
{
	while (getchar () != '\n')
		continue ;
}

int get_array_size (void)
{
	int array_size ;

	do
	{
		eat_line () ;
		fputs ("�������������Ĵ�С:", stdout) ;
	}
	while (scanf ("%d", &array_size) != 1 || array_size < 1)
		;
	puts ("�����������") ;

	return array_size ;
}

int get_table_size (void)
{
	int table_size ;

	do
	{
		eat_line () ;
		fputs ("�������Ĵ�С:", stdout) ;
	}
	while (scanf ("%d", &table_size) != 1 || table_size < 1)
		;
	puts ("�����������") ;

	return table_size ;
}

int * generate_random_array (const int size)
{
	int * arr ;
	int count ;

	arr = (int *) malloc (sizeof (int) * size) ;
	if (NULL == arr)
		return NULL ;
	srand ((unsigned int) time (NULL)) ;
	for (count = 0; count < size; count++)
		arr[count] = rand () ;

	return arr ;
}

void print_array (const int * array, const int array_size)
{
	int count ;

	for (count = 0; count < array_size; count++)
		printf ("%d ", array[count]) ;
	putchar ('\n') ;
}

int hash (const int key, const int size)
{
	return key % size ;
}

int hash2 (const int key, const int prime)
{
	return prime - (key % prime) ;
}

int leaner (const int i)
{
	return i ;
}

int square (const int i)
{
	return i * i ;
}

int twice (const int i, const int key, const int prime)
{
	return i * hash2 (key, prime) ;
}

int imitate_leaner (const int * array, const int array_size, const int table_size)
{
	int * table ;
	int count, key, hash_value, index, i, counter ;

	table = (int *) calloc (sizeof (int), table_size) ;
	if (NULL == table)
	{
		printf ("Out of space betide \"imitata_leaner\"\n") ;
		return 0 ;
	}
	for (count = 0, i = 0, counter = 0; count < array_size; count++, i = 0)
	{
		key = array[count] ;
		hash_value = hash (key, table_size) ;
		index = (hash_value + leaner (i++)) % table_size ;
		while (OCCUPANCY == table[index])
		{
			counter++ ;
			if (i < table_size)
				index = (hash_value + leaner (i++)) % table_size ;
			else
				break ;
		}
		table[index] = OCCUPANCY ;
	}
	free (table) ;
	
	return counter ;
}
int imitate_square (const int * array, const int array_size, const int table_size)
{
	int * table ;
	int count, key, hash_value, index, i, critical, counter ;

	table = (int *) calloc (sizeof (int), table_size) ;
	if (NULL == table)
	{
		printf ("Out of space betide \"imitate_square\"\n") ;
		return 0 ;
	}
	for (count = 0, i = 0, critical = table_size / 2, counter = 0 ; count < array_size; count++, i = 0)
	{
		key = array[count] ;
		hash_value = hash (key, table_size) ;
		index = (hash_value + square (i++)) % table_size ;
		while (OCCUPANCY == table[index])
		{
			counter++ ;
			if (i <= critical)
				index = (hash_value + square (i++)) % table_size ;
			else
				break ;
		}
		table[index] = OCCUPANCY ;
	}
	free (table) ;
	
	return counter ;
}

int imitate_double (const int * array, const int array_size, const int table_size)
{
	int * table ;
	int count, key, hash_value, index, i, prime, counter ;

	table = (int *) calloc (sizeof (int), table_size) ;
	if (NULL == table)
	{
		printf ("Out of space betide \"imitate_double\"\n") ;
		return 0 ;
	}
	for (count = 0, i = 0, counter = 0, prime = PRIME; count < array_size; count++, i = 0)
	{
		key = array[count] ;
		hash_value = hash (key, table_size) ;
		index = (hash_value + twice (i++, key, prime)) % table_size ;
		while (OCCUPANCY == table[index])
		{
			counter++ ;
			if (i < table_size)
				index = (hash_value + twice (i++, key, prime)) % table_size ;
			else
				/*	���������, �˳�whileѭ��.֮������Ҳ��ʧ��.���ǻ�ñ�Ĳ���С	*/
				break ;
		}
		table[index] = OCCUPANCY ;
	}
	free (table) ;
	
	return counter ;
}