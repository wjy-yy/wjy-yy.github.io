#include<bits/stdc++.h>
using namespace std;
int n,c[1000003];
struct node{
	int x,y,f;
}a[200003],s[200003],b[200003],t[200003];
bool cmp(node u,node v){
	return u.x>v.x;
}
//x1<x2  min(abs(y1-y2))
/*
c[1]   c[2]   c[3]   c[4]
4
s[1]=(1,2)
7 6   1   -1
1 2   2   1
3 3   3   3
2 4   4   1
*/
void sss(int l,int r){
	if(l==r) return ;
	int mid=l+r>>1;
	sss(l,mid);
	sss(mid+1,r);
	int i=l,j=mid+1,k=l,mx=a[i].y,mn=a[i].y;
	while(i<=mid && j<=r){
		if(a[i].y<=a[j].y){
			mx=a[i].y;
			s[k++]=a[i++];
		}else{
			c[a[j].f]=min(c[a[j].f],abs(a[j].y-mx));
			s[k++]=a[j++];
			//cout<<j<<" "<<;
		}
	}
	while(i<=mid){
		s[k++]=a[i++];
	}
	while(j<=r){
		c[a[j].f]=min(c[a[j].f],abs(a[j].y-mx));
		s[k++]=a[j++];
	}
	for(int i=l;i<=r;i++) a[i]=s[i];
	i=l,j=mid+1,k=l;
	while(i<=mid && j<=r){
		if(b[i].y>=b[j].y){
			mn=b[i].y;
			t[k++]=b[i++];
			//cout<<i<<" "<<a[i]<<endl;
		}else{
			c[b[j].f]=min(c[b[j].f],abs(mn-b[j].y));
			t[k++]=b[j++];
			//cout<<j<<" "<<;
		}
	}
	while(i<=mid){
		c[b[j].f]=min(c[b[j].f],abs(mn-b[j].y));
		t[k++]=b[i++];
	}
	while(j<=r){
		t[k++]=b[j++];
	}
	for(int i=l;i<=r;i++) b[i]=t[i];
	return; 
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		c[i]=INT_MAX,a[i].f=i;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++) b[i]=a[i];
	sss(1,n);
	for(int i=1;i<=n;i++){
		//printf("%d %d\n",a[i].x,a[i].y);
		printf("%d\n",c[i]==INT_MAX?-1:c[i]);
	}
	return 0;
}