#include<stdio.h>
#include<stdlib.h>

int cmp(const void*a,const void*b)
{
   long long* aa=(long long*)a;
    long long*bb=(long long*)b;
    return (*aa)-(*bb);
}

int lower_bound(long long*arr,int N,long long target)
{
    int l=0,r=N;
    while(l<r)
    {
        int mid=l+(r-l)/2;
        if(arr[mid]<target)
        l=mid+1;
        else
        r=mid;
    }
    return l;
}

int upper_bound(long long*arr,int N,long long target)
{
    int l=0,r=N;
    while(l<r)
    {
        int mid=l+(r-l)/2;
        if(arr[mid]<=target)
        l=mid+1;
        else
        r=mid;
    }
    return l;
}

int main()
{
    int N;
    long long C;
    while(scanf("%d%lld",&N,&C)==2)
    {
        long long*nums=(long long*)malloc(N*sizeof(long long));
        if(nums==NULL)return 1;
        for(int i=0;i<N;i++)
        {
            scanf("%lld",&nums[i]);
        }
        qsort(nums,N,sizeof(long long),cmp);
        long long ans=0;
        for(int k=0;k<N;k++)
        {
            long long target=C+nums[k];
            ans+=upper_bound(nums,N,target)-lower_bound(nums,N,target);

        }
        printf("%lld\n",ans);
        free(nums);
    }
    return 0;
}