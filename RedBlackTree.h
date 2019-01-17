/*	RedBlackTree.h -- �����ͷ�ļ�	*/
/*	��������,��д��4��.ɾ������д������.ɾ���������Լ�ʵ�ֵ�,��ˬ.	*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*	���Գ�������	*/

#define FALSE (0)
#define TRUE (1)
#define INFINITY (~(1 << 31))
#define NEGATIVE_INFINITY (1 << 31)

/*	�������Ͷ���	*/

typedef int BOOL ;
typedef enum colorType {Red, Black} ColorType ;
typedef int Item ;
typedef struct node
{
	Item item ;
	struct node * left, * right ;
	ColorType color ;
} Node ;
typedef struct redBlackTree
{
	Node * root ;
	int current ;
} * RedBlackTree ;

/*	ȫ�ֱ�������	*/

static Node * NullNode = NULL ;
Node * Current, * Sibling, * Parent, * GrParent, * GrGrParent ;

/*	�ӿں�������	*/

/*	����:	��������ʼ��һ�ú������Ϊ NullNode �����ڴ�ռ�	*/
/*	����ǰ:	prbt ָ��һ�ú����	*/
/*	������:	����ڴ����ɹ�, �ú��������ʼ��Ϊ��, Ϊ NullNode �����ڴ�ռ�, ���� TRUE ; ���򷵻� FALSE	*/
/*	ʱ�临�Ӷ�:	O (1)	*/
BOOL Create_R (RedBlackTree * const prbt) ;

/*	����:	ȷ��һ�ú�����Ƿ�Ϊ��	*/
/*	����ǰ:	prbt ָ��һ���ѳ�ʼ���ĺ����	*/
/*	������:	����ú����Ϊ��, ���� TRUE ; ���򷵻� FALSE	*/
/*	ʱ�临�Ӷ�:	O (1)	*/
BOOL IsEmpty_R (const RedBlackTree * const prbt) ;

/*	����:	�������в���һ�����	*/
/*	����ǰ:	prbt ָ��һ���ѳ�ʼ���ĺ����, item �Ǵ��������	*/
/*	������:	����ڴ����ɹ� && item ֮ǰ�������ڸú������, ��ú���������1��������Ϊ item �Ľ��, ���� TRUE ; ���򷵻� FALSE	*/
/*	ʱ�临�Ӷ�:	O (log N)	*/
BOOL Insert_R (RedBlackTree * const prbt, const Item item) ;

/*	����:	�Ӻ������ɾ��һ�����	*/
/*	����ǰ:	prbt ָ��һ���ѳ�ʼ���ĺ����, item �Ǵ�ɾ������	*/
/*	������:	����ҵ��ý��, ɾ����, ���� TRUE ; ���򷵻� FALSE	*/
/*	ʱ�临�Ӷ�:	O (log N)	*/
BOOL Delete_R (RedBlackTree * const prbt, const Item item) ;

/*	����:	��һ�����������������ں���������н��1��	*/
/*	����ǰ:	prbt ָ��һ���ѳ�ʼ���ĺ����, pfun ָ��һ��û�з���ֵ, ����һ�� Node * ���Ͳ����ĺ���	*/
/*	������:	pfun ָ��ĺ��������������������ڸú���������н��1��	*/
/*	ʱ�临�Ӷ�:	O (N)	*/
void Traversal_R (const RedBlackTree * const prbt, void (* pfun) (const Node * const pn)) ;

/*	����:	�ͷ�һ�ú����ռ�õ��ڴ�ռ�	*/
/*	����ǰ:	prbt ָ��һ���ѳ�ʼ���ĺ����	*/
/*	������:	�ú����ռ�õ��ڴ�ռ䱻�ͷ�	*/
/*	ʱ�临�Ӷ�:	O (N)	*/
void Release_R (const RedBlackTree * const prbt) ;