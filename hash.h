/*	hash.h -- 哈希表头文件	*/
enum KindOfEntry {LEGITIMATE, EMPTY, DELETED} ;

#define PRIME (7)
#define FAILED (-2)
#define NUL ('\0')
#define FALSE (0)
#define TRUE (1)

/*	数据类型定义	*/

typedef char Name ;
typedef struct cell
{
	Name name ;
	int be_deleted ;		//	在优先队列中是否是已删除过的
	enum KindOfEntry entry ;
	int index_in_adjacenty_list ;
} Cell ;
typedef struct hash_table
{
	Cell * lists ;
	int current ;
	int capacity ;
} * Hash_Table ;

/*	接口函数声明	*/

/*	操作:	根据一个数据产生一个数值并返回	*/
/*	操作前:	pht 指向一个已初始化的散列表, pname 指向一个数据	*/
/*	操作后:	根据该数据产生一个数值并返回	*/
/*	时间复杂度:	O(1)	*/
int Hash (const Hash_Table * const pht, const Name * const pname) ;

/*	操作:	创建并初始化一个散列表	*/
/*	操作前:	pht 指向一个散列表, capacity 是指示表大小的数据	*/
/*	操作后:	如果 capacity > 0 && 内存分配成功, 该散列表被创建为 >= capacity 最小素数大小并初始化为空, 返回1; 否则返回0	*/
/*	时间复杂度:	O(1)	*/
int Initialize_H (Hash_Table * const pht, const int capacity) ;

/*	操作:	查找并返回一个指向数据在散列表中的位置的指针	*/
/*	操作前:	pht 指向一个已初始化的散列表, pname 指向被查找的数据	*/
/*	操作后:	如果找到数据域为 *pname 的元素, 返回指向该元素的指针; 否则返回指向查找结束时停止在散列表元素的指针	*/
/*	时间复杂度: O(N)	*/
Cell * Find_H (const Hash_Table * const pht, const Name * const pname) ;

/*	操作:	向散列表中添加一个元素并返回在散列表中的索引	*/
/*	操作前:	pht 指向一个已初始化的散列表, pname 是指向名字的指针, index 是元素在邻接表中的索引	*/
/*	操作后:	如果表当前大小 <= 表大小的一半, 添加该元素, 返回当前索引; 否则返回 FAILED	*/
/*	时间复杂度: O(N)	*/
int Insert_H (const Hash_Table * const pht, const Name * const pname, const int index) ;

/*	操作:	从散列表中懒惰删除数据域为指定数据的元素	*/
/*	操作前:	pht 指向一个已初始化的散列表, pname 是指向名字的指针	*/
/*	操作后:	如果找到该元素, 对其进行懒惰删除, 返回 1 ; 否则返回 0	*/
/*	时间复杂度:	O(N)	*/
int Delete_H (const Hash_Table * const pht, const Name * const pname) ;

/*	操作:	释放一个散列表所占用的内存空间	*/
/*	操作前:	pht 指向一个已初始化的散列表	*/
/*	操作后:	该散列表所占内存空间被释放	*/
/*	时间复杂度:	O(1)	*/
void Release_H (const Hash_Table * const pht) ;