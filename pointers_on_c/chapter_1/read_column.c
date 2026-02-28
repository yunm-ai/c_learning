#include<stdio.h>
#include<stdlib.h>
#include"read_column.h"
/*
 **读取列标号，超出规定范围不理会num>=max
 */
int read_column_numbers(int columns[],int max)
{
    int num=0;//下标
    int ch;

    /*
    **取到列标号，如果所读取数小于0则停止
    */
   while(num<max&&scanf("%d",&columns[num])==1&&columns[num]>=0)
   num+=1;
   
   /*
   **标号是偶数个（成对出现）
   */
  if(num%2!=0)
  {
    puts("Last column number is not paired.");
    exit(EXIT_FAILURE);
  }

  /*
  **丢弃该行中包含最后一个数字的那部分内容
  */
 while((ch=getchar())!=EOF&&ch!='\n')
                ;
return num;
}