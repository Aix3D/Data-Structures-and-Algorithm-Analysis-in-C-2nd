/* 3-1-09-15-16.31.c -- 第三章第一题  */

void print_one_way_list (const List head)
{
	while (head != NULL)
	{
		printf ("%s", head -> elment) ;
		return printf_one_way_list (head -> next) ;
	}
}
