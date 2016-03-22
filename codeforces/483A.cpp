
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
#define gcd __gcd

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

int main() {
	uint64 l, r;
	cin >> l >> r;
	for (uint64 a = l; a <= r; ++a)
		for (uint64 b = a; b <= r; ++b)
			for (uint64 c = b; c <= r; ++c)
				if (gcd(a, b)==1 && gcd(b, c)==1 && gcd(a, c)!=1) {
					cout << a << ' ' << b << ' ' << c;
					return 0;
				}
	cout << -1;

	return 0;
}

