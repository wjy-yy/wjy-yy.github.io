#include "stdio.h"
#include "string.h"
int a[100100],b[100100];
long long ans=0;
void merge_sort(int l,int r)
{
    if(l==r)
        return;
    int L=l;
    //[l,mid] [mid+1,r]
    int mid=(l+r)>>1;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    int l1=mid+1,t1=l;
    while(l<=mid&&l1<=r)
    {
        if(a[l]<=a[l1])
            b[t1++]=a[l++];
        else//a[l]>a[l1]
        {
            ans+=mid-l+1;
            b[t1++]=a[l1++];
        }
    }
    while(l<=mid)//
        b[t1++]=a[l++];
    while(l1<=r)
        b[t1++]=a[l1++];
    for(int i=L;i<=r;++i)
        a[i]=b[i];
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",a+i);
    merge_sort(1,n);
    printf("%lld\n",ans);
    return 0;
}