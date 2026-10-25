#include<bits/stdc++.h>
using namespace std;
struct node{
	int start,end,num;
};
bool cmp(node a,node b){
	return a.end<b.end;
}
vector<node>nodes;
int n,m,ans;
bool flag[50005];
int main(){
	scanf("%d %d",&n,&m);
	int s,e,h;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&s,&e,&h);
		nodes.push_back({s,e,h});
	}
	sort(nodes.begin(),nodes.end(),cmp);
	for(int i=0;i<m;i++){
		int tmp=0;
		for(int j=nodes[i].start;j<=nodes[i].end;j++){
			if(flag[j]){
				tmp++;
			}
			if(tmp==nodes[i].num){
				break;
			}
		}
		if(tmp<nodes[i].num){
			for(int j=nodes[i].end;j>=nodes[i].start;j--){
				if(!flag[j]){
					flag[j]=true;
					tmp++;
					ans++;
					if(tmp==nodes[i].num){
						break;
					}
				}
			}
		}
	}
	printf("%d",ans+1);
	return 0;
}
