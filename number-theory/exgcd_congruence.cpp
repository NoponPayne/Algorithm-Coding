#include<bits/stdc++.h>
using namespace std;
int x,y,m,n,l;
int exgcd(int a,int b){
	if(!b){
		x=1;
		y=0;
		return a;
	}
	int d=exgcd(b,a%b);
	int t=x;
	x=y;
	y=t-(a/b)*y;
	return d;
}
int main(){
	cin>>x>>y>>m>>n>>l;
	int a=m-n,b=l,c=-(x-y);
	if(a<0){
		a=-a;
		c=-c;
	} 
	int d=exgcd(a,b);
	if(c%d){
		cout<<"Impossible\n"<<endl;
		return 0;
	}
	x*=c/d;
	int minx=(x%(b/d)+(b/d))%(b/d);
	if(minx==0)minx+=b/d;
	cout<<minx<<'\n';
	return 0;
}
