#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int max_n = 5000000;

long long fact[max_n + 10];
long long inv_fact[max_n + 10];
long long inv_arr[max_n + 10];
long long inv2[max_n + 10];

long long pow_mod(long long base, long long exp, long long mod) {
	long long result = 1;
	while (exp) {
		if (exp & 1) result = result * base % mod;
		base = base * base % mod;
		exp >>= 1;
	}
	return result;
}

void precompute() {
	fact[0] = 1;
	for (int i = 1; i <= max_n; i++) {
		fact[i] = fact[i - 1] * i % mod;
	}
	inv_fact[max_n] = pow_mod(fact[max_n], mod - 2, mod);
	for (int i = max_n - 1; i >= 0; i--) {
		inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
	}
	inv_arr[1] = 1;
	for (int i = 2; i <= max_n; i++) {
		inv_arr[i] = (mod - mod / i) * inv_arr[mod % i] % mod;
	}
	long long inv2_base = pow_mod(2, mod - 2, mod);
	inv2[0] = 1;
	for (int i = 1; i <= max_n; i++) {
		inv2[i] = inv2[i - 1] * inv2_base % mod;
	}
}

int main() {
//	freopen("home.in", "r", stdin);
//	freopen("home.out", "w", stdout);
	precompute();
	int N, K;
	cin >> N >> K;
	if (N == 0) {
		cout << 1 << endl;
		return 0;
	}
	if (K < N) {
		cout << 0 << endl;
		return 0;
	}
	long long ans = 0;
	for (int m = N; m <= K; m += 2) {
		int r = (m + N) / 2;
		long long c = fact[m] * inv_fact[r] % mod * inv_fact[m - r] % mod;
		long long term = N * inv_arr[m] % mod * c % mod * inv2[m] % mod;
		ans = (ans + term) % mod;
	}
	cout << ans << endl;
	return 0;
}
