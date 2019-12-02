// URL: https://atcoder.jp/contests/dp/tasks/dp_a
// TYPE: DP

#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	cin >> n;
	// Cost to jump to stone i
	vector<int> cost(n);
	for (int &x : cost) {
		cin >> x;
	}

	// The shortest cost path to stone i is stored in dp[i]
	int dp[n] = {};
	dp[0] = 0;
	dp[1] = abs(cost[0] - cost[1]);
	for (int i = 2; i < n; ++i) {
		dp[i] = min(dp[i - 2] + abs(cost[i - 2] - cost[i]),
			    dp[i - 1] + abs(cost[i - 1] - cost[i]));
	}

	cout << dp[n - 1];

	return 0;
}
