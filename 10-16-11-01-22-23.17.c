/*	10-16-11-01-22-23.17.c -- 第十章第十六题	*/
/*	有问题存在,偶尔出现段错误.偶尔出现计算错误.这道习题耽误太久了,先不去研究了. -- 11-01-27-21.49	*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE (99)
#define MAX (6000)
#define INFINITY_DOUBLE (999999)

typedef int Item ;
typedef struct point
{
	Item x_coordinate ;
	Item y_coordinate ;
} Point ;

int main (void) ;
void initializeSet (Point * const set, const int size, const int max) ;
/*	ShortestDistance is the boxing of shortestDistance.	*/
double ShortestDistance (const Point * const set, const int size) ;
double shortestDistance (const Point * const set_sorted_by_x, const Point * const set_sorted_by_y, const int left, const int right, const int size) ;
double operose (const Point * const set, const int size) ;
double distance (const Point * const pl, const Point * const pr) ;
double minimum (const double l_num, const double r_num) ;
double square (const int num) ;
void shellSortAsX (Point * const set, const int size) ;
void shellSortAsY (Point * const set, const int size) ;


int main (void)
{
	Point set[SIZE] ;
	int size = SIZE, max = MAX, index = 0, times = 100, i ;

	for (i = 0; i < times; i++)
	{
		initializeSet (set, size, max) ;
		if (ShortestDistance (set, size) != operose (set, size))
			index++ ;
	}
	if (index)
		printf ("Wrong times is : %d.\n", index) ;
	else
		printf ("All is OK.\n") ;

	return 0 ;
}

void initializeSet (Point * const set, const int size, const int max)
{
	int i ;

	srand ((unsigned int) time (NULL)) ;
	for (i = 0; i < size; i++)
	{
		set[i].x_coordinate = rand () % max + 1 ;
		set[i].y_coordinate = rand () % max + 1 ;
	}
}

double ShortestDistance (const Point * const set, const int size)
{
	Point * set_sorted_by_x, * set_sorted_by_y ;
	double dist = INFINITY_DOUBLE ;
	int i ;

	if (NULL == set || size <= 0)
	{
		printf ("Failed in \"if (NULL == set || size <= 0)\"\n") ;
		return INFINITY_DOUBLE ;
	}
	set_sorted_by_x = (Point *) malloc (sizeof (Point) * size) ;
	if (NULL == set_sorted_by_x)
	{
		printf ("Failed in \"if (NULL == set_sorted_by_x)\"\n") ;
		return INFINITY_DOUBLE ;
	}
	set_sorted_by_y = (Point *) malloc (sizeof (Point) * size) ;
	if (NULL == set_sorted_by_y)
	{
		printf ("Failed in \"if (NULL == set_sorted_by_y)\"\n") ;
		free (set_sorted_by_x) ;
		return INFINITY_DOUBLE ;
	}
	for (i = 0; i < size; i++)
	{
		set_sorted_by_x[i] = set[i] ;
		set_sorted_by_y[i] = set[i] ;
	}
	shellSortAsX (set_sorted_by_x, size) ;
	shellSortAsY (set_sorted_by_y, size) ;
	dist = shortestDistance (set_sorted_by_x, set_sorted_by_y, 0, size - 1, size) ;
	free (set_sorted_by_x) ;
	free (set_sorted_by_y) ;

	return dist ;
}

double shortestDistance (const Point * const set_sorted_by_x, const Point * const set_sorted_by_y, const int left, const int right, const int size)
{
	Point * strip ;
	double dl, dr, delta, boundary, temp, left_bracket, right_bracket ;
	int left_end, start, end, i, j, width ;

	/*	Two points	*/
	if (1 == right - left)
		return distance (set_sorted_by_x + left, set_sorted_by_x + right) ;
	/*	Three points	*/
	else if (2 == right - left)
		return minimum (distance (set_sorted_by_x + left, set_sorted_by_x + left + 1), distance (set_sorted_by_x + left + 1, set_sorted_by_x + right)) ;
	else
	{
		left_end = (left + right) / 2 ;
		dl = shortestDistance (set_sorted_by_x, set_sorted_by_y, left, left_end, size) ;
		dr = shortestDistance (set_sorted_by_x, set_sorted_by_y, left_end + 1, right, size) ;
		delta = minimum (dl, dr) ;
		boundary = set_sorted_by_x[left_end].x_coordinate ;
		/*	Find out the start of the strip.	*/
		if (delta > set_sorted_by_x[left_end].x_coordinate - set_sorted_by_x[left].x_coordinate)
			start = left ;
		else
		{
			temp = boundary - delta ;
			for (start = left; start < left_end; start++)
			{
				if (set_sorted_by_x[start].x_coordinate >= temp)
					break ;
			}
		}
		/*	Find out the end of the strip.	*/
		if (delta > set_sorted_by_x[right].x_coordinate - set_sorted_by_x[left_end].x_coordinate)
			end = right ;
		else
		{
			temp = boundary - delta ;
			for (end = left_end + 1; end < right; end++)
			{
				if (set_sorted_by_x[end].x_coordinate >= temp)
					break ;
			}
		}
		width = end - start ;
		/*	Empty strip.	*/
		if (1 == width)
			return delta ;
		/*	There is only one point in the strip.	*/
		else if (2 == width)
			return delta ;
		else
		{
			strip = (Point *) malloc (sizeof (Point) * (width + 1)) ;
			if (NULL == strip)
			{
				printf ("Failed in \"strip = (Point *) malloc (sizeof (Point) * (width + 1))\"\n") ;
				return INFINITY_DOUBLE ;
			}
			left_bracket = set_sorted_by_x[start].x_coordinate ;
			right_bracket = set_sorted_by_x[end].x_coordinate ;
			/*	Copy.	*/
			for (i = 0, j = 0; i < size; i++)
			{
				if (set_sorted_by_y[i].x_coordinate >= left_bracket && set_sorted_by_y[i].x_coordinate <= right_bracket)
					strip[j++] = set_sorted_by_y[i] ;
			}
			for (i = 0; i <= width; i++)
			{
				for (j = i + 1; j <= width; j++)
				{
					/*	If Yi and Yj coordinates differ by more than delta.	*/
					if (strip[j].y_coordinate - strip[i].y_coordinate > delta)
						break ;
					else if ((temp = distance (strip + i, strip + j)) < delta)
						delta = temp ;
				}
			}
			free (strip) ;
		}
		return delta ;
	}
}

double operose (const Point * const set, const int size)
{
	double min = INFINITY_DOUBLE, temp ;
	int i, j ;
	
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (j == i)
				continue ;
			else
			{
				if ((temp = distance (set + i, set + j)) < min)
					min = temp ;
			}
		}
	}

	return min ;
}


double distance (const Point * const pl, const Point * const pr)
{
	return	pow ((double)
			/*	(x1 - x2) ^ 2	*/
			(square (pl -> x_coordinate - pr -> x_coordinate) +
			/*	(y1 - y2) ^ 2	*/
			square (pl -> y_coordinate - pr -> y_coordinate)),
			0.5) ;
}

double minimum (const double l_num, const double r_num)
{
	return (l_num < r_num) ? l_num : r_num ;
}

double square (const int num)
{
	return num * num ;
}

void shellSortAsX (Point * const set, const int size)
{
	Point temp ;
	int i, j, increment ;

	for (increment = size / 2; increment > 0; increment--)
	{
		for (i = increment; i < size; i++)
		{
			temp = set[i] ;
			for (j = i; j >= increment; j -= increment)
			{
				if (temp.x_coordinate < set[j - increment].x_coordinate)
					set[j] = set[j - increment] ;
				else
					break ;
			}
			set[j] = temp ;
		}
	}
}

void shellSortAsY (Point * const set, const int size)
{
	Point temp ;
	int i, j, increment ;

	for (increment = size / 2; increment > 0; increment--)
	{
		for (i = increment; i < size; i++)
		{
			temp = set[i] ;
			for (j = i; j >= increment; j -= increment)
			{
				if (temp.y_coordinate < set[j - increment].y_coordinate)
					set[j] = set[j - increment] ;
				else
					break ;
			}
			set[j] = temp ;
		}
	}
}