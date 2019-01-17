/*	box.c -- ��������ʵ���ļ�	*/
#ifndef GENERIC
#include "box.h"
#endif

/*	�ֲ���������	*/

static Box * Make_Box (const Weight capacity) ;
static Box * Find_Max (Box * box) ;
static Box * Find_Min (Box * box) ;
static int Insert_ (BoxTree * const pbt, const Weight capacity, const Weight unoccupied) ;
static Box * Delete_ (Box * root, const Weight unoccupied) ;
static Box * Inorder_Find (Box * box, const Weight unoccupied) ;
static void Work_For_Release (Box * const box) ;

/*	�ӿں�������	*/

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

//	���������е� size �������ɿ�, ��Ҫ��ʱ���Ĺ�ϵ
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
	//	û�к����ܹ����ɵ�ǰ��Ʒ����ʱ
	if (triangle > max -> unoccupied)
	{
		unoccupied = capacity - triangle ;
		if (Insert_ (pbt, capacity, unoccupied))
			return 1 ;
		else
			return 0 ;
	}
	//	���ڵ��ܹ����ɵ�ǰ��Ʒʱ
	else
	{
		unoccupied = max -> unoccupied - triangle ;
		//	65�� - 71���Ǽ��˵�ɾ������
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
	//	��������ܹ����ɵ�ǰ��Ʒ�����ĺ���
	if (max -> unoccupied >= triangle)
	{
		//	�ҵ�����Ҫ�����С�ĺ���
		min = Inorder_Find ((*pbt) -> root, triangle) ;
		capacity = min -> capacity ;
		unoccupied = min -> unoccupied - triangle ;
		(*pbt) -> root = Delete_ ((*pbt) -> root, min -> unoccupied) ;
		(*pbt) -> size-- ;
		//	�����������
		if ((*pbt) -> root)
			if ((*pbt) -> root -> parent != NULL)
				(*pbt) -> root -> parent = NULL ;
		//	�����min
		if (Insert_ (pbt, capacity, unoccupied))
			return 1 ;
		else
			return 0 ;
	}
	//	����������ܹ����ɵ�ǰ��Ʒ�����ĺ���
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

/*	�ֲ���������	*/

static Box * Make_Box (const Weight capacity)
{
	Box * new_box ;

	new_box = (Box *) malloc (sizeof (Box)) ;
	if (NULL == new_box)
		return NULL ;
	new_box -> capacity = capacity ;
	//	�˴�û�ж���ָ�򸸽ڵ��ָ���ʣ������, ������ģ����
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
			//	ʹ�պ�������£
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
			temp = Find_Min (box -> right) ;								//	ȡ�����������ؼ������ڽڵ�
			box -> unoccupied = temp -> unoccupied ;						//	�������滻����
			box -> capacity = temp -> capacity ;							//	�������滻����
			box -> right = Delete_ (box -> right, box -> unoccupied) ;		//	ɾ����ù��
		}
		else
		{
			temp = box ;
			if (box -> left)												//	��֪����, �����Щ����
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

//	����Ϊ����������������̵ľ�������.�ë�ĵ�ʱ���뵽�� ^_^
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