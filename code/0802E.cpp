#include<cstdio>
int Min(int x,int y)
{
    return x<y?x:y;
}
long long calc(long long a,long long d,long long n)
{
    return a*n+n*(n-1)*d/2;
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    long long ans=(long long)n*k;
    for(int i=1;i<=k&&i<=n;++i)
    {
        ans-=calc((long long)i*(k/i),k/i,Min(n,k/(k/i))-i+1);
        i=Min(n,k/(k/i));
    }
    printf("%lld\n",ans);
    return 0;
}