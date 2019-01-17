/*  BinarySearchTree.h -- 二叉搜索树头文件  */

/*	数据类型定义	*/

typedef int Item ;
typedef struct node
{
	Item item ;
	struct node * left ;
	struct node * right ;
} Node ;
typedef Node * Position ;
typedef Node * Tree ;

/*	接口函数声明	*/

/*	操作:	将二叉搜索树初始为空	*/
/*	操作前:	ptree 指向一棵二叉搜索树	*/
/*	操作后:	该树被初始化为空	*/
void InitializeTree (Tree * ptree) ;

/*	操作:	确定二叉搜索树是否为空	*/
/*	操作前:	tree 是一棵已初始化的二叉搜索树	*/
/*	操作后:	如果该树为空, 返回1; 否则返回0	*/
int TreeIsEmpty (const Tree tree) ;

/*	操作:	返回二叉搜索树中具有指定数据的结点的位置	*/
/*	操作前:	tree 是一棵已初始化的二叉搜索树, item 是被查找的数据	*/
/*	操作后:	如果可能, 返回具有 item 数据的结点在树中的位置; 否则返回NULL	*/
Position Find (const Tree tree, const Item item) ;

/*	操作:	返回树中的最小数据结点的位置	*/
/*	操作前:	tree 是一棵已初始化的二叉搜索树	*/
/*	操作后:	如果可能, 返回该树中最小数据结点的位置; 否则返回NULL	*/
Position FindMin (const Tree tree) ;

/*	操作:	返回树中的最大数据结点的位置	*/
/*	操作前:	tree 是一棵已初始化的二叉搜索树	*/
/*	操作后:	如果可能, 返回该树中最小数据结点的位置; 否则返回NULL	*/
Position FindMax (const Tree tree) ;

/*	操作:	向二叉搜索树中插入一个结点	*/
/*	操作前:	tree 是一棵已初始化的二叉搜索树, item 是被添加到结点的数据	*/
/*	操作后:	如果可能, 一个具有 item 数据的结点被添加到树中, 返回根结点的位置; 否则返回NULL	*/
Tree Insert (Tree tree, const Item item) ;

/*	操作:	中序遍历二叉搜索树中的所有结点	*/
/*	操作前:	tree 是一棵已初始化的二叉搜索树, pfun 指向一个没有返回值, 接受一个Item类型参数的函数	*/
/*	操作后:	函数 pfun 以中序遍历作用到树中所有结点数据	*/
void InorderTraversal (const Tree tree, void (* pfun) (const Item item)) ;

/*	操作:	删除二叉搜索树中举有指定数据的一个结点	*/
/*	操作前:	tree 是一棵已初始化的二叉搜索树, item 是指定的数据	*/
/*	操作后:	如果可能, 具有 item 数据的结点被从该树中删除, 返回最初接受的结点的指针(通常用法是传递树的根节点指针,于是这么做得到一颗新树);
			否则不改变原树, 返回传入的结点的指针	*/
Tree Delete (Tree tree, const Item item) ;

/*	操作:	清空一棵二叉搜索树	*/
/*	操作前:	tree 是一棵已初始化的二叉搜索树	*/
/*	操作后:	该树被置为为空树	*/
void EmptyTheTree (Tree tree) ;