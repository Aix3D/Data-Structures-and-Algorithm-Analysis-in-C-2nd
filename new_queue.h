/*  new_queue.h -- ����ͷ�ļ�.ûʲô��ͬ.ֻ����ϰһ��	*/
#include "binary_search_tree.h"

/*	�������Ͷ���	*/

typedef Node * QueueItem ;
typedef struct queue_node
{
	QueueItem item ;
	struct queue_node * next ;
} QueueNode ;
typedef struct queue
{
	QueueNode * front ;
	QueueNode * rear ;
} Queue ;

/*	�ӿں�������	*/

/*	����:	��ʼ��һ������	*/
/*	����ǰ:	pqueue ָ��һ������	*/
/*	������:	�ö��б���ʼΪ��	*/
void InitializeQueue (Queue * const pqueue) ;

/*	����:	ȷ�������Ƿ�Ϊ��	*/
/*	����ǰ:	pqueue ָ��һ���ѳ�ʼ���Ķ���	*/
/*	������:	�������Ϊ��, ����1; ���򷵻�0	*/
int QueueIsEmpty (const Queue * const pqueue) ;

/*	����:	�����(β)���ָ�����ݵĽ��	*/
/*	����ǰ:	pqueue ָ��һ���ѳ�ʼ���Ķ���, pitem ָ��ָ��������	*/
/*	������:	�������, �����(β)���һ��ӵ�� pitem ָ�����ݵĽ��, ����1; ���򷵻�0	*/
int EnQueue (Queue * const pqueue, const QueueItem * const pitem) ;

/*	����:	�Ӷ���(��)ɾ��һ�����	*/
/*	����ǰ:	pqueue ָ��һ���ѳ�ʼ���Ķ���	*/
/*	������:	�������, �Ӷ����׶�ɾ��һ�����, ���ظý������(�����Ǹý��); ���򷵻�NULL	*/
QueueItem DeQueue (Queue * const pqueue) ;

/*	����:	��һ������������(�Ӷ����׶�-β��)��ÿһ�����	*/
/*	����ǰ:	pqueue ָ��һ���ѳ�ʼ���Ķ���, pfun ָ��һ��û�з���ֵ, ����һ��QueueItem���ͱ����ĺ���	*/
/*	������:	pfun ָ��ĺ����������ڶ�����ÿ�����һ��	*/
void Traversal (const Queue * const pqueue, void (* pfun) (const QueueItem item)) ;

/*	����:	���һ������	*/
/*	����ǰ:	pqueue ָ��һ���ѳ�ʼ���Ķ���	*/
/*	������:	�ö��б����	*/
void EmptyTheQueue (Queue * const pqueue) ;