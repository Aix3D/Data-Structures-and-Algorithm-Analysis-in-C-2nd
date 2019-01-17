/*	rqueue.h -- ����ͷ�ļ�	*/

/*	�������Ͷ���	*/

typedef int Item_R ;
typedef struct rqueue_node
{
	Item_R index_in_adjacenty_list ;
	struct rqueue_node * next ;
} Rqueue_Node ;
typedef struct rqueue
{
	Rqueue_Node * front ;
	Rqueue_Node * rear ;
	int current ;
} * Rqueue ;

/*	�ӿں�������	*/

/*	����:	��������ʼ��һ���������	*/
/*	����ǰ:	prq ָ��һ���������	*/
/*	������:	����ڴ����ɹ�, �ö��б�����������ʼ��Ϊ��, ���� 1; ���򷵻� 0	*/
/*	ʱ�临�Ӷ�:	O (1)	*/
int Initialize_R (Rqueue * const prq) ;

/*	����:	ȷ��һ����������Ƿ�Ϊ��	*/
/*	����ǰ:	prq ָ��һ���ѳ�ʼ���ļ������	*/
/*	������:	����ö���Ϊ��, ���� 1; ���򷵻� 0	*/
/*	ʱ�临�Ӷ�:	O (1)	*/
int IsEmpty_R (const Rqueue * const prq) ;

/*	����:	��һ��������������һ��Ԫ��	*/
/*	����ǰ:	prq ָ��һ���ѳ�ʼ���ļ������, index �Ǵ����Ԫ�ص�����	*/
/*	������:	����ڴ����ɹ�, ��ö��������������Ϊָ�����ݵ�Ԫ��, ���� 1; ���򷵻� 0	*/
/*	ʱ�临�Ӷ�:	O (1)	*/
int Insert_R (const Rqueue * const prq, const Item_R index) ;

/*	����:	�Ӽ��������ɾ��һ��Ԫ��	*/
/*	����ǰ:	prq ָ��һ���ѳ�ʼ���ļ������, pindex ��һ��ָ�����������͵�ָ��	*/
/*	������:	����ö��в�Ϊ��, �Ӹö�����ɾ��һ��Ԫ��, ������Ԫ������������ݸ��� pindex, ���� 1; ���򷵻� 0	*/
/*	ʱ�临�Ӷ�:	O (1)	*/
int Delete_R (const Rqueue * const prq, Item_R * const pindex) ;

/*	����:	�ͷ�һ�����������ռ�õ��ڴ�ռ�	*/
/*	����ǰ:	prq ָ��һ���ѳ�ʼ���ļ������	*/
/*	������:	�ö�����ռ�õ��ڴ�ռ䱻�ͷ�	*/
/*	ʱ�临�Ӷ�:	O (N)	*/
void Release_R (const Rqueue * const prq) ;