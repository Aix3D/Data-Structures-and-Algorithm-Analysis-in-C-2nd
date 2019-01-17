/*	k-dTree.h -- k-d��ͷ�ļ�	*/
#include <stdio.h>
#include <stdlib.h>

/*	�궨��	*/

#define ADD_INDEX(k, index) (k == index + 1 ? 0 : index + 1)
#define SUBTRACT_INDEX(k, index) (0 == index ? k - 1 : index - 1)

/*	���Գ�������	*/

#define FALSE (0)
#define TRUE (1)

/*	�������Ͷ���	*/

typedef int BOOL ;

/*	k-d������	*/
typedef int Item ;
typedef struct node
{
	Item * item ;
	BOOL deleted ;
	struct node * left, * right ;
} Node ;
typedef struct kDTree
{
	Node * root ;
	int current ;
	int k ;
} * KDTree ;

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

/*	k-d������	*/
/*	����:	��������ʼ��һ��k-d��	*/
/*	����ǰ:	pt ָ��һ��k-d��	*/
/*	������:	����ڴ����ɹ�, ��������ʼ����k-d��, ���� TRUE ; ���򷵻� FALSE	*/
/*	ʱ�临�Ӷ�:	O (1)	*/
BOOL Initialize_K (KDTree * const pt, const int k) ;

/*	����:	ȷ��һ��k-d���Ƿ�Ϊ��	*/
/*	����ǰ:	pt ָ��һ���ѳ�ʼ����k-d��	*/
/*	������:	�����k-d��Ϊ��, ���� TRUE ; ���򷵻� FALSE	*/
/*	ʱ�临�Ӷ�:	O (1)	*/
BOOL IsEmpty_K (const KDTree * const pt) ;

/*	����:	��һ��k-d���в���������Ϊָ�����ݵĽ��	*/
/*	����ǰ:	pt ָ��һ���ѳ�ʼ����k-d��, pi ָ���һ����������ݵĵ�ַ	*/
/*	������:	����ڴ����ɹ�, ���k-d�������������Ϊ pi[0]...pi[k - 1] �Ľ��(�ظ�Ԫ����ӵ���������), ���� TRUE ; ���򷵻� FALSE	*/
/*	ƽ��ʱ�临�Ӷ�:	O (log N)	*/
BOOL Insert_K (const KDTree * const pt, const Item * const pi) ;

/*	����:	��һ��k-d���н�һ������������������ҷ�Χ�����н��1��	*/
/*	����ǰ:	pt ָ��һ���ѳ�ʼ����k-d��, low �� high �ֱ���ָ����Ӧ��Χ�����е�һ�����ݵ�ָ��, pfun ָ��һ��û�з���ֵ, ����һ�� Node * ���Ͳ����� k ֵ�ĺ���	*/
/*	������:	�� pfun ָ��ĺ������������㷶Χ�����н��1��, �����ҵ��Ľ��ĸ���	*/
/*	ƽ��ʱ�临�Ӷ�:	�Ҳ�֪��	*/
int Find_K (const KDTree * const pt, const Item * const low, const Item * const high, void (* pfun) (const Node * const pn, const int k)) ;

/*	����:	��һ��k-d��������ɾ��������Ϊָ�����ݵ����н��	*/
/*	����ǰ:	pt ָ��һ���ѳ�ʼ����k-d��, pi ��ָ���һ����ɾ�����ݵ�ָ��	*/
/*	������:	ɾ��������Ϊ��ɾ�����ݲ���δ��ɾ���Ľ��, ���ش˴ε���ɾ�����ĸ���	*/
/*	ƽ��ʱ�临�Ӷ�:	O (log N)	*/
int Delete_K (const KDTree * const pt, const Item * const pi) ;

/*	����:	�ͷ�һ��k-d��ռ�õ��ڴ�ռ�	*/
/*	����ǰ:	pt ָ��һ���ѳ�ʼ����k-d��	*/
/*	������:	��k-d��ռ�õ��ڴ�ռ䱻�ͷ�	*/
/*	ƽ��ʱ�临�Ӷ�:	O (log N)	*/
void Release_K (const KDTree * const pt) ;