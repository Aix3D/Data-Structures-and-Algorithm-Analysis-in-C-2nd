/*	PairingHeap.h -- 配对堆头文件	*/
#include <stdio.h>
#include <stdlib.h>

/*	明显常量定义	*/

#define FALSE (0)
#define TRUE (1)
#define MAXSIBLINGS (100)

/*	数据类型定义	*/

typedef int BOOL ;

typedef int Item ;
typedef struct node
{
	Item item ;
	struct node * left, * previous, * nextSibling ;
} Node ;
typedef struct pairingHeap
{
	Node * root ;
	int current ;
} * PairingHeap ;

/*	接口函数声明	*/

/*	操作:	创建并初始化配对堆, 并为 NullNode 分配内存空间	*/
/*	操作前:	pph 指向一个配对堆*/
/*	操作后:	如果内存分配成功, *pph 和 NullNode 得到内存空间并被初始化, 返回 TRUE ; 否则返回 FALSE	*/
/*	时间复杂度:	O (1)	*/
BOOL Initialize_P (PairingHeap * const pph) ;

/*	操作:	确定一个配对堆是否为空	*/
/*	操作前:	pph 指向一个已初始化的配对堆	*/
/*	操作后:	如果该配对堆为空, 返回 TRUE ; 否则返回 FALSE	*/
/*	时间复杂度:	O (1)	*/
BOOL IsEmpty_P (const PairingHeap * const pph) ;

/*	操作:	向一个配对堆中添加一个数据域为指定数据的结点	*/
/*	操作前:	pph 指向一个已初始化的配对堆, item 是指定的待添加数据, localizer 是一个指向 Node * 类型的指针, 用来传递回新结点的地址	*/
/*	操作后:	如果内存分配成功, 将一个数据域为 item 的结点添加到该配对堆中, *localizer 指向新结点, 返回 TRUE ; 否则返回 FALSE	*/
/*	时间复杂度:	O (1)	*/
BOOL Insert_P (const PairingHeap * const pph, const Item item, const Node * * const localizer) ;

/*	操作:	将配对堆中指定结点的数据降低 delta	*/
/*	操作前:	pph 指向一个已初始化的配对堆, position 是一个指向配对堆中结点的指针, delta 是待减少的数据	*/
/*	操作后:	如果 delta > 0, 将 position 指向结点的数据减少 delta , 返回 TRUE ; 否则返回 FALSE	*/
/*	时间复杂度:	O (1)	*/
BOOL DecreaseKey_P (const PairingHeap * const pph, Node * const position, const Item delta) ;

/*	操作:	删除配对堆中数据域最小的结点, 并通过 pmin 将其携带回调用该函数的函数	*/
/*	操作前:	pph 指向一个已初始化的配对堆, pmin 是一个指向Item的指针	*/
/*	操作后:	如果该配对堆不为空, 删除数据域最小的结点, 并将其数据赋予 *pmin , 返回 TRUE ; 否则返回 FALSE	*/
/*	时间复杂度:	未知	*/
BOOL DeleteMin_P (const PairingHeap * const pph, Item * const pmin) ;

/*	操作:	释放一个配对堆占用的内存空间	*/
/*	操作前:	pph 指向一个已初始化的配对堆	*/
/*	操作后:	该配对堆所占用的内存空间被释放. NullNode 占用的内存空间被释放, 并被赋予 NULL	*/
/*	时间复杂度:	未知	*/
void Release_P (PairingHeap * const pph) ;