/*	PairingHeap.h -- ��Զ�ͷ�ļ�	*/
#include <stdio.h>
#include <stdlib.h>

/*	���Գ�������	*/

#define FALSE (0)
#define TRUE (1)
#define MAXSIBLINGS (100)

/*	�������Ͷ���	*/

typedef int BOOL ;

typedef int Item ;
typedef struct node
{
	Item item ;
	struct node * left, * previous, * nextSibling ;
} Node ;
typedef struct pairingHeap
{
	Node * root ;
	int current ;
} * PairingHeap ;

/*	�ӿں�������	*/

/*	����:	��������ʼ����Զ�, ��Ϊ NullNode �����ڴ�ռ�	*/
/*	����ǰ:	pph ָ��һ����Զ�*/
/*	������:	����ڴ����ɹ�, *pph �� NullNode �õ��ڴ�ռ䲢����ʼ��, ���� TRUE ; ���򷵻� FALSE	*/
/*	ʱ�临�Ӷ�:	O (1)	*/
BOOL Initialize_P (PairingHeap * const pph) ;

/*	����:	ȷ��һ����Զ��Ƿ�Ϊ��	*/
/*	����ǰ:	pph ָ��һ���ѳ�ʼ������Զ�	*/
/*	������:	�������Զ�Ϊ��, ���� TRUE ; ���򷵻� FALSE	*/
/*	ʱ�临�Ӷ�:	O (1)	*/
BOOL IsEmpty_P (const PairingHeap * const pph) ;

/*	����:	��һ����Զ������һ��������Ϊָ�����ݵĽ��	*/
/*	����ǰ:	pph ָ��һ���ѳ�ʼ������Զ�, item ��ָ���Ĵ��������, localizer ��һ��ָ�� Node * ���͵�ָ��, �������ݻ��½��ĵ�ַ	*/
/*	������:	����ڴ����ɹ�, ��һ��������Ϊ item �Ľ����ӵ�����Զ���, *localizer ָ���½��, ���� TRUE ; ���򷵻� FALSE	*/
/*	ʱ�临�Ӷ�:	O (1)	*/
BOOL Insert_P (const PairingHeap * const pph, const Item item, const Node * * const localizer) ;

/*	����:	����Զ���ָ���������ݽ��� delta	*/
/*	����ǰ:	pph ָ��һ���ѳ�ʼ������Զ�, position ��һ��ָ����Զ��н���ָ��, delta �Ǵ����ٵ�����	*/
/*	������:	��� delta > 0, �� position ָ��������ݼ��� delta , ���� TRUE ; ���򷵻� FALSE	*/
/*	ʱ�临�Ӷ�:	O (1)	*/
BOOL DecreaseKey_P (const PairingHeap * const pph, Node * const position, const Item delta) ;

/*	����:	ɾ����Զ�����������С�Ľ��, ��ͨ�� pmin ����Я���ص��øú����ĺ���	*/
/*	����ǰ:	pph ָ��һ���ѳ�ʼ������Զ�, pmin ��һ��ָ��Item��ָ��	*/
/*	������:	�������ԶѲ�Ϊ��, ɾ����������С�Ľ��, ���������ݸ��� *pmin , ���� TRUE ; ���򷵻� FALSE	*/
/*	ʱ�临�Ӷ�:	δ֪	*/
BOOL DeleteMin_P (const PairingHeap * const pph, Item * const pmin) ;

/*	����:	�ͷ�һ����Զ�ռ�õ��ڴ�ռ�	*/
/*	����ǰ:	pph ָ��һ���ѳ�ʼ������Զ�	*/
/*	������:	����Զ���ռ�õ��ڴ�ռ䱻�ͷ�. NullNode ռ�õ��ڴ�ռ䱻�ͷ�, �������� NULL	*/
/*	ʱ�临�Ӷ�:	δ֪	*/
void Release_P (PairingHeap * const pph) ;