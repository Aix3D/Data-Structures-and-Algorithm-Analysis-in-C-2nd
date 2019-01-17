/*  doubly_queue.h -- 双端队列头文件	*/

/*	明显常量声明	*/
#define MAXDOUBLYQUEUE (10)
#define NUL '\0'

/*	数据类型定义	*/

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

/*	操作:	初始化一个双端队列	*/
/*	操作前:	pqueue 指向一个双端队列	*/
/*	操作后:	该双端队列被初始化为空双端队列	*/
void InitializeDoublyQueue (Queue * pqueue) ;

/*	操作:	确定双端队列是否为空	*/
/*	操作前:	pqueue 指向一个已初始化的双端队列	*/
/*	操作后: 如果该双端队列为空,返回1; 否则返回0	*/
int DoublyQueueIsEmpty (const Queue * pqueue) ;

/*	操作:	确定双端队列是否已满	*/
/*	操作前:	pqueue 指向一个已初始化的双端队列	*/
/*	操作后:	如果该双端队列已满,返回1; 否则返回0	*/
int DoublyQueueIsFull (const Queue * pqueue) ;

/*	操作:	获得双端队列中元素的个数	*/
/*	操作前:	pqueue 指向一个已初始化的双端队列	*/
/*	操作后:	返回该双端队列中元素的个数	*/
int DoublyQueueItemCount (const Queue * pqueue) ;

/*	操作:	向双端对列首端添加元素	*/
/*	操作前:	pqueue 指向一个已初始化的双端队列, pitem 指向被添加元素的数据	*/
/*	操作后:	如果可能, pitem 指向元素的数据被添加到双端队列首端, 返回1; 否则返回0	*/
int Push (Queue * pqueue, const Item * pitem) ;

/*	操作:	向双端队列尾端添加元素	*/
/*	操作前:	pqueue 指向一个已初始化的双端队列, pitem 指向被添加元素的数据	*/
/*	操作后:	如果可能, pitem 指向元素的数据被添加到双端队列尾端, 返回1; 否则返回 0	*/
int Inject (Queue * pqueue, const Item * pitem) ;

/*	操作:	从双端队列首端删除一个元素并将其返回	*/
/*	操作前:	pqueue 指向一个已初始化的双端队列	*/
/*	操作后:	如果可能, 从双端队列首端删除一个元素, 返回该元素; 否则返回NUL	*/
Item Pop (Queue * pqueue) ;

/*	操作:	从双端队列尾端删除一个元素并将其返回	*/
/*	操作前:	pqueue 指向一个已初始化的双端队列	*/
/*	操作后:	如果可能, 从双端队列尾端删除一个元素, 返回该元素; 否则返回NUL	*/
Item Eject (Queue * pqueue) ;

/*	操作:	将一个函数作用于双端队列中的所有元素一次(从首端到尾端)	*/
/*	操作前:	pqueue 指向一个已初始化的双端队列, pfun 指向一个没有返回值, 接受一个Item类型参数的函数	*/
/*	操作后:	pfun 指向的函数被作用于队列中的所有元素一次	*/
void Traverse (const Queue * pqueue, void (* pfun) (const Item item)) ;

/*	操作:	清空双端队列	*/
/*	操作前:	pqueue 指向一个已初始化的双端队列	*/
/*	操作后:	pqueue 指向的队列被清空	*/
void EmptyTheDoublyQueue (Queue * pqueue) ;