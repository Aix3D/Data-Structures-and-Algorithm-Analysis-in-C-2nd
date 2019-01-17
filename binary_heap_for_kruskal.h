/*	binary_heap_for_kruskal.h -- �����ͷ�ļ�	*/
#include "new_adjacenty_list.h"

/*	�������Ͷ���	*/

typedef struct edge
{
	int v_hash_value ;
	int w_hash_value ;
	int weight ;
} Edge ;
typedef struct binary_heap
{
	Edge * heap ;
	int capacity ;
	int current ;
} * Binary_Heap ;

/*	�ӿں�������	*/

/*	����:	��������ʼ��һ�������	*/
/*	����ǰ:	pbh ָ��һ�������, capacity ָʾ�öѵĴ�С	*/
/*	������:	��� capacity > 0 && �ڴ����ɹ�, �����ö�, ���� 1 ; ���򷵻� 0	*/
/*	ʱ�临�Ӷ�: O(1)	*/
int Initialize_B (Binary_Heap * const pbh, const int capacity) ;

/*	����:	��������һ��������Ϊָ�����ݵ�Ԫ��	*/
/*	����ǰ:	pbh ָ��һ���ѳ�ʼ���Ķ����, pd ָ�����ӵı�	*/
/*	������:	�����δ��, �������������Ԫ��, ���� 1 ; ���򷵻� 0	*/
/*	ʱ�临�Ӷ�: O (log N)	*/
int Insert_B (const Binary_Heap * const pbh, const Edge * const pd) ;

/*	����:	ɾ�����е� weight ����С��Ԫ��	*/
/*	����ǰ:	pbh ָ��һ���ѳ�ʼ���Ķ����, pd ��ָ�������ݵ�ָ��	*/
/*	������:	�����δ��, ɾ����СԪ��, ����ֵ���� pd ָ�������, ���� 1 ; ���򷵻� 0	*/
/*	ʱ�临�Ӷ�:	O (log N)	*/
int DeleteMin_B (const Binary_Heap * const pbh, Edge * const pd) ;

/*	����:	�ͷ�һ������ռ�õ��ڴ�ռ�	*/
/*	����ǰ:	pbh ָ��һ���ѳ�ʼ���Ķ����	*/
/*	������:	�ö���ռ�õ��ڴ�ռ䱻�ͷ�	*/
/*	ʱ�临�Ӷ�:	O (1)	*/
void Release_B (const Binary_Heap * const pbh) ;