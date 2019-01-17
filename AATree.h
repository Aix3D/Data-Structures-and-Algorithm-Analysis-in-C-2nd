/*	AATree.h -- AA树头文件	*/
#include <stdio.h>
#include <stdlib.h>

/*	明显常量定义	*/

#define FALSE (0)
#define TRUE (1)

/*	数据类型定义	*/

typedef int BOOL ;

typedef int Item ;
typedef struct node
{
	Item item ;
	struct node * left, * right ;
	int level ;
} Node ;
typedef Node * AATree ;

/*	接口函数声明	*/

/*	操作:	创建并初始化一棵AA树	*/
/*	操作前:	*/
/*	操作后:	如果为 NullNode 分配内存空间成功, 将其返回; 否则返回 NULL	*/
/*	时间复杂度:	O (1)	*/
Node * Initialize_A (void) ;

/*	操作:	向一棵AA树中添加一个数据域为指定数据的结点	*/
/*	操作前:	aat 是一棵已初始化的AA树, item 是指定的待添加数据	*/
/*	操作后:	如果数据未重复 && 内存分配成功, 向该AA树中添加指定数据的结点, 返回新的AA树; 否则返回原AA树	*/
/*	时间复杂度:	O (log N)	*/
AATree Insert_A (AATree aat, const Item item) ;

/*	操作:	确定指定数据是否在AA树中	*/
/*	操作前:	aat 是一棵已初始化的AA树, item 是指定的待添加数据	*/
/*	操作后:	如果找到该数据, 返回 TRUE; 否则返回 FALSE	*/
/*	时间复杂度:	O (log N)	*/
BOOL Find_A (AATree aat, const Item item) ;

/*	操作:	确定AA树结点的数目	*/
/*	操作前:	aat 是一棵已初始化的AA树	*/
/*	操作后:	返回该AA树中结点的数目	*/
/*	时间复杂度:	O (log N)	*/
int Count_A (AATree aat) ;

/*	操作:	删除AA树中数据域为指定数据的结点	*/
/*	操作前:	aat 是一棵已初始化的AA树, item 是指定的待删除数据	*/
/*	操作后:	如果找到该结点, 删除它, 返回新AA树; 否则返回原AA树	*/
/*	时间复杂度:	O (log N)	*/
AATree Delete_A (AATree aat, const Item item) ;

/*	操作:	释放一棵AA树占用的内存空间	*/
/*	操作前:	aat 是一棵已初始化的AA树	*/
/*	操作后:	该AA树占用的内存空间被释放, NullNode 占用空间被释放	*/
/*	时间复杂度:	O (log N)	*/
void Release_A (AATree aat) ;