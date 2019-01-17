/*	5-13(b)-10-28-21.17.c -- �����µ�ʮ����	*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD 1
#define PREFIX 2
#define ROW 4
#define COLS 4
#define NUL '\0'
#define PF '\n'
#define CONSTANT 5
#define TABLESIZE 107

/*	�������Ͷ���	*/
typedef struct cell
{
	char * word ;
	int word_or_prefix ;
} Cell ;
typedef struct hashtable
{
	int size ;
	Cell * cell ;
} * HashTable ;

/*	ADT����	*/
long int Hash (const char * word, const int size) ;
int InitializeTable (HashTable * const ph, const int size) ;
Cell * Find (const HashTable * const ph, const char * const word) ;
int Insert (const HashTable * const ph, const char * word, const int mode) ;
void Release (const HashTable * const ph) ;
int leaner (const int i) ;

/*	�ֲ���������	*/
int main (void) ;
char * eat_enter (char * const word) ;
void test_and_printf (const HashTable * const ph, const char * const word) ;

int main (void)
{
	HashTable h ;
	FILE * fp ;
	char riddle[ROW][COLS] = {
		"this",
		"wats",
		"oahg",
		"fgdt"
	} ;
	char word[ROW * COLS] ;
	int size = TABLESIZE, lenth = ROW * COLS ;
	int i, j, i_max, j_max, i_temp, j_temp, w ;

	//	��һ���ʵ�������
	InitializeTable (&h, size) ;
	fp = fopen ("word.txt", "r") ;
	while (fgets (word, lenth, fp) != NULL)
	{
		strcpy (word, eat_enter (word)) ;
		if (0 == Insert (&h, word))
			puts ("Insert failed") ;
	}
	fclose (fp) ;
	//	��ʼ����
	for (i = 0, i_max = ROW; i < i_max; i++)
	{
		for (j = 0, j_max = COLS; j < j_max; j++)
		{
			//	��
			for (j_temp = j, w = 0; j_temp >= 0; j_temp--, w++)
			{
				word[w] = riddle[i][j_temp] ;
				word[w + 1] = NUL ;
				test_and_printf (&h, word) ;
			}
			//	��
			for (j_temp = j, w = 0; j_temp < j_max; j_temp++, w++)
			{
				word[w] = riddle[i][j_temp] ;
				word[w + 1] = NUL ;
				test_and_printf (&h, word) ;
			}
			//	��
			for (i_temp = i, w = 0; i_temp >= 0; i_temp--, w++)
			{
				word[w] = riddle[i_temp][j] ;
				word[w + 1] = NUL ;
				test_and_printf (&h, word) ;
			}
			//	��
			for (i_temp = i, w = 0; i_temp < i_max; i_temp++, w++)
			{
				word[w] = riddle[i_temp][j] ;
				word[w + 1] = NUL ;
				test_and_printf (&h, word) ;
			}
			//	����
			for (i_temp = i, j_temp = j, w = 0; i_temp >= 0 && j_temp >= 0; i_temp--, j_temp--, w++)
			{
				word[w] = riddle[i_temp][j_temp] ;
				word[w + 1] = NUL ;
				test_and_printf (&h, word) ;
			}
			//	����
			for (i_temp = i, j_temp = j, w = 0; i_temp >= 0 && j_temp < j_max; i_temp--, j_temp++, w++)
			{
				word[w] = riddle[i_temp][j_temp] ;
				word[w + 1] = NUL ;
				test_and_printf (&h, word) ;
			}
			//	����
			for (i_temp = i, j_temp = j, w = 0; i_temp < i_max && j_temp >= 0; i_temp++, j_temp--, w++)
			{
				word[w] = riddle[i_temp][j_temp] ;
				word[w + 1] = NUL ;
				test_and_printf (&h, word) ;
			}
			//	����
			for (i_temp = i, j_temp = j, w = 0; i_temp < i_max && j_temp < j_max; i_temp++, j_temp++, w++)
			{
				word[w] = riddle[i_temp][j_temp] ;
				word[w + 1] = NUL ;
				test_and_printf (&h, word) ;
			}
		}
	}
	Release (&h) ;
	
	return 0 ;
}

char * eat_enter (char * const word)
{
	int count = 0;

	while (word[count] != PF)
	{
		count++ ;
		if (NUL == word[count])
			return word ;
	}
	word[count] = NUL ;

	return word ;
}

void test_and_printf (const HashTable * const ph, const char * const word)
{
	Cell * cell ;

	cell = Find (ph, word) ;
	if (cell -> word && 0 == strcmp (cell -> word, word))
		printf ("%s\n", word) ;
}

/*	ADT����	*/

long int Hash (const char * word, const int size)
{
	long int hash_value = 0 ;

	while (*word != PF && *word != NUL)
		hash_value = (hash_value << CONSTANT) + *word++ ;

	return hash_value % size ;
}

int InitializeTable (HashTable * const ph, const int size)
{
	int temp ;

	*ph = (struct hashtable *) malloc (sizeof (struct hashtable)) ;
	if (NULL == *ph)
	{
		puts ("Out of space.[1]") ;
		return 0 ;
	}
	temp = sizeof (Cell) ;
	(*ph) -> cell = (Cell *) calloc (temp, size) ;
	if (NULL == (*ph) -> cell)
	{
		puts ("Out of space.[2]") ;
		free (*ph) ;
		return 0 ;
	}
	(*ph) -> size = size ;

	return 1 ;
}

Cell * Find (const HashTable * const ph, const char * const word)
{
	long int hash_value ;
	int size, i, index ;

	size = (*ph) -> size ;
	i = 0 ;
	do
	{
		hash_value = Hash (word, size) ;
		index = (hash_value + leaner (i++)) % size ;
	}
	/*	������Ϊ�ղ����ַ�������ͬ	*/
	while ((*ph) -> cell[index].word != NULL && strcmp (word, (*ph) -> cell[index].word) != 0)
		;

	return (*ph) -> cell + index ;
}

int Insert (const HashTable * const ph, const char * word, const int mode)
{
	Cell * cell ;
	int size = (*ph) -> size ;

	//	����ӻ��з�
	if ('\n' == *word)
		return 0 ;
	cell = Find (ph, word) ;
	if (NULL == cell -> word)
	{
		cell -> word = (char *) malloc (sizeof (char)) ;
		if (NULL == cell -> word)
		{
			puts ("out of space.[4]") ;
			return 0 ;
		}
		strcpy (cell -> word, word) ;
		cell ->
		return 1 ;
	}
	/*	���ظ����	*/

	return 0 ;
}

void Release (const HashTable * const ph)
{
	free ((*ph) -> cell) ;
	free (*ph) ;
}

int leaner (const int i)
{
	return i ;
}