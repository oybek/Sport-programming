
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
	int n, count = 0;
	cin >> n;
	while (n--) {
		int c1, c2, c3;
		cin >> c1 >> c2 >> c3;
		count += (c1+c2+c3 >= 2);
	}
	cout << count << endl;

	return 0;
}

