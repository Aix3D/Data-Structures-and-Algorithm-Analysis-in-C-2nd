/*  doubly_queue.h -- ˫�˶���ͷ�ļ�	*/

/*	���Գ�������	*/
#define MAXDOUBLYQUEUE (10)
#define NUL '\0'

/*	�������Ͷ���	*/

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

/*	����:	��ʼ��һ��˫�˶���	*/
/*	����ǰ:	pqueue ָ��һ��˫�˶���	*/
/*	������:	��˫�˶��б���ʼ��Ϊ��˫�˶���	*/
void InitializeDoublyQueue (Queue * pqueue) ;

/*	����:	ȷ��˫�˶����Ƿ�Ϊ��	*/
/*	����ǰ:	pqueue ָ��һ���ѳ�ʼ����˫�˶���	*/
/*	������: �����˫�˶���Ϊ��,����1; ���򷵻�0	*/
int DoublyQueueIsEmpty (const Queue * pqueue) ;

/*	����:	ȷ��˫�˶����Ƿ�����	*/
/*	����ǰ:	pqueue ָ��һ���ѳ�ʼ����˫�˶���	*/
/*	������:	�����˫�˶�������,����1; ���򷵻�0	*/
int DoublyQueueIsFull (const Queue * pqueue) ;

/*	����:	���˫�˶�����Ԫ�صĸ���	*/
/*	����ǰ:	pqueue ָ��һ���ѳ�ʼ����˫�˶���	*/
/*	������:	���ظ�˫�˶�����Ԫ�صĸ���	*/
int DoublyQueueItemCount (const Queue * pqueue) ;

/*	����:	��˫�˶����׶����Ԫ��	*/
/*	����ǰ:	pqueue ָ��һ���ѳ�ʼ����˫�˶���, pitem ָ�����Ԫ�ص�����	*/
/*	������:	�������, pitem ָ��Ԫ�ص����ݱ���ӵ�˫�˶����׶�, ����1; ���򷵻�0	*/
int Push (Queue * pqueue, const Item * pitem) ;

/*	����:	��˫�˶���β�����Ԫ��	*/
/*	����ǰ:	pqueue ָ��һ���ѳ�ʼ����˫�˶���, pitem ָ�����Ԫ�ص�����	*/
/*	������:	�������, pitem ָ��Ԫ�ص����ݱ���ӵ�˫�˶���β��, ����1; ���򷵻� 0	*/
int Inject (Queue * pqueue, const Item * pitem) ;

/*	����:	��˫�˶����׶�ɾ��һ��Ԫ�ز����䷵��	*/
/*	����ǰ:	pqueue ָ��һ���ѳ�ʼ����˫�˶���	*/
/*	������:	�������, ��˫�˶����׶�ɾ��һ��Ԫ��, ���ظ�Ԫ��; ���򷵻�NUL	*/
Item Pop (Queue * pqueue) ;

/*	����:	��˫�˶���β��ɾ��һ��Ԫ�ز����䷵��	*/
/*	����ǰ:	pqueue ָ��һ���ѳ�ʼ����˫�˶���	*/
/*	������:	�������, ��˫�˶���β��ɾ��һ��Ԫ��, ���ظ�Ԫ��; ���򷵻�NUL	*/
Item Eject (Queue * pqueue) ;

/*	����:	��һ������������˫�˶����е�����Ԫ��һ��(���׶˵�β��)	*/
/*	����ǰ:	pqueue ָ��һ���ѳ�ʼ����˫�˶���, pfun ָ��һ��û�з���ֵ, ����һ��Item���Ͳ����ĺ���	*/
/*	������:	pfun ָ��ĺ����������ڶ����е�����Ԫ��һ��	*/
void Traverse (const Queue * pqueue, void (* pfun) (const Item item)) ;

/*	����:	���˫�˶���	*/
/*	����ǰ:	pqueue ָ��һ���ѳ�ʼ����˫�˶���	*/
/*	������:	pqueue ָ��Ķ��б����	*/
void EmptyTheDoublyQueue (Queue * pqueue) ;