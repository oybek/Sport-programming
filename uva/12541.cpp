
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

struct person {
	string name;
	int d, m, y;

	bool operator < (const person & a) const {
		if (y != a.y)
			return y < a.y;
		if (m != a.m)
			return m < a.m;
		return d < a.d;
	}
};

int main() {
	int N;
	vector<person> p;

	cin >> N;
	p.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> p[i].name >> p[i].d >> p[i].m >> p[i].y;

	sort(p.begin(), p.end());
	cout	<< p.rbegin()->name << endl
			<< p.begin()->name << endl;

	return 0;
}

