/*	min-max_heap.h -- ��С-����ͷ�ļ�	*/
#define ODD 1	//	����
#define EVEN 2	//	ż��
#define DATA -32768

/*	�������Ͷ���	*/

typedef struct item
{
	int element ;
	int index ;
} Item ;
typedef struct heap
{
	Item * array ;
	int capacity ;
	int size ;
	int layer ;
} * Heap ;

/*	�ӿں�������	*/

/*	����:	��������ʼ��һ����С-����	*/
/*	����ǰ:	pheap ָ��һ����С-����, capacity ָʾ�ѵ�����	*/
/*	������:	����ڴ����ɹ�, capacity ��Ч, ���������öѳ�ʼ��Ϊ��, ����1; ���򷵻�0	*/
int InitializeHeap (Heap * const pheap, const int capacity) ;

/*	����:	ȷ��һ����С-�����Ƿ�Ϊ��	*/
/*	����ǰ:	pheap ָ��һ���ѳ�ʼ������С-����	*/
/*	������:	����ö�Ϊ��, ����1; ���򷵻�0	*/
int HeapIsEmpty (const Heap * const pheap) ;

/*	����:	ȷ��һ����С-�����Ƿ�����	*/
/*	����ǰ:	pheap ָ��һ���ѳ�ʼ������С-����	*/
/*	������:	����ö�����, ����1; ���򷵻�0	*/
int HeapIsFull (const Heap * const pheap) ;

/*	����:	��һ����С-���������һ��Ԫ��	*/
/*	����ǰ:	pheap ָ��һ���ѳ�ʼ������С-����, element ָʾ����ӵ�����	*/
/*	������:	�����δ��, �� element ��ӽ�����, ����1; ���򷵻�0	*/
int Insert (const Heap * const heap, const int element) ;

/*	����:	ɾ����������С-�����е���СԪ��	*/
/*	����ǰ:	pheap ָ��һ���ѳ�ʼ������С-����	*/
/*	������:	����Ѳ�Ϊ��, ɾ�������ض��е���СԪ��; ���򷵻� DATA	*/
Item DeleteMin (const Heap * const pheap) ;

/*	����:	�ӵ���������������ν�һ���������������-��С��������Ԫ��1��	*/
/*	����ǰ:	pheap ָ��һ���ѳ�ʼ������С-����, pfun ָ��һ��û�з���ֵ, ����һ��Item���Ͳ����ĺ���	*/
/*	������:	pfun �����������ڶ�������Ԫ��1��	*/
void Traversal (const Heap * const pheap, void (* pfun) (const Item item)) ;