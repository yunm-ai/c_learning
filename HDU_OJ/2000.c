#include<stdio.h>
void char_swap(char*c1,char*c2)
{
    if(*c1>*c2)
    {
        char temp;
        temp=*c1;
        *c1=*c2;
        *c2=temp;
    }
}
int main()
{
    char a,b,c,ch;
    while(scanf("%c%c%c",&a,&b,&c)==3)
    {
      
        char_swap(&a,&b);
        char_swap(&a,&c);
        char_swap(&b,&c);
        printf("%c %c %c\n",a,b,c);
        while((ch=getchar())!=EOF&&ch!='\n');/*没读到换行符或者文件末尾就一直读*/
    }
    return 0;
}