#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,maxn=1,No=0,ans=0,g[10005],d[10005];
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>g[i]>>d[i];
    for(int i=n;i>=1;--i)
        {
            for(int j=1;j<=n;++j)
              if(d[j]>=i&&g[j]>=maxn)
              {
                  No=j;
                  maxn=g[j];
              }
            if(No!=0){g[No]=0;d[No]=10005;ans+=maxn;}
            maxn=0;
            No=0;
        }
    cout<<ans;
    return 0;
}