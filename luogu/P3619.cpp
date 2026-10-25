// Luogu P3619 Solvement
#include<bits/stdc++.h>
using namespace std;
struct node{
	int t;
	int b;
}a[100005];
int cmp(node x,node y){
	return x.t+x.b>y.t+y.b;
}
int T,ti,n;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&ti);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&a[i].t,&a[i].b);
		}
		sort(a+1,a+n+1,cmp);
		bool f=1;
		for(int i=1;i<=n;i++){
			if(ti>a[i].t&&ti+a[i].b>0){
				ti+=a[i].b;
			}else{
				printf("-1s\n");
				f=0;
				break;
			}
		}
		if(f){
			printf("+1s\n");
		}
	}
	return 0;
}
