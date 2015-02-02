
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

inline void DEBUG(bool cond, const char * msg) {
#ifdef DO_DEBUG
	if (cond) {
		std::cerr << msg << '\n';
		exit(0);
	}
#endif
}

#define INF INT_MAX-1
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

#define N_MAX 21

int N, M;
uint64 fact[N_MAX];

int main() {
	fact[0] = 1;
	for (int i = 1; i < N_MAX; ++i)
		fact[i] = fact[i-1]*static_cast<uint64>(i);

	while (cin >> N >> M)
		cout << fact[N]+fact[M] << endl;

	return 0;
}

