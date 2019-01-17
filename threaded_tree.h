/*	threaded_tree.h -- ������ͷ�ļ�	*/
#define LINK 0
#define THREAD 1

/*	�������Ͷ���	*/

typedef int Item ;
typedef struct node
{
	Item item ;
	struct node * left ;
	struct node * right ;
	int left_tag ;
	int right_tag ;
} Node ;
typedef struct node * Tree ;

/*	�ӿں�������	*/

/*	����:	��ʼ��һ��������	*/
/*	����ǰ:	ptree ָ��һ��������	*/
/*	������:	��������ʼΪ����	*/
void InitializeTree (Tree * const ptree) ;

/*	����:	ȷ��һ���������Ƿ�Ϊ��	*/
/*	����ǰ:	ptree ָ��һ���ѳ�ʼ����������	*/
/*	������:	�������Ϊ��, ����1; ���򷵻�0	*/
int TreeIsEmpty (const Tree * const ptree) ;

/*	����:	�������������Ԫ��	*/
/*	����ǰ:	ptree ָ��һ���ѳ�ʼ����������, pitem ָ����ӵ�ָ������	*/
/*	������:	�������, ��ӵ�� pitem ָ������ݵĽ����ӵ�����, ����1; ���򷵻�0	*/
int Insert (Tree * const ptree, const Item * const pitem) ;

/*	����:	���ָ��������С�������ڽ���ָ��	*/
/*	����ǰ:	ptree ָ��һ���ѳ�ʼ����������	*/
/*	������:	����ָ��������С�������ڽ���ָ��	*/
Node * FindMin (const Tree * const ptree) ;

/*	����:	���ָ����������������ڽ���ָ��	*/
/*	����ǰ:	ptree ָ��һ���ѳ�ʼ����������	*/
/*	������:	����ָ����������������ڽ���ָ��	*/
Node * FindMax (const Tree * const ptree) ;

/*	����:	����������ɾ��һ��ָ���������ڵĽ��	*/
/*	����ǰ:	tree ��һ���ѳ�ʼ����������, item �ǵı�ɾ��������	*/
/*	������:	�������, pitem ָ���������ڵĽ�������ɾ��, ������������; ����������ԭ��	*/
Tree Delete (Tree tree, const Item item) ;

/*	����:	���ý�һ�ö��������������������ĺ���������������������	*/
/*	����ǰ:	ptree ָ��һ���ѳ�ʼ���Ķ���������	*/
/*	������:	����������������	*/
void PreorderThreading (Tree * const ptree) ;

/*	����:	���ý�һ�ö��������������������ĺ���������������������	*/
/*	����ǰ:	ptree ָ��һ���ѳ�ʼ���Ķ���������	*/
/*	������:	����������������	*/
void InorderThreading (Tree * const ptree) ;

/*	����:	���ý�һ�ö��������������������ĺ����������Ժ���������	*/
/*	����ǰ:	ptree ָ��һ���ѳ�ʼ���Ķ���������	*/
/*	������:	����������������	*/
void PostorderThreading (Tree * const ptree) ;

/*	����:	������һ��������������������Ԫ��	*/
/*	����ǰ:	tree ��һ���ѳ�ʼ����������, pfun ָ��һ��û�з���ֵ, ����һ��Item���Ͳ����ĺ���	*/
/*	������:	pfun ָ��ĺ�����������������������Ԫ��һ��	*/
void PreorderThreadedTraversal (const Tree tree, void (* pfun) (const Item item)) ;

/*	����:	������һ��������������������Ԫ��	*/
/*	����ǰ:	tree ��һ���ѳ�ʼ����������, pfun ָ��һ��û�з���ֵ, ����һ��Item���Ͳ����ĺ���	*/
/*	������:	pfun ָ��ĺ�����������������������Ԫ��һ��	*/
void InorderThreadedTraversal (const Tree tree, void (* pfun) (const Item item)) ;

/*	����:	�Ժ���һ��������������������Ԫ��	*/
/*	����ǰ:	tree ��һ���ѳ�ʼ����������, pfun ָ��һ��û�з���ֵ, ����һ��Item���Ͳ����ĺ���	*/
/*	������:	pfun ָ��ĺ����Ժ�����������������Ԫ��һ��	*/
void PostorderThreadedTraversal (const Tree tree, void (* pfun) (const Item item)) ;

/*	����:	������һ��������������������Ԫ��	*/
/*	����ǰ:	tree ��һ���ѳ�ʼ����������, pfun ָ��һ��û�з���ֵ, ����һ��Item���Ͳ����ĺ���	*/
/*	������:	pfun ָ��ĺ�����������������������Ԫ��һ��	*/
void InorderTraversal (const Tree tree, void (* pfun) (const Item item)) ;