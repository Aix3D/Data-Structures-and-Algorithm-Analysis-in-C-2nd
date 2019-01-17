/*	SkipList.h -- 跳跃表头文件	*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define FALSE (0)
#define TRUE (1)
#define UNDECIDED (32768)

#define A (48271L)
#define M (2147486647L)
#define Q (M / A)
#define R (M % A)
#define MASK (0x01)

#define DEBUG (UNDECIDED)

/*	数据类型定义	*/

typedef int Item ;
typedef struct node
{
	Item item ;
	struct node * * next ;
	int height ;
	int times ;
} Node ;
typedef struct skiplist
{
	Node * head ;
	int current ;
	int capacity ;
	int maximum_of_height ;
} * SkipList ;

typedef int BOOL ;

/*	全局变量	*/

long int Seed ;

/*	接口函数声明	*/

/*	操作:	初始化种子	*/
/*	操作前:	种子值不确定*/
/*	操作后:	种子被初始化*/
/*	时间复杂度: O (1)	*/
void InitializSeed_S (const long int initial_value) ;

/*	操作:	产生 FALSE 值或者 TRUE 值并返回	*/
/*	操作前:	种子已被初始化	*/
/*	操作:	产生 FALSE 值或者 TRUE 值并返回	*/
/*	时间复杂度:	O (1)	*/
BOOL Random_S (void) ;

/*	操作:	创建并初始化一个跳跃表	*/
/*	操作前:	psl 指向一个跳跃表, capacity 指示该表的最大大小	*/
/*	操作后:	如果内存分配成功, 创建该跳跃表, 返回 TRUE ; 否则返回 FALSE	*/
/*	时间复杂度:	O (1)	*/
BOOL Initialize_S (SkipList * const psl, const int capacity) ;

/*	操作:	确定一个跳跃表是否为空	*/
/*	操作前:	psl 指向一个已初始化的跳跃表	*/
/*	操作后:	如果该跳跃表为空, 返回 TRUE ; 否则返回 FALSE	*/
/*	时间复杂度:	O (1)	*/
BOOL IsEmpty_S (const SkipList * const psl) ;

/*	操作:	确定一个跳跃表是否已满	*/
/*	操作前:	psl 指向一个已初始化的跳跃表	*/
/*	操作后:	如果该跳跃表已满, 返回 TRUE ; 否则返回 FALSE	*/
/*	时间复杂度:	O (1)	*/
BOOL IsFull_S (const SkipList * const psl) ;

/*	操作:	确定指定数据是否在跳跃表中	*/
/*	操作前:	psl 指向一个已初始化的跳跃表, pi 指向指定数据	*/
/*	操作后:	如果 pi 指向的数据在该表中, 返回 TRUE ; 否则返回 FALSE	*/
/*	时间复杂度:	O (log N)	*/
BOOL Find_S (const SkipList * const psl, const Item * const pi) ;

/*	操作:	向跳跃表中插入指定数据	*/
/*	操作前:	psl 指向一个已初始化的跳跃表, pi 指向指定数据	*/
/*	操作后:	如果该跳跃表未满 && 内存分配成功, 在该跳跃表找插入该数据, 返回 TRUE ; 否则返回 FALSE	*/
/*	时间复杂度: O (log N)	*/
BOOL Insert_S (const SkipList * const psl, const Item * const pi) ;

/*	操作:	从跳跃表中删除指定数据	*/
/*	操作前:	psl 指向一个已初始化的跳跃表, pi 指向指定数据	*/
/*	操作后:	如果表不为空 && 该数据在该跳跃表中, 从该跳跃表中删除该数据, 返回 TRUE ; 否则返回 FALSE	*/
/*	时间复杂度:	O (log N)	*/
BOOL Delete_S (const SkipList * const psl, const Item * const pi) ;

/*	操作:	从头至尾将一个函数作用于跳跃表中所有元素1次	*/
/*	操作前:	psl 指向一个已初始化的跳跃表, pfun 指向一个没有返回值, 接受一个 Node * 类型参数的函数	*/
/*	操作后:	从头至尾将一个函数作用于跳跃表中所有元素1次	*/
/*	时间复杂度: O (N)	*/
void Traversal_S (const SkipList * const psl, void (* pfun) (const Node * const pn)) ;

/*	操作:	释放一个跳跃表占用的内存空间	*/
/*	操作前:	psl 指向一个已初始化的跳跃表	*/
/*	操作后:	该跳跃表所占内存空间被释放	*/
/*	时间复杂度:	O (N)	*/
void Release_S (const SkipList * const psl) ;