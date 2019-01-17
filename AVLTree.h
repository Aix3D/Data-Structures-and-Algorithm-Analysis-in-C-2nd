/*  AVLTree.h -- AVl树头文件	*/

/*	数据类型定义	*/

typedef int Item ;
typedef struct node
{
	Item item ;
	struct node * left ;
	struct node * right ;
	int height ;
} Node ;
typedef Node * Position ;
typedef Node * Tree ;

/*	接口函数声明	*/

/*	操作:	初始化一棵AVL树	*/
/*	操作前:	ptree 指向一棵AVL树	*/
/*	操作后:	该树被初始化为空树	*/
void InitializeAVLTree (Tree * ptree) ;

/*	操作:	确定AVL树是否为空	*/
/*	操作前:	tree 是一棵已初始化的AVL树	*/
/*	操作后:	如果该树为空, 返回1; 否则返回0	*/
int AVLTreeIsEmpty (const Tree tree) ;

/*	操作:	返回树中指定数据所在结点	*/
/*	操作前:	tree 是一棵已初始化的AVL树, item 是被查找的数据	*/
/*	操作后:	如果可能, 返回被查找数据所在结点的地址; 否则返回?	*/
Position Find (const Tree tree, const Item item) ;

/*	操作:	返回树中最大数据所在结点位置	*/
/*	操作前:	tree 是一棵已初始化的AVL树	*/
/*	操作后:	如果可能, 返回树中最大数据所在结点的位置; 否则返回NULL	*/
Position FindMax (const Tree tree) ;

/*	操作:	返回树中最小数据所在结点位置	*/
/*	操作前:	tree 是一棵已初始化的AVL树	*/
/*	操作后:	如果可能, 返回树中最小数绝所在结点的位置; 否则返回NULL	*/
Position FindMin (const Tree tree) ;

/*	操作:	向AVL树中插入结点	*/
/*	操作前:	tree 是一棵已初始化的AVL树, item 是准备插入结点的指定数据	*/
/*	操作后:	如果可能, 返回插入结点后的新树; 否则返回原树	*/
Tree Insert (Tree tree, const Item item) ;

/*	操作:	向AVL树中插入结点(非递归实现)	*/
/*	操作前:	tree 是一棵已初始化的AVL树, item 是准备插入结点的指定数据	*/
/*	操作后:	如果可能, 返回插入结点后的新树; 否则返回原树	*/
Tree AddItem (Tree tree, const Item item) ;

/*	操作:	以中序遍历将一个函数作用于AVL树中的所有结点	*/
/*	操作前:	tree 是一棵已初始化的AVL树, pfun 指向一个没有返回值, 接受一个 Position 类型参数的函数	*/
/*	操作后:	该函数被作用到该树的所有结点, 后序中历方式	*/
void InorderTraversal (const Tree tree, void (* pfun) (const Position position)) ;

/*	操作:	删除AVL树中指定数据所在结点	*/
/*	操作前:	tree 是一棵已初始化的AVL树, item 是被删除的数据	*/
/*	操作后:	如果可能, 删除该数据所在结点, 并调整树符合AVL树特性, 返回树根结点地址; 否则不做更改, 返回树根结点地址	*/
Tree Delete (Tree tree, const Item item) ;

/*	操作:	清空一棵AVL树	*/
/*	操作前:	tree 是一棵已初始化的AVL树	*/
/*	操作后:	该树被清空	*/
void EmptyTheAVLTree (Tree tree) ;