#include<bits/stdc++.h>
using namespace std;
struct node{
	int s,f;
} q[1005];
bool cmp(node x,node y){
	if(x.f==y.f){
		return x.s<y.s;
	}
	return x.f<y.f;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&q[i].s,&q[i].f);
	}
	sort(q+1,q+n+1,cmp);
	int k=q[1].f,num=1;
	for(int i=1;i<=n;i++){
		if(k<=q[i].s){
			num++;
			k=q[i].f;
		}
	}
	printf("%d\n",num);
	return 0;
}
