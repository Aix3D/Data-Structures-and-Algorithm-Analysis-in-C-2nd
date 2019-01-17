/*	Separate_Chaining_Hash.h -- 分离链接散列表头文件	*/
#define MAXTABLESIZE 4096
#define CONSTANT 10
#define NUL '\0'

/*	数据类型定义	*/

typedef int Item ;
typedef struct list_node
{
	Item item ;
	struct list_node * next ;
} ListNode ;
typedef ListNode * Header ;
typedef struct hashtable
{
	int size ;
	Header * lists ;
} * HashTable ;

/*	操作:	初始化一个分离链接散列表	*/
/*	操作前:	size 是指定分离链接散列表的大小的变量	*/
/*	操作后:	该表被创建并且表中的所有表元指针被初始化为空, 返回该表	*/
HashTable InitializeTable (const int size) ;

/*	操作:	根据传递来的参数产生并返回一个索引值	*/
/*	操作前:	item 是数据, size 表示表的大小	*/
/*	操作后:	返回一个索引值	*/
int Hash (const Item item, const int size) ;

/*	操作:	返回一个指向表中指定数据所在结点的指针	*/
/*	操作前:	item 是被查找的数据, h 是一个已初始化的表	*/
/*	操作后:	如果可能, 返回指向表中指定数据所在结点的指针; 否则返回NULL	*/
Header Find (const Item item, const HashTable h) ;

/*	操作:	将一个具有指定数据以插入新结点的方式插入到表中	*/
/*	操作前:	item 是待插入的数据, ph 指向一个已初始化的表	*/
/*	操作后:	如果可能, 以 item 为数据创建一个结点被插入到表中(如果冲突, 它将出现在链表的最前面的位置), 返回1; 否则返回0	*/
int Insert (const Item item, HashTable * const ph) ;

/*	操作:	从表中删除一个结点	*/
/*	操作前:	item 是待删除结点的数据, ph 指向一个已初始化的表	*/
/*	操作后:	如果可能, item 所在结点被从表中删除, 返回1; 否则返回0	*/
int Delete (const Item item, HashTable * const ph) ;

/*	操作:	从低索引向高索引将一个函数作用于表中所有存在的结点	*/
/*	操作前:	ph 指向一个已初始化的表, pfun 指向一个没有返回值, 接受一个ListNode *类型参数的函数	*/
/*	操作后:	pfun 指向的函数被从低索引向高索引作用到所有存在的结点一次	*/
void Traversal (const HashTable * const ph, void (* pfun) (const ListNode * const pnode)) ;

/*	操作:	清空一个表	*/
/*	操作前:	ph 指向一个已初始化的表	*/
/*	操作后:	该表所占用的全部内存空间被释放	*/
void Release (HashTable * ph) ;