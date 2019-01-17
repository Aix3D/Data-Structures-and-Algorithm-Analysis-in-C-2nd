/*	stack.h -- 栈接口文件	*/
#ifndef NUL
#define NUL '\0'
#define SIZE 20

/*	类型定义	*/
typedef char Item ;
typedef struct node
{
	Item item[SIZE] ;
	struct node * next ;
} Node ;
typedef Node * Stack ;

/*	函数声明	*/

/*	操作:	初始化一个栈	*/
/*	操作前:	pstack指向一个栈	*/
/*	操作后:	pstack指向的栈被置为空栈	*/
void InitializeStack (Stack * pstack) ;

/*	操作:	检查栈是否为空	*/
/*	操作前:	pstack指向一个已初始化的栈	*/
/*	操作后:	如果栈为空,返回1;否则返回0	*/
int StackIsEmpty (const Stack * pstack) ;

/*	操作:	检查栈是否已满	*/
/*	操作前:	pstack指向一个已初始化的栈	*/
/*	操作后:	如果栈已满,返回1;否则返回0	*/
int StackIsFull (const Stack * pstack) ;

/*	操作:	统计栈中结点数量	*/
/*	操作前:	pstack指向一个已经初始化的栈	*/
/*	操作后:	返回栈中结点的数量	*/
int StackItemCount (const Stack * pstack) ;

/*	操作:	向栈顶添加结点	*/
/*	操作前:	pstack指向一个已初始化的栈,pitem指向要添加到栈的数据	*/
/*	操作后:	如果可能,创建一个具有pitem指向的数据的结点添加到栈顶,返回1;否则返回0	*/
int Push (Stack * pstack, const Item * pitem) ;

/*	操作:	返回栈顶结点数据	*/
/*	操作前:	pstack指向一个已初始化的栈	*/
/*	操作后:	如果可能,返回栈顶结点的数据;否则返回NUL	*/
Item * Top (const Stack * pstack) ;

/*	操作:	从栈顶弹出一个结点	*/
/*	操作前:	pstack指向一个已初始化的栈	*/
/*	操作后:	如果可能,栈顶结点被弹出,返回1;否则返回0	*/
int Pop (Stack * pstack) ;

/*	操作:	将一个函数作用到栈中每个结点	*/
/*	操作前:	pstack指向一个已经初始化的栈,pfun指向一个没有返回值,接受一个指向Item类型的指针参数的函数	*/
/*	操作后:	pfun指向的函数被作用到栈中每个结点一次	*/
void Traverse (const Stack * pstack, void (* pfun)(const Item * pitem)) ;

/*	操作:	清空栈	*/
/*	操作前:	pstack指向一个已初始化的栈	*/
/*	操作后:	pstack指向的栈被置为空	*/
void DeleteStack (Stack * pstack) ;

#endif