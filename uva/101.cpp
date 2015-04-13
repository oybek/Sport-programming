
#include <set>
#include <map>
#include <list>
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

#define n_MAX 25

int n;
vector<int> stack[n_MAX];

pair<int, int> stack_of(int x) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < stack[i].size(); ++j)
			if (stack[i][j] == x)
				return make_pair(i, j);
	}
	assert(false);
}

void return_back(int a, int i) {
	for (int j = stack[a].size()-1; j >= i; --j) {
		stack[stack[a][j]].push_back(stack[a][j]);
		stack[stack[a][j]].pop_back();
	}
}

void move_onto(int a, int b) {
	return_back(stack_of(a).first, stack_of(a).second);
	return_back(stack_of(b).first, stack_of(b).second);
}

int main() {
	for (int i = 0; i < n_MAX; ++i)
		stack[i].reserve(n_MAX);

	while (cin >> n) {
	}

	return 0;
}

