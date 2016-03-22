
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define INF 1000000001
#define SQR(x) ((x)*(x))
#define ALL(a) a.begin(), a.end()
#define DIVC(a, b) (a/b+(a%b?1:0))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

int n, t, cnt[6];
int main() {
	cin >> n;
	while (n--) {
		cin >> t;
		++cnt[t];
	}
	if (cnt[0] > 0) {
		if (cnt[5]/9 > 0) {
			cout << string(cnt[5]-cnt[5]%9, '5') << string(cnt[0], '0');
		} else {
			cout << "0";
		}
	} else {
		cout << "-1";
	}

	return 0;
}

