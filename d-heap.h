/*	d-heap.h -- d-��ͷ�ļ�	*/
#define MINDATA -32678

/*	�������Ͷ���	*/

typedef int Item ;
typedef struct heap
{
	Item * array ;
	int capacity ;
	int size ;
	int d ;
} * Heap ;

/*	�ӿں�������	*/

/*	����:	��������ʼ��һ��d-��	*/
/*	����ǰ:	pheap ָ��һ��d-��, capacity ������ָʾ�������ı���, d �����нڵ������ӵ�����	*/
/*	������:	����ڴ����ɹ�, һ������Ϊ capacity �Ķѱ�����������ʼΪ��, ���ж�������������Ϊ d , ����1; ���򷵻�0	*/
int InitializeHeap (Heap * const pheap, const int capacity, const int d) ;

/*	����:	ȷ��һ�����Ƿ�Ϊ��	*/
/*	����ǰ:	pheap ָ��һ���ѳ�ʼ����d-��	*/
/*	������:	����ö�Ϊ��, ����1; ���򷵻�0	*/
int HeapIsEmpty (const Heap * const pheap) ;

/*	����:	ȷ��һ�����Ƿ�����	*/
/*	����ǰ:	pheap ָ��һ���ѳ�ʼ����d-��	*/
/*	������:	����ö�����, ����1; ���򷵻�0	*/
int HeapIsFull (const Heap * const pheap) ;

/*	����:	��d-�������һ��Ԫ��	*/
/*	����ǰ:	pheap ָ��һ���ѳ�ʼ����d-��, item �Ǵ���ӵ�����	*/
/*	������:	�����δ��, �� item ��ӵ�����, ����1; ���򷵻�0	*/
int Insert (const Heap * const pheap, const Item item) ;

/*	����:	ɾ�������ض�����С��Ԫ��	*/
/*	����ǰ:	pheap ָ��һ���ѳ�ʼ����d-��	*/
/*	������:	����Ѳ�Ϊ��, ɾ�������ض��е���СԪ��; ���򷵻�MINDATA	*/
Item DeleteMin (const Heap * const pheap) ;

/*	����:	���Ͷ���ָ��λ�ô�Ԫ�ص�ֵ	*/
/*	����ǰ:	pheap ָ��һ���ѳ�ʼ����d-��, position ָʾ���е�λ��, triangle �Ǹı���	*/
/*	������:	��� position �ڶ��е�λ�ô���, triangle > 0, ��λ���ϵ�Ԫ�ر����� triangle, ����1; ���򷵻�0	*/
int DecreaseKey (const Heap * const pheap, const int position, const int triangle) ;

/*	����:	���Ӷ���ָ��λ�ô�Ԫ�ص�ֵ	*/
/*	����ǰ:	pheap ָ��һ���ѳ�ʼ����d-��, position ָʾ���е�λ��, triangle �Ǹı���	*/
/*	������:	��� position �ڶ��е�λ�ô���, traingle > 0, ��λ���ϵ�Ԫ�ر����� traingle, ����1; ���򷵻�0	*/
int IncreaseKey (const Heap * const pheap, const int position, const int triangle) ;

/*	����:	����һ���������鹹��һ��d-��	*/
/*	����ǰ:	pheap ָ��һ���ѳ�ʼ����d-��, array ��һ��ָ������������Ԫ�ص�ָ��, size �������С	*/
/*	������:	�����Ϊ��, �����С>0, �����ö�, ����1; ���򷵻�0	*/
int BuildHeap (const Heap * const pheap, const Item * parray, const int size) ;

/*	����:	ɾ��d-����ָ��λ�õ�Ԫ��	*/
/*	����ǰ:	pheap ָ��һ���ѳ�ʼ����d-��, position ָʾ���е�λ��	*/
/*	������:	������� position λ�ô���, ��λ�ô���Ԫ�ر�ɾ��, ����1; ���򷵻�0	*/
int Delete (const Heap * const pheap, const int position) ;

/*	����:	������1 - size ���ν�һ������������d-��������Ԫ��1��	*/
/*	����ǰ:	pheap ָ��һ���ѳ�ʼ���Ķ�, pfun ָ��һ��û�з���ֵ, ����һ��Item���Ͳ����ĺ���	*/
/*	������:	pfun ָ��ĺ������������õ���������Ԫ��1��	*/
void Traversal (const Heap * const pheap, void (* pfun) (const Item item)) ;

/*	����:	�ͷ�һ��d-��ռ�õ��ڴ�ռ�	*/
/*	����ǰ:	pheap ָ��һ���ѳ�ʼ���Ķ�	*/
/*	������: �ö�ռ�õ��ڴ�ռ䱻�ͷ�	*/
void Release (const Heap * const pheap) ;