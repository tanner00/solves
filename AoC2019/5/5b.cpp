#include <bits/stdc++.h>

using namespace std;

vector<int> program;

int get1(int pc, int m) {
	int v;
	if (m == 1) {
		v = program[pc + 1];
	} else {
		v = program[program[pc + 1]];
	}
	return v;
}

pair<int, int> get2(int pc, int m1, int m2) {
	return make_pair(get1(pc, m1), get1(pc + 1, m2));
}

int main() {

	string s;
	getline(cin, s);
	stringstream ss(s);

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
			auto [op1, op2] = get2(pc, m1, m2);
			program[program[pc + 3]] = op1 + op2;

			pc += 4;
		}
		// Multiply instruction
		if (op == 2) {
			auto [op1, op2] = get2(pc, m1, m2);
			program[program[pc + 3]] = op1 * op2;

			pc += 4;
		}
		// Input instruction
		if (op == 3) {
			program[program[pc + 1]] = 5;
			pc += 2;
		}
		// Output instruction
		if (op == 4) {
			cout << program[program[pc + 1]];
			pc += 2;
		}
		// Jump-if-true instruction
		if (op == 5) {
			auto [op1, op2] = get2(pc, m1, m2);
			pc = op1 ? op2 : pc + 3;
		}
		// Jump-if-false instruction
		if (op == 6) {
			auto [op1, op2] = get2(pc, m1, m2);
			pc = (op1 == 0) ? op2 : pc + 3;
		}
		// Less-than instruction
		if (op == 7) {
			auto [op1, op2] = get2(pc, m1, m2);
			program[program[pc + 3]] = op1 < op2;
			pc += 4;
		}
		// Equals instruction
		if (op == 8) {
			auto [op1, op2] = get2(pc, m1, m2);
			program[program[pc + 3]] = op1 == op2;
			pc += 4;
		}
		// Halt instruction
		if (op == 99) {
			break;
		}
	}

	return 0;
}
