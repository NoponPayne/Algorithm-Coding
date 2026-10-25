#include<bits/stdc++.h>
using namespace std;
struct num{
	int f,s;
}a[500005];
bool tt[5000005];
int q[500005];
bool f=0;
int n;
int front,back;
bool check(int jk,int pk){
	if(a[q[jk]].f){
		if(pk+a[q[jk]].f==((n<<1)|1)){
			return true;	
		}else{
			return false;
		}
	}
	return true;
}
void dfs(int k){
	if(k>(n<<1)){
		f=1;
		return;
	}
	if(f)return;
	if(check(front+1,k)&&(!f)){
		front++;
		tt[k]=0;
		if(a[q[front]].f){
			a[q[front]].s=k;
			dfs(k+1);
			if(f)return;
			a[q[front]].s=0;
		}else{
			a[q[front]].f=k;
			dfs(k+1);
			if(f)return;
			a[q[front]].f=0;
		}
		tt[k]=-1;
		front--;
	}
	if((!f)&&check(back-1,k)){
		back--;
		tt[k]=1;
		if(a[q[back]].f){
			a[q[back]].s=k;
			dfs(k+1);
			if(f)return;
			a[q[back]].s=0;
		}else{
			a[q[back]].f=k;
			dfs(k+1);
			if(f)return;
			a[q[back]].f=0;
		}
		tt[k]=-1;
		back++;
	}
	return;
}
int main(){
	int T,tmp;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		f=0;
		for(int i=1;i<=(n<<1);i++){
			cin>>tmp;
			q[++back]=tmp;
		}
		back++;
		dfs(1);
		if(f==0){
			putchar('-');
			putchar('1');
			putchar('\n');
		}else{
			for(int i=1;i<=(n<<1);i++){
				if(tt[i]){
					putchar('R');
				}else{
					putchar('L');
				}
			}
			putchar('\n');
		}
	}
	return 0;
}
