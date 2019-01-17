/*	10-22-11-02-02-08.17.c -- 第十章第二十二题	*/
/*	有问题存在.主要,是为了体验分治算法的思想,沿着思路写出来了.说真的,对数字没有兴趣. - 01-03-16.06	*/
#include <stdio.h>
#include <stdlib.h>

int main (void) ;
int multiplication (const int cardinal, const int multiplier) ;
int powBaseTen (const int power) ;

int main (void)
{
	printf ("Is %d.\n", multiplication (54321, 12345)) ;

	return 0 ;
}

int multiplication (const int cardinal, const int multiplier)
{
	int temp, c_l, c_r, m_l, m_r, d1, d2, d3, c_lm_l, c_rm_r ;
	int width_c, width_m ;

	if (cardinal <= 10 || multiplier <= 10)
		return cardinal * multiplier ;
	else
	{
		for (width_c = 1, temp = 1; temp * 10 < cardinal; width_c++, temp *= 10)
			NULL ;
		c_l = cardinal / powBaseTen (width_c / 2) ;
		c_r = cardinal - c_l * powBaseTen (width_c / 2) ;
		for (width_m = 1, temp = 1; temp * 10 < multiplier; width_m++, temp *= 10)
			NULL ;
		m_l = multiplier / powBaseTen (width_m / 2) ;
		m_r = multiplier - m_l * powBaseTen (width_m / 2) ;
		d1 = c_l - c_r ;
		d2 = m_r - m_l ;
		c_lm_l = multiplication (c_l, m_l) ;
		c_rm_r = multiplication (c_r, m_r) ;
		d3 = multiplication (d1, d2) + c_lm_l + c_rm_r ;
		
		return c_lm_l * powBaseTen (width_c) + d3 * powBaseTen (width_c / 2) + c_rm_r ;
	}
}

int powBaseTen (const int power)
{
	int result, i ;

	if (power <= 0)
		return 0 ;
	for (i = 1, result = 10; i < power; i++)
		result *= 10 ;

	return result ;
}
