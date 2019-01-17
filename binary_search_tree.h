/*  binary_search_tree.h -- 二叉搜索树头文件	*/

/*	数据类型定义	*/
typedef int Item ;
typedef struct node
{
	Item item ;
	int depth ;
	int x_coordinate ;
	int y_coordinate ;
	struct node * left ;
	struct node * right ;
} Node ;
typedef Node * Position ;
typedef Node * Tree ;

/*	接口函数声明	*/

/*	操作:	初始化一棵二叉搜索树	*/
/*	操作前:	ptree 指向一棵二叉搜索树	*/
/*	操作后:	该树被初始化为空树	*/
void InitializeTree (Tree * const ptree) ;

/*	操作:	确定二叉搜索树是否为空	*/
/*	操作前:	ptree 指向一棵已初始化的二叉搜索树	*/
/*	操作后:	如果该树为空, 返回1; 否则返回0	*/
int TreeIsEmpty (const Tree * const ptree) ;

/*	操作:	寻找树中最小结点	*/
/*	操作前:	ptree 指向一棵已初始化的二叉搜索树	*/
/*	操作后:	如果可能, 返回该树中最小的结点; 否则返回NULL	*/
Node * FindMin (const Tree * const ptree) ;

/*	操作:	寻找树中最大结点	*/
/*	擦左前:	ptree 指向一棵已初始化的二叉搜索树	*/
/*	操作后:	如果可能, 返回该树中最小的结点; 否则返回NULL	*/
Node * FindMax (const Tree * const ptree) ;

/*	操作:	向树中添加一个结点	*/
/*	操作前:	ptree 指向一棵已初始化的二叉搜索树, pitem 指向指定添加的数据	*/
/*	操作后:	如果可能, 向树中添加一个新的结点拥有 pitem 指向数据作为数据, 返回1; 否则返回0	*/
int Insert (Tree * const ptree, const Item * const pitem) ;

/*	操作:	从树中删除一个结点	*/
/*	操作前:	tree 是一棵已初始化的二叉搜索树, item 是指定删除的数据	*/
/*	操作后:	如果可能, pitem 指向数据的结点从树中删除, 返回新树; 否则返回原树	*/
Tree Delete (Tree tree, const Item item) ;

/*	操作:	将一个函数作用于树中所有结点(中序)	*/
/*	操作前:	tree 是一棵已初始化的二叉搜索树, pfun 指向一个没有返回值, 接受一个Item类型数据的函数	*/
/*	操作后:	函数作用于该树中所有结点一次(中序)	*/
void InorderTraversal (const Tree tree, void (* pfun) (const Item item)) ;

/*	操作:	清空一棵二叉搜索树	*/
/*	操作恰:	tree 是一棵已初始化的二叉搜索树	*/
/*	操作后:	该树被清空	*/
void EmptyTheTree (const Tree tree) ;