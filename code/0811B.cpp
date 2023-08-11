#include<cstdio>
#include<cstring>
int a[200100];
int main()
{
    for(int I=1;I<=1;++I)
    {
    int n;
    scanf("%d",&n);
    long long sum=0,mx=0,mn=0;
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    long long ans=-1e18;
    for(int i=1;i<=n;++i)
    {
        sum+=a[i];
        ans=ans>sum-mn?ans:sum-mn;
        mn=mn<sum?mn:sum;
    }
    long long Sum=0;
    for(int i=1;i<=n;++i)
    {
        Sum+=a[i];
        ans=ans>sum-(Sum-mx)?ans:sum-(Sum-mx);
        mx=mx>Sum?mx:Sum;
    }
    printf("%lld\n",ans);
    }
    return 0;
}