/*	10-40-11-02-16-06.10.c -- 第十章第四十题	*/
/*	02-18-01.54 完成.大概用了13小时.	*/
#include <stdio.h>
#include <stdlib.h>

#define FALSE (0)
#define TRUE (1)

typedef int Item ;
typedef int BOOL ;

/*	Data is a kind of data structures.	*/
BOOL turnpike (Item * const points, const int size, Data * const distance) ;
BOOL place (Item * const points, const int size, const int left, const int right, Data * const distance) ;
Item absoluteValue (const Item value) ;

/*	If it returns FLASE, points is no go.	*/
BOOL turnpike (Item * const points, const int size, Data * const distance)
{
	Item max, temp ;

	/*	Set starting point.	*/
	points[0] = 0 ;
	max = FindMax (distance) ;
	points[size - 1] = max ;
	Delete (distance, max) ;
	max = FindMax (distance) ;
	points[size - 2] = max ;
	Delete (distance, max) ;
	temp = absoluteValue (points[size - 1] - points[size - 2]) ;
	if (TRUE == Find (distance, temp))
	{
		Delete (distance, temp) ;
		return place (points, size, 1, size - 3, distance) ;
	}
	else
		return FALSE ;
}

BOOL place (Item * const points, const int size, const int left, const int right, Data * const distance)
{
	BOOL found = FALSE, index = FALSE ;
	Item max_in_distance, temp ;
	int i, j, k ;

	if (IsEmpty (distance))
		return TRUE ;
	max_in_distance = FindMax (distance) ;
	/*	Check if setting points[right] = DMax is feasible.	*/
	/*	Testing	*/
	for (i = 0; i < left; i++)
	{
		temp = absoluteValue (points[i] - max_in_distance) ;
		if (TRUE == Find (distance, temp))
			Delete (distance, temp) ;
		/*	If hasn't found temp in distance.	*/
		else
		{
			/*	If has deleted.	*/
			if (i > 0)
			{
				/*	Recover the items that has been deleted.	*/
				for (k = i - 1; k >= 0; k--)
				{
					temp = absoluteValue (points[k] - max_in_distance) ;
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
		for (j = right + 1; j < size; j++)
		{
			temp = absoluteValue (points[j] - max_in_distance) ;
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
						temp = absoluteValue (points[k] - max_in_distance) ;
						Insert (distance, temp) ;
					}
				}
				/*	From points[i - 1] to points[0] has been deleted certainly.	*/
				/*	Recover the items that from points[i - 1] to points[0].	*/
				for (k = i - 1; k >= 0; k--)
				{
					temp = absoluteValue (points[k] - max_in_distance) ;
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
			points[right] = max_in_distance ;
			found = place (points, size, left, right - 1, distance) ;
			/*	Decide if go to backtrack.	*/
			if (FALSE == found)
			{
				/*	Backtrack.	*/
				for (i = 0; i < left; i++)
				{
					temp = absoluteValue (points[i] - max_in_distance) ;
					Insert (distance, temp) ;
				}
				for (i = right + 1; i < size; i++)
				{
					temp = absoluteValue (points[i] - max_in_distance) ;
					Insert (distance, temp) ;
				}
			}
		}
	}
	/*	If first attempt failed, try to setting x[left] = x[N] - DMax is feasible.	*/
	/*	Decide if need this test.	*/
	if (FALSE == found)
	{
		/*	Initialize "index" again.	*/
		index = FALSE ;
		for (i = 0; i < left; i++)
		{
			/*	Make sure you has known that temp is the absolute value of distance.	*/
			temp = absoluteValue (points[size - 1] - max_in_distance - points[i]) ;
			if (TRUE == Find (distance, temp))
				Delete (distance, temp) ;
			else
			{
				if (i > 0)
				{
					for (k = i - 1; k >= 0; k--)
					{
						temp = absoluteValue (points[size - 1] - max_in_distance - points[k]) ;
						Insert (distance, temp) ;
					}
				}
				index = TRUE ;
				break ;
			}
		}
		if (FALSE == index)
		{
			for (j = right + 1; j < size; j++)
			{
				temp = absoluteValue (points[size - 1] - max_in_distance - points[j]) ;
				if (TRUE == find (distance, temp))
					Delete (distance, temp) ;
				else
				{
					if (j > right + 1)
					{
						for (k = j - 1; k > right; k--)
						{
							temp = absoluteValue (points[size - 1] - max_in_distance - points[k]) ;
							Insert (distance, temp) ;
						}
					}
					for (k = i - 1; k >= 0; k--)
					{
						temp = absoluteValue (points[size - 1] - max_in_distance - points[k]) ;
						Insert (distance, temp) ;
					}
					index = TRUE ;
					break ;
				}
			}
		}
		if (FALSE == index)
		{
			points[left] = points[size - 1] - max_in_distance ;
			found = place (points, size, left + 1, right, distance) ;
			if (FALSE == found)
			{
				/*	Backtrack.	*/
				for (i = 0; i < left; i++)
				{
					temp = absoluteValue (points[size - 1] - max_in_distance - points[i]) ;
					Insert (distance, temp) ;
				}
				for (i = right + 1; i < size; i++)
				{
					temp = absoluteValue (points[size - 1] - max_in_distance - points[i]) ;
					Insert (distance, temp) ;
				}
			}
		}
	}

	return found ;
}

Item absoluteValue (const Item value)
{
	if (value < 0)
		return 0 - value ;
	else
		return value ;
}