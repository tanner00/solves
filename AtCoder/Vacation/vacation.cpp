// URL: https://atcoder.jp/contests/dp/tasks/dp_c
// TYPE: DP

#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(3));
	for (auto &x : v) {
		cin >> x[0] >> x[1] >> x[2];
	}

	// Everyday, you can take ai or bi or ci
	// If taken yesterday, you can't take it again
	// Maximize the amount taken

	// max_today(n) = max(max(a(n - 1) + bn, a(n - 1) + cn),
	//                max(b(n - 1) + an, b(n - 1) + cn),
	//                max(c(n - 1) + an, c(n - 1) + bn))

	// [day][activity]
	vector<int[3]> dp(n);
	dp[0][0] = v[0][0];
	dp[0][1] = v[0][1];
	dp[0][2] = v[0][2];

	for (int d = 1; d < n; ++d) {
		int ma = dp[d - 1][0];
		int mb = dp[d - 1][1];
		int mc = dp[d - 1][2];

		dp[d][0] = max(v[d][0] + mb, v[d][0] + mc);
		dp[d][1] = max(v[d][1] + ma, v[d][1] + mc);
		dp[d][2] = max(v[d][2] + ma, v[d][2] + mb);
	}
	cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});

	return 0;
}
