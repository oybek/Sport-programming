
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

int n;
pair<int, string> cnt[3];

int main() {
	cnt[0].second = "chest";
	cnt[1].second = "biceps";
	cnt[2].second = "back";

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		cnt[i%3].first += t;
	}
	cout << max(max(cnt[0], cnt[1]), cnt[2]).second;

	return 0;
}

