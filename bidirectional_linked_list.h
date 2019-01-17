/*  bidirectional_linked_list.h -- ˫������ͷ�ļ�  */
/*	���Ͷ���	*/
typedef int Item ;
typedef struct node
{
	Item item ;
	struct node * previous ;	/*	ָ����һ���ڵ��ָ��	*/
	struct node * next ;		/*	ָ����һ���ڵ��ָ��	*/
} Node ;
typedef Node * Position ;		/* ָ������ڵ�λ�õ�ָ��	*/
typedef Node * List ;			/* Listָ���ͷ�ڵ�	*/

/*	�ӿں�������	*/

/*	����:	��ʼ��һ������	*/
/*	����ǰ:	plistָ��һ������	*/
/*	������:	list����ʼ��Ϊ������	*/
void InitializeList (List * plist) ;

/*	����:	ȷ�������Ƿ�Ϊ��	*/
/*	����ǰ:	plistָ��һ������	*/
/*	������:	�������Ϊ��,����1;���򷵻�0	*/
int ListIsEmpty (const List * plist) ;

/*	����:	ȷ�������Ƿ�����	*/
/*	����ǰ:	plistָ��һ������	*/
/*	������:	�����������,����1;���򷵻�0	*/
int ListIsFull (const List * plist) ;

/*	����:	�������������	*/
/*	����ǰ:	plistָ��һ������, pitem��ָ��Item���͵�����	*/
/*	������:	�������,pitemָ������ݱ���ӵ�����,��������1;���򷵻�0	*/
int AddItem (List * plist, const Item * pitem) ;

/*	����:	��ͷ��β��������,����pfunָ��ĺ���������������������һ��	*/
/*	����ǰ:	plistָ��һ������, pfunָ��һ��û�з���ֵ,����һ��ָ��Item��ָ��Ĳ���	*/
/*	������:	pfunָ��ĺ�������������ÿ������һ��	*/
void Traverse (const List * plist, void (* pfun) (const Item * pitem)) ;

/*	����:	���һ������	*/
/*	����ǰ:	plistָ��һ������	*/
/*	������:	plistָ����������	*/
void DeleteList (List * plist) ;

/*	����:	������������������ָ��Ԫ�ص�λ��	*/
/*	����ǰ:	position_nowadayָ��������Ҫ����λ�õ�ǰ�ڵ�ǰһ���ڵ��λ��	*/
/*	������:	�������,����ǰ�ڵ���һ���ڵ��λ���뵱ǰ�ڵ��ڶ����ڵ��λ�û���,����1;���򷵻�0	*/
int SwapPosition (Position position_nowaday) ;