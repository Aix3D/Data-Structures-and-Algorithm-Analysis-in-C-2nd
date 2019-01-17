/*	open_addressing_hash_with_hashing_again.h -- ���Ŷ�ַɢ�б�����̽�ⷨ����ɢ��ͷ�ļ�	*/
enum KindOfEntry {Legitimate, Empty, Deleted} ;
#define ZERO 0
#define ONE 1
#define TWO 2

/*	�������Ͷ���	*/

typedef int Item ;
typedef struct cell
{
	Item item ;
	enum KindOfEntry info ;
	int times ;
} Cell ;
typedef struct hashtable
{
	int size ;
	int used ;				/*	ʹ����Ԫ�ص�����, �ظ���Ӳ����Ӵ�����	*/
	Cell * lists ;
} * HashTable ;

/*	����:	���ݴ����������ݲ���һ����ֵ������	*/
/*	����ǰ:	key , size �Ǵ�����������	*/
/*	������:	���� key, size ��ֵ����һ����ֵ������	*/
int Hash (const int key, const int size) ;

/*	����:	���ݴ������Ĳ�������һ��int����ֵ������	*/
/*	����ǰ:	item �Ǵ������Ĳ���	*/
/*	������:	����һ��int����ֵ������	*/
int Change (const Item item) ;

/*	����:	��������ʼ��һ����	*/
/*	����ǰ:	ph ָ��һ��δ��ʼ���ı�, size ������ָʾ���С�ı���	*/
/*	������:	����ڴ�ռ����ɹ�, ������, ��������Ԫ����������Ϊ��, ��� size ����������ȡ���� size ����С����Ϊ��Ĵ�С, ����1; ���򲻴�����, ����0	*/
int InitializeTable (HashTable * const ph, const int size) ;

/*	����:	����һ��������Ϊָ�����ݵ�Ԫ���ڱ��е�λ�ò�����ָ���λ�õ�ָ��	*/
/*	����ǰ:	ph ָ��һ���ѳ�ʼ���ı�, item ��ָ������	*/
/*	������:	����ҵ�, ����һ��ָ��������Ϊָ�����ݵ�Ԫ�ص�ָ��; ���򷵻�һ��ָ����ҽ���ʱͣ��Ԫ�ش���ָ��	*/
Cell * Find (const HashTable * const ph, const Item item) ;

/*	����:	��������һ��������Ϊָ�����ݵ�Ԫ��	*/
/*	����ǰ:	ph ָ��һ���ѳ�ʼ���ı�, item ��ָ������	*/
/*	������:	����ҵ���������Ԫ�ص�λ��, ��������Ϊָ�����ݵ�Ԫ����ӵ�����, ���ظ�����ӳ��ִ���, ����1; ���򷵻�0	*/
int Insert (const HashTable * const ph, const Item item) ;

/*	����:	��һ������ɢ��Ϊ��СΪ���ڵ���ԭ���С2������С�����ı�, �������ݿ������±�, �ͷ�ԭ��ռ�õ��ڴ�ռ�	*/
/*	����ǰ:	ph ָ��һ���ѳ�ʼ���ı�	*/
/*	������:	����ڴ�ռ����ɹ�, �±�����, ��СΪ���ڵ���ԭ���С2������С�����ı�, ԭ�����ݿ������±�, ����1; ���򲻸ı�ԭ��, ����0	*/
int HashAgain (const HashTable * const ph) ;

/*	����:	��һ��������Ϊָ�����ݵ�Ԫ�شӱ���ɾ��	*/
/*	����ǰ:	ph ָ��һ���ѳ�ʼ���ı�	*/
/*	����ǰ:	����ҵ�������Ϊָ�����ݵ�Ԫ��, ����ӱ���ɾ��, ����1; ���򷵻�0	*/
int Delete (const HashTable * const ph, const Item item) ;

/*	����:	�ӵ���������������ν�һ�����������ڱ�������Ԫ��1��	*/
/*	����ǰ:	ph ָ��һ���ѳ�ʼ���ı�, pfun ָ��һ��û�з���ֵ, ����һ��Cell���Ͳ����ĺ���	*/
/*	������:	�ӵ������������һ�ν�pfunָ��ĺ��������ڱ�������Ԫ��1��	*/
void Traversal (const HashTable * const ph, void (* pfun) (const Cell cell)) ;

/*	����:	�ͷ�һ����ռ�õ��ڴ�ռ�	*/
/*	����ǰ:	ph ָ��һ���ѳ�ʼ���ı�	*/
/*	������:	�ñ�ռ�õ��ڴ�ռ䱻�ͷ�	*/
void Release (const HashTable * const ph) ;