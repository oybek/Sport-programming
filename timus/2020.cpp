
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
	string s1, s2;

	cin >> s1
		>> s2;

	int i = 0, j = 0, count = 0;
	while (i < s1.size() && j < s2.size()) {
		if (s1[i] == 'L') {
			if (s2[j] != 'L') {
				++j;
				++count;
			} else {
				++i, ++j;
				++count;
			}
		} else {
			if (s2[j] == 'L') {
				++i;
				++count;
			} else {
				++i, ++j;
				++count;
			}
		}
	}

	count += s1.size()-i;
	count += s2.size()-j;

	cout << count << endl;

	return 0;
}

