
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
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
#define ALL(a) a.begin(), a.end()
#define DIVC(a, b) (a/b+(a%b?1:0))

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

int r, c;
string a[11];

bool is_eatable(int x, int y, int dx, int dy) {
	while (x >= 0 && x < r && y >= 0 && y < c) {
		if (a[x][y] == 'S')
			return 0;
		x += dx;
		y += dy;
	}
	return 1;
}

int eat(int x, int y, int dx, int dy) {
	int cnt = 0;
	while (x >= 0 && x < r && y >= 0 && y < c) {
		if (a[x][y] == '.') {
			a[x][y] = ' ';
			++cnt;
		}
		x += dx;
		y += dy;
	}
	return cnt;
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; ++i)
		cin >> a[i];

	int count = 0;
	for (int i = 0; i < r; ++i)
		if (is_eatable(i, 0, 0, 1))
			count += eat(i, 0, 0, 1);
	for (int i = 0; i < c; ++i)
		if (is_eatable(0, i, 1, 0))
			count += eat(0, i, 1, 0);
	cout << count << endl;

	return 0;
}

