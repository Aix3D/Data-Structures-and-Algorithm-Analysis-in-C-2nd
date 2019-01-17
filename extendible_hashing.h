/*	extendible_hashing.h	-- ����ɢ��ͷ�ļ�	*/
#define NO 0
#define YES 1
#define M 4
#define LENTH 8

/*	�������Ͷ���	*/

typedef unsigned char Item ;		/*	����	*/
typedef struct unit
{
	Item * array ;					/*	��������	*/
	char sub ;						/*	ʹ���б�Ԫ������	*/
} Unit ;							/*	���ݵ�Ԫ	*/
typedef struct subdirectories
{
	Unit * point ;					/*	ָ�����ݵ�Ԫ��ָ��	*/
	char point_to_itself ;			/*	����Ƿ�ָ����䱾������ݿռ�	*/
	char byte_index ;				/*	λ����ֵ	*/
} Subdirectories ;					/*	��Ŀ¼	*/
typedef struct table
{
	Subdirectories * directory ;	/*	Ŀ¼(��Ŀ¼����)	*/
	char directory_size ;			/*	Ŀ¼��С	*/
	char index_digit ;				/*	����λ��	*/
	char item_digit ;				/*	����λ��	*/
	char array_size ;				/*	���������С	*/
} * Table ;

/*	˵��:	��������û�������������͵�ģ��, �����Լ�����Ҫ����	*/
/*			��������������Ϊchar����.�з���8λ������,�������ڲ���	*/

/*	�ӿں�������	*/

/*	����:	���ݶ����������ݲ���һ����ֵ������	*/
/*	����ǰ:	pitem ָ��ָ������, constant �Ǳ���λ����ֵ	*/
/*	������:	����һ����ֵ������	*/
int Hash (const Item * const pitem, const char constant) ;

/*	����:	��������ʼ��һ������ɢ�б�	*/
/*	����ǰ:	ptable ָ��һ������ɢ�б�	*/
/*	������:	����ڴ����ɹ�, �����ÿ���ɢ�б�, Ŀ¼��С��ʼ��Ϊ4, ����λ����ʼ��Ϊ2, ���������С��ʼ��Ϊ4, ����1; ���򷵻�0	*/
int InitializeTable (Table * const ptable) ;

/*	����:	�����ɢ�б������һ��Ԫ��	*/
/*	����ǰ:	ptable ָ��һ���ѳ�ʼ���Ŀ���ɢ�б�, pitem ָ��ָ��������	*/
/*	������:	���δ�ظ����, ����ڴ����ɹ�, ��ָ����������ӵ�����ɢ�б���, ����1; ���򷵻�0	*/
int Insert (const Table * const ptable, const Item * const pitem) ;

/*	����:	���Ҳ����ؿ���ɢ�б��е�һ��ָ������	*/
/*	����ǰ:	ptable ָ��һ���ѳ�ʼ���Ŀ���ɢ�б�, pitem ָ��ָ��������	*/
/*	������:	����ҵ�, ����1; ���򷵻�0	*/
int Find (const Table * const ptable, const Item * const pitem) ;

/*	����:	�ӿ���ɢ�б�Ŀ¼�ĵ���������������ν�һ������������pointָ��ָ�����������ݿռ�ĵ���Ŀ¼	*/
/*	����ǰ:	ptable ָ��һ���ѳ�ʼ���Ŀ���ɢ�б�, pfun ָ��һ��û�з���ֵ, ����һ��Subdirectories���Ͳ����ĺ���	*/
/*	������:	�ӿ���ɢ�б�Ŀ¼�ĵ���������������ν�һ������������pointָ��ָ�����������ݿռ�ĵ���Ŀ¼	*/
void Traversal (const Table * const ptable, void (* pfun) (const Subdirectories subdirectories)) ;

/*	����:	�ӿ���ɢ�б���ɾ��һ��ָ������	*/
/*	����ǰ:	ptable ָ��һ���ѳ�ʼ���Ŀ���ɢ�б�, pitem ��׼��ɾ��������	*/
/*	������:	����ҵ�������, �������ݴӿ���ɢ�б���ɾ��, ����1; ���򷵻�0	*/
int Delete (const Table * const ptable, const Item * const pitem) ;

/*	����:	��տ���ɢ�б�ռ�õ��ڴ�ռ�	*/
/*	����ǰ:	pteble ָ��һ���ѳ�ʼ���Ŀ���ɢ�б�	*/
/*	������:	�ÿ���ɢ�б�ռ�õ��ڴ�ռ䱻�ͷ�	*/
void Release (const Table * const ptable) ;