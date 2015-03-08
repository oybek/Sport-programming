
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
typedef unsigned int uint32;
typedef long long int64;

using namespace std;

#define N_MAX 91

int N;
list<int> G[N_MAX];
list<uint32> hosts[N_MAX];

uint32 compute(const string & s1, const string & s2) {
	uint32 x, y, b[4];

	sscanf(s1.c_str(), "%u.%u.%u.%u", b, b+1, b+2, b+3);
	x = b[0] + (b[1]<<8) + (b[2]<<16) + (b[3]<<24);

	sscanf(s2.c_str(), "%u.%u.%u.%u", b, b+1, b+2, b+3);
	y = b[0] + (b[1]<<8) + (b[2]<<16) + (b[3]<<24);

	return x&y;
}

bool is_connected(const int i, const int j) {
	for (list<uint32>::iterator it = hosts[i].begin(); it != hosts[i].end(); ++it)
		for (list<uint32>::iterator jt = hosts[j].begin(); jt != hosts[j].end(); ++jt)
			if (*it == *jt)
				return true;
	return false;
}

void build_graph() {
	for (int i = 0; i < N; ++i)
		for (int j = i+1; j < N; ++j)
			if (is_connected(i, j)) {
				G[i].push_back(j);
				G[j].push_back(i);
			}
}

string bfs(int a, int b) {
	bitset<N_MAX> was;
	queue<pair<int, string> > Q;

	Q.push(make_pair(a, to_string(a+1)));

	while (!Q.empty()) {
		pair<int, string> cur = Q.front(); Q.pop();

		if (cur.first == b) {
			return cur.second;
		}

		for (list<int>::iterator it = G[cur.first].begin(); it != G[cur.first].end(); ++it)
			if (!was[*it]) {
				was[*it] = true;
				Q.push(make_pair(*it, cur.second + " " + to_string(*it+1)));
			}
	}

	return "";
}

int main() {
	int K, x, y;
	string s1, s2, ans;

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> K;
		while (K--) {
			cin >> s1 >> s2;
			hosts[i].push_back(compute(s1, s2));
		}
	}
	build_graph();

	cin >> x >> y; --x, --y;
	cout << ((ans = bfs(x, y)).size() == 0 ? "No" : "Yes\n" + ans) << endl;

	return 0;
}

