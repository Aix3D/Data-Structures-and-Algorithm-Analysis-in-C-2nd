/*  queue_achievied_by_array.h -- ����ͷ�ļ�	*/

/*	�������Գ���	*/
#define MINQUEUESIZE (5)

/*	������������	*/
typedef int Item ;
typedef struct record
{
	int capacity ;		/*	���д�С	*/
	int front ;			/*	ͷ������ֵ	*/
	int rear ;			/*	β������ֵ	*/
	int size ;			/*	�Ѵ���Ԫ�صĸ���	*/
	Item * array ;
} Record ;
typedef Record * Queue ;

/*	�ӿں�������	*/

/*	����:	����һ������	*/
/*	����ǰ:	size ��ʾ���������С	*/
/*	������:	����һ����СΪ size ���ѳ�ʼ���Ķ���	*/
Queue CreateQueue (const int size) ;

/*	����:	ȷ�������Ƿ�Ϊ��	*/
/*	����ǰ:	queue ��һ���ѳ�ʼ���Ķ���	*/
/*	������:	�������Ϊ��,����1;���򷵻�0	*/
int QueueIsEmpty (const Queue queue) ;

/*	����:	ȷ�������Ƿ�����	*/
/*	����ǰ:	queue ��һ���ѳ�ʼ���Ķ���	*/
/*	������:	�����������,����1;���򷵻�0	*/
int QueueIsFull (const Queue queue) ;

/*	����:	��ö�����Ԫ�صĸ���	*/
/*	����ǰ:	queue ��һ���ѳ�ʼ���Ķ���	*/
/*	������:	���ض�����Ԫ�صĸ���	*/
int QueueItemCount (const Queue queue) ;

/*	����:	�����(β��)���Ԫ��	*/
/*	����ǰ:	queue ��һ���ѳ�ʼ���Ķ���, item ��׼����ӽ����е�Ԫ��	*/
/*	������:	�������,itemԪ�ر���ӵ�����(β��),����1;���򷵻�0	*/
int EnQueue (Queue queue, const Item item) ;

/*	����:	�Ӷ���(�׶�)ɾ��Ԫ��	*/
/*	����ǰ:	queue ��һ���ѳ�ʼ���Ķ���, pitem ��һ��������ö����׶�Ԫ�����ݵ�ָ��	*/
/*	������:	�������, �����׶�Ԫ�ص�ֵ������ *pitem,�����׶�Ԫ�شӶ�����ɾ��,����1;���򷵻�0	*/
int DeQueue (Queue queue, Item * const pitem) ;

/*	����:	ʹһ�����������ڶ���������Ԫ��(���׵���β)	*/
/*	����ǰ:	queue ��һ���ѳ�ʼ���Ķ���, pfun ָ��һ��û�з���ֵ,����һ��Item��������λ�����ĺ���	*/
/*	������:	pfunָ��ĺ��������õ�����������Ԫ��һ��	*/
void Traverse (const Queue queue, void (* pfun) (const Item item)) ;

/*	����:	���һ������	*/
/*	����ǰ:	queue��һ���ѳ�ʼ���Ķ���	*/
/*	������:	���б����	*/
void EmptyTheQueue (Queue queue) ;
