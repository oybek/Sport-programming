
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
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

const int size = 10;
int c[size];

int main() {
	int t;
	for (int i = 0; i < 6; ++i) {
		cin >> t;
		++c[t];
	}
	if (find(c, c+size, 4) < c+size) {
		if (find(c, c+size, 2) < c+size) {
			cout << "Elephant";
		} else {
			cout << "Bear";
		}
	} else
	if (find(c, c+size, 5) < c+size) {
		cout << "Bear";
	} else
	if (find(c, c+size, 6) < c+size) {
		cout << "Elephant";
	} else {
		cout << "Alien";
	}

	return 0;
}

