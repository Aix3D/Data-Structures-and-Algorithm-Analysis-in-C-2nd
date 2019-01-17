/*	new_adjacenty_list.h -- �ڽӱ�ͷ�ļ�	*/
#include <stdarg.h>
#include "hash.h"

#define INFINITY (~(1 << 31))
#define NEGATIVEINFINITY (-INFINITY - 1)

/*	�������Ͷ���	*/

typedef struct adjoin_to_vertex
{
	int hash_value ;
	int cvw ;
	struct adjoin_to_vertex * next ;
} Adjoin_To_Vertex ;
typedef struct vertex
{
	int hash_value ;
	int known ;
	int dist ;
	int weight ;
	Name path ;
	Adjoin_To_Vertex * adjoin_to ;
} Vertex ;
typedef struct adjacenty_list
{
	Vertex * list ;
	int * indegree ;
	int capacity ;
} * Adjacenty_List ;

/*	�ӿں�������	*/

/*	����:	����һ���ڽӱ�	*/
/*	����ǰ:	padj ָ��һ���ڽӱ�, capacity ָʾ�ڽӱ�Ĵ�С	*/
/*	������:	��� capacity > 0 && �ڴ����ɹ�, �������ڽӱ�, ���� 1; ���򷵻� 0	*/
/*	ʱ�临�Ӷ�:	O(1)	*/
int Initialize_A (Adjacenty_List * const padj, const int capacity) ;

/*	����:	��ʼ���ڽӱ��ĳһ��	*/
/*	����ǰ:	padj ָ��һ���ѳ�ʼ�����ڽӱ�, pht ָ��һ���ѳ�ʼ����ɢ�б�, index ָʾ�е�����, name ָʾ��������, indegree ָʾ�������, sub ָʾ�����ĸ���, ... �������ָʾ�ڽӵ��ö���Ķ������ֺͶ��㵽�ö��㹹�ɵıߵ�Ȩ	*/
/*	������:	��� index �ǺϷ������� && indegree >= 0 && sub >= 0, ���б����ղ�����ʼ��, ���� 1; ���򷵻� 0	*/
/*	ʱ�临�Ӷ�:	O(V)	*/
int InitializeALine_A (Adjacenty_List * const padj, const Hash_Table * const pht, const int index, const Name name, const int indegree, const int sub, ...) ;

/*	����:	����֪�ڽӱ����б�ȡ��(�����Ȩͼ)	*/
/*	����ǰ:	padj ָ��һ���ѳ�ʼ�����ڽӱ�, pht ָ��һ���ѳ�ʼ����ɢ�б�	*/
/*	������:	���ڽӱ�����б߱�ȡ����	*/
/*	ʱ�临�Ӷ�:	O(V^2)	*/
int Reverse_A (Adjacenty_List * const padj, const Hash_Table * const pht) ;

/*	����:	��ӡһ���ڽӱ�	*/
/*	����ǰ:	padj ָ��һ���ѳ�ʼ�����ڽӱ�, pht ָ��һ���ѳ�ʼ����ɢ�б�	*/
/*	������:	���ڽӱ���ӡ	*/
/*	ʱ�临�Ӷ�:	O (V)	*/
void PrintAdjacenty_List_A (const Adjacenty_List * const padj, const Hash_Table * const pht) ;

/*	����:	�ͷ�һ���ڽӱ���ռ�õ��ڴ�ռ�	*/
/*	����ǰ:	padj ָ��һ���ѳ�ʼ�����ڽӱ�	*/
/*	������:	���ڽӱ���ռ�õ��ڴ�ռ䱻�ͷ�	*/
/*	ʱ�临�Ӷ�:	O(V)	*/
void Release_A (const Adjacenty_List * const padj) ;