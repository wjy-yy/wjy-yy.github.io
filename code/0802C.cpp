#include<cstdio>
char s[100100];
int main()
{
    int cnt=0,ans=0;
    scanf("%s",s+1);
    for(int i=1;s[i]!='\0';++i)
        if(s[i]=='(')
            ++cnt;
        else if(!cnt)
        {
            ++cnt;
            ++ans;
        }
        else
            --cnt;
    printf("%d\n",ans+cnt/2);
    return 0;
}