
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
#include <numeric>
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
	string names[5] = { "Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };

	int n;
	cin >> n; --n;
	for (; n > 4; n /= 2)
		n -= 5;
	cout << names[n] << endl;

	return 0;
}

