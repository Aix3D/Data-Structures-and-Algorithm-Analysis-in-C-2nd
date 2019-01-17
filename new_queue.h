/*  new_queue.h -- 队列头文件.没什么不同.只是练习一次	*/
#include "binary_search_tree.h"

/*	数据类型定义	*/

typedef Node * QueueItem ;
typedef struct queue_node
{
	QueueItem item ;
	struct queue_node * next ;
} QueueNode ;
typedef struct queue
{
	QueueNode * front ;
	QueueNode * rear ;
} Queue ;

/*	接口函数声明	*/

/*	操作:	初始化一个队列	*/
/*	操作前:	pqueue 指向一个队列	*/
/*	操作后:	该队列被初始为空	*/
void InitializeQueue (Queue * const pqueue) ;

/*	操作:	确定队列是否为空	*/
/*	操作前:	pqueue 指向一个已初始化的队列	*/
/*	操作后:	如果队列为空, 返回1; 否则返回0	*/
int QueueIsEmpty (const Queue * const pqueue) ;

/*	操作:	向队列(尾)添加指定数据的结点	*/
/*	操作前:	pqueue 指向一个已初始化的队列, pitem 指向指定的数据	*/
/*	操作后:	如果可能, 向队列(尾)添加一个拥有 pitem 指向数据的结点, 返回1; 否则返回0	*/
int EnQueue (Queue * const pqueue, const QueueItem * const pitem) ;

/*	操作:	从队列(首)删除一个结点	*/
/*	操作前:	pqueue 指向一个已初始化的队列	*/
/*	操作后:	如果可能, 从队列首端删除一个结点, 返回该结点数据(而不是该结点); 否则返回NULL	*/
QueueItem DeQueue (Queue * const pqueue) ;

/*	操作:	将一个函数作用于(从队列首端-尾端)中每一个结点	*/
/*	操作前:	pqueue 指向一个已初始化的队列, pfun 指向一个没有返回值, 接受一个QueueItem类型变量的函数	*/
/*	操作后:	pfun 指向的函数被作用于队列中每个结点一次	*/
void Traversal (const Queue * const pqueue, void (* pfun) (const QueueItem item)) ;

/*	操作:	清空一个队列	*/
/*	操作前:	pqueue 指向一个已初始化的队列	*/
/*	操作后:	该队列被清空	*/
void EmptyTheQueue (Queue * const pqueue) ;