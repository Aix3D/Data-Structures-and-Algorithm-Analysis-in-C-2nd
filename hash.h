/*	hash.h -- ��ϣ��ͷ�ļ�	*/
enum KindOfEntry {LEGITIMATE, EMPTY, DELETED} ;

#define PRIME (7)
#define FAILED (-2)
#define NUL ('\0')
#define FALSE (0)
#define TRUE (1)

/*	�������Ͷ���	*/

typedef char Name ;
typedef struct cell
{
	Name name ;
	int be_deleted ;		//	�����ȶ������Ƿ�����ɾ������
	enum KindOfEntry entry ;
	int index_in_adjacenty_list ;
} Cell ;
typedef struct hash_table
{
	Cell * lists ;
	int current ;
	int capacity ;
} * Hash_Table ;

/*	�ӿں�������	*/

/*	����:	����һ�����ݲ���һ����ֵ������	*/
/*	����ǰ:	pht ָ��һ���ѳ�ʼ����ɢ�б�, pname ָ��һ������	*/
/*	������:	���ݸ����ݲ���һ����ֵ������	*/
/*	ʱ�临�Ӷ�:	O(1)	*/
int Hash (const Hash_Table * const pht, const Name * const pname) ;

/*	����:	��������ʼ��һ��ɢ�б�	*/
/*	����ǰ:	pht ָ��һ��ɢ�б�, capacity ��ָʾ���С������	*/
/*	������:	��� capacity > 0 && �ڴ����ɹ�, ��ɢ�б�����Ϊ >= capacity ��С������С����ʼ��Ϊ��, ����1; ���򷵻�0	*/
/*	ʱ�临�Ӷ�:	O(1)	*/
int Initialize_H (Hash_Table * const pht, const int capacity) ;

/*	����:	���Ҳ�����һ��ָ��������ɢ�б��е�λ�õ�ָ��	*/
/*	����ǰ:	pht ָ��һ���ѳ�ʼ����ɢ�б�, pname ָ�򱻲��ҵ�����	*/
/*	������:	����ҵ�������Ϊ *pname ��Ԫ��, ����ָ���Ԫ�ص�ָ��; ���򷵻�ָ����ҽ���ʱֹͣ��ɢ�б�Ԫ�ص�ָ��	*/
/*	ʱ�临�Ӷ�: O(N)	*/
Cell * Find_H (const Hash_Table * const pht, const Name * const pname) ;

/*	����:	��ɢ�б������һ��Ԫ�ز�������ɢ�б��е�����	*/
/*	����ǰ:	pht ָ��һ���ѳ�ʼ����ɢ�б�, pname ��ָ�����ֵ�ָ��, index ��Ԫ�����ڽӱ��е�����	*/
/*	������:	�����ǰ��С <= ���С��һ��, ��Ӹ�Ԫ��, ���ص�ǰ����; ���򷵻� FAILED	*/
/*	ʱ�临�Ӷ�: O(N)	*/
int Insert_H (const Hash_Table * const pht, const Name * const pname, const int index) ;

/*	����:	��ɢ�б�������ɾ��������Ϊָ�����ݵ�Ԫ��	*/
/*	����ǰ:	pht ָ��һ���ѳ�ʼ����ɢ�б�, pname ��ָ�����ֵ�ָ��	*/
/*	������:	����ҵ���Ԫ��, �����������ɾ��, ���� 1 ; ���򷵻� 0	*/
/*	ʱ�临�Ӷ�:	O(N)	*/
int Delete_H (const Hash_Table * const pht, const Name * const pname) ;

/*	����:	�ͷ�һ��ɢ�б���ռ�õ��ڴ�ռ�	*/
/*	����ǰ:	pht ָ��һ���ѳ�ʼ����ɢ�б�	*/
/*	������:	��ɢ�б���ռ�ڴ�ռ䱻�ͷ�	*/
/*	ʱ�临�Ӷ�:	O(1)	*/
void Release_H (const Hash_Table * const pht) ;