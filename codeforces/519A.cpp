
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

int w[256];

int main() {
	w['Q'] = w['q'] = 9;
	w['R'] = w['r'] = 5;
	w['B'] = w['b'] = 3;
	w['N'] = w['n'] = 3;
	w['P'] = w['p'] = 1;

	int c, s1 = 0, s2 = 0;
	while ((c = getchar()) != EOF)
		if (isalpha(c)) {
			if (isupper(c)) {
				s1 += w[c];
			} else {
				s2 += w[c];
			}
		}
	cout << (s1 == s2 ? "Draw" : s1 < s2 ? "Black" : "White");

	return 0;
}

