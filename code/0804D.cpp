#include"stdio.h"
#include"string.h"
char s[105];
int f[105][105];
int main()
{
    memset(f,0x3f,sizeof(f));
    scanf("%s",s+1);
    int n=0;
    for(int i=1;s[i]!='\0';++i)
    {
        f[i][i]=1;
        f[i][i-1]=0;
        n=i;
    }
        
    for(int l=1;l<n;++l)
    {
        for(int i=1;i+l<=n;++i)
        {
            if(s[i]=='('&&s[i+l]==')'||
              s[i]=='['&&s[i+l]==']')
                f[i][i+l]=f[i+1][i+l-1];
            for(int k=i;k<i+l;++k)
                f[i][i+l]=f[i][i+l]<f[i][k]+f[k+1][i+l]?f[i][i+l]:f[i][k]+f[k+1][i+l];
        }
    }
    printf("%d\n",f[1][n]);
    return 0;
}