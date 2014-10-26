
#include <vector>
#include <bitset>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 10000

vector<int> g[ MAX_N+1 ];
bitset<MAX_N+1> visited;

int dfs_count(int cur) {
	if (visited[cur])
		return 0;

	visited[cur] = true;
	int s = 1;
	for (int i = 0; i < int(g[cur].size()); ++i)
		s += dfs_count(g[cur][i]);

	return s;
}

int main() {
	int tt;
	cin >> tt;

	while (tt--) {
		int n, m, l, x, y, z, ans;

		cin >> n >> m >> l;

		for (int i = 0; i < n; ++i)
			g[i].resize(0);
		visited.reset();

		while (m--) {
			cin >> x >> y;
			g[x].push_back(y);
		}

		ans = 0;
		while (l--) {
			cin >> z;
			ans += dfs_count(z);
		}

		cout << ans << endl;
	}

	return 0;
}

