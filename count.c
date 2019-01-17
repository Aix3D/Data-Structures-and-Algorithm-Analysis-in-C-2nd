#include <stdio.h>   
#include <string.h>   
#include <stdlib.h>   
#define INITIAL_VALUE 1   
#define NUMBER_LENTH 4   
#define BIG_SPACE 10   
#define FULL_NAME_LENTH 15   
#define PF '\n'   
#define FINISH printf ("全部文件统计完毕,报告如下:\n")   
#define ERROR(i) printf ("第%d个文件关闭失败\n", i)   
  
struct item   
{   
    int the_number_of_char ;   
    int the_number_of_enter ;   
} ;   
  
int main (void) ;   
void get_full_name_base_on_number (const int integer, char * string) ;          /*  根据数字值获得文件全名 */  
struct item count_and_printf (FILE * const fp, const int i) ;                   /*  计算并返回当前文件字符数以及行数    */  
  
int main (void)   
{   
    FILE * fp ;   
    char file_name[FULL_NAME_LENTH] ;   
    int i, max_char_file, max_enter_file ;   
    struct item temp, sum, max ;   
  
    sum.the_number_of_char = sum.the_number_of_enter = 0 ;   
    max.the_number_of_char = max.the_number_of_enter = 0 ;   
    for (i = INITIAL_VALUE; ; i++)   
    {   
        get_full_name_base_on_number (i, file_name) ;   
        if (NULL == (fp = fopen (file_name, "r")))   
        {   
            FINISH ;
			i-- ;
            break ;   
        }   
        else  
        {   
            temp = count_and_printf (fp, i) ;   
            sum.the_number_of_char += temp.the_number_of_char ;   
            sum.the_number_of_enter += temp.the_number_of_enter ;   
            if (temp.the_number_of_char > max.the_number_of_char)   
            {   
                max.the_number_of_char = temp.the_number_of_char ;   
                max_char_file = i ;   
            }   
            if (temp.the_number_of_enter > max.the_number_of_enter)   
            {   
                max.the_number_of_enter = temp.the_number_of_enter ;   
                max_enter_file = i ;   
            }   
        }   
        if (fclose (fp) != 0)   
        {   
            ERROR (i) ;   
            exit (EXIT_FAILURE) ;   
        }   
    }   
    printf ("  文件总数:%-5d全部字符数:%-10d全部行数:%-10d\n"  
            , i, sum.the_number_of_char, sum.the_number_of_enter) ;
	if (i)
		printf ("  最大字符数:%-10d出现在文件:1 (%d).c中\n  最大行数:%-10d出现在文件:1 (%d).c中\n",
		max.the_number_of_char, max_char_file, max.the_number_of_enter, max_enter_file) ;   
    getchar () ;   
  
    return 0 ;   
}   
  
void get_full_name_base_on_number (const int integer, char * string)   
{   
    char number[NUMBER_LENTH] ;   
  
    strcpy (string, "1 (") ;   
    sprintf (number, "%d", integer) ;   
    strcat (string, number) ;   
    strcat (string, ").c") ;   
}   
  
struct item count_and_printf (FILE * const fp, const int i)   
{   
    struct item sum ;   
    char ch ;   
       
    sum.the_number_of_char = 0, sum.the_number_of_enter = 0 ;   
    while ((ch = getc (fp)) != EOF)   
    {   
        if (PF == ch)
            sum.the_number_of_enter++ ;
		else
			sum.the_number_of_char++ ;   
    }   
    sum.the_number_of_enter++ ;   
    printf ("当前第:%-2d个文件: 字符数:%-5d 行数:%-10d\n", i, sum.the_number_of_char, sum.the_number_of_enter) ;   
  
    return sum ;   
}
