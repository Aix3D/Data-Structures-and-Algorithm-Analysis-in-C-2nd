/*	binary_heap.h -- 二叉堆头文件	*/
#include "new_adjacenty_list.h"

/*	数据类型定义	*/

typedef Vertex * Heap_Item ;
typedef struct binary_heap
{
	Heap_Item * heap ;
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
/*	操作前:	pbh 指向一个已初始化的二叉堆, hi 是待添加的指定数据	*/
/*	操作后:	如果堆未满, 向二叉堆中添加新元素, 返回 1 ; 否则返回 0	*/
/*	时间复杂度: O (log N)	*/
int Insert_B (const Binary_Heap * const pbh, const Heap_Item hi) ;

/*	操作:	删除并返回堆中最小的元素	*/
/*	操作前:	pbh 指向一个已初始化的二叉堆	*/
/*	操作后:	如果堆未空, 删除堆中最小元素并返回; 否则返回堆中的哑元素	*/
/*	时间复杂度:	O (log N)	*/
Heap_Item DeleteMin_B (const Binary_Heap * const pbh) ;

/*	操作:	将堆中指定元素的 dist 域的值增加 Δ	*/
/*	操作前:	phb 指向一个已初始化的二叉堆, index 指示指定元素的索引, triangle 指示Δ的大小	*/
/*	操作后:	如果堆不为空 && index 是合法的索引 && Δ >= 0, 堆中索引为 index 的元素的 dist 域被增加 Δ, 返回 1 ; 否则返回 0	*/
/*	时间复杂度:	O (log N)	*/
int IncreaseKey_B (const Binary_Heap * const pbh, const int index, const int triangle) ;

/*	操作:	将堆中指定元素的 dist 域值减少 Δ	*/
/*	操作前:	pbh 指向一个一初始化的二叉堆, index 指示指定元素的索引, triangle 指示Δ的大小	*/
/*	操作后:	如果堆不为空 && index 是合法的索引 && Δ >= 0, 堆中索引为 index 的元素的 dist 域被减少 Δ, 返回 1 ; 否则返回 0	*/
/*	时间复杂度:	O (log N)	*/
int DecreaseKey_B (const Binary_Heap * const pbh, const int index, const int triangle) ;

/*	操作:	释放一个二叉堆所占用的内存空间	*/
/*	操作前:	pbh 指向一个已初始化的二叉堆	*/
/*	操作后:	该堆所占用的内存空间被释放	*/
/*	时间复杂度:	O (1)	*/
void Release_B (const Binary_Heap * const pbh) ;