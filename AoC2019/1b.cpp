// URL: https://adventofcode.com/2019/day/1
// Type: Ad-Hoc

#include <bits/stdc++.h>

using namespace std;

int main() {

	int sum = 0;
	int mass;
	while (cin >> mass) {
		while (true) {
			mass = (mass / 3) - 2;
			if (mass > 0) {
				sum += mass;
			} else {
				break;
			}
		}
	}

	cout << sum;

	return 0;
}
