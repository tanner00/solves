#include <bits/stdc++.h>

using namespace std;

int main() {

	string s;
	getline(cin, s);
	stringstream ss(s);

	vector<int> program;
	for (int i; ss >> i;) {
		program.push_back(i);
		if (ss.peek() == ',')
			ss.ignore();
	}

	int pc = 0;
	while (true) {
		int instr = program[pc];
		int op = instr % 100;
		// 1 is immediate, 0 is position
		int m1 = (instr / 100) % 10;
		int m2 = (instr / 1000) % 10;
		int m3 = (instr / 10000) % 10;

		// Add instruction
		if (op == 1) {
			int v1;
			if (m1 == 1) {
				v1 = program[pc + 1];
			} else {
				v1 = program[program[pc + 1]];
			}

			int v2;
			if (m2 == 1) {
				v2 = program[pc + 2];
			} else {
				v2 = program[program[pc + 2]];
			}

			program[program[pc + 3]] = v1 + v2;

			pc += 4;
		}
		// Multiply instruction
		if (op == 2) {
			int v1;
			if (m1 == 1) {
				v1 = program[pc + 1];
			} else {
				v1 = program[program[pc + 1]];
			}

			int v2;
			if (m2 == 1) {
				v2 = program[pc + 2];
			} else {
				v2 = program[program[pc + 2]];
			}

			program[program[pc + 3]] = v1 * v2;

			pc += 4;
		}
		// Input instruction
		if (op == 3) {
			program[program[pc + 1]] = 1;
			pc += 2;
		}
		// Output instruction
		if (op == 4) {
			cout << program[program[pc + 1]] << '\n';
			pc += 2;
		}
		// Halt instruction
		if (op == 99) {
			break;
		}
	}

	return 0;
}
