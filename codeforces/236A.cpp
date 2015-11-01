
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

#define size 256
int a[size];

int main() {
	for (int c; isalpha(c = getchar()); a[c] = 1);
	cout << (accumulate(a, a+size, 0)%2 ? "IGNORE HIM!" : "CHAT WITH HER!") << endl;

	return 0;
}

