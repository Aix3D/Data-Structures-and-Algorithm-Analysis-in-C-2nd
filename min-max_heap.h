/*	min-max_heap.h -- 最小-最大堆头文件	*/
#define ODD 1	//	奇数
#define EVEN 2	//	偶数
#define DATA -32768

/*	数据类型定义	*/

typedef struct item
{
	int element ;
	int index ;
} Item ;
typedef struct heap
{
	Item * array ;
	int capacity ;
	int size ;
	int layer ;
} * Heap ;

/*	接口函数声明	*/

/*	操作:	创建并初始化一个最小-最大堆	*/
/*	操作前:	pheap 指向一个最小-最大堆, capacity 指示堆的容量	*/
/*	操作后:	如果内存分配成功, capacity 有效, 创建并将该堆初始化为空, 返回1; 否则返回0	*/
int InitializeHeap (Heap * const pheap, const int capacity) ;

/*	操作:	确定一个最小-最大堆是否为空	*/
/*	操作前:	pheap 指向一个已初始化的最小-最大堆	*/
/*	操作后:	如果该堆为空, 返回1; 否则返回0	*/
int HeapIsEmpty (const Heap * const pheap) ;

/*	操作:	确定一个最小-最大堆是否已满	*/
/*	操作前:	pheap 指向一个已初始化的最小-最大堆	*/
/*	操作后:	如果该堆已满, 返回1; 否则返回0	*/
int HeapIsFull (const Heap * const pheap) ;

/*	操作:	向一个最小-最大堆中添加一个元素	*/
/*	操作前:	pheap 指向一个已初始化的最小-最大堆, element 指示待添加的数据	*/
/*	操作后:	如果堆未满, 将 element 添加进堆中, 返回1; 否则返回0	*/
int Insert (const Heap * const heap, const int element) ;

/*	操作:	删除并返回最小-最大堆中的最小元素	*/
/*	操作前:	pheap 指向一个已初始化的最小-最大堆	*/
/*	操作后:	如果堆不为空, 删除并返回堆中的最小元素; 否则返回 DATA	*/
Item DeleteMin (const Heap * const pheap) ;

/*	操作:	从低索引向高索引依次将一个函数作用于最大-最小堆中所有元素1次	*/
/*	操作前:	pheap 指向一个已初始化的最小-最大堆, pfun 指向一个没有返回值, 接受一个Item类型参数的函数	*/
/*	操作后:	pfun 被依次作用于堆中所有元素1次	*/
void Traversal (const Heap * const pheap, void (* pfun) (const Item item)) ;