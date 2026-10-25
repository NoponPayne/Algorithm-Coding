#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,u;
}edge[200100];
int n,m,f[5100],d[5100],v[200100],e[5100],num,ans;
int k;
int get(int x){
	return x==f[x]?x:f[x]=get(f[x]);
}
void bor()
{
	for(int i=1;i<=n;i++)
		f[i]=i;
	while(1)
	{
		int res=0;
		memset(d,0x3f3f,sizeof(d));//清空d数组 
		for(int i=1;i<=m;i++){
			int f1=get(edge[i].x),f2=get(edge[i].y);//用并查集找到根 
			if(f1==f2||v[i])//如果一棵树或者拓展过这个边 
				continue;
			res++;//记录一下看下有没有边可以拓展 
			if(edge[i].u<d[f1])
				d[f1]=edge[i].u,e[f1]=i;//更新，e数组表示d数组对应的边 
			if(edge[i].u<d[f2])
				d[f2]=edge[i].u,e[f2]=i;
		}
		if(res==0 || num==n-1)
			break;
		for(int i=1;i<=n;i++)//扫描每棵树 
		{
			int f1=get(edge[e[i]].x),f2=get(edge[e[i]].y);
			if(d[i]==0x3f3f3f3f || f1==f2 || v[e[i]])
				continue;
			v[e[i]]=1;//加入最小生成树集合 
			f[f1]=f2;
			ans+=edge[e[i]].u;
			num++;
		}
	}
}
int main(){
	scanf("%d %d %d",&k,&n,&m);
	int cnt=0;
	for(int i=n;i<=m;i++){
		for(int j=i+1;j<=m;j++){
			edge[++cnt].x=i-n+1;
			edge[cnt].y=j-n+1;
			edge[cnt].u=i*j/__gcd(i,j);
		}
	}
	n=m-n+1;
	m=cnt;
	cout<<n<<' '<<m<<endl;
	bor();
	if(num==n-1)
		printf("%d",ans);
	else printf("orz");
	return 0;
}
