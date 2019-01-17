/*	new_adjacenty_list.h -- 邻接表头文件	*/
#include <stdarg.h>
#include "hash.h"

#define INFINITY (~(1 << 31))
#define NEGATIVEINFINITY (-INFINITY - 1)

/*	数据类型定义	*/

typedef struct adjoin_to_vertex
{
	int hash_value ;
	int cvw ;
	struct adjoin_to_vertex * next ;
} Adjoin_To_Vertex ;
typedef struct vertex
{
	int hash_value ;
	int known ;
	int dist ;
	int weight ;
	Name path ;
	Adjoin_To_Vertex * adjoin_to ;
} Vertex ;
typedef struct adjacenty_list
{
	Vertex * list ;
	int * indegree ;
	int capacity ;
} * Adjacenty_List ;

/*	接口函数声明	*/

/*	操作:	创建一个邻接表	*/
/*	操作前:	padj 指向一个邻接表, capacity 指示邻接表的大小	*/
/*	操作后:	如果 capacity > 0 && 内存分配成功, 创建该邻接表, 返回 1; 否则返回 0	*/
/*	时间复杂度:	O(1)	*/
int Initialize_A (Adjacenty_List * const padj, const int capacity) ;

/*	操作:	初始化邻接表的某一行	*/
/*	操作前:	padj 指向一个已初始化的邻接表, pht 指向一个已初始化的散列表, index 指示行的索引, name 指示顶点名字, indegree 指示顶点入度, sub 指示参数的个数, ... 交替出现指示邻接到该顶点的顶点名字和顶点到该顶点构成的边的权	*/
/*	操作后:	如果 index 是合法的索引 && indegree >= 0 && sub >= 0, 该行被按照参数初始化, 返回 1; 否则返回 0	*/
/*	时间复杂度:	O(V)	*/
int InitializeALine_A (Adjacenty_List * const padj, const Hash_Table * const pht, const int index, const Name name, const int indegree, const int sub, ...) ;

/*	操作:	将已知邻接表所有边取反(针对无权图)	*/
/*	操作前:	padj 指向一个已初始化的邻接表, pht 指向一个已初始化的散列表	*/
/*	操作后:	该邻接表的所有边被取反向	*/
/*	时间复杂度:	O(V^2)	*/
int Reverse_A (Adjacenty_List * const padj, const Hash_Table * const pht) ;

/*	操作:	打印一个邻接表	*/
/*	操作前:	padj 指向一个已初始化的邻接表, pht 指向一个已初始化的散列表	*/
/*	操作后:	该邻接表被打印	*/
/*	时间复杂度:	O (V)	*/
void PrintAdjacenty_List_A (const Adjacenty_List * const padj, const Hash_Table * const pht) ;

/*	操作:	释放一个邻接表所占用的内存空间	*/
/*	操作前:	padj 指向一个已初始化的邻接表	*/
/*	操作后:	该邻接表所占用的内存空间被释放	*/
/*	时间复杂度:	O(V)	*/
void Release_A (const Adjacenty_List * const padj) ;