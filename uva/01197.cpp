
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

#define INF 1000000001
#define SQR(x) ((x)*(x))

#define n_MAX 30001
#define m_MAX 501

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

class ufds_t {
	private:
		int parent[n_MAX],
			set_size[n_MAX];

	public:
		void init(int n = n_MAX-1) {
			for (int i = 0; i <= n; ++i) {
				parent[i] = i;
				set_size[i] = 1;
			}
		}

		int find(int x) {
			return x == parent[x] ? x : parent[x] = find(parent[x]);
		}

		void join(int x, int y) {
			x = find(x);
			y = find(y);
			if (x == y) {
				return;
			} else {
				parent[x] = parent[y];
				set_size[x] += set_size[y];
				set_size[y] = set_size[x];
			}
		}

		int size(int n) {
			return set_size[find(n)];
		}
};

ufds_t ufds;
int n, m;

int main() {
	for (;;) {
		cin >> n >> m;
		if (!n && !m)
			break;

		ufds.init(n);

		while (m--) {
			int first, a;
			cin >> a >> first;
			while (--a) {
				int b;
				cin >> b;
				ufds.join(first, b);
			}
		}

		cout << ufds.size(0) << endl;
	}

	return 0;
}

