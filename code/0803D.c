#include"stdio.h"
int f[303][303],ans[303][303];
int a[303];
int dfs(int l,int r)
{
    if(l==r)
        return 0;
    if(f[l][r])
        return f[l][r];
    for(int i=l;i<r;++i)
    {
        int tmp=dfs(l,i)+dfs(i+1,r)+a[i]*(a[l]+a[r]);
        if(tmp>f[l][r])
        {
            f[l][r]=tmp;
            ans[l][r]=i;
        }
    }
    return f[l][r];
}
int q1[443],q2[443],l,r=1;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",a+i);
    printf("%d\n",dfs(1,n));
    q1[1]=1;
    q2[1]=n;
    while(l<r)
    {
        ++l;
        if(q1[l]==q2[l])
            continue;
        printf("%d ",ans[q1[l]][q2[l]]);
        q1[++r]=q1[l];
        q2[r]=ans[q1[l]][q2[l]];

        q1[++r]=ans[q1[l]][q2[l]]+1;
        q2[r]=q2[l];
    }
    return 0;
}