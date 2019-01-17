/*  unidirectional_linked_list.h -- ��������ͷ�ļ�  */

/*	���Ͷ���	*/
typedef int Item ;
typedef struct node
{
	Item item ;
	struct node * next ;
} Node ;
typedef Node * Position ;	/* ָ������ڵ�λ�õ�ָ��	*/
typedef Node * List ;		/* Listָ���ͷ�ڵ�	*/

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
/*	����ǰ:	position_nowadayָ��������Ҫ����λ�õĿ�ǰ�ڵ�ǰһ���ڵ��λ��	*/
/*	������:	�������,����ǰ�ڵ���һ���ڵ��λ���뵱ǰ�ڵ��ڶ����ڵ��λ�û���,����1;���򷵻�0	*/
int SwapPosition (Position position_nowaday) ;

/*	����:	ɾ��������ָ���ڵ�(��Է�ѭ������,��Եݹ鷽��)	*/
/*	����ǰ:	plistָ��һ������,pitemָ��һ���ڵ��е���Ŀ	*/
/*	������:	�������,pitemָ��Ľڵ��������ɾ��,����1;���򷵻�0	*/
int RecursiveDeleteItem (List * plist, const Item * pitem) ;

/*	����:	ɾ��������ָ���ڵ�(��Է�ѭ������,��Էǵݹ鷽��)	*/
/*	����ǰ:	plistָ��һ������,pitemָ��һ���ڵ��е���Ŀ	*/
/*	������:	�������,pitemָ��Ľڵ��������ɾ��,����1;���򷵻�0	*/
int DeleteItem (List * plist, const Item * pitem) ;

/*	����:	ɾ��������ָ���ڵ�(���ѭ������)	*/
/*	����ǰ:	plistָ��һ������,pitemָ��һ���ڵ��е���Ŀ	*/
/*	������:	�������,pitemָ��Ľڵ��������ɾ��,����1;���򷵻�0	*/
int DeleteCircularListItem (List * plist, const Item * pitem) ;

/*	����:	���������һ���ڵ�,ʹ��nextָ��ָ��ͷ�ڵ�(���ѭ������)	*/
/*	����ǰ:	plistָ��һ������,pitemָ��һ���ڵ��е���Ŀ	*/
/*	������:	�������,��pitemָ���������ӵ������һ���ڵ�,����1;���򷵻�0	*/
int MakeACircularList (List * plist, const Item * pitem) ;

/*	����:	��תһ������	*/
/*	����ǰ:	plistָ��һ������	*/
/*	������:	�����������ݱ���ת	*/
void InverseList (List * plist) ;

/*	����:	���һ������(���ѭ������)	*/
/*	����ǰ:	plistָ��һ������	*/
/*	������:	plistָ����������	*/
