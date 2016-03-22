
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
	int n;
	cin >> n;
	switch (n) {
		case 1:
			cout << "1\n1";
			break;
		case 2:
			cout << "1\n1";
			break;
		case 3:
			cout << "2\n1 3";
			break;
		default:
			cout << n << endl;
			for (int i = (n%2 ? n : n-1); i >= 1; i -= 2)
				cout << i << ' ';
			for (int i = (n%2 ? n-1 : n); i >= 2; i -= 2)
				cout << i << ' ';
			break;
	}

	return 0;
}

