#include<cstdio>
#include<cstring>
int a[1001000];
int main()
{
	int n,k,x,ans=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		if(x>=k)
			continue;
		if(a[k-x])
		{
			--a[k-x];
			ans+=2;
		}
		else
			++a[x];
	}
	printf("%d",ans);
	return 0;
}