
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
	int n;
	cin >> n;
	switch (n) {
		case 1:
			puts("88");
			break;
		case 2:
			puts("68 88");
			break;
		case 3:
			puts("06 68 88");
			break;
		case 4:
			puts("16 06 68 88");
			break;
		default:
			puts("Glupenky Pierre");
			break;
	}

	return 0;
}

