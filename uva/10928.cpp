
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

#define INF INT_MAX-1
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

#define P_MAX 1001

int P;
pair<int, int> neighbour[P_MAX];
string s;

int count_degree(const string & s) {
	int nn = 0;

	for (string::const_iterator it = s.begin(); it < s.end(); ++it) {
		if (isdigit(*it)) {
			++nn;
			for (++it; it < s.end() && isdigit(*it); ++it);
		}
	}
	return nn;
}

int main() {
	int test_n;
	cin >> test_n;

	while (test_n--) {
		cin >> P;
		getline(cin, s);

		for (int i = 0; i < P; ++i) {
			getline(cin, s);
			neighbour[i] = make_pair(count_degree(s), i+1);
		}

		sort(neighbour, neighbour+P);

		cout << neighbour[0].second;
		for (int i = 1; i < P && neighbour[i].first == neighbour[i-1].first; ++i) {
			cout << ' ' << neighbour[i].second;
		}
		cout << endl;
	}

	return 0;
}

