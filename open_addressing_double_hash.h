/*	open_addressing_double_hash.h -- ���Ŷ�ַɢ�б�˫ɢ��ͷ�ļ�	*/
enum KindOfEntry {Legitimate, Empty, Deleted} ;
#define PRIME 7

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

/*	����:	�������������������ݲ���һ�����ݲ�����	*/
/*	����ǰ: item �� size �ǽ��ܵ�����	*/
/*	������:	����item �� size ����һ�����ݲ�����	*/
int Hash (const int item, const int size) ;

/*	����:	�������������������ݲ���һ�����ݲ�����	*/
/*	����ǰ: item �� prime �ǽ��ܵ�����	*/
/*	������:	����item �� prime ����һ�����ݲ�����	*/
int Hash2 (const int item, const int prime) ;

/*	����:	��������ʼ��һ����	*/
/*	����ǰ:	ph ָ��һ����, size ������ָʾ���С�ı���	*/
/*	������:	�������, �����ñ�, ��������Ԫ����������Ϊ��, ��� size ������, ȡ size Ϊ��Ĵ�С, ����ȡ���� size ����С����Ϊ��Ĵ�С, ����1; ���򷵻�0	*/
int InitializeTable (HashTable * const ph, const int size) ;

/*	����:	���Ҳ�����һ��ָ��������Ϊָ�����ݵ�Ԫ�ص�ָ��	*/
/*	����ǰ:	ph ָ��һ���ѳ�ʼ���ı�, item ��ָ�������ҵ�����	*/
/*	������:	�������, ����һ��ָ�򱻲���Ԫ�ص�ָ��; ���򷵻�һ��ָ����ҽ���ʱԪ��λ�õ�ָ��	*/
Cell * Find (const HashTable * const ph, const Item item) ;

/*	����:	��������һ��������Ϊָ�����ݵĽ��	*/
/*	����ǰ:	ph ָ��һ���ѳ�ʼ���ı�, item ��ָ������ӵ�����	*/
/*	������:	�������, ������Ϊָ�����ݵ�һ���½�㱻��ӵ�����, ����1; �������, ����0	*/
int Insert (const HashTable * const ph, const Item item) ;

/*	����:	�ӱ���ɾ��һ��������Ϊָ�����ݵĽ��	*/
/*	����ǰ: ph ָ��һ���ѳ�ʼ���ı�, item ��ָ����ɾ��������	*/
/*	������:	�������, ������Ϊָ�����ݵ�һ����㱻�ӱ���ɾ��, ����1; ����ɾ��, ����0	*/
int Delete (const HashTable * const ph, const Item item) ;

/*	����:	�ӵ���������������ν�һ�����������ڱ�������Ԫ��һ��	*/
/*	����ǰ:	ph ָ��һ���ѳ�ʼ���ı�, pfun ָ��һ��û�з���ֵ, ����һ��Cell���Ͳ����ĺ���	*/
/*	������:	pfun ָ��ĺ����ӵ���������������������ڱ�������Ԫ��һ��	*/
void Traversal (const HashTable * const ph, void (* pfun) (const Cell cell)) ;

/*	����:	�ͷ�һ����ռ�õ��ڴ�ռ�	*/
/*	����ǰ: ph ָ��һ���ѳ�ʼ���ı�	*/
/*	������: �ñ�ռ�õ��ڴ�ռ䱻�ͷ�	*/
void Release (const HashTable * const ph) ;