
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

#define DEG_PER_HOUR	30
#define DEG_PER_MIN		6

int main() {
	int h, m;
	while (1) {
		scanf("%d:%d", &h, &m);

		if (!h && !m)
			break;

		h %= 12;
		float t = abs(h*DEG_PER_HOUR + m/2.0 - m*DEG_PER_MIN);
		printf("%.3f\n", min(t, 360.0f-t));
	}

	return 0;
}

