
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

int main() {
	int test_n;
	cin >> test_n;

	while (test_n--) {
		int a, b, c;
		cin >> a >> b >> c;

		if ((a+b > c) && (a+c > b) && (b+c > a)) {
			cout << "OK\n";
		} else {
			cout << "Wrong!!\n";
		}
	}

	return 0;
}

