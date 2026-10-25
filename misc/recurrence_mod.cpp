#include<bits/stdc++.h>
using namespace std;
long long ans;
int k;
int main(){
	int n;
	cin>>n;
	int x=1,y=1,z=2,tmp;
	for(int i=4;i<=n;i++){
		tmp=x+z;
		tmp%=1000;
		x=y;		
		y=z;
		z=tmp;
		//cout<<x<<' '<<y<<' '<<z<<endl;
	}
	cout<<z<<endl;
	return 0;
	
}
