#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
using namespace std;
long long g[71],l,r;
inline long long Solve(long long x)
{
	if (x<2) return 0;
	int len=0;	long long y=x;
	while (y) {
		++len; y>>=1;
	}
	long long tmp=0;
	for (int i=1;i<=len;++i) {
		y=g[i+1]-1;
		for (int j=0;j<i;++j) {
			if (y-g[j]<=x) ++tmp;
		}
	}
	return tmp;
}
int main()
{
	g[0]=1;
	for (int i=1;i<=61;++i) g[i]=g[i-1]<<1;
	
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%I64d%I64d",&l,&r);
		printf("%I64d\n",Solve(r)-Solve(l-1));
	}
} 