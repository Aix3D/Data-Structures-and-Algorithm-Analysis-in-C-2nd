/*	FibonacciHeap.h -- 쳲�������ͷ�ļ�	*/
/*	����׶κ�ʱ14Сʱ.	2011-03-01-22.32���	*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*	���Գ�������	*/

#define FALSE (0)
#define TRUE (1)
#define EMPTY (1 << 31)
#define NEGATIVE_INFINTY (1 << 30)
#define BE_RELEASED (1 << 31)

/*	�������Ͷ���	*/

typedef int BOOL ;

typedef int Item ;
typedef struct node
{
	Item item ;
	struct node * left, * right, * parent, * child ;
	int degree ;
	BOOL index ;
} Node ;
typedef struct fibonacciheap
{
	Node * min ;
	int current ;
} * FibonacciHeap ;

/*	�ӿں�������	*/

/*	����:	��������ʼ��һ��쳲�������	*/
/*	����ǰ:	pfh ָ��һ��쳲�������	*/
/*	������:	����ڴ����ɹ�, ��������ʼ����쳲�������, ���� TRUE ; ���򷵻� FALSE ;	*/
/*	̯��ʱ��:	O (1)	*/
BOOL Initialize_F (FibonacciHeap * const pfh) ;

/*	����:	ȷ��һ��쳲��������Ƿ�Ϊ��	*/
/*	����ǰ:	pfh ָ��һ���ѳ�ʼ����쳲�������	*/
/*	������:	�����쳲�������Ϊ��, ���� TRUE ; ���򷵻� FALSE	*/
/*	̯��ʱ��: O (1)	*/
BOOL IsEmpty_F (const FibonacciHeap * const pfh) ;

/*	����:	��쳲��������в���һ������ָ�����ݵĽ��	*/
/*	����ǰ:	pfh ָ��һ���ѳ�ʼ����쳲�������, pi ָ�����ӵ�����	*/
/*	������:	����ڴ����ɹ�, ���쳲��������в���1��������Ϊ�����ݵĽ��, ���� TRUE ; ���򷵻� FALSE	*/
/*	̯��ʱ��:	O (1)	*/
BOOL Insert_F (const FibonacciHeap * const pfh, const Item * const pi) ;

/*	����:	ɾ��������쳲�����������С��������	*/
/*	����ǰ:	pfh ָ��һ���ѳ�ʼ����쳲�������	*/
/*	������:	�����쳲������Ѳ�Ϊ��, ɾ����쳲�����������С���, ���ظý������� ; ���򷵻� EMPTY	*/
/*	̯��ʱ��: O (log N)	*/
Item DeleteMin_F (const FibonacciHeap * const pfh) ;

/*	����:	����쳲���������ָ�����ݵ�ֵ	*/
/*	����ǰ:	pfh ָ��һ���ѳ�ʼ����쳲�������, pn ָ��ָ���Ľ��, delta ָʾ�ı����Ĵ�С	*/
/*	������:	�����쳲������Ѳ�Ϊ��, ʹ��쳲��������� pn ָ�������ݵ�ֵ���� delta , ���� TRUE ; ���򷵻� FALSE	*/
/*	̯��ʱ��:	O (1)	*/
BOOL DecreaseKey_F (const FibonacciHeap * const pfh, Node * const pn, const int delta) ;

/*	����:	ɾ��쳲���������ָ�����	*/
/*	����ǰ:	pfh ָ��һ���ѳ�ʼ����쳲�������, pn ָ���ɾ���Ľ��	*/
/*	������:	�����쳲������Ѳ�Ϊ��, ɾ�� pn ָ��Ľ��, ���� TRUE ; ���򷵻� FALSE	*/
/*	̯��ʱ��:	O (log N)	*/
BOOL Delete_F (const FibonacciHeap * const pfh, Node * const pn) ;

/*	����:	�ͷ�һ��쳲���������ռ�õ��ڴ�ռ�	*/
/*	����ǰ:	pfh ָ��һ���ѳ�ʼ����쳲�������	*/
/*	������:	��쳲���������ռ�õ��ڴ�ռ䱻�ͷ�	*/
/*	̯��ʱ��:	O (N)	*/
void Release_F (const FibonacciHeap * const pfh) ;