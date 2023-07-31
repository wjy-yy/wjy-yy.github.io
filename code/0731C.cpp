#include<cstdio> 
#include<cstring>
#include<iostream>
using namespace std;
int t[5005],b[5005];
bool in[5005];//这个点在不在生成树里 
int dis[5005];
int f(int i,int j)
{
	return min(t[i]^b[j],t[j]^b[i]);
}
int main()
{
	memset(dis,-1,sizeof(dis));
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&t[i],&b[i]);
	int now=1;
	long long ans=0;
	in[1]=true;
	
	for(int i=1;i<n;++i)
	{
		int mx=-1,mxp=0;
		for(int j=1;j<=n;++j)
			if(!in[j]&&dis[j]<f(now,j))
			//不在生成树
				dis[j]=f(now,j);
		for(int j=1;j<=n;++j)
			if(!in[j]&&dis[j]>mx)
			{
				mx=dis[j];
				mxp=j;
			}
		now=mxp;
		ans+=dis[now];
		in[now]=true;
	}
	printf("%lld\n",ans);
	return 0;
}