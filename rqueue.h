/*	rqueue.h -- 队列头文件	*/

/*	数据类型定义	*/

typedef int Item_R ;
typedef struct rqueue_node
{
	Item_R index_in_adjacenty_list ;
	struct rqueue_node * next ;
} Rqueue_Node ;
typedef struct rqueue
{
	Rqueue_Node * front ;
	Rqueue_Node * rear ;
	int current ;
} * Rqueue ;

/*	接口函数声明	*/

/*	操作:	创建并初始化一个记忆队列	*/
/*	操作前:	prq 指向一个记忆队列	*/
/*	操作后:	如果内存分配成功, 该队列被创建并被初始化为空, 返回 1; 否则返回 0	*/
/*	时间复杂度:	O (1)	*/
int Initialize_R (Rqueue * const prq) ;

/*	操作:	确定一个记忆队列是否为空	*/
/*	操作前:	prq 指向一个已初始化的记忆队列	*/
/*	操作后:	如果该队列为空, 返回 1; 否则返回 0	*/
/*	时间复杂度:	O (1)	*/
int IsEmpty_R (const Rqueue * const prq) ;

/*	操作:	向一个记忆队列中添加一个元素	*/
/*	操作前:	prq 指向一个已初始化的记忆队列, index 是待添加元素的数据	*/
/*	操作后:	如果内存分配成功, 向该队列中添加数据域为指定数据的元素, 返回 1; 否则返回 0	*/
/*	时间复杂度:	O (1)	*/
int Insert_R (const Rqueue * const prq, const Item_R index) ;

/*	操作:	从记忆队列中删除一个元素	*/
/*	操作前:	prq 指向一个已初始化的记忆队列, pindex 是一个指向数据域类型的指针	*/
/*	操作后:	如果该队列不为空, 从该队列中删除一个元素, 并将该元素数据域的数据赋予 pindex, 返回 1; 否则返回 0	*/
/*	时间复杂度:	O (1)	*/
int Delete_R (const Rqueue * const prq, Item_R * const pindex) ;

/*	操作:	释放一个记忆队列所占用的内存空间	*/
/*	操作前:	prq 指向一个已初始化的记忆队列	*/
/*	操作后:	该队列所占用的内存空间被释放	*/
/*	时间复杂度:	O (N)	*/
void Release_R (const Rqueue * const prq) ;