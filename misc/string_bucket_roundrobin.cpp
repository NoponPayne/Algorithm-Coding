#include<bits/stdc++.h>
using namespace std;
int n,m;
int x[30],ans[30];
string s[100005];
string a[30][10005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++){
		a[s[i][0]-'a'+1][++x[s[i][0]-'a'+1]]=s[i];
	}
	for(int i=1;i<=26;i++){
		ans[i]=1;
	}
	char c;
	for(int i=1;i<=m;i++){
		cin>>c;
		int t=c-'a'+1;
		cout<<a[t][ans[t]]<<endl;
		ans[t]++;
		if(ans[t]>x[t]){
			ans[t]=1;
		}
	}
	return 0;
}
