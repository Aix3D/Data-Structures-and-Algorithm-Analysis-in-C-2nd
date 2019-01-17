/*  queue_achievied_by_array.h -- 队列头文件	*/

/*	定义明显常量	*/
#define MINQUEUESIZE (5)

/*	定义数据类型	*/
typedef int Item ;
typedef struct record
{
	int capacity ;		/*	队列大小	*/
	int front ;			/*	头索引的值	*/
	int rear ;			/*	尾索引的值	*/
	int size ;			/*	已存在元素的个数	*/
	Item * array ;
} Record ;
typedef Record * Queue ;

/*	接口函数声明	*/

/*	操作:	创建一个队列	*/
/*	操作前:	size 表示队列数组大小	*/
/*	操作后:	返回一个大小为 size 的已初始化的队列	*/
Queue CreateQueue (const int size) ;

/*	操作:	确定队列是否为空	*/
/*	操作前:	queue 是一个已初始化的队列	*/
/*	操作后:	如果队列为空,返回1;否则返回0	*/
int QueueIsEmpty (const Queue queue) ;

/*	操作:	确定队列是否已满	*/
/*	操作前:	queue 是一个已初始化的队列	*/
/*	操作后:	如果队列已满,返回1;否则返回0	*/
int QueueIsFull (const Queue queue) ;

/*	操作:	获得队列中元素的个数	*/
/*	操作前:	queue 是一个已初始化的队列	*/
/*	操作后:	返回队列中元素的个数	*/
int QueueItemCount (const Queue queue) ;

/*	操作:	向队列(尾端)添加元素	*/
/*	操作前:	queue 是一个已初始化的队列, item 是准备添加进队列的元素	*/
/*	操作后:	如果可能,item元素被添加到队列(尾端),返回1;否则返回0	*/
int EnQueue (Queue queue, const Item item) ;

/*	操作:	从队列(首端)删除元素	*/
/*	操作前:	queue 是一个已初始化的队列, pitem 是一个用来获得队列首端元素数据的指针	*/
/*	操作后:	如果可能, 队列首端元素的值被赋给 *pitem,队列首端元素从队列中删除,返回1;否则返回0	*/
int DeQueue (Queue queue, Item * const pitem) ;

/*	操作:	使一个函数作用于队列中所有元素(队首到队尾)	*/
/*	操作前:	queue 是一个已初始化的队列, pfun 指向一个没有返回值,接受一个Item类型数据位参数的函数	*/
/*	操作后:	pfun指向的函数被作用到队列中所有元素一次	*/
void Traverse (const Queue queue, void (* pfun) (const Item item)) ;

/*	操作:	清空一个队列	*/
/*	操作前:	queue是一个已初始化的队列	*/
/*	操作后:	队列被清空	*/
void EmptyTheQueue (Queue queue) ;
