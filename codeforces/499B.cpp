
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
#include <unordered_map>
#include <vector>

#define INF 1000000001
#define SQR(x) ((x)*(x))
#define ALL(a) a.begin(), a.end()
#define DIVC(a, b) (a/b+(a%b?1:0))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

template <class iteratorT>
void show(string s, iteratorT a, iteratorT b) {
	cout << s << ':';
	for (; a != b; ++a)
		cout << ' ' << *a;
	cout << endl;
}

int main() {
	int n, m;
	string s1, s2;
	unordered_map<string, string> dict;

	cin >> n >> m;
	while (m--) {
		cin >> s1 >> s2;
		dict[s1] = s2;
	}

	while (n--) {
		cin >> s1;
		cout << min(s1, dict[s1], [](const string & s1, const string & s2) {
			return s1.size() < s2.size();
		}) << ' ';
	}

	return 0;
}

