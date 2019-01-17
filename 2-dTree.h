/*	2dTree.h -- 2-d树头文件	*/
#include <stdio.h>
#include <stdlib.h>

/*	明显常量定义	*/

#define FALSE (0)
#define TRUE (1)
#define TWO (2)
#define MASK (1)

/*	数据类型定义	*/

typedef int BOOL ;

/*	2-d树部分	*/
typedef int Item ;
typedef struct node
{
	Item item[TWO] ;
	int deleted ;
	struct node * left, * right ;
} Node ;
typedef struct twoDTree
{
	Node * root ;
	int current ;
} * TwoDTree ;

/*	队列部分	*/
typedef struct queueNode
{
	Node * node ;
	int index ;
	struct queueNode * next ;
} QueueNode ;
typedef struct queue
{
	QueueNode * front, * rear ;
	int current ;
} * Queue ;

/*	接口函数声明	*/

/*	队列部分	*/
/*	操作:	创建并初始化一个队列	*/
/*	操作前:	pq 指向一个队列	*/
/*	操作前:	如果内存分配成功, 创建并初始化该队列, 返回 TRUE ; 否则返回 FALSE	*/
/*	时间复杂度:	O (1)	*/
BOOL Initialize_Q (Queue * const pq) ;

/*	操作:	确定队列是否为空	*/
/*	操作前:	pq 指向一个已初始化的队列	*/
/*	操作后:	如果该队列为空, 返回 TRUE ; 否则返回 FALSE	*/
/*	时间复杂度:	O (1)	*/
BOOL IsEmpty_Q (const Queue * const pq) ;

/*	操作:	向队列中添加一个数据域为指定数据的结点	*/
/*	操作前:	pq 指向一个已初始化的队列, pn 和 index 是待添加的数据	*/
/*	操作后:	如果内存分配成功, 向该队列中添加数据域为 pn 和 index 的结点, 返回 TRUE ; 否则返回 FALSE	*/
/*	时间复杂度:	O (1)	*/
BOOL EnQueue_Q (const Queue * const pq, Node * const pn, const int index) ;

/*	操作:	删除队列头部的结点, 取出该结点指向地址的值赋给 * pqn	*/
/*	操作前:	pq 指向一个已初始化的队列, pqn 是一个指向QueueNode类型结点的指针	*/
/*	操作后:	如果该队列非空, 删除该队列头部结点, 取出该结点指向地址的值赋给 * pqn, 返回 TRUE ; 否则返回 FALSE	*/
/*	时间复杂度:	O (1)	*/
BOOL DeQueue_Q (const Queue * const pq, QueueNode * const pqn) ;

/*	操作:	释放一个队列占用的内存空间	*/
/*	操作前:	pq 指向一个已初始化的队列	*/
/*	操作后:	该队列占用的内存空间被释放	*/
/*	时间复杂度:	O (N)	*/
void Release_Q (const Queue * const pq) ;

/*	2-d树部分	*/
/*	操作:	创建并初始化一个2-d树	*/
/*	操作前:	pt 指向一棵2-d树	*/
/*	操作后:	如果内存分配成功, 创建并初始化该2-d树, 返回 TRUE ; 否则返回 FALSE	*/
/*	时间复杂度:	O (1)	*/
BOOL Initialize_T (TwoDTree * const pt) ;

/*	操作:	确定一棵2-d树是否为空	*/
/*	操作前:	pt 指向一棵已初始化的2-d树	*/
/*	操作后:	如果该2-d树为空, 返回 TRUE ; 否则返回 FALSE	*/
/*	时间复杂度:	O (1)	*/
BOOL IsEmpty_T (const TwoDTree * const pt) ;

/*	操作:	向一棵2-d树中插入数据域为指定数据的结点	*/
/*	操作前:	pt 指向一棵已初始化的2-d树, pi 指向第一个待添加数据的地址	*/
/*	操作后:	如果内存分配成功, 向该2-d树中添加数据域为 pi[0] 和 pi[1] 的结点(重复元将添加到右子树上), 返回 TRUE ; 否则返回 FALSE	*/
/*	平均时间复杂度:	O (log N)	*/
BOOL Insert_T (const TwoDTree * const pt, const Item * const pi) ;

/*	操作:	在一棵2-d树中将一个函数作用于满足查找范围的所有结点1次	*/
/*	操作前:	pt 指向一棵已初始化的2-d树, low 和 high 分别是指向相应范围数据中第一个数据的指针, pfun 指向一个没有返回值, 接受一个 Node * 类型参数的函数	*/
/*	操作后:	将 pfun 指向的函数作用于满足范围的所有结点1次, 返回找到的结点的个数	*/
/*	平均时间复杂度:	O (log N)	*/
int Find_T (const TwoDTree * const pt, const Item * const low, const Item * const high, void (* pfun) (const Node * const pn)) ;

/*	操作:	从一棵2-d树中懒惰删除数据域为指定数据的所有结点	*/
/*	操作前:	pt 指向一棵已初始化的2-d树, pi 是指向第一个待删除数据的指针	*/
/*	操作后:	删除数据域为待删除数据并且未被删除的结点, 返回此次调用删除结点的个数	*/
/*	平均时间复杂度:	O (log N)	*/
int Delete_T (const TwoDTree * const pt, const Item * const pi) ;

/*	操作:	释放一棵2-d树占用的内存空间	*/
/*	操作前:	pt 指向一棵已初始化的2-d树	*/
/*	操作后:	该2-d树占用的内存空间被释放	*/
/*	平均时间复杂度:	O (log N)	*/
void Release_T (const TwoDTree * const pt) ;