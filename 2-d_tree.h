/*  2-d_tree.h -- 2-d树头文件	*/
#define ODD 1
#define EVEN 0
#define TRUE 1
#define FALSE 0

/*	数据类型定义	*/
typedef int Item ;
typedef struct node
{
	int layer ;
	Item key1, key2 ;
	struct node * left ;
	struct node * right ;
} Node ;
typedef Node * Tree ;

/*	接口函数声明	*/

/*	操作:	初始化一个2-d树	*/
/*	操作前:	ptree 指向一棵2-d树	*/
/*	操作后:	该树被初始化为空树	*/
void InitializeTree (Tree * const ptree) ;

/*	操作:	确定一棵2-d树是否为空	*/
/*	操作前:	ptree 指向一棵已初始化的2-d树	*/
/*	操作后:	如果该树为空, 函数返回1; 否则函数返回0	*/
int TreeIsEmpty (const Tree * const ptree) ;

/*	操作:	返回一棵2-d树最左侧的结点的指针	*/
/*	操作前:	ptree 指向一棵已初始化的2-d树	*/
/*	操作后:	返回该树中最左侧的结点的指针	*/
Node * FindMin (const Tree * const ptree) ;

/*	操作:	返回一棵2-d树最右侧结点的指针	*/
/*	操作前:	ptree 指向一棵已初始化的2-d树	*/
/*	操作后:	返回该树中最右侧结点的指针	*/
Node * FindMax (const Tree * const ptree) ;

/*	操作:	向树中添加一个数据为指定数据的结点	*/
/*	操作前:	ptree 指向一棵已初始化的2-d树, pkey1 指向第一个关键字, pkey2 指向第二个关键字	*/
/*	操作后:	如果可能, 一个关键字1同 *pkey1 相同, 关键字2同 *pkey2 相同的结点被添加到树中, 函数返回1; 否则函数返回0	*/
int Insert (Tree * const ptree, const Item * const pkey1, const Item * const pkey2) ;

/*	操作:	以中序将一个函数作用于树中满足low1 <= key1 <= high1 && low2 <= key2 <= high2的所有结点	*/
/*	操作前:	ptree 指向一棵已初始化的2-d树, low1, high1, low2, high2代表范围, pfun 指向一个没有返回值, 接受一个指向Item类型的指针的函数	*/
/*	操作后: 以中序将一个函数作用于树中满足low1 <= key1 <= high1 && low2 <= key2 <= high2的所有结点	*/
void InorderSeekTraversal (const Tree * const ptree, const Item low1, const Item low2, const Item high1, const Item high2, void (* pfun) (const Item * const pkey1, const Item * const pejy2)) ;

/*	操作:	从2-d树中删除一个数据为指定数据的结点	*/
/*	操作前:	ptree 指向一棵已初始化的2-d树, pkey1 指向关键字1, peky2 指向关键字2	*/
/*	操作后:	如果可能, 从树中删除该结点并返回新树; 否则返回原树	*/
Tree Delete (Tree * const ptree, const Item * const pkey1, const Item * const pkey2) ;