#include<cstdio>
#include<cstring>
#include<algorithm>
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[2100000],*p1=buf,*p2=buf;
int read()
{
	int x=0;
	char ch=gc();
	while(ch<'0'||ch>'9')
		ch=gc();
	while(ch>='0'&&ch<='9')
	{
		x=x*10+(ch&15);
		ch=gc();
	}
	return x;
}
int f[200100];
struct check
{
	int l,r;
	friend bool operator <(check a,check b)
	{
		return a.l<b.l;
	}
}a[200100];
int main()
{
	int n=read();
	int m=read();
	for(int i=1;i<=m;++i)
	{
		a[i].l=read();
		a[i].r=read();
	}
	std::sort(a+1,a+1+m);
	int t=0,mx=0,ans=0;
	for(int i=1;i<=m;++i)
	{
		while(t<a[i].l)
		{
			mx=mx>f[t]?mx:f[t];
			++t;
		}
		f[a[i].r]=f[a[i].r]>mx+a[i].r-a[i].l+1?f[a[i].r]:mx+a[i].r-a[i].l+1;
		ans=ans>f[a[i].r]?ans:f[a[i].r];
	}
	printf("%d\n",ans);
	return 0;
}
