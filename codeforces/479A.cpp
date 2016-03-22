
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
	int a, b, c, ans = 0;
	cin >> a >> b >> c;

	ans = max(ans, a+b+c);
	ans = max(ans, a+b*c);
	ans = max(ans, a*b+c);
	ans = max(ans, a*b*c);
	ans = max(ans, (a+b)*c);
	ans = max(ans, a*(b+c));

	cout << ans;

	return 0;
}

