/*  2-d_tree.h -- 2-d��ͷ�ļ�	*/
#define ODD 1
#define EVEN 0
#define TRUE 1
#define FALSE 0

/*	�������Ͷ���	*/
typedef int Item ;
typedef struct node
{
	int layer ;
	Item key1, key2 ;
	struct node * left ;
	struct node * right ;
} Node ;
typedef Node * Tree ;

/*	�ӿں�������	*/

/*	����:	��ʼ��һ��2-d��	*/
/*	����ǰ:	ptree ָ��һ��2-d��	*/
/*	������:	��������ʼ��Ϊ����	*/
void InitializeTree (Tree * const ptree) ;

/*	����:	ȷ��һ��2-d���Ƿ�Ϊ��	*/
/*	����ǰ:	ptree ָ��һ���ѳ�ʼ����2-d��	*/
/*	������:	�������Ϊ��, ��������1; ����������0	*/
int TreeIsEmpty (const Tree * const ptree) ;

/*	����:	����һ��2-d�������Ľ���ָ��	*/
/*	����ǰ:	ptree ָ��һ���ѳ�ʼ����2-d��	*/
/*	������:	���ظ����������Ľ���ָ��	*/
Node * FindMin (const Tree * const ptree) ;

/*	����:	����һ��2-d�����Ҳ����ָ��	*/
/*	����ǰ:	ptree ָ��һ���ѳ�ʼ����2-d��	*/
/*	������:	���ظ��������Ҳ����ָ��	*/
Node * FindMax (const Tree * const ptree) ;

/*	����:	���������һ������Ϊָ�����ݵĽ��	*/
/*	����ǰ:	ptree ָ��һ���ѳ�ʼ����2-d��, pkey1 ָ���һ���ؼ���, pkey2 ָ��ڶ����ؼ���	*/
/*	������:	�������, һ���ؼ���1ͬ *pkey1 ��ͬ, �ؼ���2ͬ *pkey2 ��ͬ�Ľ�㱻��ӵ�����, ��������1; ����������0	*/
int Insert (Tree * const ptree, const Item * const pkey1, const Item * const pkey2) ;

/*	����:	������һ��������������������low1 <= key1 <= high1 && low2 <= key2 <= high2�����н��	*/
/*	����ǰ:	ptree ָ��һ���ѳ�ʼ����2-d��, low1, high1, low2, high2����Χ, pfun ָ��һ��û�з���ֵ, ����һ��ָ��Item���͵�ָ��ĺ���	*/
/*	������: ������һ��������������������low1 <= key1 <= high1 && low2 <= key2 <= high2�����н��	*/
void InorderSeekTraversal (const Tree * const ptree, const Item low1, const Item low2, const Item high1, const Item high2, void (* pfun) (const Item * const pkey1, const Item * const pejy2)) ;

/*	����:	��2-d����ɾ��һ������Ϊָ�����ݵĽ��	*/
/*	����ǰ:	ptree ָ��һ���ѳ�ʼ����2-d��, pkey1 ָ��ؼ���1, peky2 ָ��ؼ���2	*/
/*	������:	�������, ������ɾ���ý�㲢��������; ���򷵻�ԭ��	*/
Tree Delete (Tree * const ptree, const Item * const pkey1, const Item * const pkey2) ;