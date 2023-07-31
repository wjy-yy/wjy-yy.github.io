#include<cstdio>
#include<cstring>
int main()
{
    long long n;
    scanf("%lld",&n);
    long long tmp=n>>1;
    printf("%lld\n",tmp*(n-tmp));
    return 0;
}