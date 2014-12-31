
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

typedef string::iterator si;

#define INF INT_MAX-1

#define FOR(t, i, a, b) for (t i = t(a); i != t(b); ++i)

const int sLenMax = 256;
char s[ sLenMax ];

int main() {
	float v,
		  v0;
	int hour, min, sec,
		time0, time1;

	while (fgets(s, sLenMax, stdin) != NULL) {
		if (sscanf(s, "%d:%d:%d %f", &hour, &min, &sec, &v) == 4) {
			time0 = (3600*hour + 60*min + sec);
			v0 = v;
		} else {
			time1 = (3600*hour + 60*min + sec);
			printf("%02d:%02d:%02d %.2f\n", hour, min, sec, v0*(time1-time0)/3600.0);
		}
	}

	return 0;
}

