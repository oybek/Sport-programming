
#include <string>
#include <iostream>

namespace local {
	using namespace std;

	int getDeep(const string & s) {
		int sLen = s.size(), maxDeep, d, i;

		if (sLen == 0) {
			maxDeep = 0;
		} else {
			maxDeep = d = 0;
			for (i = 0; i < sLen; ++i) {
				switch (s[i]) {
					case '(': ++d; break;
					case ')': --d; break;
				}
				maxDeep = max(maxDeep, d);
			}
		}

		return maxDeep;
	}

	static int a[16];

	void genExp(string & s, int n, int k, int pt) {
		if (n == 0) {
			//cout << s << ' ' << getDeep(s) << endl;
			++a[getDeep(s)];
		} else {

			if (n-1 >= k+1) {
				s[pt] = '(';
				pt++;

				genExp(s, n-1, k+1, pt);
				pt--;
			}

			if ( k > 0 ) {
				s[pt] = ')';
				pt++;

				genExp(s, n-1, k-1, pt);
				pt--;
			}
		}
	}
}

int main() {
	using namespace local;

	const int size = 30;
	string s; s.resize(size);
	genExp(s, size, 0, 0);

	for (int i = 1; i < 16; ++i) {
		cout << i << ' ' << a[i] << endl;
	}

	return 0;
}

