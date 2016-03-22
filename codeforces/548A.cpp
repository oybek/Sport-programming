
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

bool is_pal(const string & s, int i, int j) {
#ifdef DEBUG
	cout << endl;
#endif
	while (i < j) {
#ifdef DEBUG
		cout << s[i] << ' ' << s[j] << endl;
#endif
		if (s[i] != s[j])
			return false;
		++i, --j;
	}
	return true;
}

int main() {
	int k;
	string s;
	cin >> s >> k;

	int l = s.size()/k;

	if (s.size()%k != 0) {
		cout << "NO";
		return 0;
	}

	for (int i = 0; i < s.size(); i += l)
		if (!is_pal(s, i, i+l-1)) {
			cout << "NO";
			return 0;
		}
	cout << "YES";

	return 0;
}

