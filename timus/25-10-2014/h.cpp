
#include <iostream>
using namespace std;

int sum(int v, int k) {
	int sum = v, s = k;
	while (s <= v) {
		sum += v/s;
		s *= k;
	}
	return sum;
}

int main() {
	int n, k, v, s, sp;
	cin >> n >> k;

	if (k >= n) {
		cout << n << endl;
		return 0;
	}

	int u = 1, w = n;
	while (u <= w) {
		v = (u+w) >> 1;
		v += (u+w)&1;

		s = sum(v, k);
		sp = sum(v-1, k);

		if (s >= n) {
			if (sp < n) {
				cout << v << endl;
				break;
			} else {
				w = v-1;
			}
		} else {
			u = v+1;
		}
	}

	return 0;
}

