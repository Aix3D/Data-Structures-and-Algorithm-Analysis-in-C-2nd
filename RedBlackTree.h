/*	RedBlackTree.h -- 红黑树头文件	*/
/*	仅仅代码,就写了4天.删除例程写了三天.删除例程是自己实现的,够爽.	*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*	明显常量定义	*/

#define FALSE (0)
#define TRUE (1)
#define INFINITY (~(1 << 31))
#define NEGATIVE_INFINITY (1 << 31)

/*	数据类型定义	*/

typedef int BOOL ;
typedef enum colorType {Red, Black} ColorType ;
typedef int Item ;
typedef struct node
{
	Item item ;
	struct node * left, * right ;
	ColorType color ;
} Node ;
typedef struct redBlackTree
{
	Node * root ;
	int current ;
} * RedBlackTree ;

/*	全局变量声明	*/

static Node * NullNode = NULL ;
Node * Current, * Sibling, * Parent, * GrParent, * GrGrParent ;

/*	接口函数声明	*/

/*	操作:	创建并初始化一棵红黑树并为 NullNode 分配内存空间	*/
/*	操作前:	prbt 指向一棵红黑树	*/
/*	操作后:	如果内存分配成功, 该红黑树被初始化为空, 为 NullNode 分配内存空间, 返回 TRUE ; 否则返回 FALSE	*/
/*	时间复杂度:	O (1)	*/
BOOL Create_R (RedBlackTree * const prbt) ;

/*	操作:	确定一棵红黑树是否为空	*/
/*	操作前:	prbt 指向一棵已初始化的红黑树	*/
/*	操作后:	如果该红黑树为空, 返回 TRUE ; 否则返回 FALSE	*/
/*	时间复杂度:	O (1)	*/
BOOL IsEmpty_R (const RedBlackTree * const prbt) ;

/*	操作:	向红黑树中插入一个结点	*/
/*	操作前:	prbt 指向一棵已初始化的红黑树, item 是待添加数据	*/
/*	操作后:	如果内存分配成功 && item 之前不存在于该红黑树中, 向该红黑树中添加1个数据域为 item 的结点, 返回 TRUE ; 否则返回 FALSE	*/
/*	时间复杂度:	O (log N)	*/
BOOL Insert_R (RedBlackTree * const prbt, const Item item) ;

/*	操作:	从红黑树中删除一个结点	*/
/*	操作前:	prbt 指向一棵已初始化的红黑树, item 是待删除数据	*/
/*	操作后:	如果找到该结点, 删除它, 返回 TRUE ; 否则返回 FALSE	*/
/*	时间复杂度:	O (log N)	*/
BOOL Delete_R (RedBlackTree * const prbt, const Item item) ;

/*	操作:	将一个函数以中序作用于红黑树中所有结点1次	*/
/*	操作前:	prbt 指向一棵已初始化的红黑树, pfun 指向一个没有返回值, 接受一个 Node * 类型参数的函数	*/
/*	操作后:	pfun 指向的函数被以中序依次作用于该红黑树中所有结点1次	*/
/*	时间复杂度:	O (N)	*/
void Traversal_R (const RedBlackTree * const prbt, void (* pfun) (const Node * const pn)) ;

/*	操作:	释放一棵红黑树占用的内存空间	*/
/*	操作前:	prbt 指向一棵已初始化的红黑树	*/
/*	操作后:	该红黑树占用的内存空间被释放	*/
/*	时间复杂度:	O (N)	*/
void Release_R (const RedBlackTree * const prbt) ;