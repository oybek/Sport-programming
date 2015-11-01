
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

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

int main() {
	int n, cap = 0, cur = 0;
	cin >> n;
	while (n--) {
		int in, out;
		cin >> out >> in;

		cur -= out;
		cur += in;

		cap = max(cur, cap);
	}
	cout << cap << endl;

	return 0;
}

