
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 500000

int main() {
	int N, a[ MAXN ];
	cin >> N;
	assert(N <= MAXN);

	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}

	sort(a, a+N);

	int max_len = 0, n, len = 1, cur = a[0];

	for (int i = 1; i < N; ++i) {
		if (a[i] != cur) {
			if (len > max_len) {
				max_len = len;
				n = cur;
			}
			cur = a[i];
			len = 1;
		} else {
			++len;
		}
	}

	if (len > max_len) {
		max_len = len;
		n = cur;
	}

	cout << n << endl;

	return 0;
}

