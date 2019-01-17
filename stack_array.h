/*	stack_array.h -- 数组实现的栈头文件	*/

/*	定义明显常量	*/
#define EMPTYTOPOFSTACK (-1)
#define MINSTACKSIZE (5)

/*	定义数据类型	*/
typedef int Item ;
typedef struct stackrecord
{
	int capacity ;
	int topofstack ;
	Item * array ;
} StackRecord ;
typedef StackRecord * Stack ;

/*	接口函数声明	*/

/*	操作:	创建一个栈	*/
/*	操作前:	maxelements是一个用来指定栈大小的数值	*/
/*	操作后:	如果可能,返回一个栈;否则返回NULL	*/
Stack CreateStack (const int maxelements) ;

/*	操作:	检测栈是否为空	*/
/*	操作前:	stack是一个栈	*/
/*	操作后:	如果栈为空,返回1;否则返回0	*/
int StackIsEmpty (const Stack stack) ;

/*	操作:	检测栈是否已满	*/
/*	操作前:	stack是一个栈	*/
/*	操作后:	如果栈已满,返回1;否则返回0	*/
int StackIsFull (const Stack stack) ;

/*	操作:	数据入栈	*/
/*	操作前:	item是准备入栈的元素,stack是栈	*/
/*	操作后:	如果可能,item元素入栈,返回1;否则返回0	*/
int Push (const Item item, Stack stack) ;

/*	操作:	返回栈顶元素	*/
/*	操作前:	stack是一个栈	*/
/*	操作后:	返回栈顶数据	*/
Item Top (const Stack stack) ;

/*	操作:	从栈顶弹出一个元素	*/
/*	操作前:	stack是一个栈	*/
/*	操作后:	如果可能,从stack栈顶弹出一个元素,返回1;否则返回0	*/
int Pop (Stack stack) ;

/*	操作:	将一个函数作用于栈中所有元素	*/
/*	操作前:	stack是一个栈,pfun指向一个没有返回值,接受一个Item作为参数的函数	*/
/*	操作后:	pfun指向的函数被作用到栈中每一个元素	*/
void Traverse (const Stack stack, void (* pfun)(const Item item)) ;

/*	操作:	释放一个栈	*/
/*	操作前:	stack是一个栈	*/
/*	操作后:	该栈被释放	*/
void DisposeStack (Stack stack) ;