
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
	int n;
	string s;
	cin >> n;
	for (; n--;) {
		cin >> s;
		if (s.size() > 10) {
			cout << *s.begin() << s.size()-2 << *s.rbegin() << endl;
		} else {
			cout << s << endl;
		}
	}

	return 0;
}

