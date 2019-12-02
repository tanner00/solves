// URL: https://adventofcode.com/2019/day/1
// TYPE: Ad-Hoc

#include <bits/stdc++.h>

using namespace std;

int main() {

	int sum = 0;
	int mass;
	while (cin >> mass) {
		sum += (mass / 3) - 2;
	}

	cout << sum;

	return 0;
}
