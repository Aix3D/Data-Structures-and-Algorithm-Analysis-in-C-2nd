/*	Separate_Chaining_Hash.h -- ��������ɢ�б�ͷ�ļ�	*/
#define MAXTABLESIZE 4096
#define CONSTANT 10
#define NUL '\0'

/*	�������Ͷ���	*/

typedef int Item ;
typedef struct list_node
{
	Item item ;
	struct list_node * next ;
} ListNode ;
typedef ListNode * Header ;
typedef struct hashtable
{
	int size ;
	Header * lists ;
} * HashTable ;

/*	����:	��ʼ��һ����������ɢ�б�	*/
/*	����ǰ:	size ��ָ����������ɢ�б�Ĵ�С�ı���	*/
/*	������:	�ñ��������ұ��е����б�Ԫָ�뱻��ʼ��Ϊ��, ���ظñ�	*/
HashTable InitializeTable (const int size) ;

/*	����:	���ݴ������Ĳ�������������һ������ֵ	*/
/*	����ǰ:	item ������, size ��ʾ��Ĵ�С	*/
/*	������:	����һ������ֵ	*/
int Hash (const Item item, const int size) ;

/*	����:	����һ��ָ�����ָ���������ڽ���ָ��	*/
/*	����ǰ:	item �Ǳ����ҵ�����, h ��һ���ѳ�ʼ���ı�	*/
/*	������:	�������, ����ָ�����ָ���������ڽ���ָ��; ���򷵻�NULL	*/
Header Find (const Item item, const HashTable h) ;

/*	����:	��һ������ָ�������Բ����½��ķ�ʽ���뵽����	*/
/*	����ǰ:	item �Ǵ����������, ph ָ��һ���ѳ�ʼ���ı�	*/
/*	������:	�������, �� item Ϊ���ݴ���һ����㱻���뵽����(�����ͻ, �����������������ǰ���λ��), ����1; ���򷵻�0	*/
int Insert (const Item item, HashTable * const ph) ;

/*	����:	�ӱ���ɾ��һ�����	*/
/*	����ǰ:	item �Ǵ�ɾ����������, ph ָ��һ���ѳ�ʼ���ı�	*/
/*	������:	�������, item ���ڽ�㱻�ӱ���ɾ��, ����1; ���򷵻�0	*/
int Delete (const Item item, HashTable * const ph) ;

/*	����:	�ӵ��������������һ�����������ڱ������д��ڵĽ��	*/
/*	����ǰ:	ph ָ��һ���ѳ�ʼ���ı�, pfun ָ��һ��û�з���ֵ, ����һ��ListNode *���Ͳ����ĺ���	*/
/*	������:	pfun ָ��ĺ������ӵ���������������õ����д��ڵĽ��һ��	*/
void Traversal (const HashTable * const ph, void (* pfun) (const ListNode * const pnode)) ;

/*	����:	���һ����	*/
/*	����ǰ:	ph ָ��һ���ѳ�ʼ���ı�	*/
/*	������:	�ñ���ռ�õ�ȫ���ڴ�ռ䱻�ͷ�	*/
void Release (HashTable * ph) ;