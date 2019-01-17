/*  self_adjusting_list.h -- 接口头文件  */

/*	定义数据类型	*/
/*	Node具体类型放在接口函数实现文件中	*/
typedef int Item ;
typedef struct node
{
	Item item ;
	struct node * next ;
} Node ;
typedef Node * List ;
typedef Node * Position ;

/* function prototypes */

/*	operation:		initialize a list to empty	*/
/*	preconditions:  plist points to a list	*/
/*	postconditions:	the list is initialized to empty	*/
void InitializeList (List * plist) ;

/*	operation:		determine if list is empty	*/
/*	preconditions:	plist points to a list	*/
/*	postconditions:	function returns 1 if list is empty and returns 0 otherwise	*/
int ListIsEmpty (const List * plist) ;

/*	operation:		determine if list is full	*/
/*	preconditions:	plist points to a list	*/
/*	postconditionsL	function returns 1 if list is full and returns 0 otherwise	*/
int ListIsFull (const List * plist) ;

/*	operation:		add an item to a list	*/
/*	preconditions:	pitem is address of item to be added plist points to the head of an initialized list	*/
/*  postconditions:	if possible, function adds item to list and returns 1; otherwise the function returns 0	*/
int AddItem (List * plist, const Item * pitem) ;

/*	operation:		find an item of the list	*/
/*	preconditions:	pitem points an item, plist points an initialized list	*/
/*	postconditions:	if *pitem is one element of the list, the head poniter points to pitem and other element's opposite position are abiding,return 1 and function
					returns 0 otherwise	*/
int FindItem (List * plist, const Item * pitem) ;

/*	operation:		apply a function to each item in the list	*/
/*	preconditions:	plist points to a list.pfun points to a function that takes an Item argument and has no return value	*/
/*	postconditions:	the function pointed to by pfun is executed once for each item in the list	*/
void Traverse (const List * plist, void (* pfun)(const Item item)) ;

/*	operation:		Delete everything from a list	*/
/*	preconditions:	plist points to an initialized list	*/
/*	postconditions:	list is empty	*/
void DeleteAll (List * plist) ;