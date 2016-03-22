
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
#include <numeric>
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
	int n, c = 1;
	string s1, s2;
	cin >> n >> s1;
	for (; --n; s1 = s2) {
		cin >> s2;
		if (s2[0] == s1[1])
			++c;
	}
	cout << c;

	return 0;
}

