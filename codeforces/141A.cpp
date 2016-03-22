
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define INF 1000000001
#define SQR(x) ((x)*(x))
#define all(a) a.begin(), a.end()

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

template <class iteratorT>
void show(string s, iteratorT a, iteratorT b) {
	cout << s << ':';
	for (; a != b; ++a)
		cout << ' ' << *a;
	cout << endl;
}

const int size = 256;
int c1[size], c2[size], c3[size];
string s1, s2, s3;

bool check() {
	for (int i = 0; i < size; ++i)
		if (c3[i] != c1[i]+c2[i])
			return false;
	return true;
}

int main() {
	cin >> s1 >> s2 >> s3;
	for (char c : s1) ++c1[c];
	for (char c : s2) ++c2[c];
	for (char c : s3) ++c3[c];
	cout << (check() ? "YES" : "NO");

	return 0;
}

