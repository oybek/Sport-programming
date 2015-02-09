
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

using namespace std;

int A, B, C;

inline
bool is_good(int x, int y, int z) {
	return (
		x + y + z == A &&
		x * y * z == B &&
		x*x + y*y + z*z == C
	);
}

int main() {
	int test_n;
	cin >> test_n;

	while (test_n--) {
		cin >> A >> B >> C;

		bool solution_found = false;
		for (int x = -100; !solution_found && x <= 100; ++x) {
			for (int y = x+1; !solution_found && y <= 100; ++y) {
				for (int z = y+1; !solution_found && z <= 100; ++z) {
					if (is_good(x, y, z)) {
						cout	<< x << ' '
								<< y << ' '
								<< z << '\n';
						solution_found = true;
					}
				}
			}
		}

		if (!solution_found) {
			cout << "No solution.\n";
		}
	}

	return 0;
}

