/*	8-3-11-29-23.52.c -- ���ཻ��ADTͷ�ļ�	*/
#define OOS (-65536)
#define SIZE (-1)
#define HEIGHT (0)

/*	�������Ͷ���	*/

typedef int Item ;
typedef Item SetType   ;
typedef SetType * DisjiontSet ;

/*	�ӿں�������	*/

/*	����:	���߶ȳ�ʼ��һ�����ཻ����	*/
/*	����ǰ:	gather ��һ�����ཻ����, size ��ָʾ���ཻ���ϵĴ�С	*/
/*	������:	������һ����������������Ϊ���ϵ�ʵ�ʴ�С��, �����м��������򱻳�ʼ��ΪHEIGHT	*/
void InitializeAsHeight (DisjiontSet gather, const int size) ;

/*	����:	����С��ʼ��һ�����ཻ����	*/
/*	����ǰ:	gather ��һ�����ཻ����, size ָʾ���ཻ���ϵĴ�С	*/
/*	������:	������һ������������λ��Ϊ���ϵ�ʵ�ʴ�С��, ���м��������򱻳�ʼ��ΪSIZE	*/
void InitializeAsSize (DisjiontSet gather, const int size) ;

/*	����:	�����ĸ߶�����������	*/
/*	����ǰ:	gather ��һ���ѳ�ʼ���Ĳ��ཻ����, root1, root2 �������������͵ı���	*/
/*	������:	������������� gather ��, ���߶��� root1 ���Ϻ� root2 ����, ����1; ���򷵻�0	*/
int SetUnionAsHeight (DisjiontSet gather, SetType root1, SetType root2) ;

/*	����:	�����Ĵ�С����������	*/
/*	����ǰ:	gather ��һ���ѳ�ʼ���Ĳ��ཻ����, root1, root2 �������������͵ı���	*/
/*	������:	������������� gather ��, ����С�� root1 ���Ϻ� root2 ����, ����1; ���򷵻�0	*/
int SetUnionAsSize (DisjiontSet gather, SetType root1, SetType root2) ;

/*	����:	����һ�����ཻ���Ϻ�һ������, ���Ҳ����ظ��������ڼ�������, ������·��ѹ��	*/
/*	����ǰ:	gather ��һ���ѳ�ʼ���Ĳ��ཻ����, item ��һ��Item���ͱ���	*/
/*	������:	��� item ���ڼ����� gather ��, �ҵ������� item ���ڼ��ϵ�����, ������·��ѹ��; ���򷵻� OOS	*/
SetType Find (DisjiontSet gather, const Item item) ;
