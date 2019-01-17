/*	5-7-10-24-00.29 -- 第五章第七题	*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define USED 1
#define LEISURE 0

typedef int Item ;
typedef struct node
{
	Item coefficent ;		/*	系数	*/
	Item power ;			/*	指数	*/
	struct node * next ;
} Node ;					/*	结点,可用作多项式链表结点和表的元素	*/
typedef struct linkedlist
{
	Node * noumenon ;		/*	指向结点的指针	*/
	int sum_of_power ;		/*	指数和	*/
} * LinkedList ;
typedef struct cell
{
	Item coefficent ;
	Item power ;
	int condition ;
} Cell ;
typedef struct hashtable
{
	int size ;				/*	表的大小	*/
	Cell * cell ;			/*	指向元素的指针	*/
} * HashTable ;

int main (void) ;
int hash (const int key, const int size) ;
int get_random_coefficent (const int max) ;
int get_random_power (const int max) ;
LinkedList create_list (const int lenth, const int c_max, const int p_max) ;
HashTable create_table (const int size) ;
void print_multinomial (Node * const multinomial) ;
void print_table (const HashTable * const ph) ;
void Release_list (const LinkedList * const pl) ;
void Release_table (const HashTable * const ph) ;

int main (void)
{
	LinkedList m1, m2 ;
	Node * scan_m1, * scan_m2 ;
	Cell * temp ;
	HashTable h ;
	int lenth_1, lenth_2, c_max_1, c_max_2, p_max_1, p_max_2, table_size, key ;

	lenth_1 = 7 ;				/*	多项式1项数	*/
	c_max_1 = 50 ;				/*	多项式1最高系数	*/
	p_max_1 = 12 ;				/*	多项式1最高指数	*/
	lenth_2 = 9 ;				/*	多项式2项数	*/
	c_max_2 = 12 ;				/*	多项式2最高系数	*/
	p_max_2 = 7 ;				/*	多项式2最高指数	*/

	m1 = create_list (lenth_1, c_max_1, p_max_1) ;
	m2 = create_list (lenth_2, c_max_2, p_max_2) ;
	table_size = p_max_1 + m2 -> sum_of_power + 1 ;
	h = create_table (table_size) ;
	for (scan_m1 = m1 -> noumenon; scan_m1 != NULL; scan_m1 = scan_m1 -> next)
	{
		for (scan_m2 = m2 -> noumenon; scan_m2 != NULL; scan_m2 = scan_m2 -> next)
		{
			scan_m1 -> coefficent *= scan_m2 -> coefficent ;
			scan_m1 -> power += scan_m2 -> power ;
			key = hash (scan_m1 -> power, table_size) ;
			temp = &h -> cell[key] ;
			if (LEISURE == temp -> condition)
			{
				temp -> coefficent = scan_m1 -> coefficent ;
				temp -> power = scan_m1 -> power ;
				temp -> condition = USED ;
			}
			else
				temp -> coefficent += scan_m1 -> coefficent ;
		}
	}
	print_table (&h) ;

	Release_list (&m1) ;
	Release_list (&m2) ;
	Release_table (&h) ;

	return 0 ;
}

int hash (const int key, const int size)
{
	return key % size ;
}

int get_random_coefficent (const int max)
{
	return rand () % max + 1 ;
}

int get_random_power (const int max)
{
	return rand () % max + 1 ;
}

LinkedList create_list (const int lenth, const int c_max, const int p_max)
{
	LinkedList list ;
	Node * new_node, * parent = NULL ;
	int count, sum_of_power = 0 ;

	list = (struct linkedlist *) malloc (sizeof (struct linkedlist)) ;

	for (count = 0; count < lenth; count++)
	{
		new_node = (Node *) malloc (sizeof (Node)) ;
		if (NULL == new_node)
			puts ("Out of space[1]") ;
		if (parent != NULL)
			parent -> next = new_node ;
		else
			list -> noumenon = new_node ;
		new_node -> coefficent = get_random_coefficent (c_max) ;
		new_node -> power = get_random_coefficent (p_max) ;
		sum_of_power += new_node -> power ;
		parent = new_node ;
	}
	parent -> next = NULL ;
	list -> sum_of_power = sum_of_power ;

	return list ;
}

HashTable create_table (const int size)
{
	HashTable h ;
	int count ;

	h = (struct hashtable *) malloc (sizeof (struct hashtable)) ;
	if (NULL == h)
		puts ("Out of space[2]") ;
	h -> cell = (Cell *) malloc (sizeof (Cell) * size) ;
	if (NULL == h -> cell)
		puts ("Out of space[3]") ;
	h -> size = size ;
	for (count = 0; count < size; count++)
		h -> cell[count].condition = LEISURE ;

	return h ;
}


void print_multinomial (Node * const multinomial)
{
	Node * scan = multinomial ;
	
	while (scan)
	{
		printf ("[系数:%-30d 指数:%-10d]\n", scan -> coefficent, scan -> power) ;
		scan = scan -> next ;
	}
	putchar ('\n') ;
}

void print_table (const HashTable * const ph)
{
	int count, size = (*ph) -> size ;
	Cell temp ;

	for (count = 0; count < size; count++)
	{
		temp = (*ph) -> cell[count] ;
		if (USED == temp.condition)
			printf ("[系数:%-30d指数:%-10d]\n", temp.coefficent, temp.power) ;
	}
}

void Release_list (const LinkedList * const pl)
{
	Node * scan = (*pl) -> noumenon, * temp ;
	
	while (scan)
	{
		temp = scan ;
		scan = scan -> next ;
		free (temp) ;
	}
	free (*pl) ;
}

void Release_table (const HashTable * const ph)
{
	free ((*ph) -> cell) ;
	free (*ph) ;
}