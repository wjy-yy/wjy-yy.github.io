#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define p 998244353
int Plus(int x,int y){return x+y>=p?x+y-p:x+y;}
int Mul(int x,int y){return 1ll*x*y%p;}
int f[55][55][2550];
int main()
{
	f[0][0][0]=1;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=i;++j)
			for(int k=2*j;k<=m;++k)
			{
				f[i][j][k]=Plus(f[i][j][k],Mul(j+1,Mul(j+1,f[i-1][j+1][k-2*j])));
				f[i][j][k]=Plus(f[i][j][k],Mul(2*j+1,f[i-1][j][k-2*j]));
				if(j)
					f[i][j][k]=Plus(f[i][j][k],f[i-1][j-1][k-2*j]);
			}
	cout<<f[n][0][m];
	return 0;
}