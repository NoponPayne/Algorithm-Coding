#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n, m, x[10], y[10], id[10], res = 1e9;
bool st[5];
set<pair<int, int> > v;

void get(int X, int Y){
	if(X > Y) swap(X, Y);
	if(X * Y < res){
		v.clear();
		res = X * Y;
		v.insert({X, Y});
	}
	else if(X * Y == res) v.insert({X, Y});
}

void check(){
	
	int X, Y;
	// 1 2 3 4
	X = x[id[1]] + x[id[2]] + x[id[3]] + x[id[4]];
	Y = max(y[id[1]], max(y[id[2]], max(y[id[3]], y[id[4]])));
	get(X, Y);
	// 1 2 3
	// 4 4 4
	X = max(x[id[1]] + x[id[2]] + x[id[3]], x[id[4]]);
	Y = y[id[4]] + max(y[id[1]], max(y[id[2]], y[id[3]])); 
	get(X, Y);
	// 1 2 3
	// 4 4 3
	X = x[id[3]] + max(x[id[4]], x[id[1]] + x[id[2]]);
	Y = max(y[id[3]], y[id[4]] + max(y[id[1]], y[id[2]]));
	get(X, Y);
	//1 2 4
	//1 3 4
	X = x[id[1]] + max(x[id[2]], x[id[3]]) + x[id[4]];
	Y = max(y[id[1]], max(y[id[2]] + y[id[3]], y[id[4]]));
	get(X, Y);
	// 1 3 4
	// 2 3 4
	X = max(x[id[1]], x[id[2]]) + x[id[3]] + x[id[4]];
	Y = max(y[id[3]], max(y[id[4]], y[id[1]] + y[id[2]]));
	get(X, Y);
	// 1 2
	// 3 4
	Y = max(y[id[1]] + y[id[3]], y[id[2]] + y[id[4]]);
	X = max(x[id[1]] + x[id[2]], x[id[3]] + x[id[4]]);
	if(y[id[3]]>y[id[4]])X=max(X,x[id[3]]+x[id[2]]);
	else X=max(X,x[id[4]]+x[id[1]]);
	get(X, Y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	for(int i = 1; i <= 4; i ++) cin >> x[i] >> y[i], id[i] = i;
	
	check();
	for(ll i=0;i<=1;i++){
		swap(x[1],y[1]);
		for(ll j=0;j<=1;j++){
			swap(x[2],y[2]);
			for(ll k=0;k<=1;k++){
				swap(x[3],y[3]);
				for(ll r=0;r<=1;r++){
					swap(x[4],y[4]);
					check();
				}
			}
		}
	}
	while(next_permutation(id + 1, id + 5)){
		check();
		for(ll i=0;i<=1;i++){
			swap(x[1],y[1]);
			for(ll j=0;j<=1;j++){
				swap(x[2],y[2]);
				for(ll k=0;k<=1;k++){
					swap(x[3],y[3]);
					for(ll r=0;r<=1;r++){
						swap(x[4],y[4]);
						check();
					}
				}
			}
		}
	}
	cout << res << endl;
	for(auto c: v) cout << c.first << ' ' << c.second << endl;
	return 0;
}

