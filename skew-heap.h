/*	skew-heap.h -- б��ͷ�ļ�	*/
#define INSERT(heap, item) (heap = Insert (heap, item))
#define DELETEMIN(heap, pnode) (heap = DeleteMin (heap, pnode))
#define BUILD(heap, parray, size) (heap = Build (parray, size))

/*	�������Ͷ���	*/

typedef int Item ;
typedef struct node
{
	Item item ;
	struct node * left ;
	struct node * right ;
} Node ;
typedef Node * Heap ;

/*	�ӿں�������	*/

/*	����:	��������һ��б����Ϊ��	*/
/*	����ǰ:	pheap ָ��һ��б��	*/
/*	������:	����ڴ����ɹ�, ��б�ѱ���ʼΪ��, ����1; ���򷵻�0	*/
int Create (Heap * const ph) ;

/*	����:	ȷ��һ��б���Ƿ�Ϊ��	*/
/*	����ǰ:	h ��һ���ѳ�ʼ����б��	*/
/*	������:	����ö�Ϊ��, ����1; ���򷵻�0	*/
int HeapIsEmpty (const Heap h) ;

/*	����:	�ϲ�����б�Ѳ����غϲ����б��	*/
/*	����ǰ:	h1, h2 �������ѳ�ʼ����б��	*/
/*	������:	�ϲ�����, �����¶�	*/
Heap Merge (const Heap h1, const Heap h2) ;

/*	����:	��б���в���һ���ڵ�	*/
/*	����ǰ:	h ��һ���ѳ�ʼ����б��, item ���½ڵ������	*/
/*	������:	���½ڵ���뵽����, �����¶�	*/
Heap Insert (Heap h, const Item item) ;

/*	����:	ɾ��б������С�ؼ��ֵĽڵ�	*/
/*	����ǰ:	heap ��һ���ѳ�ʼ����б��, pnode �ǳ�����С�ؼ��ֽڵ��ָ�����	*/
/*	������:	����Ѳ�Ϊ��, ɾ����С�ؼ��ֵĽڵ�, ʹ pnode ָ��ýڵ�, �����¶�; ���򷵻�ԭ��	*/
Heap DeleteMin (Heap h, Node * const pnode) ;

/*	����:	���Ҳ�����ָ��б���о���ָ���ؼ��ֽڵ��ָ��	*/
/*	����ǰ:	h ��һ���ѳ�ʼ����б��, item ָʾ�����ҵĹؼ���	*/
/*	������:	����ҵ��ýڵ�, ����ָ��ýڵ��ָ��; ���򷵻�NULL	*/
Node * Find (const Heap h, const Item item) ;

/*	����:	����һ���������鹹��������һ��б�Ѷ�	*/
/*	����ǰ:	array ��һ����������, size ָʾ����Ĵ�С	*/
/*	������:	����ڴ����ɹ�, ���������ظö�; ���򷵻�NULL	*/
Heap Build (const Item array[], const int size) ;

/*	����:	���һ��б����ռ�ڴ�ռ�	*/
/*	����ǰ:	h ��һ���ѳ�ʼ����б��	*/
/*	������:	�ö���ռ�ڴ�ռ䱻�ͷ�	*/
void Release (const Heap h) ;