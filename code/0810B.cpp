#include<cstdio>
long long d[101000];
long long b[101000];
int a[101000];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        b[i]=a[i]+b[i-1];
        d[i]=a[i]*i+d[i-1];
    }
    long long ans=0,t;
    for(int i=0;i<=n-k;i++)
    {
        t=d[i+k]-d[i]-i*(b[i+k]-b[i]);
        if(t>ans)
            ans=t;
    }
    printf("%lld\n",ans);
    return 0;
}