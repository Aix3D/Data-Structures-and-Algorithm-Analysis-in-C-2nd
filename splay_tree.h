/*  splay_tree.h -- 伸展树头文件  */

/*	数据类型定义	*/
typedef int Item ;
typedef struct node
{
	Item item ;
	struct node * left ;
	struct node * right ;
} Node ;
typedef Node * Position ;
typedef Node * SplayTree ;

/*	接口函数声明	*/

/*	操作:	初始化一棵伸展树	*/
/*	操作前:	ptree 指向一棵伸展树	*/
/*	操作后:	该树被初始化为空	*/
void IintializeSplayTree (SplayTree * ptree) ;

/*	操作:	确定一棵伸展树是否为空	*/
/*	操作前:	tree 是一棵已初始化的伸展树	*/
/*	操作后:	如果该树为空, 返回1; 否则返回0	*/
int SplayTreeIsEmpty (const SplayTree tree) ;

/*	操作:	确定一棵伸展树是否已满	*/
/*	操作前:	(该函数不接受任何参数)	*/
/*	操作后:	如果该树已满,返回1; 否则返回0	*/
int SplayTreeIsFull (void) ;

/*	操作:	向树中添加一个结点(非递归)	*/
/*	操作前:	tree 是一棵已初始化的伸展树, item 是一个Item类型数据	*/
/*	操作后:	如果可能, 拥有 item 数据的结点被添加到树中, 返回新树的根节点; 否则返回原树	*/
SplayTree AddItem (SplayTree tree, const Item item) ;

/*	操作:	向树中添加一个结点(递归)	*/
/*	操作前:	tree 是一棵已初始化的伸展树, item 是一个Item类型数据	*/
/*	操作后:	如果可能, 拥有 item 数据的结点被添加到树中, 返回新树的根节点; 否则返回原树	*/
SplayTree Insert (SplayTree tree, const Item item) ;

/*	操作:	找到树中最大数据的结点	*/
/*	操作前:	tree 是一棵已初始化的伸展树	*/
/*	操作后:	如果可能, 返回树中最大数据结点的指针; 否则返回NULL	*/
Position FindMax (const SplayTree tree) ;

/*	操作:	找到树中最小数据的结点	*/
/*	操作前:	tree 是一棵已初始化的伸展树	*/
/*	操作后:	如果可能, 返回树中最小数据结点的指针; 否则返回NULL	*/
Position FindMin (const SplayTree tree) ;

/*	操作:	查找指定数据的结点并放到根节点的位置	*/
/*	操作前:	tree 是一棵已初始化的伸展树, item 是指定的被查找的数据	*/
/*	操作后:	如果可能, 被找到的结点作为根节点, 返回该结点; 否则返回原树	*/
SplayTree Find (SplayTree tree, const Item item) ;

/*	操作:	查找指定数据的结点并放到跟结点的位置(使用栈)	*/
/*	操作前:	tree 是一棵已初始化的伸展树, item 是指定的被查找的数据	*/
/*	操作后:	如果可能, 被找到的结点作为跟结点, 返回该结点; 否则返回原树	*/
SplayTree Find_By_Use_Stack (SplayTree tree, const Item item) ;

/*	操作:	删除指定数据所在结点	*/
/*	操作前:	tree 是一棵已初始化的伸展树, item 是指定的被删除的数据	*/
/*	操作后:	如果可能, 拥有 item 数据的结点被删除, 返回新树的结点; 否则返回原树	*/
SplayTree Delete (SplayTree tree, const Item item) ;

/*	操作:	将一个函数以中序作用于树中所有结点	*/
/*	操作前:	tree 是一棵已初始化的伸展树, pfun 指向一个没有返回值, 接受一个Item类型信息的参数	*/
/*	操作后:	该函数以中序被作用于树中所有结点一次	*/
void InorderTraversal (const SplayTree tree, void (* pfun) (const Item item)) ;