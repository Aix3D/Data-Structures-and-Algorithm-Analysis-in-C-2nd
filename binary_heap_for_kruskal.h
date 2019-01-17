/*	binary_heap_for_kruskal.h -- 二叉堆头文件	*/
#include "new_adjacenty_list.h"

/*	数据类型定义	*/

typedef struct edge
{
	int v_hash_value ;
	int w_hash_value ;
	int weight ;
} Edge ;
typedef struct binary_heap
{
	Edge * heap ;
	int capacity ;
	int current ;
} * Binary_Heap ;

/*	接口函数声明	*/

/*	操作:	创建并初始化一个二叉堆	*/
/*	操作前:	pbh 指向一个二叉堆, capacity 指示该堆的大小	*/
/*	操作后:	如果 capacity > 0 && 内存分配成功, 创建该堆, 返回 1 ; 否则返回 0	*/
/*	时间复杂度: O(1)	*/
int Initialize_B (Binary_Heap * const pbh, const int capacity) ;

/*	操作:	向堆中添加一个数据域为指定数据的元素	*/
/*	操作前:	pbh 指向一个已初始化的二叉堆, pd 指向待添加的边	*/
/*	操作后:	如果堆未满, 向二叉堆中添加新元素, 返回 1 ; 否则返回 0	*/
/*	时间复杂度: O (log N)	*/
int Insert_B (const Binary_Heap * const pbh, const Edge * const pd) ;

/*	操作:	删除堆中的 weight 域最小的元素	*/
/*	操作前:	pbh 指向一个已初始化的二叉堆, pd 是指向存放数据的指针	*/
/*	操作后:	如果堆未空, 删除最小元素, 将其值赋予 pd 指向的数据, 返回 1 ; 否则返回 0	*/
/*	时间复杂度:	O (log N)	*/
int DeleteMin_B (const Binary_Heap * const pbh, Edge * const pd) ;

/*	操作:	释放一个堆所占用的内存空间	*/
/*	操作前:	pbh 指向一个已初始化的二叉堆	*/
/*	操作后:	该堆所占用的内存空间被释放	*/
/*	时间复杂度:	O (1)	*/
void Release_B (const Binary_Heap * const pbh) ;