#include<cstdio>
int min(int x,int y)
{
    return x<y?x:y;
}
int a[101000],b[101000];
int main()
{
    int n,m,k;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    int q,l1,l2,r1,r2;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d%d%d%d",&l1,&r1,&l2,&r2,&k);
        l1--,l2--;
        while(k>1&&l1<r1&&l2<r2)
        {
            int now1=min(r1,l1+k/2),now2=min(r2,l2+k/2);
            if(a[now1]<b[now2])
                k-=now1-l1,l1=now1;
            else
                k-=now2-l2,l2=now2;
        }
        if(l1==r1)
            printf("%d\n",b[l2+k]);
        else if(l2==r2)
            printf("%d\n",a[l1+k]);
        else
            printf("%d\n",min(a[l1+1],b[l2+1]));
    }
    return 0;
}