/*	d-heap.h -- d-堆头文件	*/
#define MINDATA -32678

/*	数据类型定义	*/

typedef int Item ;
typedef struct heap
{
	Item * array ;
	int capacity ;
	int size ;
	int d ;
} * Heap ;

/*	接口函数声明	*/

/*	操作:	创建并初始化一个d-堆	*/
/*	操作前:	pheap 指向一个d-堆, capacity 是用来指示堆容量的变量, d 是所有节点最多儿子的数量	*/
/*	操作后:	如果内存分配成功, 一个容量为 capacity 的堆被创建并被初始为空, 所有儿子最多儿子数量为 d , 返回1; 否则返回0	*/
int InitializeHeap (Heap * const pheap, const int capacity, const int d) ;

/*	操作:	确定一个堆是否为空	*/
/*	操作前:	pheap 指向一个已初始化的d-堆	*/
/*	操作后:	如果该堆为空, 返回1; 否则返回0	*/
int HeapIsEmpty (const Heap * const pheap) ;

/*	操作:	确定一个堆是否已满	*/
/*	操作前:	pheap 指向一个已初始化的d-堆	*/
/*	操作后:	如果该堆已满, 返回1; 否则返回0	*/
int HeapIsFull (const Heap * const pheap) ;

/*	操作:	向d-堆中添加一个元素	*/
/*	操作前:	pheap 指向一个已初始化的d-堆, item 是待添加的数据	*/
/*	操作后:	如果堆未满, 将 item 添加到堆中, 返回1; 否则返回0	*/
int Insert (const Heap * const pheap, const Item item) ;

/*	操作:	删除并返回堆中最小的元素	*/
/*	操作前:	pheap 指向一个已初始化的d-堆	*/
/*	操作后:	如果堆不为空, 删除并返回堆中的最小元素; 否则返回MINDATA	*/
Item DeleteMin (const Heap * const pheap) ;

/*	操作:	降低堆中指定位置处元素的值	*/
/*	操作前:	pheap 指向一个已初始化的d-堆, position 指示堆中的位置, triangle 是改变量	*/
/*	操作后:	如果 position 在堆中的位置存在, triangle > 0, 该位置上的元素被降低 triangle, 返回1; 否则返回0	*/
int DecreaseKey (const Heap * const pheap, const int position, const int triangle) ;

/*	操作:	增加堆中指定位置处元素的值	*/
/*	操作前:	pheap 指向一个已初始化的d-堆, position 指示堆中的位置, triangle 是改变量	*/
/*	操作后:	如果 position 在堆中的位置存在, traingle > 0, 该位置上的元素被增加 traingle, 返回1; 否则返回0	*/
int IncreaseKey (const Heap * const pheap, const int position, const int triangle) ;

/*	操作:	根据一个数据数组构建一个d-堆	*/
/*	操作前:	pheap 指向一个已初始化的d-堆, array 是一个指向数据数组首元素的指针, size 是数组大小	*/
/*	操作后:	如果堆为空, 数组大小>0, 构建该堆, 返回1; 否则返回0	*/
int BuildHeap (const Heap * const pheap, const Item * parray, const int size) ;

/*	操作:	删除d-堆中指定位置的元素	*/
/*	操作前:	pheap 指向一个已初始化的d-堆, position 指示堆中的位置	*/
/*	操作后:	如果堆中 position 位置存在, 该位置处的元素被删除, 返回1; 否则返回0	*/
int Delete (const Heap * const pheap, const int position) ;

/*	操作:	从索引1 - size 依次将一个函数作用于d-堆中所有元素1次	*/
/*	操作前:	pheap 指向一个已初始化的堆, pfun 指向一个没有返回值, 接受一个Item类型参数的函数	*/
/*	操作后:	pfun 指向的函数被依次作用到堆中所有元素1次	*/
void Traversal (const Heap * const pheap, void (* pfun) (const Item item)) ;

/*	操作:	释放一个d-堆占用的内存空间	*/
/*	操作前:	pheap 指向一个已初始化的堆	*/
/*	操作后: 该堆占用的内存空间被释放	*/
void Release (const Heap * const pheap) ;