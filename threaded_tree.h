/*	threaded_tree.h -- 线索树头文件	*/
#define LINK 0
#define THREAD 1

/*	数据类型定义	*/

typedef int Item ;
typedef struct node
{
	Item item ;
	struct node * left ;
	struct node * right ;
	int left_tag ;
	int right_tag ;
} Node ;
typedef struct node * Tree ;

/*	接口函数声明	*/

/*	操作:	初始化一棵线索树	*/
/*	操作前:	ptree 指向一棵线索树	*/
/*	操作后:	该树被初始为空树	*/
void InitializeTree (Tree * const ptree) ;

/*	操作:	确定一棵线索树是否为空	*/
/*	操作前:	ptree 指向一棵已初始化的线索树	*/
/*	操作后:	如果该树为空, 返回1; 否则返回0	*/
int TreeIsEmpty (const Tree * const ptree) ;

/*	操作:	向线索树中添加元素	*/
/*	操作前:	ptree 指向一棵已初始化的线索树, pitem 指向被添加的指定数据	*/
/*	操作后:	如果可能, 将拥有 pitem 指向的数据的结点添加到树中, 返回1; 否则返回0	*/
int Insert (Tree * const ptree, const Item * const pitem) ;

/*	操作:	获得指向树中最小数据所在结点的指针	*/
/*	操作前:	ptree 指向一棵已初始化的线索树	*/
/*	操作后:	返回指向树中最小数据所在结点的指针	*/
Node * FindMin (const Tree * const ptree) ;

/*	操作:	获得指向树中最大数据所在结点的指针	*/
/*	操作前:	ptree 指向一棵已初始化的线索树	*/
/*	操作后:	返回指向树中最大数据所在结点的指针	*/
Node * FindMax (const Tree * const ptree) ;

/*	操作:	从线索树中删除一个指定数据所在的结点	*/
/*	操作前:	tree 是一棵已初始化的线索树, item 是的被删除的数据	*/
/*	操作后:	如果可能, pitem 指向数据所在的结点从树中删除, 函数返回新树; 否则函数返回原树	*/
Tree Delete (Tree tree, const Item item) ;

/*	操作:	调用将一棵二叉搜索树中序线索化的函数将该树以先序线索化	*/
/*	操作前:	ptree 指向一棵已初始化的二叉搜索树	*/
/*	操作后:	该树被先序线索化	*/
void PreorderThreading (Tree * const ptree) ;

/*	操作:	调用将一棵二叉搜索树中序线索化的函数将该树以中序线索化	*/
/*	操作前:	ptree 指向一棵已初始化的二叉搜索树	*/
/*	操作后:	该树被中序线索化	*/
void InorderThreading (Tree * const ptree) ;

/*	操作:	调用将一棵二叉搜索树中序线索化的函数将该树以后序线索化	*/
/*	操作前:	ptree 指向一棵已初始化的二叉搜索树	*/
/*	操作后:	该树被后序线索化	*/
void PostorderThreading (Tree * const ptree) ;

/*	操作:	以先序将一个函数作用于树中所有元素	*/
/*	操作前:	tree 是一棵已初始化的线索树, pfun 指向一个没有返回值, 接受一个Item类型参数的函数	*/
/*	操作后:	pfun 指向的函数以先序被作用于树中所有元素一次	*/
void PreorderThreadedTraversal (const Tree tree, void (* pfun) (const Item item)) ;

/*	操作:	以中序将一个函数作用于树中所有元素	*/
/*	操作前:	tree 是一棵已初始化的线索树, pfun 指向一个没有返回值, 接受一个Item类型参数的函数	*/
/*	操作后:	pfun 指向的函数以中序被作用于树中所有元素一次	*/
void InorderThreadedTraversal (const Tree tree, void (* pfun) (const Item item)) ;

/*	操作:	以后序将一个函数作用于树中所有元素	*/
/*	操作前:	tree 是一棵已初始化的线索树, pfun 指向一个没有返回值, 接受一个Item类型参数的函数	*/
/*	操作后:	pfun 指向的函数以后序被作用于树中所有元素一次	*/
void PostorderThreadedTraversal (const Tree tree, void (* pfun) (const Item item)) ;

/*	操作:	以中序将一个函数作用于树中所有元素	*/
/*	操作前:	tree 是一棵已初始化的线索树, pfun 指向一个没有返回值, 接受一个Item类型参数的函数	*/
/*	操作后:	pfun 指向的函数以中序被作用于树中所有元素一次	*/
void InorderTraversal (const Tree tree, void (* pfun) (const Item item)) ;