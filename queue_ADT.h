/*	queue_ADT.h -- 队列模型头文件	*/
#include "adjacenty_list.h"

/*	数据类型定义	*/
typedef Vertex * Queue_Item ;
typedef struct queue_node
{
	Queue_Item queue_item ;
	struct queue_node * next ;
} Queue_Node ;

typedef struct queue
{
	Queue_Node * front ;
	Queue_Node * rear ;
} * Queue ;

/*	接口函数声明	*/

/*	操作:	创建并初始化一个队列	*/
/*	操作前:	pqueue 指向一个队列	*/
/*	操作后:	如果内存分配成功, 队列被创建并被初始化为空, 返回1; 否则返回0	*/
/*	时间复杂度:	O(1)	*/
int InitializeQueue (Queue * const pqueue) ;

/*	操作:	确定一个队列是否为空	*/
/*	操作前:	pqueue 指向一个已初始化的队列	*/
/*	操作后:	如果该队列为空, 返回1; 否则返回0	*/
/*	时间复杂度:	O(1)	*/
int QueueIsEmpty (const Queue * const pqueue) ;

/*	操作:	向队列中添加数据域为指定数据的元素	*/
/*	操作前:	pqueue 指向一个已初始化的队列, pqueue_item 指向被添加的数据	*/
/*	操作后:	如果内存分配成功, 数据域为 *pqueue_item 的元素被添加到队列中, 返回1; 否则返回0	*/
/*	时间复杂度:	O(1)	*/
int EnQueue (Queue * const pqueue, const Queue_Item * const pqueue_item) ;

/*	操作:	从队列中删除一个元素	*/
/*	操作前:	pqueue 指向一个已初始化的队列, pqueue_item 是一个Queue_Item *类型的变量	*/
/*	操作后:	如果队列不为空, 从队列中删除一个元素, 并将该元素的数据赋予 *pqueue_item 返回1; 否则返回0	*/
/*	时间复杂度:	O(1)	*/
int DeQueue (Queue * const pqueue, Queue_Item * const pqueue_item) ;

/*	操作:	释放一个队列所占用的内存空间	*/
/*	操作前:	pqueue 指向一个已初始化的队列	*/
/*	操作后:	该队列所占用的内存空间被释放	*/
/*	时间复杂度:	O(N)	*/
void ReleaseQueue (Queue * const pqueue) ;