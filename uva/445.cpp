
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
	int c, n = 0;
	while ((c = getchar()) != EOF) {
		if (isdigit(c)) {
			n += c-'0';
		} else
		if (c == 'b') {
			do {
				putchar(' ');
			} while (--n);
		} else
		if (isalpha(c) || c == '*') {
			do {
				putchar(c);
			} while (--n);
		} else
		if (c == '!') {
			putchar('\n');
		} else
		if (c == '\n') {
			putchar('\n');
		}
	}

	return 0;
}

