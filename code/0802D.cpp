#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[2020],f[2020];
int main()
{
    int n,A,B;
    scanf("%d%d%d",&n,&A,&B);
    for(int i=1;i<=n;++i)
        scanf("%d",a+i);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i)
    {
        f[i]=1e9;
        for(int j=0;j<i;++j)
            f[i]=min(f[i],f[j]+(a[i]-a[j+1])*B+2*A);
    }
    if(f[n]&1)
        printf("%.1lf\n",f[n]/2.0);
    else
        printf("%d\n",int(f[n]/2.0+.1));
    return 0;
}