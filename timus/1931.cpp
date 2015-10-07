
#include <iostream>
#include <algorithm>
using namespace std;

#define n_MAX 100001

int cmpn[n_MAX], n, a[n_MAX];

int max(int * a, int size) {
	int ans = 0;
	for (int i = 1; i < size; ++i)
		if (a[i] > a[ans])
			ans = i;
	return ans;
}

int main() {
	cin >> n;
	int cur;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	cur = 0;
	for (int i = 1; i < n; ++i) {
		++cmpn[cur];
		++cmpn[i];
		if (a[cur] > a[i])
			cur = i;
	}

	cout << max(cmpn, n)+1 << endl;

	return 0;
}

