/*  lazy_deletion_linked_list.h -- ����ɾ������ͷ�ļ�  */
/*	�������Ͷ���	*/
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

/*	�ӿں�������	*/

/*	����:	��ʼ��һ������	*/
/*	����ǰ:	plistָ��һ������	*/
/*	������:	������ͷ��㱻��ΪNULL	*/
void InitializeList (List * plist) ;

/*	����:	ȷ�������Ƿ�Ϊ��	*/
/*	����ǰ:	plistָ��һ������	*/
/*	������:	�������Ϊ��,����1;���򷵻�0	*/
int ListIsEmpty (const List * plist) ;

/*	����:	ȷ�������Ƿ�����	*/
/*	����ǰ:	plistָ��һ������	*/
/*	������:	�����������,����1;���򷵻�0	*/
int ListIsFull (const List * plist) ;

/*	����:	���������һ�����	*/
/*	����ǰ:	plistָ��һ���ѳ�ʼ��������,pitemָ��׼������ӵ�����Ľ��	*/
/*	������:	�������,��pitemָ���������ӵ�����β��,����1;���򷵻�0	*/
int AddItem (List * plist, Item * pitem) ;

/*	����:	���跽ʽɾ�������һ�����	*/
/*	����ǰ:	plistָ��һ���ѳ�ʼ��������, pitemָ��׼����ɾ���Ľ��	*/
/*	������:	������������ҵ�*pitem,�������Ƿ��ѱ�ɾ���ı�����Ϊ1, ����1;���򷵻�0	*/
int LazyDeleteItem (List * plist, const Item * pitem) ;

/*	����:	ɾ�������е�һ�����	*/
/*	����ǰ:	pitemָ��һ���ѱ���ʼ��������, pitemָ��ɾ���Ľ��	*/
/*	������:	�������,pitemָ��Ľ�㱻ɾ��,����1;���򷵻�0	*/
int DeleteItem (List * plist, const Item * pitem) ;

/*	����:	��һ�����������������е�����Ԫ��	*/
/*	����ǰ:	plistָ��һ���ѱ���ʼ��������, pfunָ��һ��û�з���ֵ,����һ��ָ��Item��ָ��pitem��ΪΨһ����	*/
/*	������:	pfunָ��ĺ��������õ������е����н��	*/
void Traverse (const List * plist, void (* pfun)(const Item item)) ;

/*	����:	ɾ�������е����н��	*/
/*	����ǰ:	plistָ��һ���ѱ���ʼ��������	*/
/*	������:	plistָ����������н�㱻ɾ��	*/
void DeleteList (List * plist) ;