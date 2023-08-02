#include<iostream>
#include<vector>
#include<queue>
using namespace std;
 
const int MAXN=10001;
int n,m,ans,t[MAXN],tot[MAXN],d[MAXN];
vector<int> g[MAXN];
queue<int> q;
 
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>t[i];
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        d[y]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(d[i]==0)
        {
            tot[i]=t[i];
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            d[v]--;
            tot[v]=max(tot[v],tot[u]+t[v]);
            if(d[v]==0)q.push(v);
        }
    }
    for(int i=1;i<=n;i++)
        ans=max(tot[i],ans);
    cout<<ans;
    return 0;
}