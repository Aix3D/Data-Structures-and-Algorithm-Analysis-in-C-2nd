/*	8-14-12-03-00.30.c -- 第八章第十四题	*/

SetType Find (DisjiontSet gather, const Item item) ;

SetType Find (DisjiontSet gather, const Item item)
{
	Item temp, i, j ;

	if (gather[item] < 0)
		return item ;
	i = gather[item] ;
	while ((temp = gather[gather[i]]) > 0)
	{
		j = i ;
		gather[i] = temp ;
		i = gather[j] ;
	}

	return i ;
}