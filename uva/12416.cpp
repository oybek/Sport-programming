
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

#define INF 1000000001
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

int main() {
	int c, n_max = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			int n = 1;
			while (((c = getchar()) != EOF) && (c == ' '))
				++n;
			n_max = max(n_max, n);
			if (c == '\n') {
				cout << ceill(log2l(n_max)) << endl;
				n_max = 0;
			}
		} else
		if (c == '\n') {
			cout << ceill(log2l(n_max)) << endl;
			n_max = 0;
		}
	}
	return 0;
}

