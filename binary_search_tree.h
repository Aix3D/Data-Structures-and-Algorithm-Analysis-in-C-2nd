/*  binary_search_tree.h -- ����������ͷ�ļ�	*/

/*	�������Ͷ���	*/
typedef int Item ;
typedef struct node
{
	Item item ;
	int depth ;
	int x_coordinate ;
	int y_coordinate ;
	struct node * left ;
	struct node * right ;
} Node ;
typedef Node * Position ;
typedef Node * Tree ;

/*	�ӿں�������	*/

/*	����:	��ʼ��һ�ö���������	*/
/*	����ǰ:	ptree ָ��һ�ö���������	*/
/*	������:	��������ʼ��Ϊ����	*/
void InitializeTree (Tree * const ptree) ;

/*	����:	ȷ�������������Ƿ�Ϊ��	*/
/*	����ǰ:	ptree ָ��һ���ѳ�ʼ���Ķ���������	*/
/*	������:	�������Ϊ��, ����1; ���򷵻�0	*/
int TreeIsEmpty (const Tree * const ptree) ;

/*	����:	Ѱ��������С���	*/
/*	����ǰ:	ptree ָ��һ���ѳ�ʼ���Ķ���������	*/
/*	������:	�������, ���ظ�������С�Ľ��; ���򷵻�NULL	*/
Node * FindMin (const Tree * const ptree) ;

/*	����:	Ѱ�����������	*/
/*	����ǰ:	ptree ָ��һ���ѳ�ʼ���Ķ���������	*/
/*	������:	�������, ���ظ�������С�Ľ��; ���򷵻�NULL	*/
Node * FindMax (const Tree * const ptree) ;

/*	����:	���������һ�����	*/
/*	����ǰ:	ptree ָ��һ���ѳ�ʼ���Ķ���������, pitem ָ��ָ����ӵ�����	*/
/*	������:	�������, ���������һ���µĽ��ӵ�� pitem ָ��������Ϊ����, ����1; ���򷵻�0	*/
int Insert (Tree * const ptree, const Item * const pitem) ;

/*	����:	������ɾ��һ�����	*/
/*	����ǰ:	tree ��һ���ѳ�ʼ���Ķ���������, item ��ָ��ɾ��������	*/
/*	������:	�������, pitem ָ�����ݵĽ�������ɾ��, ��������; ���򷵻�ԭ��	*/
Tree Delete (Tree tree, const Item item) ;

/*	����:	��һ�������������������н��(����)	*/
/*	����ǰ:	tree ��һ���ѳ�ʼ���Ķ���������, pfun ָ��һ��û�з���ֵ, ����һ��Item�������ݵĺ���	*/
/*	������:	���������ڸ��������н��һ��(����)	*/
void InorderTraversal (const Tree tree, void (* pfun) (const Item item)) ;

/*	����:	���һ�ö���������	*/
/*	����ǡ:	tree ��һ���ѳ�ʼ���Ķ���������	*/
/*	������:	���������	*/
void EmptyTheTree (const Tree tree) ;