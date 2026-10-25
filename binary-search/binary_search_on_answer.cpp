#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

bool check(ll ans, const vector<ll>& a, ll total_A, ll m, int n, int& k) {
	if (ans == 0) {
		if (total_A <= m) {
			k = 0;
			return true;
		}
		return false;
	}
	
	vector<ll> c0(n + 2, 0), c1(n + 2, 0), diff2(n + 2, 0);
	
	for (int i = 0; i < n; i++) {
		ll t = a[i] / ans;
		ll L = max(1ll * 0, i - t);
		ll R = min(1ll * (n - 1), i + t);
		
		c0[L] += i;
		c1[L] -= 1;
		c0[i + 1] -= i;
		c1[i + 1] += 1;
		
		c0[i] -= i;
		c1[i] += 1;
		c0[R + 1] += i;
		c1[R + 1] -= 1;
		
		diff2[L] += a[i];
		diff2[R + 1] -= a[i];
	}
	
	ll cur_c0 = 0, cur_c1 = 0, cur_diff2 = 0;
	for (int K = 0; K < n; K++) {
		cur_c0 += c0[K];
		cur_c1 += c1[K];
		cur_diff2 += diff2[K];
		ll F1 = cur_c0 + cur_c1 * K;
		ll F2 = cur_diff2;
		ll f = ans * F1 + total_A - F2;
		if (f >= total_A - m) {
			k = K;
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	ll m;
	cin >> n >> m;
	vector<ll> a(n);
	ll total_A = 0;
	ll max_a = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		total_A += a[i];
		if (a[i] > max_a) max_a = a[i];
	}
	
	if (total_A <= m) {
		cout << "1 0" << endl;
		return 0;
	}
	
	ll low = 1, high = max_a;
	ll best_ans = high;
	int best_k = n - 1;
	
	while (low <= high) {
		ll mid = low + (high - low) / 2;
		int k;
		if (check(mid, a, total_A, m, n, k)) {
			best_ans = mid;
			best_k = k;
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	
	cout << best_k + 1 << " " << best_ans << endl;
	
	return 0;
}
