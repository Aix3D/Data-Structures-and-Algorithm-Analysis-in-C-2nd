/*	Separate_Chaining_Hash -- 分离链接散列表实现文件	*/
#include <stdio.h>
#include <stdlib.h>
#include "Separate_Chaining_Hash.h"

/*	局部数据类型定义	*/

typedef struct pair
{
	ListNode * parent ;
	ListNode * current ;
} Pair ;

/*	局部函数声明	*/

int Get_Prime_Size (const int size) ;
int Is_A_Prime_Number (const int number) ;
ListNode * Make_Node (const Item item) ;
Pair Seek_and_Return (const Item item, const int key, const HashTable * const ph) ;
void Work_For_Release (ListNode * node) ;

/*	接口函数定义	*/

HashTable InitializeTable (const int size)
{
	HashTable h ;
	int count ;

	if (size > MAXTABLESIZE)
	{
		puts ("Table size is too big!") ;
		return NULL ;
	}
	h = (struct hashtable *) malloc (sizeof (struct hashtable)) ;
	if (NULL == h)
		puts ("Out of space![1]") ;
	h -> size = Get_Prime_Size (size) ;
	h -> lists = (Header *) malloc (sizeof (Header) * h -> size) ;
	if (NULL == h -> lists)
		puts ("Out of space![2]") ;
	for (count = 0; count < h -> size; count++)
		h -> lists[count] = NULL ;

	return h ;
}

int Hash (const Item item, const int size)
{
	int hash_value = item ;

	return hash_value % 10 ;
}

Header Find (const Item item, const HashTable h)
{
	ListNode * p ;
	int key = Hash (item, h -> size) ;
	
	p = h -> lists[key] ;
	while (p != NULL && p -> item != item)
		p = p -> next ;

	return p ;
}

int Insert (const Item item, HashTable * const ph)
{
	ListNode * new_node, * location, * record ;
	int key ;

	key = Hash (item, (*ph) -> size) ;
	record = (*ph) -> lists[key] ;
	/*	如果头结点的指针为NULL	*/
	if (NULL == record)
	{
		new_node = Make_Node (item) ;
		if (NULL == new_node)
		{
			puts ("Out of space![3]") ;
			return 0 ;
		}
		(*ph) -> lists[key] = new_node ;
	}
	else
	{
		location = Find (item, *ph) ;
		/*	如果无重复	*/
		if (NULL == location)
		{
			new_node = Make_Node (item) ;
			if (NULL == new_node)
			{
				puts ("Out of space![4]") ;
				return 0 ;
			}
			new_node -> next = (*ph) -> lists[key] ;
			(*ph) -> lists[key] = new_node ;
		}
		else
			/*	不进行重复添加	*/
			return 0 ;
	}

	return 1 ;
}

int Delete (const Item item, HashTable * const ph)
{
	ListNode * temp ;
	Pair pair ;
	int key ;

	key = Hash (item, (*ph) -> size) ;
	pair = Seek_and_Return (item, key, ph) ;
	if (pair.current != NULL)
	{
		temp = pair.current ;
		if (pair.parent != NULL)
			pair.parent -> next = pair.current -> next ;
		else
			(*ph) -> lists[key] = pair.current -> next ;
		free (temp) ;
		return 1 ;
	}
	else
		return 0 ;

}

void Traversal (const HashTable * const ph, void (* pfun) (const ListNode * const pnode))
{
	ListNode * scan ;
	int count, size ;

	for (count = 0, size = (*ph) -> size; count < size; count++)
	{
		if ((*ph) -> lists[count] != NULL)
		{
			scan = (*ph) -> lists[count] ;
			while (scan != NULL)
			{
				(* pfun) (scan) ;
				scan = scan -> next ;
			}
		}
	}
}

void Release (HashTable * ph)
{
	int count, size ;

	for (count = 0, size = (*ph) -> size; count < size; count++)
	{
		if ((*ph) -> lists[count] != NULL)
			Work_For_Release ((*ph) -> lists[count]) ;
	}
	free ((*ph) -> lists) ;
	free (*ph) ;
}


/*	局部函数定义	*/

int Get_Prime_Size (const int size)
{
	int temp = size ;

	while (!Is_A_Prime_Number (temp))
		temp++ ;

	return temp ;
}

int Is_A_Prime_Number (const int number)
{
	int count, value ;

	if (number < 2)
		puts ("Input wrong!") ;
	value = number / 2 + 1 ;
	for (count = 2; count < value; count++)
		if (0 == number % count)
			return 0 ;

	return 1 ;
}

ListNode * Make_Node (const Item item)
{
	ListNode * new_node ;

	new_node = (ListNode *) malloc (sizeof (ListNode)) ;
	if (NULL == new_node)
		return NULL ;
	else
	{
		new_node -> item = item ;
		new_node -> next = NULL ;
	}

	return new_node ;
}

Pair Seek_and_Return (const Item item, const int key, const HashTable * const ph)
{
	Pair pair ;
	pair.parent = NULL ;
	pair.current = (*ph) -> lists[key] ;

	while (pair.current != NULL && pair.current -> item != item)
	{
		pair.parent = pair.current ;
		pair.current = pair.current -> next ;
	}

	return pair ;
}

void Work_For_Release (ListNode * node)
{
	if (node != NULL)
		Work_For_Release (node -> next) ;
	else
		free (node) ;
}