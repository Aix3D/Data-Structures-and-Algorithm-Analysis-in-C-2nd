/*	box.h -- ��������ͷ�ļ�	*/
#include <stdio.h>
#include <stdlib.h>

#define GENERIC 10
#define LEFT 1
#define RIGHT 2

/*	�������Ͷ���	*/

typedef int Weight ;		//	����
typedef struct box
{
	Weight unoccupied ;		//	��������
	Weight capacity ;		//	����
	struct box * parent ;
	struct box * left ;
	struct box * right ;
} Box ;
typedef struct boxtree
{
	Box * root ;
	Weight usual ;			//	ͨ������µ�����
	int size ;
} * BoxTree ;

/*	�ӿں�������	*/

/*	����:	��������ʼ��һ��BoxTree	*/
/*	����ǰ:	pbt ָ��һ��BoxTree	*/
/*	������:	����ڴ����ɹ�, ��������ʼ��һ��BoxTree, Ĭ������Ϊ capacity, ����1; ���򷵻�0	*/
/*	ʱ�临�Ӷ�:	O(1)	*/
int InitializeBoxTree (BoxTree * const pbt, const Weight capacity) ;

/*	����:	ȷ��һ��BoxTree�Ƿ�Ϊ��	*/
/*	����ǰ:	pbt ָ��һ���ѳ�ʼ����BoxTree	*/
/*	������:	�����BoxTreeΪ��, ����1; ���򷵻�0	*/
/*	ʱ�临�Ӷ�:	O(1)	*/
int BoxTreeIsEmpty (const BoxTree * const pbt) ;

/*	����:	��Сָ��BoxTree�� >= triangle ���ؼ��ֵ�ֵ	*/
/*	����ǰ:	pbt ָ��һ���ѳ�ʼ����BoxTree, triangle �Ƿ��������	*/
/*	������:	��������ڼ��ڴ����ɹ�, ��ɲ���, ����1; ���򷵻�0	*/
/*	ʱ�临�Ӷ�:	O(2logN)	*/
int DealWithTheBiggest (BoxTree * const pbt, const Weight triangle) ;

/*	����:	��Сָ��BoxTree�� >= triangle ��С�ؼ��ֵ�ֵ	*/
/*	����ǰ:	pbt ָ��һ���ѳ�ʼ����BoxTree, triangle �Ƿ��������	*/
/*	������:	��������ڼ��ڴ����ɹ�, ��ɲ���, ����1; ���򷵻�0	*/
/*	ʱ�临�Ӷ�:	O(7logN)	*/
int DealWithTheSmallest (BoxTree * const pbt, const Weight triangle) ;

/*	����:	������һ������������һ��BoxTree�����нڵ�1��	*/
/*	����ǰ:	pbt ָ��һ���ѳ�ʼ����BoxTree, pfun ָ��һ��û�з���ֵ, ����һ��Box *���Ͳ����ĺ���	*/
/*	������:	pfun ָ��ĺ�����������������BoxTree�����нڵ�1��	*/
/*	ʱ�临�Ӷ�:	O(logN)	*/
void InorderTraversal (const Box * const box, void (* pfun) (const Box * const box)) ;

/*	����:	�ͷ�һ��BoxTree��ռ�õ��ڴ�ռ�	*/
/*	����ǰ:	pbt ָ��һ���ѳ�ʼ����BoxTree	*/
/*	������:	��BoxTree��ռ�õ��ڴ�ռ䱻�ͷ�	*/
/*	ʱ�临�Ӷ�:	O(1)	*/
void Release (const BoxTree * const pbt) ;
