
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
	int c;
	while ((c = getchar()) != EOF) {
		switch (c) {
			case 'H': case 'Q': case '9':
				puts("YES");
				return 0;
		}
	}
	puts("NO");

	return 0;
}

