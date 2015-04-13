
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

#define a_size_MAX 101

struct person {
	int v, u, w;
};

int a_size;
person a[a_size_MAX];
bitset<a_size_MAX> good;

int main() {
	while (cin >> a_size) {
		for (int i = 0; i < a_size; ++i)
			cin >> a[i].v >> a[i].u >> a[i].w;

		for (int i = 0; i < a_size; ++i) {
			for (int j = 0; j < a_size; ++j)
				good[j] = true;

			for (int j = 0; j < a_size; ++j)
				if (a[j].v < a[i].v)
					good[j] = 0;
			for (int j = 0; j < a_size; ++j)
				if (a[j].u < a[i].u)
					good[j] = 0;
			for (int j = 0; j < a_size; ++j)
				if (a[j].w < a[i].w)
					good[j] = 0;

			cout << (good.count() == 1 ? "Yes" : "No") << endl;
		}
	}

	return 0;
}

