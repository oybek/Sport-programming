
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

template <int SIZE>
class ufds {
	private:
		int parent[SIZE];

	public:
		ufds() {
			reset();
		}

		void reset() {
			for (int i = 0; i < SIZE; ++i)
				parent[i] = i;
		}

		int find(int x) {
			return x == parent[x] ? x : parent[x] = find(parent[x]);
		}

		void join(int x, int y) {
			parent[find(x)] = parent[find(y)];
		}

		bool joint(int x, int y) {
			return find(x) == find(y);
		}
};

#define SIZE 256

ufds<SIZE> set1, set2;

string solve() {
	for (int i = 0; i < SIZE; ++i)
		for (int j = i+1; j < SIZE; ++j)
			if (set1.joint(i, j) != set2.joint(i, j))
				return "NO";
	return "YES";
}

int main() {
	bool f = true;
	int test_n, A, B;
	char x, y;

	cin >> test_n;
	while (test_n--) {
		/* init */
		set1.reset();
		set2.reset();

		/* input */
		cin >> A;
		while (A--) {
			cin >> x >> y;
			set1.join(x, y);
		}

		cin >> B;
		while (B--) {
			cin >> x >> y;
			set2.join(x, y);
		}

		/* solve */
		if (f) f = false;
		else cout << endl;
		cout << solve() << endl;
	}

	return 0;
}

