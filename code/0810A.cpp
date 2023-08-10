#include<cstdio>
#include<cstring>
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int x,y;
    y=m-2*n;
    y/=2;
    x=n-y;
    printf("%d %d\n",x,y);
    return 0;
}