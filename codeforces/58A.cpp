
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
	string w = "hello", s;
	cin >> s;
	int j = 0;
	for (int i = 0; i < int(s.size()); ++i)
		if (s[i] == w[j])
			++j;
	cout << (j == 5 ? "YES" : "NO") <<endl;

	return 0;
}

