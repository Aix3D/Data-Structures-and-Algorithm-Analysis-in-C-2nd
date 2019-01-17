/*  splay_tree.h -- ��չ��ͷ�ļ�  */

/*	�������Ͷ���	*/
typedef int Item ;
typedef struct node
{
	Item item ;
	struct node * left ;
	struct node * right ;
} Node ;
typedef Node * Position ;
typedef Node * SplayTree ;

/*	�ӿں�������	*/

/*	����:	��ʼ��һ����չ��	*/
/*	����ǰ:	ptree ָ��һ����չ��	*/
/*	������:	��������ʼ��Ϊ��	*/
void IintializeSplayTree (SplayTree * ptree) ;

/*	����:	ȷ��һ����չ���Ƿ�Ϊ��	*/
/*	����ǰ:	tree ��һ���ѳ�ʼ������չ��	*/
/*	������:	�������Ϊ��, ����1; ���򷵻�0	*/
int SplayTreeIsEmpty (const SplayTree tree) ;

/*	����:	ȷ��һ����չ���Ƿ�����	*/
/*	����ǰ:	(�ú����������κβ���)	*/
/*	������:	�����������,����1; ���򷵻�0	*/
int SplayTreeIsFull (void) ;

/*	����:	���������һ�����(�ǵݹ�)	*/
/*	����ǰ:	tree ��һ���ѳ�ʼ������չ��, item ��һ��Item��������	*/
/*	������:	�������, ӵ�� item ���ݵĽ�㱻��ӵ�����, ���������ĸ��ڵ�; ���򷵻�ԭ��	*/
SplayTree AddItem (SplayTree tree, const Item item) ;

/*	����:	���������һ�����(�ݹ�)	*/
/*	����ǰ:	tree ��һ���ѳ�ʼ������չ��, item ��һ��Item��������	*/
/*	������:	�������, ӵ�� item ���ݵĽ�㱻��ӵ�����, ���������ĸ��ڵ�; ���򷵻�ԭ��	*/
SplayTree Insert (SplayTree tree, const Item item) ;

/*	����:	�ҵ�����������ݵĽ��	*/
/*	����ǰ:	tree ��һ���ѳ�ʼ������չ��	*/
/*	������:	�������, ��������������ݽ���ָ��; ���򷵻�NULL	*/
Position FindMax (const SplayTree tree) ;

/*	����:	�ҵ�������С���ݵĽ��	*/
/*	����ǰ:	tree ��һ���ѳ�ʼ������չ��	*/
/*	������:	�������, ����������С���ݽ���ָ��; ���򷵻�NULL	*/
Position FindMin (const SplayTree tree) ;

/*	����:	����ָ�����ݵĽ�㲢�ŵ����ڵ��λ��	*/
/*	����ǰ:	tree ��һ���ѳ�ʼ������չ��, item ��ָ���ı����ҵ�����	*/
/*	������:	�������, ���ҵ��Ľ����Ϊ���ڵ�, ���ظý��; ���򷵻�ԭ��	*/
SplayTree Find (SplayTree tree, const Item item) ;

/*	����:	����ָ�����ݵĽ�㲢�ŵ�������λ��(ʹ��ջ)	*/
/*	����ǰ:	tree ��һ���ѳ�ʼ������չ��, item ��ָ���ı����ҵ�����	*/
/*	������:	�������, ���ҵ��Ľ����Ϊ�����, ���ظý��; ���򷵻�ԭ��	*/
SplayTree Find_By_Use_Stack (SplayTree tree, const Item item) ;

/*	����:	ɾ��ָ���������ڽ��	*/
/*	����ǰ:	tree ��һ���ѳ�ʼ������չ��, item ��ָ���ı�ɾ��������	*/
/*	������:	�������, ӵ�� item ���ݵĽ�㱻ɾ��, ���������Ľ��; ���򷵻�ԭ��	*/
SplayTree Delete (SplayTree tree, const Item item) ;

/*	����:	��һ�������������������������н��	*/
/*	����ǰ:	tree ��һ���ѳ�ʼ������չ��, pfun ָ��һ��û�з���ֵ, ����һ��Item������Ϣ�Ĳ���	*/
/*	������:	�ú����������������������н��һ��	*/
void InorderTraversal (const SplayTree tree, void (* pfun) (const Item item)) ;