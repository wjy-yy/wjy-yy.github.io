#include<cstdio>
#include<cstring>
#include<queue>
using std::priority_queue;
struct statu
{
    int l,r;
    long long sum;
    friend bool operator <(statu a,statu b)
    {
        return a.sum<b.sum;
    }
    statu(int l,int r,long long sum)
    {
        this->l=l;
        this->r=r;
        this->sum=sum;
    }
    statu(){}
};
priority_queue<statu> q;
long long a[101000];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        a[i]+=a[i-1];
    }
    for(int i=1;i<=n;i++)
        q.push(statu(1,i,a[i]));
    for(int i=1;i<=k;i++)
    {
        statu p=q.top();
        q.pop();
        printf("%lld ",p.sum);
        q.push(statu(p.l+1,p.r,a[p.r]-a[p.l]));
    }
    return 0;
}