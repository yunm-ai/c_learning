/*
**这个程序从标准输入中读取输入行并在标准输出中打印这些输入行
**每个输入行的后面一行是该行内容的一部分
**
**输入的第一行是一串标列号，串的最后以负数结尾
**这些列标号成对出现
**例如：0 3 10 12 -1表示第0列到第3列，第10列到第12列的内容将会被打印
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"rearrange.h"
#include"read_column.h"
#define MAX_COLS 20/*所能处理最大列号*/
#define MAX_INPUT 1000/*每个输入行最大长度*/


void rearrange(char*output,char const*input,int n_columns
,int const columns[]);

int main(void)
{
    int n_columns;/*进行处理的列标号*/;
    int columns[MAX_COLS];/*需要处理的列数*/
    char input[MAX_INPUT];/*容纳输入行的数组*/
    char output[MAX_INPUT];/*容纳输出行的数组*/
    
    /*
    **读取该串列编号
    */
   n_columns=read_column_numbers(columns,MAX_COLS);

   /*
   **读取处理和打印剩余输入行
   */
  while(fgets(input,sizeof(input),stdin)!=NULL)
  {
    input[strcspn(input,"\n")]='\0';
    printf("Original input:%s\n",input);
    rearrange(output,input,n_columns,columns);
    printf("Rearranged line:%s\n",output);
  }

  return EXIT_SUCCESS;
}




