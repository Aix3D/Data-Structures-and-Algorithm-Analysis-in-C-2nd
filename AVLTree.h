/*  AVLTree.h -- AVl��ͷ�ļ�	*/

/*	�������Ͷ���	*/

typedef int Item ;
typedef struct node
{
	Item item ;
	struct node * left ;
	struct node * right ;
	int height ;
} Node ;
typedef Node * Position ;
typedef Node * Tree ;

/*	�ӿں�������	*/

/*	����:	��ʼ��һ��AVL��	*/
/*	����ǰ:	ptree ָ��һ��AVL��	*/
/*	������:	��������ʼ��Ϊ����	*/
void InitializeAVLTree (Tree * ptree) ;

/*	����:	ȷ��AVL���Ƿ�Ϊ��	*/
/*	����ǰ:	tree ��һ���ѳ�ʼ����AVL��	*/
/*	������:	�������Ϊ��, ����1; ���򷵻�0	*/
int AVLTreeIsEmpty (const Tree tree) ;

/*	����:	��������ָ���������ڽ��	*/
/*	����ǰ:	tree ��һ���ѳ�ʼ����AVL��, item �Ǳ����ҵ�����	*/
/*	������:	�������, ���ر������������ڽ��ĵ�ַ; ���򷵻�?	*/
Position Find (const Tree tree, const Item item) ;

/*	����:	������������������ڽ��λ��	*/
/*	����ǰ:	tree ��һ���ѳ�ʼ����AVL��	*/
/*	������:	�������, ������������������ڽ���λ��; ���򷵻�NULL	*/
Position FindMax (const Tree tree) ;

/*	����:	����������С�������ڽ��λ��	*/
/*	����ǰ:	tree ��һ���ѳ�ʼ����AVL��	*/
/*	������:	�������, ����������С�������ڽ���λ��; ���򷵻�NULL	*/
Position FindMin (const Tree tree) ;

/*	����:	��AVL���в�����	*/
/*	����ǰ:	tree ��һ���ѳ�ʼ����AVL��, item ��׼���������ָ������	*/
/*	������:	�������, ���ز�����������; ���򷵻�ԭ��	*/
Tree Insert (Tree tree, const Item item) ;

/*	����:	��AVL���в�����(�ǵݹ�ʵ��)	*/
/*	����ǰ:	tree ��һ���ѳ�ʼ����AVL��, item ��׼���������ָ������	*/
/*	������:	�������, ���ز�����������; ���򷵻�ԭ��	*/
Tree AddItem (Tree tree, const Item item) ;

/*	����:	�����������һ������������AVL���е����н��	*/
/*	����ǰ:	tree ��һ���ѳ�ʼ����AVL��, pfun ָ��һ��û�з���ֵ, ����һ�� Position ���Ͳ����ĺ���	*/
/*	������:	�ú��������õ����������н��, ����������ʽ	*/
void InorderTraversal (const Tree tree, void (* pfun) (const Position position)) ;

/*	����:	ɾ��AVL����ָ���������ڽ��	*/
/*	����ǰ:	tree ��һ���ѳ�ʼ����AVL��, item �Ǳ�ɾ��������	*/
/*	������:	�������, ɾ�����������ڽ��, ������������AVL������, ������������ַ; ����������, ������������ַ	*/
Tree Delete (Tree tree, const Item item) ;

/*	����:	���һ��AVL��	*/
/*	����ǰ:	tree ��һ���ѳ�ʼ����AVL��	*/
/*	������:	���������	*/
void EmptyTheAVLTree (Tree tree) ;