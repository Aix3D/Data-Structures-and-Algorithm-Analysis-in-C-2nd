/*	box.h -- 盒子问题头文件	*/
#include <stdio.h>
#include <stdlib.h>

#define GENERIC 10
#define LEFT 1
#define RIGHT 2

/*	数据类型定义	*/

typedef int Weight ;		//	重量
typedef struct box
{
	Weight unoccupied ;		//	可用重量
	Weight capacity ;		//	容量
	struct box * parent ;
	struct box * left ;
	struct box * right ;
} Box ;
typedef struct boxtree
{
	Box * root ;
	Weight usual ;			//	通常情况下的重量
	int size ;
} * BoxTree ;

/*	接口函数声明	*/

/*	操作:	创建并初始化一个BoxTree	*/
/*	操作前:	pbt 指向一个BoxTree	*/
/*	操作后:	如果内存分配成功, 创建并初始化一个BoxTree, 默认容量为 capacity, 返回1; 否则返回0	*/
/*	时间复杂度:	O(1)	*/
int InitializeBoxTree (BoxTree * const pbt, const Weight capacity) ;

/*	操作:	确定一个BoxTree是否为空	*/
/*	操作前:	pbt 指向一个已初始化的BoxTree	*/
/*	操作后:	如果该BoxTree为空, 返回1; 否则返回0	*/
/*	时间复杂度:	O(1)	*/
int BoxTreeIsEmpty (const BoxTree * const pbt) ;

/*	操作:	减小指定BoxTree中 >= triangle 最大关键字的值	*/
/*	操作前:	pbt 指向一个已初始化的BoxTree, triangle 是放入的重量	*/
/*	操作后:	如果操作期间内存分配成功, 完成操作, 返回1; 否则返回0	*/
/*	时间复杂度:	O(2logN)	*/
int DealWithTheBiggest (BoxTree * const pbt, const Weight triangle) ;

/*	操作:	减小指定BoxTree中 >= triangle 最小关键字的值	*/
/*	操作前:	pbt 指向一个已初始化的BoxTree, triangle 是放入的重量	*/
/*	操作后:	如果操作期间内存分配成功, 完成操作, 返回1; 否则返回0	*/
/*	时间复杂度:	O(7logN)	*/
int DealWithTheSmallest (BoxTree * const pbt, const Weight triangle) ;

/*	操作:	以中序将一个函数作用于一棵BoxTree中所有节点1次	*/
/*	操作前:	pbt 指向一棵已初始化的BoxTree, pfun 指向一个没有返回值, 接受一个Box *类型参数的函数	*/
/*	操作后:	pfun 指向的函数被以中序作用于BoxTree中所有节点1次	*/
/*	时间复杂度:	O(logN)	*/
void InorderTraversal (const Box * const box, void (* pfun) (const Box * const box)) ;

/*	操作:	释放一棵BoxTree所占用的内存空间	*/
/*	操作前:	pbt 指向一棵已初始化的BoxTree	*/
/*	操作后:	该BoxTree所占用的内存空间被释放	*/
/*	时间复杂度:	O(1)	*/
void Release (const BoxTree * const pbt) ;
