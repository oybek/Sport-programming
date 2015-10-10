
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct interval {
	int a, b;

	bool operator < (const interval a) const {
		return b < a.b;
	}
};

int main() {
	int N;
	vector<interval> a;

	cin >> N;
	a.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> a[i].a >> a[i].b;

	sort(a.begin(), a.end());

	int count = 1;
	interval last = a[0];
	for (int i = 1; i < N; ++i) {
		if (last.b+1 <= a[i].a) {
			last = a[i];
			++count;
		}
	}

	cout << count << endl;

	return 0;
}

