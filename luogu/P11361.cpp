#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N],b[N],ans,idx1,idx0;
string s1,s2,t1,t2;
bool sta[N],stb[N];
int v0[N],v1[N];
int main() {
	scanf("%d ",&t);
	while(t--) {
		memset(v0,0,sizeof v0);
		memset(v1,0,sizeof v1);
		idx1=idx0=0;
		ans=0;
		scanf("%d ",&n);
		cin>>s1>>s2>>t1>>t2;
		for(int i=0; i<n; i++) {
			a[i]=s1[i]-'0';
			b[i]=s2[i]-'0';
			if(t1[i]=='0') sta[i]=false;
			else sta[i]=true;
			if(t2[i]=='0') stb[i]=false;
			else stb[i]=true;
		}
		for(int i=0; i<n; i++) {
			if(a[i]==b[i]) {
				ans++;
				sta[i]=stb[i]=false;
			}
		}
		for(int i=0; i<n; i++) {
			if(!sta[i]) continue;
			if(a[i]==1) {
				if(idx0) {
					stb[i]=stb[v0[idx0]]=false;
					v0[idx0--]=0;
					ans+=2;
				} else {
					v1[++idx1]=i;
				}
			} else {
				if(idx1) {
					stb[i]=stb[v1[idx1]]=false;
					v1[idx1--]=0;
					ans+=2;
				} else {
					v1[++idx0]=i;
				}
			}
		}
		idx0=0;
		idx1=0;
		for(int i=0; i<n; i++) {
			if(!stb[i]) continue;
			if(b[i]==1) {
//					printf("2");
				if(idx0) {
					v0[idx0--]=0;
					ans+=2;
				} else {
//					printf("2");
					v1[++idx1]=i;
				}
			} else {
				if(idx1) {
					v1[idx1--]=0;
					ans+=2;
				} else {
					v1[++idx0]=i;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

