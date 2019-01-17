/*	treapTree.h -- treap树头文件	*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INFINITY (~(1 << 31))

typedef int Item ;
typedef struct node
{
	Item item ;
	struct node * left, * right ;
	int priority ;
} Node ;
typedef Node * TreapTree ;

/*	接口函数声明	*/

/*	操作:	初始化一棵Treap树	*/
/*	操作前:		*/
/*	操作后:	如果内存分配成功, 为 NullNode 分配内存, 初始化随机数种子, 返回 NullNode; 否则返回 NULL	*/
/*	时间复杂度:	O (1)	*/
TreapTree Initialize_T (void) ;

/*	操作:	向一棵Treap树中添加一个数据域为指定数据的结点	*/
/*	操作前:	tt 是一棵已初始化的Treap树, item 是待添加的数据	*/
/*	操作后:	如果内存分配成功 && 数据未重复, 向该课Treap树中添加数据域为 item 的结点, 返回新树; 否则返回原树	*/
/*	时间复杂度:	O (log N)	*/
TreapTree Insert_T (TreapTree tt, const Item item) ;

/*	操作:	从一颗Treap树中删除数据域为指定数据的结点	*/
/*	操作前:	tt 是一棵已初始化的Treap树, item 是待删除的数据	*/
/*	操作后:	如果找到数据域为 item 的结点, 删除该结点, 返回新树; 否则返回原树	*/
/*	时间复杂度:	O (log N)	*/
TreapTree Delete_T (TreapTree tt, const Item item) ;

/*	操作:	释放一棵Treap树占用的内存空间	*/
/*	操作前:	tt 是一棵已初始化的Treap树	*/
/*	操作后:	该Treap树占用的内存空间被释放	*/
/*	时间复杂度:	O (log N)	*/
void Release_T (const TreapTree tt) ;


