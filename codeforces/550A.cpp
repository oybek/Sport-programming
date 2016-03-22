
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

template <class iteratorT>
void show(string s, iteratorT a, iteratorT b) {
	cout << s << ':';
	for (; a != b; ++a)
		cout << ' ' << *a;
	cout << endl;
}

int main() {
	string s, t;
	string::size_type pos;

	cin >> t;

	s = t;
	if ((pos = s.find("AB")) != string::npos) {
		s[pos] = s[pos+1] = ' ';
		if (s.find("BA") != string::npos) {
			cout << "YES";
			return 0;
		}
	}
	s = t;
	if ((pos = s.find("BA")) != string::npos) {
		s[pos] = s[pos+1] = ' ';
		if (s.find("AB") != string::npos) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";

	return 0;
}

