#include"stdio.h"
#include"string.h"
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
long long min(long long x,long long y){return x<y?x:y;}
int lg[400100],a[400100];
long long sum[400100];
long long f[20][400100];
int main()
{
    memset(f,0x3f,sizeof(f));
	int n,m,l,r;
	n=read();
	lg[0]=-1;
	for(int i=1;i<=n;++i)
	{
		lg[i]=lg[i>>1]+1;
		a[i]=read();
		
        sum[i]=sum[i-1]+a[i];
        f[0][i]=sum[i]; 
	}
    for(int i=n+1;i<=n+n;++i)
    {
        lg[i]=lg[i>>1]+1;
        a[i]=a[i-n];
        sum[i]=sum[i-1]+a[i];
        f[0][i]=sum[i]; 
    }
	//n=100000, 1<<16=65536
	//log2 100000 = 16
	for(int i=1;i<=19;++i)
		for(int j=1;j<=2*n;++j)
			f[i][j]=min(f[i-1][j],f[i-1][j+(1<<i-1)]); 
			//j开始的2^i j开始的2^i-1 j 
    long long ans=-1e18;
	for(int i=1;i<=n;++i)
	{
		l=i-1;
		r=i+n-1;
		//lg[r-l+1]
		int L=lg[r-l+1];
		long long tmp=sum[n+i-1]-min(f[L][l],f[L][r-(1<<L)+1]);
        // printf("%lld\n",sum[i+n-1]);
        ans=ans>tmp?ans:tmp;
	}
    printf("%lld\n",ans);
	return 0;
}