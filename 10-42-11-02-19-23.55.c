/*	10-42-11-02-19-23.55.c -- 第十章第四十二题	*/
#include <stdio.h>
#include <stdlib.h>

#define FALSE (0)
#define TRUE (1)

typedef int Item ;
typedef int BOOL ;

/*	Data is a kind of data structures.	*/
int turnpike (Item * const * const points, const int column, const int row, Data * const distance) ;
int place (Item * const * const points, const int column, const int row, const int left, const int right, Data * const distance) ;
Item absoluteValue (const Item value) ;

/*	It will return the number of lines that can be rebuilded.	*/
/*	In the case where there are some duplicate distances, it is possible that several symmetries will be printed.	*/
int turnpike (Item * const * const points, const int column, const int row, Data * const distance)
{
	Item max ;
	int i ;

	/*	To cause the cood expressly, abnegate to optimize the loop.	*/
	/*	Set starting point.	*/
	for (i = 0; i < column; i++)
		points[i][0] = 0 ;
	max = FindMax (distance) ;
	for (i = 0; i < column; i++)
		points[i][row - 1] = max ;
	Delete (distance, max) ;

	return place (points, column, row, 1, row - 2, distance) ;
}

int place (Item * const * const points, const int column, const int row, const int left, const int right, Data * const distance)
{
	static int count = 0 ;
	BOOL index = FALSE ;
	Item max_in_distance, temp ;
	int i, j, k ;

	if (IsEmpty (distance))
	{
		count++ ;
		return count ;
	}
	max_in_distance = FindMax (distance) ;
	/*	Check if setting points[count][right] = DMax is feasible.	*/
	/*	Testing	*/
	for (i = 0; i < left; i++)
	{
		temp = absoluteValue (points[count][i] - max_in_distance) ;
		if (TRUE == Find (distance, temp))
			Delete (distance, temp) ;
		/*	If it hasn't found temp in distance.	*/
		else
		{
			/*	If it has deleted.	*/
			if (i > 0)
			{
				/*	Recover the items that has been deleted.	*/
				for (k = i - 1; k >= 0; k--)
				{
					temp = absoluteValue (points[count][k] - max_in_distance) ;
					Insert (distance, temp) ;
				}
			}
			/*	To guide next step.	*/
			index = TRUE ;
			break ;
		}
	}
	/*	If has passed through the test on last step.	*/
	if (FALSE == index)
	{
		/*	Testing.	*/
		for (j = right + 1; j < row; j++)
		{
			temp = absoluteValue (points[count][j] - max_in_distance) ;
			if (TRUE == Find (distance, temp))
				Delete (distance, temp) ;
			/*	If hasn't found temp in distance.	*/
			else
			{
				/*	If has deleted.	*/
				if (j > right + 1)
				{
					/*	Recover the items that has been deleted.	*/
					for (k = j - 1; k > right; k--)
					{
						temp = absoluteValue (points[count][k] - max_in_distance) ;
						Insert (distance, temp) ;
					}
				}
				/*	From points[count][i - 1] to points[count][0] has been deleted certainly.	*/
				/*	Recover the items that from points[count][i - 1] to points[count][0].	*/
				for (k = i - 1; k >= 0; k--)
				{
					temp = absoluteValue (points[count][k] - max_in_distance) ;
					Insert (distance, temp) ;
				}
				/*	To guide next step.	*/
				index = TRUE ;
				break ;
			}
		}
		/*	If has passed through the test on last step.	*/
		if (FALSE == index)
		{
			/*	Undoubted attempt.	*/
			for (i = count; i < column; i++)
				points[i][right] = max_in_distance ;
			count = place (points, column, row, left, right - 1, distance) ;
			/*	Unconditional recall.	*/
			/*	Backtrack.	*/
			for (i = 0; i < left; i++)
			{
				temp = absoluteValue (points[count][i] - max_in_distance) ;
				Insert (distance, temp) ;
			}
			for (i = right + 1; i < row; i++)
			{
				temp = absoluteValue (points[count][i] - max_in_distance) ;
				Insert (distance, temp) ;
			}
		}
	}
	/*	Even if first attempt is successful, try to setting points[count][left] = points[N] - DMax is feasible.	*/
	/*	Initialize "index" again.	*/
	index = FALSE ;
	for (i = 0; i < left; i++)
	{
		/*	Make sure you has known that temp is the absolute value of distance.	*/
		temp = absoluteValue (points[count][row - 1] - max_in_distance - points[count][i]) ;
		if (TRUE == Find (distance, temp))
			Delete (distance, temp) ;
		else
		{
			if (i > 0)
			{
				for (k = i - 1; k >= 0; k--)
				{
					temp = absoluteValue (points[count][row - 1] - max_in_distance - points[count][k]) ;
					Insert (distance, temp) ;
				}
			}
			index = TRUE ;
			break ;
		}
	}
	if (FALSE == index)
	{
		for (j = right + 1; j < row; j++)
		{
			temp = absoluteValue (points[count][row - 1] - max_in_distance - points[count][j]) ;
			if (TRUE == find (distance, temp))
				Delete (distance, temp) ;
			else
			{
				if (j > right + 1)
				{
					for (k = j - 1; k > right; k--)
					{
						temp = absoluteValue (points[count][row - 1] - max_in_distance - points[count][k]) ;
						Insert (distance, temp) ;
					}
				}
				for (k = i - 1; k >= 0; k--)
				{
					temp = absoluteValue (points[count][row - 1] - max_in_distance - points[count][k]) ;
					Insert (distance, temp) ;
				}
				index = TRUE ;
				break ;
			}
		}
	}
	if (FALSE == index)
	{
		for (i = count; i < column; i++)
			points[i][left] = points[count][row - 1] - max_in_distance ;
		count = place (points, column, row, left + 1, right, distance) ;
		/*	Backtrack.	*/
		for (i = 0; i < left; i++)
		{
			temp = absoluteValue (points[count][row - 1] - max_in_distance - points[count][i]) ;
			Insert (distance, temp) ;
		}
		for (i = right + 1; i < row; i++)
		{
			temp = absoluteValue (points[count][row - 1] - max_in_distance - points[count][i]) ;
			Insert (distance, temp) ;
		}
	}

	return count ;
}

Item absoluteValue (const Item value)
{
	if (value < 0)
		return 0 - value ;
	else
		return value ;
}