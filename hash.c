/*	hash.c -- 哈希表实现文件	*/
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

/*	局部函数声明	*/

static int Get_A_Prime (const int number) ;
static int Is_A_Prime (const int number) ;
static int Square (const int i) ;

/*	接口函数定义	*/

int Hash (const Hash_Table * const pht, const Name * const pname)
{
	return *pname * PRIME % (*pht) -> capacity ;
}

int Initialize_H (Hash_Table * const pht, const int capacity)
{
	int real_capacity, i ;

	if (capacity <= 0)
		return 0 ;
	real_capacity = Get_A_Prime (capacity) ;
	*pht = (struct hash_table *) malloc (sizeof (struct hash_table)) ;
	if (NULL == *pht)
		return 0 ;
	(*pht) -> lists = (Cell *) malloc (sizeof (Cell) * real_capacity) ;
	if (NULL == (*pht) -> lists)
	{
		free (*pht) ;
		return 0 ;
	}
	for (i = 0; i < real_capacity; i++)
	{
		(*pht) -> lists[i].entry = EMPTY ;
		(*pht) -> lists[i].name = NUL ;
		(*pht) -> lists[i].be_deleted = FALSE ;
	}
	(*pht) -> current = 0 ;
	(*pht) -> capacity = real_capacity ;

	return 1 ;
}

Cell * Find_H (const Hash_Table * const pht, const Name * const pname)
{
	int hash_value, i = 1, capacity = (*pht) -> capacity ;

	hash_value = Hash (pht, pname) ;
	while (LEGITIMATE == (*pht) -> lists[hash_value].entry && (*pht) -> lists[hash_value].name != *pname)
	{
		putchar ('\a') ;
		hash_value = (hash_value + Square (i++)) % capacity ;
	}

	return (*pht) -> lists + hash_value ;
}

int Insert_H (const Hash_Table * const pht, const Name * const pname, const int index)
{
	Cell * p ;

	if ((*pht) -> current > (*pht) -> capacity / 2 + 1)
		return FAILED ;
	p = Find_H (pht, pname) ;
	if (EMPTY == p -> entry || DELETED == p -> entry)
	{
		p -> entry = LEGITIMATE ;
		p -> name = *pname ;
		p -> index_in_adjacenty_list = index ;
	}
	(*pht) -> current++ ;

	return (p - (*pht) -> lists) / sizeof (Cell) ;
}

int Delete_H (const Hash_Table * const pht, const Name * const pname)
{
	Cell * p ;

	p = Find_H (pht, pname) ;
	if (*pname == p -> name && LEGITIMATE == p -> entry)
	{
		p -> entry = DELETED ;
		(*pht) -> current-- ;
		return 1 ;
	}
	else
		return 0 ;
}

void Release_H (const Hash_Table * const pht)
{
	free ((*pht) -> lists) ;
	free (*pht) ;
}

/*	局部函数定义	*/

static int Get_A_Prime (const int number)
{
	int result = number ;

	while (!Is_A_Prime (result))
		result++ ;

	return result ;
}

static int Is_A_Prime (const int number)
{
	int i, limit ;

	for (i = 2, limit = number / 2 + 1; i <= limit; i++)
	{
		if (0 == number % i)
			return 0 ;
	}

	return 1 ;
}

static int Square (const int i)
{
	return i * i ;
}