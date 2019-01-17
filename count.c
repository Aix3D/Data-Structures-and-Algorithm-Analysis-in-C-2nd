#include <stdio.h>   
#include <string.h>   
#include <stdlib.h>   
#define INITIAL_VALUE 1   
#define NUMBER_LENTH 4   
#define BIG_SPACE 10   
#define FULL_NAME_LENTH 15   
#define PF '\n'   
#define FINISH printf ("ȫ���ļ�ͳ�����,��������:\n")   
#define ERROR(i) printf ("��%d���ļ��ر�ʧ��\n", i)   
  
struct item   
{   
    int the_number_of_char ;   
    int the_number_of_enter ;   
} ;   
  
int main (void) ;   
void get_full_name_base_on_number (const int integer, char * string) ;          /*  ��������ֵ����ļ�ȫ�� */  
struct item count_and_printf (FILE * const fp, const int i) ;                   /*  ���㲢���ص�ǰ�ļ��ַ����Լ�����    */  
  
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
    printf ("  �ļ�����:%-5dȫ���ַ���:%-10dȫ������:%-10d\n"  
            , i, sum.the_number_of_char, sum.the_number_of_enter) ;
	if (i)
		printf ("  ����ַ���:%-10d�������ļ�:1 (%d).c��\n  �������:%-10d�������ļ�:1 (%d).c��\n",
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
    printf ("��ǰ��:%-2d���ļ�: �ַ���:%-5d ����:%-10d\n", i, sum.the_number_of_char, sum.the_number_of_enter) ;   
  
    return sum ;   
}
