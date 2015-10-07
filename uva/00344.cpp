
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

const int arabar[]  = {  1,   4,    5,   9,    10,  40,  50,   90,  100, 400,  500, 900,  1000};
const char *romanar[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

char * arab2roman(unsigned short int arab) {
	static char roman[80];
	const int
		m = sizeof (arabar)/sizeof (int)-1,
		arabmax=arabar[m];
	const char romanmax=romanar[m][0];
	int i, n;
	if (!arab) {
		*roman=0;
		return roman;
	}
	i = 0;
	while (arab > arabmax) {
		roman[i++] = romanmax;
		arab -= arabmax;
	}
	n = m;
	while (arab > 0) {
		if (arab >= arabar[n]) {
			roman[i++] = romanar[n][0];
			if (n&1)
				roman[i++] = romanar[n][1];
			arab -= arabar[n];
		} else
			n--;
	}
	roman[i] = 0;
	return roman;
}

#define n_MAX 101
int i[n_MAX], v[n_MAX], x[n_MAX], l[n_MAX], c[n_MAX];

void count(int n, int & i, int & v, int & x, int & l, int & c) {
}

int main() {

	return 0;
}

