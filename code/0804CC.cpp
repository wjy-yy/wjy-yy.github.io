#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
pair<pair<int,int>,int> p[200100];
int ans[200100];
set<int> s;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d",&p[i].first.first,&p[i].first.second);
        p[i].second=i;
    }
    sort(p+1,p+1+n);
    for(int i=n;i>=1;--i)
    {
        if(s.empty())
            ans[p[i].second]=-1;
        else
        {
            auto it=s.upper_bound(p[i].first.second);
            ans[p[i].second]=1e9;
            if(it!=s.end())
                ans[p[i].second]=min(ans[p[i].second],*it-p[i].first.second);
            if(it!=s.begin())
            {
                it--;
                ans[p[i].second]=min(ans[p[i].second],p[i].first.second-*it);
            }
        }
        if(p[i].first.first!=p[i-1].first.first)
        {
            for(int j=i;p[j].first.first==p[i].first.first;++j)
                s.insert(p[j].first.second);
        }
    }
    for(int i=1;i<=n;++i)
        printf("%d\n",ans[i]);
    return 0;
}