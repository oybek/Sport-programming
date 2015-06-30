
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

#define N_MAX 100045
int generator[N_MAX];

int digit_sum(int n) {
	int s = 0;
	for (; n > 0; n /= 10)
		s += n%10;

	return s;
}

int main() {
	for (int i = N_MAX-1; i >= 0; --i)
		generator[i+digit_sum(i)] = i;

	int test_n;
	cin >> test_n;
	while (test_n--) {
		int n;
		cin >> n;
		cout << generator[n] << endl;
	}

	return 0;
}

