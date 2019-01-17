/*	8-10-12-02-22.29.c -- 第八章第十题	*/

/*	This is a model that can return a proximate communal parent betwen two node	*/
/*	First, map a tree to an array	*/

ElementType FindCommunalParent (const ElementType * const array, const int v, const int w) ;

ElementType FindCommunalParent (const ElementType * const array, const int v, const int w)
{
	if (ROOT == v || ROOT == w)
		return FAILED ;
	if (array[v] < array[w])
	{
		while (w != ROOT && array[v] != array[w])
			w = array[w] ;
	}
	else if (array[v] > array[w])
	{
		while (v != ROOT && array[v] != arrat[w])
			v = array[v] ;
	}
	else
		return array[v] ;	/*	Or array[w]	*/
}