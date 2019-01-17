/*  queue_achievied_by_linked_list.h -- 队列头文件	*/

/*	定义数据类型	*/
typedef int Item ;
typedef struct node
{
	Item item ;
	struct node * next ;
} Node ;
typedef struct queue
{
	Node * front ;
	Node * rear ;
	int items ;
} Queue ;

/*	接口函数声明	*/

/*	操作:	初始化一个队列	*/
/*	操作前:	pqueue 指向一个队列	*/
/*	操作后:	pqueue 指向的队列被初始化为空队列	*/
void InitializeQueue (Queue * pqueue) ;

/*	操作:	确定队列是否为空	*/
/*	操作前:	pqueue指向一个已初始化的队列	*/
/*	操作后:	如果队列为空,返回1;否则返回0	*/
int QueueIsEmpty (const Queue * pqueue) ;

/*	操作:	确定队列是否已满	*/
/*	操作前:	pqueue 指向一个已初始化的队列	*/
/*	操作后:	如果队列已满,返回1;否则返回0	*/
int QueueIsFull (const Queue * pqueue) ;

/*	操作:	获得队列中元素的个数	*/
/*	操作前:	pqueue 指向一个已初始化的队列	*/
/*	操作后:	返回队列中元素的个数	*/
int QueueItemCount( const Queue * pqueue) ;

/*	操作:	向队列(尾端)添加元素	*/
/*	操作前:	pqueue 指向一个已初始化的队列, pitem 指向将要添加到队列的元素	*/
/*	操作后:	如果可能, pitem指向的元素被添加到队列(尾端),返回1;否则返回0	*/
int EnQueue (Queue * pqueue, const Item * pitem) ;

/*	操作:	从队列(首端)删除元素	*/
/*	操作前:	pqueue 指向一个已初始化的队列, pitem 是用来存放被删除元素数据的指针	*/
/*	操作后:	如果可能, 从队列(首端)删除一个元素, 该元素的数据被赋予 *pitem,返回1;否则返回0	*/
int DeQueue (Queue * pqueue, Item * pitem) ;

/*	操作:	将一个函数作用到队列中的所有元素(从头至尾)	*/
/*	操作前:	pqueue 指向一个已初始化的队列, pfun 指向一个没有返回值,接受一个Item类型数据的函数	*/
/*	操作后:	pfun 指向的函数被作用到队列中的所有元素(从头至尾)	*/
void Traverse (const Queue * pqueue, void (* pfun) (const Item item)) ;

/*	操作:	清空一个队列	*/
/*	操作前:	pqueue指向一个已初始化的队列	*/
/*	操作后:	该队列被清空	*/
void EmptyTheQueue (Queue * pqueue) ;