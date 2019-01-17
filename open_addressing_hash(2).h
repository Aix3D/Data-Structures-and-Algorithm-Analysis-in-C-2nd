/*	open_addressing_hash(2).h -- ���Ŷ�ַɢ�б�ͷ�ļ�	*/
enum KindOfEntry {Legitimate, Empty, Deleted} ;

/*	�������Ͷ���	*/

typedef int Item ;
typedef struct cell
{
	Item item ;
	enum KindOfEntry entry ;
} Cell ;
typedef struct hashtable
{
	int size ;
	Cell * lists ;
} * HashTable ;

/*	�ӿں�������	*/

/*	����:	���ݴ����������ݲ���һ��ֵ������	*/
/*	����ǰ:	item , size ���������������ֵ������	*/
/*	������:	ͨ���������һ��ֵ������	*/
int Hash (const int item, const int size) ;

/*	����:	��������ʼ��һ����	*/
/*	����ǰ:	ph ָ��һ����, size ��ָʾ��Ĵ�С�ı���	*/
/*	������:	�������, �ñ�������������Ԫ����������Ϊ��, ��� size ��������, ��ȡ���� size ����С����Ϊ��Ĵ�С, ����1; ���򷵻�0	*/
int InitializeTable (HashTable * const ph, const int size) ;

/*	����:	���Ҳ����ر���������Ϊָ�����ݵ�Ԫ��	*/
/*	����ǰ:	ph ָ��һ���ѳ�ʼ���ı�, item ��ָ��������	*/
/*	������:	�������, ����һ��ָ��������Ϊָ�����ݵ�Ԫ�ص�ָ��; ���򷵻�һ��ָ��ͣ���ڲ��ҹ��̽���ʱԪ��λ�õ�ָ��	*/
Cell * Find (const HashTable * const ph, const Item item) ;

/*	����:	��������һ��������Ϊָ�����ݵ�Ԫ��	*/
/*	����ǰ:	ph ָ��һ���ѳ�ʼ���ı�, item ��ָ��������	*/
/*	������:	�������, ������Ϊָ�����ݵ�Ԫ�ر���ӵ�����, ����1; ���򷵻�0	*/
int Insert (const HashTable * const ph, const Item item) ;

/*	����:	�ӱ���ɾ��һ��������Ϊָ�����ݵ�Ԫ��	*/
/*	����ǰ:	ph ָ��һ���ѳ�ʼ���ı�, item ��ָ��������	*/
/*	������:	�������, ������Ϊָ�����ݵ�Ԫ�ر��ӱ���ɾ��, ����1; ���򷵻�0	*/
int Delete (const HashTable * const ph, const Item item) ;

/*	����:	�ӵ���������������ν�һ�����������ڱ�������Ԫ��һ��	*/
/*	����ǰ:	ph ָ��һ���ѳ�ʼ���ı�, pfun ָ��һ��û�з���ֵ, ����һ��Cell���Ͳ����ĺ���	*/
/*	������:	�ӵ���������������ν� pfun ָ��ĺ��������ڱ�������Ԫ��һ��	*/
void Traversal (const HashTable * const ph, void (* pfun) (const Cell cell)) ;

/*	����:	�ͷ�һ����ռ�õ��ڴ�ռ�	*/
/*	����ǰ:	ph ָ��һ���ѳ�ʼ���ı�	*/
/*	������:	�ñ�ռ�õ��ڴ�ռ䱻�ͷ�	*/
void Release (const HashTable * const ph) ;