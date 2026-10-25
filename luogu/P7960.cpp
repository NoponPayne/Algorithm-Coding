#include<bits/stdc++.h>
using namespace std;
const int MAXX=1e7+100;
int cnt;
int f[MAXX],nex[MAXX];
bool p(int x){
	while(x){
		if(x%10==7)return false;
		x/=10;
	}
	return true;
}
void fun(){
	for(int i=1;i<=MAXX-10;i++){
		if(f[i])continue;
		if(!p(i)){
			for(int j=i;j<=MAXX-10;j+=i){
				f[j]=1;
			}
			continue;
		}
		nex[cnt]=i;
		cnt=i;
	}
}
int main(){
	fun(); 
	int T,x;
	cin>>T;
	while(T--){
		cin>>x;
		if(f[x]){
			cout<<-1<<endl;
		}else{
			cout<<nex[x]<<endl;
		}
	}
	return 0;
}
