/*	stack.h -- ջ�ӿ��ļ�	*/
#ifndef NUL
#define NUL '\0'
#define SIZE 20

/*	���Ͷ���	*/
typedef char Item ;
typedef struct node
{
	Item item[SIZE] ;
	struct node * next ;
} Node ;
typedef Node * Stack ;

/*	��������	*/

/*	����:	��ʼ��һ��ջ	*/
/*	����ǰ:	pstackָ��һ��ջ	*/
/*	������:	pstackָ���ջ����Ϊ��ջ	*/
void InitializeStack (Stack * pstack) ;

/*	����:	���ջ�Ƿ�Ϊ��	*/
/*	����ǰ:	pstackָ��һ���ѳ�ʼ����ջ	*/
/*	������:	���ջΪ��,����1;���򷵻�0	*/
int StackIsEmpty (const Stack * pstack) ;

/*	����:	���ջ�Ƿ�����	*/
/*	����ǰ:	pstackָ��һ���ѳ�ʼ����ջ	*/
/*	������:	���ջ����,����1;���򷵻�0	*/
int StackIsFull (const Stack * pstack) ;

/*	����:	ͳ��ջ�н������	*/
/*	����ǰ:	pstackָ��һ���Ѿ���ʼ����ջ	*/
/*	������:	����ջ�н�������	*/
int StackItemCount (const Stack * pstack) ;

/*	����:	��ջ����ӽ��	*/
/*	����ǰ:	pstackָ��һ���ѳ�ʼ����ջ,pitemָ��Ҫ��ӵ�ջ������	*/
/*	������:	�������,����һ������pitemָ������ݵĽ����ӵ�ջ��,����1;���򷵻�0	*/
int Push (Stack * pstack, const Item * pitem) ;

/*	����:	����ջ���������	*/
/*	����ǰ:	pstackָ��һ���ѳ�ʼ����ջ	*/
/*	������:	�������,����ջ����������;���򷵻�NUL	*/
Item * Top (const Stack * pstack) ;

/*	����:	��ջ������һ�����	*/
/*	����ǰ:	pstackָ��һ���ѳ�ʼ����ջ	*/
/*	������:	�������,ջ����㱻����,����1;���򷵻�0	*/
int Pop (Stack * pstack) ;

/*	����:	��һ���������õ�ջ��ÿ�����	*/
/*	����ǰ:	pstackָ��һ���Ѿ���ʼ����ջ,pfunָ��һ��û�з���ֵ,����һ��ָ��Item���͵�ָ������ĺ���	*/
/*	������:	pfunָ��ĺ��������õ�ջ��ÿ�����һ��	*/
void Traverse (const Stack * pstack, void (* pfun)(const Item * pitem)) ;

/*	����:	���ջ	*/
/*	����ǰ:	pstackָ��һ���ѳ�ʼ����ջ	*/
/*	������:	pstackָ���ջ����Ϊ��	*/
void DeleteStack (Stack * pstack) ;

#endif