/*	treapTree.h -- treap��ͷ�ļ�	*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INFINITY (~(1 << 31))

typedef int Item ;
typedef struct node
{
	Item item ;
	struct node * left, * right ;
	int priority ;
} Node ;
typedef Node * TreapTree ;

/*	�ӿں�������	*/

/*	����:	��ʼ��һ��Treap��	*/
/*	����ǰ:		*/
/*	������:	����ڴ����ɹ�, Ϊ NullNode �����ڴ�, ��ʼ�����������, ���� NullNode; ���򷵻� NULL	*/
/*	ʱ�临�Ӷ�:	O (1)	*/
TreapTree Initialize_T (void) ;

/*	����:	��һ��Treap�������һ��������Ϊָ�����ݵĽ��	*/
/*	����ǰ:	tt ��һ���ѳ�ʼ����Treap��, item �Ǵ���ӵ�����	*/
/*	������:	����ڴ����ɹ� && ����δ�ظ�, ��ÿ�Treap�������������Ϊ item �Ľ��, ��������; ���򷵻�ԭ��	*/
/*	ʱ�临�Ӷ�:	O (log N)	*/
TreapTree Insert_T (TreapTree tt, const Item item) ;

/*	����:	��һ��Treap����ɾ��������Ϊָ�����ݵĽ��	*/
/*	����ǰ:	tt ��һ���ѳ�ʼ����Treap��, item �Ǵ�ɾ��������	*/
/*	������:	����ҵ�������Ϊ item �Ľ��, ɾ���ý��, ��������; ���򷵻�ԭ��	*/
/*	ʱ�临�Ӷ�:	O (log N)	*/
TreapTree Delete_T (TreapTree tt, const Item item) ;

/*	����:	�ͷ�һ��Treap��ռ�õ��ڴ�ռ�	*/
/*	����ǰ:	tt ��һ���ѳ�ʼ����Treap��	*/
/*	������:	��Treap��ռ�õ��ڴ�ռ䱻�ͷ�	*/
/*	ʱ�临�Ӷ�:	O (log N)	*/
void Release_T (const TreapTree tt) ;


