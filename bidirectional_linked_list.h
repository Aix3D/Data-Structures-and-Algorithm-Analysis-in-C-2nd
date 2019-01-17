/*  bidirectional_linked_list.h -- 双向链表头文件  */
/*	类型定义	*/
typedef int Item ;
typedef struct node
{
	Item item ;
	struct node * previous ;	/*	指向上一个节点的指针	*/
	struct node * next ;		/*	指向下一个节点的指针	*/
} Node ;
typedef Node * Position ;		/* 指向链表节点位置的指针	*/
typedef Node * List ;			/* List指向表头节点	*/

/*	接口函数声明	*/

/*	操作:	初始化一个链表	*/
/*	操作前:	plist指向一个链表	*/
/*	操作后:	list被初始化为空链表	*/
void InitializeList (List * plist) ;

/*	操作:	确定链表是否为空	*/
/*	操作前:	plist指向一个链表	*/
/*	操作后:	如果链表为空,返回1;否则返回0	*/
int ListIsEmpty (const List * plist) ;

/*	操作:	确定链表是否已满	*/
/*	操作前:	plist指向一个链表	*/
/*	操作后:	如果链表已满,返回1;否则返回0	*/
int ListIsFull (const List * plist) ;

/*	操作:	向链表添加数据	*/
/*	操作前:	plist指向一个链表, pitem是指向Item类型的数据	*/
/*	操作后:	如果可能,pitem指向的数据被添加到链表,函数返回1;否则返回0	*/
int AddItem (List * plist, const Item * pitem) ;

/*	操作:	从头至尾遍历链表,并将pfun指向的函数作用链表中所有数据一次	*/
/*	操作前:	plist指向一个链表, pfun指向一个没有返回值,接受一个指向Item的指针的参数	*/
/*	操作后:	pfun指向的函数作用链表中每个数据一次	*/
void Traverse (const List * plist, void (* pfun) (const Item * pitem)) ;

/*	操作:	清空一个链表	*/
/*	操作前:	plist指向一个链表	*/
/*	操作后:	plist指向的链表被清空	*/
void DeleteList (List * plist) ;

/*	操作:	交换链表中相邻两个指定元素的位置	*/
/*	操作前:	position_nowaday指向链表中要交换位置的前节点前一个节点的位置	*/
/*	操作后:	如果可以,将当前节点后第一个节点的位置与当前节点后第二个节点的位置互换,返回1;否则返回0	*/
int SwapPosition (Position position_nowaday) ;