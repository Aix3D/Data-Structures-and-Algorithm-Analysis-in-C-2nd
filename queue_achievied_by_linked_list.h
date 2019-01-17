/*  queue_achievied_by_linked_list.h -- ����ͷ�ļ�	*/

/*	������������	*/
typedef int Item ;
typedef struct node
{
	Item item ;
	struct node * next ;
} Node ;
typedef struct queue
{
	Node * front ;
	Node * rear ;
	int items ;
} Queue ;

/*	�ӿں�������	*/

/*	����:	��ʼ��һ������	*/
/*	����ǰ:	pqueue ָ��һ������	*/
/*	������:	pqueue ָ��Ķ��б���ʼ��Ϊ�ն���	*/
void InitializeQueue (Queue * pqueue) ;

/*	����:	ȷ�������Ƿ�Ϊ��	*/
/*	����ǰ:	pqueueָ��һ���ѳ�ʼ���Ķ���	*/
/*	������:	�������Ϊ��,����1;���򷵻�0	*/
int QueueIsEmpty (const Queue * pqueue) ;

/*	����:	ȷ�������Ƿ�����	*/
/*	����ǰ:	pqueue ָ��һ���ѳ�ʼ���Ķ���	*/
/*	������:	�����������,����1;���򷵻�0	*/
int QueueIsFull (const Queue * pqueue) ;

/*	����:	��ö�����Ԫ�صĸ���	*/
/*	����ǰ:	pqueue ָ��һ���ѳ�ʼ���Ķ���	*/
/*	������:	���ض�����Ԫ�صĸ���	*/
int QueueItemCount( const Queue * pqueue) ;

/*	����:	�����(β��)���Ԫ��	*/
/*	����ǰ:	pqueue ָ��һ���ѳ�ʼ���Ķ���, pitem ָ��Ҫ��ӵ����е�Ԫ��	*/
/*	������:	�������, pitemָ���Ԫ�ر���ӵ�����(β��),����1;���򷵻�0	*/
int EnQueue (Queue * pqueue, const Item * pitem) ;

/*	����:	�Ӷ���(�׶�)ɾ��Ԫ��	*/
/*	����ǰ:	pqueue ָ��һ���ѳ�ʼ���Ķ���, pitem ��������ű�ɾ��Ԫ�����ݵ�ָ��	*/
/*	������:	�������, �Ӷ���(�׶�)ɾ��һ��Ԫ��, ��Ԫ�ص����ݱ����� *pitem,����1;���򷵻�0	*/
int DeQueue (Queue * pqueue, Item * pitem) ;

/*	����:	��һ���������õ������е�����Ԫ��(��ͷ��β)	*/
/*	����ǰ:	pqueue ָ��һ���ѳ�ʼ���Ķ���, pfun ָ��һ��û�з���ֵ,����һ��Item�������ݵĺ���	*/
/*	������:	pfun ָ��ĺ��������õ������е�����Ԫ��(��ͷ��β)	*/
void Traverse (const Queue * pqueue, void (* pfun) (const Item item)) ;

/*	����:	���һ������	*/
/*	����ǰ:	pqueueָ��һ���ѳ�ʼ���Ķ���	*/
/*	������:	�ö��б����	*/
void EmptyTheQueue (Queue * pqueue) ;