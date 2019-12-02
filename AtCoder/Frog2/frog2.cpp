// URL: https://atcoder.jp/contests/dp/tasks/dp_b
// TYPE: DP

#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, k;
	cin >> n >> k;
	// Cost to jump to stone i
	vector<int> cost(n);
	for (int &x : cost) {
		cin >> x;
	}

	// The shortest cost path to stone i is stored in dp[i]
	vector<int> dp(n, INT_MAX);
	dp[0] = 0;
	for (int i = 1; i < n; ++i) {
		// now, arbitrarily sized paths

		for (int j = 1; j <= k && i - j >= 0; ++j) {
			dp[i] = min(dp[i],
				    dp[i - j] + abs(cost[i - j] - cost[i]));
		}
	}

	cout << dp[n - 1];

	return 0;
}
