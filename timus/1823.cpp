
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

#define R 8.314

using namespace std;

int main() {
	char c, ignore;
	double val['z'];

	val['p'] = val['n'] = val['T'] = val['V'] = -1.0;

	cin	>> c; cin >> ignore >> val[c];
	cin	>> c; cin >> ignore >> val[c];
	cin	>> c; cin >> ignore >> val[c];

	cout << fixed << setprecision(6);
	if (val['p'] < 0.0) {
		if (val['V'] == 0) {
			cout << "error\n";
		} else {
			cout << "p = " << R*val['T']*val['n']/val['V'] << endl;
		}
	} else
	if (val['n'] < 0.0) {
		if (val['T'] == 0) {
			cout << "error\n";
		} else {
			cout << "n = " << val['p']*val['V']/R/val['T'] << endl;
		}
	} else
	if (val['T'] < 0.0) {
		if (val['n'] == 0) {
			cout << "error\n";
		} else {
			cout << "T = " << val['p']*val['V']/R/val['n'] << endl;
		}
	} else
	if (val['V'] < 0.0) {
		if (val['p'] == 0) {
			cout << "error\n";
		} else {
			cout << "V = " << R*val['T']*val['n']/val['p'] << endl;
		}
	} else {
		assert(false);
	}

	return 0;
}

