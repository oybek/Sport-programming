
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

#define N_MAX 100001
#define Q_MAX 100001

class Ufds {
	private:
		int count, size, parent[N_MAX];

	public:
		void init(int sz) {
			count = size = sz;
			for (int i = 0; i < size; ++i)
				parent[i] = i;
		}

		int find(int x) {
			return x == parent[x] ? x : parent[x] = find(parent[x]);
		}

		int ds_num() {
			return count;
		}

		void join(int x, int y) {
			if (find(x) != find(y)) {
				--count;
				parent[find(x)] = parent[find(y)];
			}
		}
};

int N, M, Q;
bitset<N_MAX> sign;
vector<pair<int, int> > a;
vector<int> q, ans;
Ufds ufds;

void solve() {
	vector<int> ans;
	for (int i = q.size()-1; i >= 0; --i) {
		ans.push_back(ufds.ds_num());
		ufds.join(a[q[i]].first, a[q[i]].second);
	}
	for (int i = ans.size()-1; i >= 0; --i)
		cout << ans[i] << ' ';
	cout << endl;
}

int main() {
	q.reserve(Q_MAX);
	ans.reserve(Q_MAX);

	cin >> N >> M;

	ufds.init(N);
	a.resize(M);

	for (int i = 0; i < M; ++i)
		cin >> a[i].first >> a[i].second;

	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int t;
		cin >> t;
		q.push_back(t-1);
		sign.set(t-1);
	}

	for (int i = 0; i < M; ++i)
		if (!sign[i])
			ufds.join(a[i].first, a[i].second);

	solve();

	return 0;
}

