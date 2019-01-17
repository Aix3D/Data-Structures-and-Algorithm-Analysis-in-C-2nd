/*	AATree.h -- AA��ͷ�ļ�	*/
#include <stdio.h>
#include <stdlib.h>

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
	int level ;
} Node ;
typedef Node * AATree ;

/*	�ӿں�������	*/

/*	����:	��������ʼ��һ��AA��	*/
/*	����ǰ:	*/
/*	������:	���Ϊ NullNode �����ڴ�ռ�ɹ�, ���䷵��; ���򷵻� NULL	*/
/*	ʱ�临�Ӷ�:	O (1)	*/
Node * Initialize_A (void) ;

/*	����:	��һ��AA�������һ��������Ϊָ�����ݵĽ��	*/
/*	����ǰ:	aat ��һ���ѳ�ʼ����AA��, item ��ָ���Ĵ��������	*/
/*	������:	�������δ�ظ� && �ڴ����ɹ�, ���AA�������ָ�����ݵĽ��, �����µ�AA��; ���򷵻�ԭAA��	*/
/*	ʱ�临�Ӷ�:	O (log N)	*/
AATree Insert_A (AATree aat, const Item item) ;

/*	����:	ȷ��ָ�������Ƿ���AA����	*/
/*	����ǰ:	aat ��һ���ѳ�ʼ����AA��, item ��ָ���Ĵ��������	*/
/*	������:	����ҵ�������, ���� TRUE; ���򷵻� FALSE	*/
/*	ʱ�临�Ӷ�:	O (log N)	*/
BOOL Find_A (AATree aat, const Item item) ;

/*	����:	ȷ��AA��������Ŀ	*/
/*	����ǰ:	aat ��һ���ѳ�ʼ����AA��	*/
/*	������:	���ظ�AA���н�����Ŀ	*/
/*	ʱ�临�Ӷ�:	O (log N)	*/
int Count_A (AATree aat) ;

/*	����:	ɾ��AA����������Ϊָ�����ݵĽ��	*/
/*	����ǰ:	aat ��һ���ѳ�ʼ����AA��, item ��ָ���Ĵ�ɾ������	*/
/*	������:	����ҵ��ý��, ɾ����, ������AA��; ���򷵻�ԭAA��	*/
/*	ʱ�临�Ӷ�:	O (log N)	*/
AATree Delete_A (AATree aat, const Item item) ;

/*	����:	�ͷ�һ��AA��ռ�õ��ڴ�ռ�	*/
/*	����ǰ:	aat ��һ���ѳ�ʼ����AA��	*/
/*	������:	��AA��ռ�õ��ڴ�ռ䱻�ͷ�, NullNode ռ�ÿռ䱻�ͷ�	*/
/*	ʱ�临�Ӷ�:	O (log N)	*/
void Release_A (AATree aat) ;