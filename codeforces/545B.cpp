
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
	int cnt = 0, ind = 0;
	string s[2];

	cin >> s[0] >> s[1];
	for (int i = 0; i < s[0].size(); ++i)
		cnt += (s[0][i]!=s[1][i]);
	if (cnt%2)
		cout << "impossible";
	else {
		for (int i = 0; i < s[0].size(); ++i) {
			cout << s[ind][i];
			if (s[0][i] != s[1][i])
				ind = !ind;
		}
	}

	return 0;
}

