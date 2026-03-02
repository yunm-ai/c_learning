#include<stdio.h>
#include<stdbool.h>
#define MAXN 200000


int main()
{
    long long nums[MAXN];
    int N;
    long long C;
    while(scanf("%d%lld",&N,&C)==2)
    {
        int count=0;
        int i=0;
        for( ;i<N;i++)
        {
            scanf("%lld",&nums[i]);
        }
        
        for(int j=0;j<N-1;j++)
        {
            for(int k=j+1;k<N;k++)
            {
                if(nums[j]-nums[k]==C||nums[k]-nums[j]==C)
                {
                    count++;
                }
            }
            
        }
        printf("%d\n",count);
    }
    return 0;


}