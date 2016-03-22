
/* Use <F5> to compile & run program */
/* file.in will be redirected to stdin */
/* in file.out you'll get program stdout */

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

template <class T> inline T SQR(T x) { return x*x; }
template <class T> inline T DIVC(T a, T b) { return a/b+(a%b?1:0); }

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	ll d = b*b - 4*a*c;

	cout << fixed << setprecision(5);
	if (d == 0) {
		cout << ((-b + sqrtl(d)) / 2 / a);
	} else
	if (d > 0) {
		cout
			<< min(((-b + sqrtl(d)) / 2 / a), ((-b - sqrtl(d)) / 2 / a)) << ' '
			<< max(((-b + sqrtl(d)) / 2 / a), ((-b - sqrtl(d)) / 2 / a)) << endl;
	}

	return 0;
}

