
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

#define N_MAX 100001

typedef long long int64;

int N;
int64 a[N_MAX];

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> a[i];

	struct {
		int i;
		int64 k;
	} min;

	min.i = 0;
	min.k = llabs(a[1]-a[0]);
	for (int i = 1; i < N-1; ++i)
		if (llabs(a[i+1]-a[i]) > min.k) {
			min.k = llabs(a[i+1]-a[i]);
			min.i = i;
		}

	cout << min.i+1 << ' ' << min.i+1+1 << endl;

	return 0;
}

