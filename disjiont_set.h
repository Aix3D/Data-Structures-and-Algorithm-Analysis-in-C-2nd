/*	disjiont_set.h -- ���ཻ����ADTͷ�ļ�	*/

#define HEIGHT (0)
#define OOS (1 << 31)

/*	�������Ͷ���	*/

typedef int SetItem ;
typedef SetItem SetType ;
typedef SetItem * Disjiont ;

/*	�ӿں�������	*/

/*	����:	���߶ȴ�������ʼ��һ�����ཻ����	*/
/*	����ǰ:	d ��һ�����ཻ���ϱ���, capacity ָʾ�ü��ϵĴ�С	*/
/*	������:	��� capacity > 0 && �ڴ����ɹ�, �����ô�СΪ capacity �ļ���, �����г��� 0 ��Ԫ����, ����Ԫ��������Ϊ HEIGHT, ���� 1; ���򷵻� 0	*/
/*	ʱ�临�Ӷ�:	O (1)	*/
int Initialize_D (Disjiont d, const int capacity) ;

/*	����:	ȷ��һ��Ԫ���Ƿ��ڼ�����, ���ҹ����н���·��ѹ��	*/
/*	����ǰ:	d ��һ���ѳ�ʼ���Ĳ��ཻ����, si �Ǵ����ҵ�Ԫ��	*/
/*	������:	����ҵ���Ԫ��, �������ڼ��ϵ����� ; ���򷵻� OSS */
/*	ʱ�临�Ӷ�: O(log N)	*/
SetType Find_D (Disjiont d, const SetItem si) ;

/*	����:	���߶�����������	*/
/*	����ǰ:	d ��һ���ѳ�ʼ���Ĳ��ཻ����, st1 , st2 �������󲢵ļ���	*/
/*	������:	��� st1 �� st2 ���ǲ��ཻ�����еļ���, �ϲ�����������, ���� 1 ; ���򷵻� 0	*/
/*	ʱ�临�Ӷ�:	*/
int Union_D (Disjiont d, const SetType st1, const SetType st2) ;