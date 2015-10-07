
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

#define INF 1000000001
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

#define SIZE 10000000
#define MODULO 1000000009

struct triple {
	uint64 x, y, z;

	triple(uint64 ax, uint64 ay, uint64 az)
		: x(ax)
		, y(ay)
		, z(az)
	{}

	bool operator < (const triple & arg) const {
		return (x == arg.x)
				? (y == arg.y ? z < arg.z : y < arg.y)
				: (x < arg.x);
	}
};

map<triple, int> was;
uint64 trib[SIZE] = { 0, 1, 2 };

int main() {
	was[ triple(0, 1, 2) ] = 0;

	for (int i = 3; i < SIZE; ++i) {
		if (was.find(triple(trib[i-1], trib[i-2], trib[i-3])) != was.end()) {
			printf("offset: %d\n", was.find(triple(trib[i-1], trib[i-2], trib[i-3]))->second);
		}
		trib[i] = (trib[i-1] + trib[i-2] + trib[i-3]) % MODULO;
		was[triple(trib[i-1], trib[i-2], trib[i-3])] = i-3;
	}

	return 0;
}

