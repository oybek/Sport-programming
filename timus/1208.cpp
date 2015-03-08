
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
#include <unordered_map>

#define INF INT_MAX-1
#define SQR(x) ((x)*(x))

using namespace std;

#define K_MAX 19
#define parent_SIZE (K_MAX*3)

unordered_map<string, int> name2id;

class {
	private:
		int	parent[parent_SIZE],
			size[parent_SIZE];

	public:
		void init_set() {
			for (int i = 0; i < parent_SIZE; ++i) {
				parent[i] = i;
				size[i] = 1;
			}
		}

		int find_set(int x) {
			return x == parent[x] ? x : parent[x] = find_set(parent[x]);
		}

		void join_set(int x, int y) {
			size[find_set(y)] += size[find_set(x)];
			parent[find_set(x)] = parent[find_set(y)];
		}

		/* gets size of set where x located */
		int get_size(int x) {
			return size[find_set(x)];
		}
} ufds;

int K,
	command[K_MAX][3];

/*
 * returns true if commands doesn't intersect false otherwise
 */
bool is_good(int use) {
	ufds.init_set();
	for (int i = 0; i < K; ++i) {
		if ((use&(1<<i)) == 0)
			continue;

		if (ufds.get_size(command[i][0]) != 1 ||
			ufds.get_size(command[i][1]) != 1 ||
			ufds.get_size(command[i][2]) != 1)
			return false;

		ufds.join_set(command[i][0], command[i][1]);
		ufds.join_set(command[i][1], command[i][2]);
	}
	return true;
}

int count_bit(int n) {
	int count = 0;
	for (; n > 0; n >>= 1)
		count += n&1;
	return count;
}

int main() {
	int id = 0;
	string s;

	cin >> K;
	for (int i = 0; i < K; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> s;
			if (name2id.find(s) == name2id.end()) name2id[s] = id++;
			command[i][j] = name2id[s];
		}
	}

	int ans = 0;
	for (int i = 0; i < 1<<K; ++i)
		if (is_good(i))
			ans = max(count_bit(i), ans);

	cout << ans << endl;

	return 0;
}

