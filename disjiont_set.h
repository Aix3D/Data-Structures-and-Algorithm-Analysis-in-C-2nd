/*	disjiont_set.h -- 不相交集合ADT头文件	*/

#define HEIGHT (0)
#define OOS (1 << 31)

/*	数据类型定义	*/

typedef int SetItem ;
typedef SetItem SetType ;
typedef SetItem * Disjiont ;

/*	接口函数声明	*/

/*	操作:	按高度创建并初始化一个不相交集合	*/
/*	操作前:	d 是一个不相交集合变量, capacity 指示该集合的大小	*/
/*	操作后:	如果 capacity > 0 && 内存分配成功, 创建该大小为 capacity 的集合, 集合中除第 0 个元素外, 其余元素数据域为 HEIGHT, 返回 1; 否则返回 0	*/
/*	时间复杂度:	O (1)	*/
int Initialize_D (Disjiont d, const int capacity) ;

/*	操作:	确定一个元素是否在集合中, 查找过程中进行路径压缩	*/
/*	操作前:	d 是一个已初始化的不相交集合, si 是待查找的元素	*/
/*	操作后:	如果找到该元素, 返回所在集合的名字 ; 否则返回 OSS */
/*	时间复杂度: O(log N)	*/
SetType Find_D (Disjiont d, const SetItem si) ;

/*	操作:	按高度求并两个集合	*/
/*	操作前:	d 是一个已初始化的不相交集合, st1 , st2 是用来求并的集合	*/
/*	操作后:	如果 st1 和 st2 都是不相交集合中的集合, 合并这两个集合, 返回 1 ; 否则返回 0	*/
/*	时间复杂度:	*/
int Union_D (Disjiont d, const SetType st1, const SetType st2) ;