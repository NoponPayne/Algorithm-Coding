#include<bits/stdc++.h>
using namespace std;
int row[9],col[9],grid[9];
int rec[9][9];
int cnt[512],num[261];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
		x=x*10+ch-'0',ch=getchar();
	return x*f;
}
inline int calcgrid(int x,int y){
	return ((x/3)*3)+(y/3);
}
inline void tip(int x,int y,int z){
	row[x]^=1<<z;
	col[y]^=1<<z;
	grid[calcgrid(x,y)]^=1<<z;
	return;
}
bool func(int now){
	if(!now)return true;
	int temp=10,x,y;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(rec[i][j])continue;
			int val=row[i]&col[j]&grid[calcgrid(i,j)];
			if(!val)return false;
			if(temp>cnt[val]){
				temp=cnt[val];
				x=i;
				y=j;
			}
		}
	}
	int val=row[x]&col[y]&grid[calcgrid(x,y)];
	for(;val;val-=val&(-val)){
		int z=num[val&(-val)];
		rec[x][y]=z+1;
		tip(x,y,z);
		if(func(now-1))return true;
		rec[x][y]=0;
		tip(x,y,z);
	}
	return false;
}
int main(){
	for(int i=0;i<(1<<9);i++){
		for(int j=i;j;j-=j&(-j)){
			cnt[i]++;
		}
	}
	for(int i=0;i<9;i++){
		num[1<<i]=i;
	}
	for(int i=0;i<9;i++){
		row[i]=col[i]=grid[i]=(1<<9)-1;
	}
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			rec[i][j]=read();
		}
	}
	int tot=0;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(rec[i][j])tip(i,j,rec[i][j]-1);
			else tot++;
		}
	}
	func(tot);
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			printf("%d ",rec[i][j]);
		}
		putchar('\n');
	}
	return 0;
}
