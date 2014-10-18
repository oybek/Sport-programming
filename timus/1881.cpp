
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main() {
	int h, w, n;
	cin >> h >> w >> n;

	int csn = 0; /* length of current string */
	int sn = 0; /* number of strings */

	while (n--) {
		string t;
		cin >> t;

		if (csn + int(t.size()) < w) {
			csn += t.size()+1;
		} else
		if (csn + int(t.size()) == w) {
			++sn;
			csn = 0;
		} else
		if (csn + int(t.size()) > w) {
			++sn;
			csn = 0;
			if (csn + int(t.size()) < w) {
				csn += t.size()+1;
			} else
			if (csn + int(t.size()) == w) {
				++sn;
				csn = 0;
			}
		}
	}

	if (csn > 0)
		++sn;

	cout << sn/h + (sn % h ? 1: 0) << endl;

	return 0;
}

