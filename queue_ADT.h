/*	queue_ADT.h -- ����ģ��ͷ�ļ�	*/
#include "adjacenty_list.h"

/*	�������Ͷ���	*/
typedef Vertex * Queue_Item ;
typedef struct queue_node
{
	Queue_Item queue_item ;
	struct queue_node * next ;
} Queue_Node ;

typedef struct queue
{
	Queue_Node * front ;
	Queue_Node * rear ;
} * Queue ;

/*	�ӿں�������	*/

/*	����:	��������ʼ��һ������	*/
/*	����ǰ:	pqueue ָ��һ������	*/
/*	������:	����ڴ����ɹ�, ���б�����������ʼ��Ϊ��, ����1; ���򷵻�0	*/
/*	ʱ�临�Ӷ�:	O(1)	*/
int InitializeQueue (Queue * const pqueue) ;

/*	����:	ȷ��һ�������Ƿ�Ϊ��	*/
/*	����ǰ:	pqueue ָ��һ���ѳ�ʼ���Ķ���	*/
/*	������:	����ö���Ϊ��, ����1; ���򷵻�0	*/
/*	ʱ�临�Ӷ�:	O(1)	*/
int QueueIsEmpty (const Queue * const pqueue) ;

/*	����:	����������������Ϊָ�����ݵ�Ԫ��	*/
/*	����ǰ:	pqueue ָ��һ���ѳ�ʼ���Ķ���, pqueue_item ָ����ӵ�����	*/
/*	������:	����ڴ����ɹ�, ������Ϊ *pqueue_item ��Ԫ�ر���ӵ�������, ����1; ���򷵻�0	*/
/*	ʱ�临�Ӷ�:	O(1)	*/
int EnQueue (Queue * const pqueue, const Queue_Item * const pqueue_item) ;

/*	����:	�Ӷ�����ɾ��һ��Ԫ��	*/
/*	����ǰ:	pqueue ָ��һ���ѳ�ʼ���Ķ���, pqueue_item ��һ��Queue_Item *���͵ı���	*/
/*	������:	������в�Ϊ��, �Ӷ�����ɾ��һ��Ԫ��, ������Ԫ�ص����ݸ��� *pqueue_item ����1; ���򷵻�0	*/
/*	ʱ�临�Ӷ�:	O(1)	*/
int DeQueue (Queue * const pqueue, Queue_Item * const pqueue_item) ;

/*	����:	�ͷ�һ��������ռ�õ��ڴ�ռ�	*/
/*	����ǰ:	pqueue ָ��һ���ѳ�ʼ���Ķ���	*/
/*	������:	�ö�����ռ�õ��ڴ�ռ䱻�ͷ�	*/
/*	ʱ�临�Ӷ�:	O(N)	*/
void ReleaseQueue (Queue * const pqueue) ;