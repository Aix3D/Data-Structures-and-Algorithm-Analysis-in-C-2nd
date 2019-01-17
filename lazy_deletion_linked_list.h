/*  lazy_deletion_linked_list.h -- 懒惰删除链表头文件  */
/*	数据类型定义	*/
typedef struct item
{
	int num ;
	unsigned int index	: 1 ;
} Item ;

typedef struct node
{
	Item item ;
	struct node * next ;
} Node ;
typedef Node * Position ;
typedef Node * List ;

/*	接口函数声明	*/

/*	操作:	初始化一个链表	*/
/*	操作前:	plist指向一个链表	*/
/*	操作后:	该链表头结点被赋为NULL	*/
void InitializeList (List * plist) ;

/*	操作:	确定链表是否为空	*/
/*	操作前:	plist指向一个链表	*/
/*	操作后:	如果链表为空,返回1;否则返回0	*/
int ListIsEmpty (const List * plist) ;

/*	操作:	确定链表是否已满	*/
/*	操作前:	plist指向一个链表	*/
/*	操作后:	如果链表已满,返回1;否则返回0	*/
int ListIsFull (const List * plist) ;

/*	操作:	向链表添加一个结点	*/
/*	操作前:	plist指向一个已初始化的链表,pitem指向准备被添加到链表的结点	*/
/*	操作后:	如果可能,将pitem指向的数据添加到链表尾部,返回1;否则返回0	*/
int AddItem (List * plist, Item * pitem) ;

/*	操作:	懒惰方式删除链表的一个结点	*/
/*	操作前:	plist指向一个已初始化的链表, pitem指向准备被删除的结点	*/
/*	操作后:	如果在链表中找到*pitem,则将其标记是否已被删除的变量置为1, 返回1;否则返回0	*/
int LazyDeleteItem (List * plist, const Item * pitem) ;

/*	操作:	删除链表中的一个结点	*/
/*	操作前:	pitem指向一个已被初始化的链表, pitem指向被删除的结点	*/
/*	操作后:	如果可能,pitem指向的结点被删除,返回1;否则返回0	*/
int DeleteItem (List * plist, const Item * pitem) ;

/*	操作:	将一个函数作用于链表中的所有元素	*/
/*	操作前:	plist指向一个已被初始化的链表, pfun指向一个没有返回值,接受一个指向Item的指针pitem作为唯一参数	*/
/*	操作后:	pfun指向的函数被作用到链表中的所有结点	*/
void Traverse (const List * plist, void (* pfun)(const Item item)) ;

/*	操作:	删除链表中的所有结点	*/
/*	操作前:	plist指向一个已被初始化的链表	*/
/*	操作后:	plist指向的链表所有结点被删除	*/
void DeleteList (List * plist) ;