/*	2dTree.h -- 2-d��ͷ�ļ�	*/
#include <stdio.h>
#include <stdlib.h>

/*	���Գ�������	*/

#define FALSE (0)
#define TRUE (1)
#define TWO (2)
#define MASK (1)

/*	�������Ͷ���	*/

typedef int BOOL ;

/*	2-d������	*/
typedef int Item ;
typedef struct node
{
	Item item[TWO] ;
	int deleted ;
	struct node * left, * right ;
} Node ;
typedef struct twoDTree
{
	Node * root ;
	int current ;
} * TwoDTree ;

/*	���в���	*/
typedef struct queueNode
{
	Node * node ;
	int index ;
	struct queueNode * next ;
} QueueNode ;
typedef struct queue
{
	QueueNode * front, * rear ;
	int current ;
} * Queue ;

/*	�ӿں�������	*/

/*	���в���	*/
/*	����:	��������ʼ��һ������	*/
/*	����ǰ:	pq ָ��һ������	*/
/*	����ǰ:	����ڴ����ɹ�, ��������ʼ���ö���, ���� TRUE ; ���򷵻� FALSE	*/
/*	ʱ�临�Ӷ�:	O (1)	*/
BOOL Initialize_Q (Queue * const pq) ;

/*	����:	ȷ�������Ƿ�Ϊ��	*/
/*	����ǰ:	pq ָ��һ���ѳ�ʼ���Ķ���	*/
/*	������:	����ö���Ϊ��, ���� TRUE ; ���򷵻� FALSE	*/
/*	ʱ�临�Ӷ�:	O (1)	*/
BOOL IsEmpty_Q (const Queue * const pq) ;

/*	����:	����������һ��������Ϊָ�����ݵĽ��	*/
/*	����ǰ:	pq ָ��һ���ѳ�ʼ���Ķ���, pn �� index �Ǵ���ӵ�����	*/
/*	������:	����ڴ����ɹ�, ��ö��������������Ϊ pn �� index �Ľ��, ���� TRUE ; ���򷵻� FALSE	*/
/*	ʱ�临�Ӷ�:	O (1)	*/
BOOL EnQueue_Q (const Queue * const pq, Node * const pn, const int index) ;

/*	����:	ɾ������ͷ���Ľ��, ȡ���ý��ָ���ַ��ֵ���� * pqn	*/
/*	����ǰ:	pq ָ��һ���ѳ�ʼ���Ķ���, pqn ��һ��ָ��QueueNode���ͽ���ָ��	*/
/*	������:	����ö��зǿ�, ɾ���ö���ͷ�����, ȡ���ý��ָ���ַ��ֵ���� * pqn, ���� TRUE ; ���򷵻� FALSE	*/
/*	ʱ�临�Ӷ�:	O (1)	*/
BOOL DeQueue_Q (const Queue * const pq, QueueNode * const pqn) ;

/*	����:	�ͷ�һ������ռ�õ��ڴ�ռ�	*/
/*	����ǰ:	pq ָ��һ���ѳ�ʼ���Ķ���	*/
/*	������:	�ö���ռ�õ��ڴ�ռ䱻�ͷ�	*/
/*	ʱ�临�Ӷ�:	O (N)	*/
void Release_Q (const Queue * const pq) ;

/*	2-d������	*/
/*	����:	��������ʼ��һ��2-d��	*/
/*	����ǰ:	pt ָ��һ��2-d��	*/
/*	������:	����ڴ����ɹ�, ��������ʼ����2-d��, ���� TRUE ; ���򷵻� FALSE	*/
/*	ʱ�临�Ӷ�:	O (1)	*/
BOOL Initialize_T (TwoDTree * const pt) ;

/*	����:	ȷ��һ��2-d���Ƿ�Ϊ��	*/
/*	����ǰ:	pt ָ��һ���ѳ�ʼ����2-d��	*/
/*	������:	�����2-d��Ϊ��, ���� TRUE ; ���򷵻� FALSE	*/
/*	ʱ�临�Ӷ�:	O (1)	*/
BOOL IsEmpty_T (const TwoDTree * const pt) ;

/*	����:	��һ��2-d���в���������Ϊָ�����ݵĽ��	*/
/*	����ǰ:	pt ָ��һ���ѳ�ʼ����2-d��, pi ָ���һ����������ݵĵ�ַ	*/
/*	������:	����ڴ����ɹ�, ���2-d�������������Ϊ pi[0] �� pi[1] �Ľ��(�ظ�Ԫ����ӵ���������), ���� TRUE ; ���򷵻� FALSE	*/
/*	ƽ��ʱ�临�Ӷ�:	O (log N)	*/
BOOL Insert_T (const TwoDTree * const pt, const Item * const pi) ;

/*	����:	��һ��2-d���н�һ������������������ҷ�Χ�����н��1��	*/
/*	����ǰ:	pt ָ��һ���ѳ�ʼ����2-d��, low �� high �ֱ���ָ����Ӧ��Χ�����е�һ�����ݵ�ָ��, pfun ָ��һ��û�з���ֵ, ����һ�� Node * ���Ͳ����ĺ���	*/
/*	������:	�� pfun ָ��ĺ������������㷶Χ�����н��1��, �����ҵ��Ľ��ĸ���	*/
/*	ƽ��ʱ�临�Ӷ�:	O (log N)	*/
int Find_T (const TwoDTree * const pt, const Item * const low, const Item * const high, void (* pfun) (const Node * const pn)) ;

/*	����:	��һ��2-d��������ɾ��������Ϊָ�����ݵ����н��	*/
/*	����ǰ:	pt ָ��һ���ѳ�ʼ����2-d��, pi ��ָ���һ����ɾ�����ݵ�ָ��	*/
/*	������:	ɾ��������Ϊ��ɾ�����ݲ���δ��ɾ���Ľ��, ���ش˴ε���ɾ�����ĸ���	*/
/*	ƽ��ʱ�临�Ӷ�:	O (log N)	*/
int Delete_T (const TwoDTree * const pt, const Item * const pi) ;

/*	����:	�ͷ�һ��2-d��ռ�õ��ڴ�ռ�	*/
/*	����ǰ:	pt ָ��һ���ѳ�ʼ����2-d��	*/
/*	������:	��2-d��ռ�õ��ڴ�ռ䱻�ͷ�	*/
/*	ƽ��ʱ�临�Ӷ�:	O (log N)	*/
void Release_T (const TwoDTree * const pt) ;