/*
**处理输入行，将指定的字符连接在一起，输出行以NUL结尾
*/
#include<string.h>
#include"rearrange.h"
#define MAX_INPUT 1000
void rearrange(char*output,char const*input,int n_columns,
int const columns[])
{
    int col;/*columns数组的下标*/
    int output_col;/*输入列计数器*/
    int len;/*输入行长度*/

    len=strlen(input);
    output_col=0;

    /*
    **处理每对列标号
    */
   for(col=0;col<n_columns;col+=2)
   {
    int nchars=columns[col+1]-columns[col]+1;

    /*
    **如果输入行结束或者输出行数组已满，结束任务
    */
   if(columns[col]>=len||output_col==MAX_INPUT-1)
   break;

   /*
   **如果输出行数据空间不够，只复制可以容纳的数据
   */
   if(output_col+nchars>MAX_INPUT-1)
        nchars=MAX_INPUT-output_col-1;

    /*
    **复制相关的数据
    */
   strncpy(output+output_col,input+columns[col],nchars);
   output_col+=nchars;
   }
   output[output_col]='\0';
}