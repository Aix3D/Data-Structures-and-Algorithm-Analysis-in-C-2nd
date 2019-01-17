/*	box.c -- 盒子问题实现文件	*/
#ifndef GENERIC
#include "box.h"
#endif

/*	局部函数声明	*/

static Box * Make_Box (const Weight capacity) ;
static Box * Find_Max (Box * box) ;
static Box * Find_Min (Box * box) ;
static int Insert_ (BoxTree * const pbt, const Weight capacity, const Weight unoccupied) ;
static Box * Delete_ (Box * root, const Weight unoccupied) ;
static Box * Inorder_Find (Box * box, const Weight unoccupied) ;
static void Work_For_Release (Box * const box) ;

/*	接口函数定义	*/

int InitializeBoxTree (BoxTree * const pbt, const Weight capacity)
{
	*pbt = (struct boxtree *) malloc (sizeof (struct boxtree)) ;
	if (NULL == *pbt)
		return 0 ;
	(*pbt) -> root = NULL ;
	(*pbt) -> size = 0 ;
	(*pbt) -> usual = capacity ;

	return 1 ;
}

//	此套例程中的 size 测量不可靠, 主要是时间差的关系
int BoxTreeIsEmpty (const BoxTree * const pbt)
{
	return NULL == (*pbt) -> root ;
}

int DealWithTheBiggest (BoxTree * const pbt, const Weight triangle)
{
	Box * max, * parent ;
	Weight capacity, unoccupied ;

	capacity = triangle > (*pbt) -> usual ? triangle : (*pbt) -> usual ;
	if (BoxTreeIsEmpty (pbt))
	{
		unoccupied = capacity - triangle ;
		if (Insert_ (pbt, capacity, unoccupied))
			return 1 ;
		else
			return 0 ;
	}
	max = Find_Max ((*pbt) -> root) ;
	//	没有盒子能够容纳当前物品重量时
	if (triangle > max -> unoccupied)
	{
		unoccupied = capacity - triangle ;
		if (Insert_ (pbt, capacity, unoccupied))
			return 1 ;
		else
			return 0 ;
	}
	//	最大节点能够容纳当前物品时
	else
	{
		unoccupied = max -> unoccupied - triangle ;
		//	65行 - 71行是简化了的删除操作
		parent = max -> parent ;
		free (max) ;
		if (parent)
			parent -> right = NULL ;
		else
			(*pbt) -> root = NULL ;
		(*pbt) -> size-- ;
		if (Insert_ (pbt, capacity, unoccupied))
			return 1 ;
		else
			return 0 ;
	}
}

int DealWithTheSmallest (BoxTree * const pbt, const Weight triangle)
{
	Box * min, * max ;
	Weight capacity, unoccupied ;

	if (BoxTreeIsEmpty (pbt))
	{
		capacity = triangle > (*pbt) -> usual ? triangle : (*pbt) -> usual ;
		unoccupied = capacity - triangle ;
		if (Insert_ (pbt, capacity, unoccupied))
			return 1 ;
		else
			return 0 ;
	}
	max = Find_Max ((*pbt) -> root) ;
	//	如果存在能够容纳当前物品重量的盒子
	if (max -> unoccupied >= triangle)
	{
		//	找到符合要求的最小的盒子
		min = Inorder_Find ((*pbt) -> root, triangle) ;
		capacity = min -> capacity ;
		unoccupied = min -> unoccupied - triangle ;
		(*pbt) -> root = Delete_ ((*pbt) -> root, min -> unoccupied) ;
		(*pbt) -> size-- ;
		//	处理特殊情况
		if ((*pbt) -> root)
			if ((*pbt) -> root -> parent != NULL)
				(*pbt) -> root -> parent = NULL ;
		//	添加新min
		if (Insert_ (pbt, capacity, unoccupied))
			return 1 ;
		else
			return 0 ;
	}
	//	如果不存在能够容纳当前物品重量的盒子
	else
	{
		capacity = triangle > (*pbt) -> usual ? triangle : (*pbt) -> usual ;
		unoccupied = capacity - triangle ;
		if (Insert_ (pbt, capacity, unoccupied))
			return 1 ;
		else
			return 0 ;
	}
}

void InorderTraversal (const Box * const box, void (* pfun) (const Box * const box))
{
	if (box)
	{
		InorderTraversal (box -> left, pfun) ;
		(* pfun) (box) ;
		InorderTraversal (box -> right, pfun) ;
	}
}

void Release (const BoxTree * const pbt)
{
	Work_For_Release ((*pbt) -> root) ;
	free (*pbt) ;
}

/*	局部函数定义	*/

static Box * Make_Box (const Weight capacity)
{
	Box * new_box ;

	new_box = (Box *) malloc (sizeof (Box)) ;
	if (NULL == new_box)
		return NULL ;
	new_box -> capacity = capacity ;
	//	此处没有定义指向父节点的指针和剩余容量, 牺牲了模块性
	new_box -> left = new_box -> right = NULL ;

	return new_box ;
}

static Box * Find_Max (Box * box)
{
	if (NULL == box)
		return NULL ;
	while (box -> right)
		box = box -> right ;

	return box ;
}

static Box * Find_Min (Box * box)
{
	if (NULL == box)
		return NULL ;
	while (box -> left)
		box = box -> left ;

	return box ;
}

static int Insert_ (BoxTree * const pbt, const Weight capacity, const Weight unoccupied)
{
	int index ;
	Box * new_box, * scan ;

	new_box = Make_Box (capacity) ;
	if (NULL == new_box)
		return 0 ;
	if (BoxTreeIsEmpty (pbt))
	{
		new_box -> parent = NULL ;
		new_box -> unoccupied = unoccupied ;
		(*pbt) -> root = new_box ;
	}
	else
	{
		scan = (*pbt) -> root ;
		while (scan)
		{
			if (unoccupied > scan -> unoccupied)
			{
				if (NULL == scan -> right)
				{
					index = RIGHT ;
					break ;
				}
				else
					scan = scan -> right ;
			}
			//	使空盒子向左靠拢
			else if (unoccupied <= scan -> unoccupied)
			{
				if (NULL == scan -> left)
				{
					index = LEFT ;
					break ;
				}
				else
					scan = scan -> left ;
			}
		}
		if (LEFT == index)
			scan -> left = new_box ;
		else
			scan -> right = new_box ;
		new_box -> parent = scan ;
		new_box -> unoccupied = unoccupied ;
	}

	(*pbt) -> size++ ;

	return 1 ;
}

static Box * Delete_ (Box * box, const Weight unoccupied)
{
	Box * temp ;

	if (box)
	{
		if (unoccupied > box -> unoccupied)
			box -> right = Delete_ (box -> right, unoccupied) ;
		else if (unoccupied < box -> unoccupied)
			box -> left = Delete_ (box -> left, unoccupied) ;
		else if (box -> left && box -> right)
		{
			temp = Find_Min (box -> right) ;								//	取右子树中最大关键字所在节点
			box -> unoccupied = temp -> unoccupied ;						//	单纯地替换数据
			box -> capacity = temp -> capacity ;							//	单纯地替换数据
			box -> right = Delete_ (box -> right, box -> unoccupied) ;		//	删除倒霉蛋
		}
		else
		{
			temp = box ;
			if (box -> left)												//	不知不觉, 风格有些变了
				box = box -> left ;
			else
				box = box -> right ;
			free (temp) ;
		}
		return box ;
	}
	else
		return NULL ;
}

//	自以为这个函数是这套例程的精髓所在.嗑毛磕的时候想到的 ^_^
static Box * Inorder_Find (Box * box, const Weight unoccupied)
{
	Box * temp ;

	if (box)
	{
		if ((temp = Inorder_Find (box -> left, unoccupied)) != NULL)
			return temp ;
		if (box -> unoccupied >= unoccupied)
			return box ;
		if ((temp = Inorder_Find (box -> right, unoccupied)) != NULL)
			return temp ;
		else
			return NULL ;
	}
	else
		return NULL ;
}

static void Work_For_Release (Box * const box)
{
	if (box)
	{
		Work_For_Release (box -> left) ;
		Work_For_Release (box -> right) ;
		free (box) ;
	}
}