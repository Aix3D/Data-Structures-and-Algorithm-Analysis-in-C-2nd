/*	FibonacciHeap.h -- 斐波那契堆头文件	*/
/*	代码阶段耗时14小时.	2011-03-01-22.32完成	*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*	明显常量定义	*/

#define FALSE (0)
#define TRUE (1)
#define EMPTY (1 << 31)
#define NEGATIVE_INFINTY (1 << 30)
#define BE_RELEASED (1 << 31)

/*	数据类型定义	*/

typedef int BOOL ;

typedef int Item ;
typedef struct node
{
	Item item ;
	struct node * left, * right, * parent, * child ;
	int degree ;
	BOOL index ;
} Node ;
typedef struct fibonacciheap
{
	Node * min ;
	int current ;
} * FibonacciHeap ;

/*	接口函数声明	*/

/*	操作:	创建并初始化一个斐波那契堆	*/
/*	操作前:	pfh 指向一个斐波那契堆	*/
/*	操作后:	如果内存分配成功, 创建并初始化该斐波那契堆, 返回 TRUE ; 否则返回 FALSE ;	*/
/*	摊还时间:	O (1)	*/
BOOL Initialize_F (FibonacciHeap * const pfh) ;

/*	操作:	确定一个斐波那契堆是否为空	*/
/*	操作前:	pfh 指向一个已初始化的斐波那契堆	*/
/*	操作后:	如果该斐波那契堆为空, 返回 TRUE ; 否则返回 FALSE	*/
/*	摊还时间: O (1)	*/
BOOL IsEmpty_F (const FibonacciHeap * const pfh) ;

/*	操作:	向斐波那契堆中插入一个具有指定数据的结点	*/
/*	操作前:	pfh 指向一个已初始化的斐波那契堆, pi 指向待添加的数据	*/
/*	操作后:	如果内存分配成功, 向该斐波那契堆中插入1个数据域为该数据的结点, 返回 TRUE ; 否则返回 FALSE	*/
/*	摊还时间:	O (1)	*/
BOOL Insert_F (const FibonacciHeap * const pfh, const Item * const pi) ;

/*	操作:	删除并返回斐波那契堆中最小结点的数据	*/
/*	操作前:	pfh 指向一个已初始化的斐波那契堆	*/
/*	操作后:	如果该斐波那契堆不为空, 删除该斐波那契堆中最小结点, 返回该结点的数据 ; 否则返回 EMPTY	*/
/*	摊还时间: O (log N)	*/
Item DeleteMin_F (const FibonacciHeap * const pfh) ;

/*	操作:	降低斐波那契堆中指定数据的值	*/
/*	操作前:	pfh 指向一个已初始化的斐波那契堆, pn 指向指定的结点, delta 指示改变量的大小	*/
/*	操作后:	如果该斐波那契堆不为空, 使该斐波那契堆中 pn 指向结点数据的值减少 delta , 返回 TRUE ; 否则返回 FALSE	*/
/*	摊还时间:	O (1)	*/
BOOL DecreaseKey_F (const FibonacciHeap * const pfh, Node * const pn, const int delta) ;

/*	操作:	删除斐波那契堆中指定结点	*/
/*	操作前:	pfh 指向一个已初始化的斐波那契堆, pn 指向待删除的结点	*/
/*	操作后:	如果该斐波那契堆不为空, 删除 pn 指向的结点, 返回 TRUE ; 否则返回 FALSE	*/
/*	摊还时间:	O (log N)	*/
BOOL Delete_F (const FibonacciHeap * const pfh, Node * const pn) ;

/*	操作:	释放一个斐波那契堆所占用的内存空间	*/
/*	操作前:	pfh 指向一个已初始化的斐波那契堆	*/
/*	操作后:	该斐波那契堆所占用的内存空间被释放	*/
/*	摊还时间:	O (N)	*/
void Release_F (const FibonacciHeap * const pfh) ;