#include<stdio.h>
#include<stdlib.h>
#define MAX_VAL 100000

int main()
{
    int N;long long C;
    while(scanf("%d%lld",&N,&C)==2) 
    {
        int*cnt=(int*)calloc(MAX_VAL+1,sizeof(int));
        long long*nums=(long long*)malloc(N*sizeof(long long));
        if(cnt==NULL||nums==NULL)return 1;
        for(int i=0;i<N;i++)
        {
            scanf("%lld",&nums[i]);
            if(nums[i]>=0&&nums[i]<=MAX_VAL)
            cnt[nums[i]]++;
        }
        long long ans=0;
        for(int k=0;k<N;k++)
        {
            long long target=nums[k]+C;
            if(target>=0&&target<=MAX_VAL)
            ans+=cnt[target];
        }
        printf("%lld\n",ans);
        free(cnt);
        free(nums);
    }
    return 0;
}