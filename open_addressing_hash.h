/*	open_addressing_hash.h -- ���Ŷ�ַɢ�б�ͷ�ļ�	*/

enum KindOfEntry {Legitimate, Empty, Deleted} ;

/*	�������Ͷ���	*/

typedef int Item ;
typedef struct cell
{
	Item item ;
	enum KindOfEntry info ;
} Cell ;
typedef struct hashtable
{
	int size ;
	Cell * lists ;
} * HashTable ;

/*	�ӿں�������	*/

/*	����:	����һ��Item���ͱ���, �Դ�Ϊ����ͨ���������һ����ֵ��������	*/
/*	����ǰ:	item ��һ��Item���ͱ���, size �Ǳ�Ĵ�С	*/
/*	������:	�Խ��ܵĲ���Ϊ����ͨ���������һ����ֵ������	*/
int Hash (const Item item, const int size) ;

/*	����:	��������ʼ��һ����	*/
/*	����ǰ:	ph ָ��һ����, size ��ָ�����С�ı���	*/
/*	������:	�������, �ñ������������б�Ԫ��������Ϊ��(��� size ��������, ��ȡ���� size ����С������Ϊ��Ĵ�С), ����1; ���򷵻�0	*/
int InitializeTable (HashTable * const ph, const int size) ;

/*	����:	����һ��ָ��������Ϊ���������ݵ�Ԫ���ڱ��е�λ�õ�ָ��	*/
/*	����ǰ:	ph ָ��һ���ѳ�ʼ���ı�, item �Ǳ����ҵ�����	*/
/*	������:	�������, ���ظ�ָ��; ���򷵻�ָ�����������һ��Ԫ�ص�ָ��	*/
Cell * Find (const HashTable * const ph, const Item item) ;

/*	����:	��������һ��������Ϊָ�����ݵ�Ԫ��	*/
/*	����ǰ:	ph ָ��һ���ѳ�ʼ���ı�, item ��ָ������ӵ�����	*/
/*	������:	�������, ����һ��������Ϊ item ��Ԫ����ӵı���, ����1; ���򷵻�0	*/
int Insert (HashTable * const ph, const Item item) ;

/*	����:	�ӱ�������ɾ��һ��������Ϊָ�����ݵ�Ԫ��	*/
/*	����ǰ:	ph ָ��һ���ѳ�ʼ���ı�, item ��ָ����ɾ��������	*/
/*	������:	�������, ������Ϊ��ָ�����ݵ�Ԫ�ر��ӱ�������ɾ��, ����1; ���򷵻�0	*/
int Delete (HashTable * const ph, const Item item) ;

/*	����:	�ӵ��������������һ���������������ڱ��е�����Ԫ��һ��	*/
/*	����ǰ:	ph ָ��һ���ѳ�ʼ���ı�, pfun ָ��һ��û�з���ֵ, ����һ��Cell���Ͳ����ĺ���	*/
/*	������:	pfun ָ��ĺ����ӱ�ĵ���������������������ڱ��е�����Ԫ��һ��	*/
void Traversal (const HashTable * const ph, void (* pfun) (const Cell cell)) ;

/*	����:	���һ����	*/
/*	����ǰ:	ph ָ��һ���ѳ�ʼ���ı�	*/
/*	������:	�ñ���ռ�õ��ڴ�ռ䱻�ͷ�	*/
void Release (HashTable * const ph) ;