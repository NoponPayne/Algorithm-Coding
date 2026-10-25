#include<bits/stdc++.h>
using namespace std;
int a[15];
int ans=0;
void fun(int dep){
	if(dep==7){
		int tmp=0;
		for(int i=1;i<=7;i++){
			tmp+=a[i];
		}
		if(tmp%3!=0)return;
		tmp=a[1]*a[2]*a[4]+a[2]*a[3]*a[5]+a[3]*a[4]*a[6]+a[4]*a[5]*a[7]+a[5]*a[6]*a[1]+a[6]*a[7]*a[2]+a[7]*a[1]*a[3];
		if(tmp%3!=0)return;
		ans++;
		return;
	}
	for(int i=1;i<=3;i++){
		a[dep+1]=i;
		fun(dep+1);
		a[dep+1]=0;
	}
	return;
}
int main(){
	fun(0);
	cout<<ans<<endl;
	return 0;
}
