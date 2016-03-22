
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

int main() {
	int n, a[51], sum1 = 0, sum2 = 0;
	string s;

	cin >> n >> s;

	for (int i = 0; i < n/2; ++i) {
		sum1 += s[i]-'0';
		sum2 += s[n-1-i]-'0';
	}

	cout << (count_if(s.begin(), s.end(), [](char c) {
			return c=='4'||c=='7';
		}) == n && sum1 == sum2 ? "YES" : "NO");

	return 0;
}

