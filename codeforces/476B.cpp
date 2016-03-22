
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

int truepath_n, allpath_n, p1;
string s1, s2;

int backtrack(int p2, int i) {
	if (i == s2.size()) {
		return p1 == p2;
	}

	switch (s2[i]) {
		case '-' : return backtrack(p2-1, i+1);
		case '+' : return backtrack(p2+1, i+1);
		case '?' : return backtrack(p2+1, i+1) + backtrack(p2-1, i+1);
	}
}

int main() {
	cin >> s1 >> s2;

	p1 = count(s1.begin(), s1.end(), '+')
		- count(s1.begin(), s1.end(), '-');
	allpath_n = 1 << count(s2.begin(), s2.end(), '?');
	truepath_n = backtrack(0, 0);

	cout << fixed << setprecision(9) << (double)truepath_n/allpath_n << endl;

	return 0;
}

