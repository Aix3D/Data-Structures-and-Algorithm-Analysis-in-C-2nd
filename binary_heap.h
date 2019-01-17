/*	binary_heap.h -- �����ͷ�ļ�	*/
#include "new_adjacenty_list.h"

/*	�������Ͷ���	*/

typedef Vertex * Heap_Item ;
typedef struct binary_heap
{
	Heap_Item * heap ;
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
/*	����ǰ:	pbh ָ��һ���ѳ�ʼ���Ķ����, hi �Ǵ���ӵ�ָ������	*/
/*	������:	�����δ��, �������������Ԫ��, ���� 1 ; ���򷵻� 0	*/
/*	ʱ�临�Ӷ�: O (log N)	*/
int Insert_B (const Binary_Heap * const pbh, const Heap_Item hi) ;

/*	����:	ɾ�������ض�����С��Ԫ��	*/
/*	����ǰ:	pbh ָ��һ���ѳ�ʼ���Ķ����	*/
/*	������:	�����δ��, ɾ��������СԪ�ز�����; ���򷵻ض��е���Ԫ��	*/
/*	ʱ�临�Ӷ�:	O (log N)	*/
Heap_Item DeleteMin_B (const Binary_Heap * const pbh) ;

/*	����:	������ָ��Ԫ�ص� dist ���ֵ���� ��	*/
/*	����ǰ:	phb ָ��һ���ѳ�ʼ���Ķ����, index ָʾָ��Ԫ�ص�����, triangle ָʾ���Ĵ�С	*/
/*	������:	����Ѳ�Ϊ�� && index �ǺϷ������� && �� >= 0, ��������Ϊ index ��Ԫ�ص� dist ������ ��, ���� 1 ; ���򷵻� 0	*/
/*	ʱ�临�Ӷ�:	O (log N)	*/
int IncreaseKey_B (const Binary_Heap * const pbh, const int index, const int triangle) ;

/*	����:	������ָ��Ԫ�ص� dist ��ֵ���� ��	*/
/*	����ǰ:	pbh ָ��һ��һ��ʼ���Ķ����, index ָʾָ��Ԫ�ص�����, triangle ָʾ���Ĵ�С	*/
/*	������:	����Ѳ�Ϊ�� && index �ǺϷ������� && �� >= 0, ��������Ϊ index ��Ԫ�ص� dist �򱻼��� ��, ���� 1 ; ���򷵻� 0	*/
/*	ʱ�临�Ӷ�:	O (log N)	*/
int DecreaseKey_B (const Binary_Heap * const pbh, const int index, const int triangle) ;

/*	����:	�ͷ�һ���������ռ�õ��ڴ�ռ�	*/
/*	����ǰ:	pbh ָ��һ���ѳ�ʼ���Ķ����	*/
/*	������:	�ö���ռ�õ��ڴ�ռ䱻�ͷ�	*/
/*	ʱ�临�Ӷ�:	O (1)	*/
void Release_B (const Binary_Heap * const pbh) ;