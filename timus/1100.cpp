
#include <map>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define repeat(a) for (int i_ = 0; i_ < (a); ++i_)
#define whole(a) a.begin(), a.end()

using namespace std;

struct res {
	int n, m;

	friend bool operator < (const res & a1, const res & a2) {
		return a1.m > a2.m;
	}
};

int main() {
	int size;
	cin >> size;

	res * v = new res [size];
	for (int i = 0; i < size; ++i)
		cin >> v[i].n >> v[i].m;

	stable_sort(v, v+size);

	for (int i = 0; i < size; ++i)
		cout << v[i].n << ' ' << v[i].m << endl;


	return 0;
}

