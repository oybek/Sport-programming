
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstring>
#include <climits>
#include <iomanip>
#include <iostream>
#include <algorithm>

#define INF INT_MAX-1
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

#define SIZE 1000

int reg[10],
	ram[SIZE];

int digit(int n, int i) {
	while (i--) n /= 10;
	return n%10;
}

/* execute program and return number of handled commands */
int solve() {
	int ptr = 0, count = 0;
	while (1) {
#define CMD		digit(ram[ptr], 2)
#define ARG1	digit(ram[ptr], 1)
#define ARG2	digit(ram[ptr], 0)
		switch (CMD) {
			case 1: return ++count;
			case 2: reg[ARG1] = ARG2; break;
			case 3: reg[ARG1] += ARG2; break;
			case 4: reg[ARG1] *= ARG2; break;
			case 5: reg[ARG1] = reg[ARG2]; break;
			case 6: reg[ARG1] += reg[ARG2]; break;
			case 7: reg[ARG1] *= reg[ARG2]; break;
			case 8: reg[ARG1] = ram[reg[ARG2]]; break;
			case 9: ram[reg[ARG2]] = reg[ARG1]; break;
			case 0: if (reg[ARG2] != 0) ptr = reg[ARG1]-1; break;
		}
		reg[ARG1] %= SIZE;
		++ptr;
		++count;
	}
}

int main() {
	bool f = true;
	int test_n;
	string s;

	cin >> test_n;

	while (cin.get() != '\n');
	while (cin.get() != '\n');

	while (test_n--) {
		/* prepare stage */
		for (int i = 0; i < SIZE; ++i)
			ram[i] = 0;
		for (int i = 0; i < 10; ++i)
			reg[i] = 0;

		/* input stage */
		for (int i = 0; ; ++i) {
			getline(cin, s);
			if (s.size() == 0)
				break;
			ram[i] = atoi(s.c_str());
		}

		if (f) f = false;
		else cout << endl;
		cout << solve() << endl;
	}

	return 0;
}

