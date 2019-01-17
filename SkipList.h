/*	SkipList.h -- ��Ծ��ͷ�ļ�	*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define FALSE (0)
#define TRUE (1)
#define UNDECIDED (32768)

#define A (48271L)
#define M (2147486647L)
#define Q (M / A)
#define R (M % A)
#define MASK (0x01)

#define DEBUG (UNDECIDED)

/*	�������Ͷ���	*/

typedef int Item ;
typedef struct node
{
	Item item ;
	struct node * * next ;
	int height ;
	int times ;
} Node ;
typedef struct skiplist
{
	Node * head ;
	int current ;
	int capacity ;
	int maximum_of_height ;
} * SkipList ;

typedef int BOOL ;

/*	ȫ�ֱ���	*/

long int Seed ;

/*	�ӿں�������	*/

/*	����:	��ʼ������	*/
/*	����ǰ:	����ֵ��ȷ��*/
/*	������:	���ӱ���ʼ��*/
/*	ʱ�临�Ӷ�: O (1)	*/
void InitializSeed_S (const long int initial_value) ;

/*	����:	���� FALSE ֵ���� TRUE ֵ������	*/
/*	����ǰ:	�����ѱ���ʼ��	*/
/*	����:	���� FALSE ֵ���� TRUE ֵ������	*/
/*	ʱ�临�Ӷ�:	O (1)	*/
BOOL Random_S (void) ;

/*	����:	��������ʼ��һ����Ծ��	*/
/*	����ǰ:	psl ָ��һ����Ծ��, capacity ָʾ�ñ������С	*/
/*	������:	����ڴ����ɹ�, ��������Ծ��, ���� TRUE ; ���򷵻� FALSE	*/
/*	ʱ�临�Ӷ�:	O (1)	*/
BOOL Initialize_S (SkipList * const psl, const int capacity) ;

/*	����:	ȷ��һ����Ծ���Ƿ�Ϊ��	*/
/*	����ǰ:	psl ָ��һ���ѳ�ʼ������Ծ��	*/
/*	������:	�������Ծ��Ϊ��, ���� TRUE ; ���򷵻� FALSE	*/
/*	ʱ�临�Ӷ�:	O (1)	*/
BOOL IsEmpty_S (const SkipList * const psl) ;

/*	����:	ȷ��һ����Ծ���Ƿ�����	*/
/*	����ǰ:	psl ָ��һ���ѳ�ʼ������Ծ��	*/
/*	������:	�������Ծ������, ���� TRUE ; ���򷵻� FALSE	*/
/*	ʱ�临�Ӷ�:	O (1)	*/
BOOL IsFull_S (const SkipList * const psl) ;

/*	����:	ȷ��ָ�������Ƿ�����Ծ����	*/
/*	����ǰ:	psl ָ��һ���ѳ�ʼ������Ծ��, pi ָ��ָ������	*/
/*	������:	��� pi ָ��������ڸñ���, ���� TRUE ; ���򷵻� FALSE	*/
/*	ʱ�临�Ӷ�:	O (log N)	*/
BOOL Find_S (const SkipList * const psl, const Item * const pi) ;

/*	����:	����Ծ���в���ָ������	*/
/*	����ǰ:	psl ָ��һ���ѳ�ʼ������Ծ��, pi ָ��ָ������	*/
/*	������:	�������Ծ��δ�� && �ڴ����ɹ�, �ڸ���Ծ���Ҳ��������, ���� TRUE ; ���򷵻� FALSE	*/
/*	ʱ�临�Ӷ�: O (log N)	*/
BOOL Insert_S (const SkipList * const psl, const Item * const pi) ;

/*	����:	����Ծ����ɾ��ָ������	*/
/*	����ǰ:	psl ָ��һ���ѳ�ʼ������Ծ��, pi ָ��ָ������	*/
/*	������:	�����Ϊ�� && �������ڸ���Ծ����, �Ӹ���Ծ����ɾ��������, ���� TRUE ; ���򷵻� FALSE	*/
/*	ʱ�临�Ӷ�:	O (log N)	*/
BOOL Delete_S (const SkipList * const psl, const Item * const pi) ;

/*	����:	��ͷ��β��һ��������������Ծ��������Ԫ��1��	*/
/*	����ǰ:	psl ָ��һ���ѳ�ʼ������Ծ��, pfun ָ��һ��û�з���ֵ, ����һ�� Node * ���Ͳ����ĺ���	*/
/*	������:	��ͷ��β��һ��������������Ծ��������Ԫ��1��	*/
/*	ʱ�临�Ӷ�: O (N)	*/
void Traversal_S (const SkipList * const psl, void (* pfun) (const Node * const pn)) ;

/*	����:	�ͷ�һ����Ծ��ռ�õ��ڴ�ռ�	*/
/*	����ǰ:	psl ָ��һ���ѳ�ʼ������Ծ��	*/
/*	������:	����Ծ����ռ�ڴ�ռ䱻�ͷ�	*/
/*	ʱ�临�Ӷ�:	O (N)	*/
void Release_S (const SkipList * const psl) ;