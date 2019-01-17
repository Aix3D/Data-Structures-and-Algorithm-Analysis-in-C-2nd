/*	stack_array.h -- ����ʵ�ֵ�ջͷ�ļ�	*/

/*	�������Գ���	*/
#define EMPTYTOPOFSTACK (-1)
#define MINSTACKSIZE (5)

/*	������������	*/
typedef int Item ;
typedef struct stackrecord
{
	int capacity ;
	int topofstack ;
	Item * array ;
} StackRecord ;
typedef StackRecord * Stack ;

/*	�ӿں�������	*/

/*	����:	����һ��ջ	*/
/*	����ǰ:	maxelements��һ������ָ��ջ��С����ֵ	*/
/*	������:	�������,����һ��ջ;���򷵻�NULL	*/
Stack CreateStack (const int maxelements) ;

/*	����:	���ջ�Ƿ�Ϊ��	*/
/*	����ǰ:	stack��һ��ջ	*/
/*	������:	���ջΪ��,����1;���򷵻�0	*/
int StackIsEmpty (const Stack stack) ;

/*	����:	���ջ�Ƿ�����	*/
/*	����ǰ:	stack��һ��ջ	*/
/*	������:	���ջ����,����1;���򷵻�0	*/
int StackIsFull (const Stack stack) ;

/*	����:	������ջ	*/
/*	����ǰ:	item��׼����ջ��Ԫ��,stack��ջ	*/
/*	������:	�������,itemԪ����ջ,����1;���򷵻�0	*/
int Push (const Item item, Stack stack) ;

/*	����:	����ջ��Ԫ��	*/
/*	����ǰ:	stack��һ��ջ	*/
/*	������:	����ջ������	*/
Item Top (const Stack stack) ;

/*	����:	��ջ������һ��Ԫ��	*/
/*	����ǰ:	stack��һ��ջ	*/
/*	������:	�������,��stackջ������һ��Ԫ��,����1;���򷵻�0	*/
int Pop (Stack stack) ;

/*	����:	��һ������������ջ������Ԫ��	*/
/*	����ǰ:	stack��һ��ջ,pfunָ��һ��û�з���ֵ,����һ��Item��Ϊ�����ĺ���	*/
/*	������:	pfunָ��ĺ��������õ�ջ��ÿһ��Ԫ��	*/
void Traverse (const Stack stack, void (* pfun)(const Item item)) ;

/*	����:	�ͷ�һ��ջ	*/
/*	����ǰ:	stack��һ��ջ	*/
/*	������:	��ջ���ͷ�	*/
void DisposeStack (Stack stack) ;