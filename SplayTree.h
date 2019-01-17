/*	SplayTree.h -- �Զ�������չ��ͷ�ļ�	*/
/*	�ƺ�д��ͷ�ļ�Ŷ.	*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*	���Գ�������	*/

#define FALSE (0)
#define TRUE (1)

/*	�������Ͷ���	*/

typedef int BOOL ;

typedef int Item ;
typedef struct node
{
	Item item ;
	struct node * left, * right ;
	int leftSubTreeCount, rightSubTreeCount ;
} Node ;
typedef struct splayTree
{
	Node * root ;
	int current ;
} * SplayTree ;

/*	ȫ�ֱ�������	*/

static Node * NullNode = NULL ;

/*	�ӿں�������	*/

/*	����:	����һ����չ��, ��ʼ��Ϊ��, ����Ϊ NullNode �����ڴ�ռ�	*/
/*	����ǰ:	pst ָ��һ����չ��	*/
/*	������:	����ڴ����ɹ�, ����һ����չ��, �����ʼΪ��, ��Ϊ NullNode �����ڴ�ռ�, ���� TRUE ; ���򷵻� FALSE	*/
/*	ʱ�临�Ӷ�:	O (1)	*/
BOOL Create_S (SplayTree * const pst) ;

/*	����:	ȷ��һ����չ���Ƿ�Ϊ��	*/
/*	����ǰ:	pst ָ��һ���ѳ�ʼ������չ��	*/
/*	������:	�������չ��Ϊ��, ���� TRUE ; ���򷵻� FALSE	*/
/*	ʱ�临�Ӷ�:	O (1)	*/
BOOL IsEmpty_S (const SplayTree * const pst) ;

/*	����:	����չ���в���һ��Ԫ��	*/
/*	����ǰ:	pst ָ��һ���ѳ�ʼ������չ��, pi ָ����������	*/
/*	������:	����ڴ����ɹ�, �����չ�������������Ϊ *pi ���½��, ���� TRUE ; ���򷵻� FALSE	*/
/*	ʱ�临�Ӷ�:	O (log N)	*/
BOOL Insert_S (const SplayTree * const pst, const Item * const pi) ;

/*	����:	����ָ����չ���и��ڵ��ָ��	*/
/*	����ǰ:	pst ָ��һ���ѳ�ʼ������չ��	*/
/*	������:	�������չ����Ϊ��, ����ָ�����չ��������ָ��; ���򷵻� NULL	*/
/*	ʱ�临�Ӷ�:	O (1)	*/
Node * Retrieve_S (const SplayTree * const pst) ;

/*	����:	����չ���в���ָ������	*/
/*	����ǰ:	pst ָ��һ���ѳ�ʼ������չ��, pi ָ�����������	*/
/*	������:	�������չ����Ϊ�� && �ҵ�������, ���� TRUE ; ���򷵻� FALSE	*/
/*	ʱ�临�Ӷ�:	O (log N)	*/
BOOL Find_S (const SplayTree * const pst, const Item * const pi) ;

/*	����:	����ָ����չ�����������kС����ָ��	*/
/*	����ǰ:	pst ָ��һ���ѳ�ʼ������չ��, k ָʾ���������ݵ�����	*/
/*	������:	�������չ���Ĵ�С >= k && k > 0, ����ָ�����չ����������� k С�Ľ���ָ�� ; ���򷵻� NULL	*/
/*	ʱ�临�Ӷ�:	O (log N)	*/
Node * FindKthMin_S (const SplayTree * const pst, int k) ;

/*	����:	����ָ����չ�����������k�����ָ��	*/
/*	����ǰ:	pst ָ��һ���ѳ�ʼ������չ��, k ָʾ���������ݵ�����	*/
/*	������:	�������չ���Ĵ�С >= k && k > 0, ����ָ�����չ����������� k ��Ľ���ָ�� ; ���򷵻� NULL	*/
/*	ʱ�临�Ӷ�:	O (log N)	*/
Node * FindKthMax_S (const SplayTree * const pst, int k) ;

/*	����:	����ָ����չ������С����ָ��	*/
/*	����ǰ:	pst ָ��һ���ѳ�ʼ������չ��	*/
/*	������:	�������չ����Ϊ��, ����ָ�����չ������С����ָ�� ; ���򷵻� NULL	*/
/*	ʱ�临�Ӷ�:	O (log N)	*/
Node * FindMin_S (const SplayTree * const pst) ;

/*	����:	����ָ����չ����������ָ��	*/
/*	����ǰ:	pst ָ��һ���ѳ�ʼ������չ��	*/
/*	������:	�������չ����Ϊ��, ����ָ�����չ����������ָ�� ; ���򷵻� NULL	*/
/*	ʱ�临�Ӷ�:	O (log N)	*/
Node * FindMax_S (const SplayTree * const pst) ;

/*	����:	ɾ����չ����������Ϊָ�����ݵĽ��	*/
/*	����ǰ:	pst ָ��һ���ѳ�ʼ������չ��, pi ָ���ɾ������	*/
/*	������:	�������չ����Ϊ�� && �ҵ��ý��, ɾ���ý��, ���� TRUE ; ���򷵻� FALSE	*/
/*	ʱ�临�Ӷ�:	O (log N)	*/
BOOL Delete_S (const SplayTree * const pst, const Item * const pi) ;

/*	����:	������һ������������������չ�������н��1��	*/
/*	����ǰ:	pr ָ��һ���ѳ�ʼ������չ���ĸ�, pfun ָ��һ��û�з���ֵ, ����һ�� Node * ���Ͳ����ĺ���	*/
/*	������:	pfun ָ��ĺ��������������ڸ���չ�������н��1��	*/
/*	ʱ�临�Ӷ�:	O (log N)	*/
void Traversal_S (const Node * const pr, void (* pfun) (const Node * const pn)) ;

/*	����:	�ͷ�һ����չ��ռ�õ��ڴ�ռ�	*/
/*	����ǰ:	pst ָ��һ���ѳ�ʼ������չ��	*/
/*	������:	����չ��ռ�õ��ڴ�ռ䱻�ͷ�	*/
/*	ʱ�临�Ӷ�:	O (log N)	*/
void Release_S (const SplayTree * const pst) ;