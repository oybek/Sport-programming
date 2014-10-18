
#include <bitset>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

#define SIZE 64

int w, h;
char a[ SIZE ][ SIZE ];

class erase_dot_ {
	bitset<SIZE> sign[ SIZE ];
	public:
		void sign_reset() {
			for (int i = 0; i < SIZE; ++i)
				sign[i].reset();
		}

		void operator()(int x, int y) {
			if (x < 0 ||
				y < 0 ||
				x >= h ||
				y >= w ||
				a[x][y] != 'X')
				return;
			a[x][y] = '.';
		}
} erase_dot;

class count_dots_ {
	bitset<SIZE> sign[ SIZE ];
	public:
		int operator()(int x, int y) {
			if (x < 0 ||
				y < 0 ||
				x >= h ||
				y >= w ||
				a[x][y] == '.')
				return 0;

			if (a[x][y] == '*') {
			}
		}
} count_dots;

int main() {
	int tt = 1;
	vector<int> ans;

	for (;; ++tt) {
		scanf("%d%d", &w, &h);
		if (!w && !h)
			break;

		for (int i = 0; i < h; ++i)
			scanf("%s", a[i]);

		for (int x = 0; x < h; ++x)
			for (int y = 0; y < w; ++y)
				ans.push_back(count_dots(x, y));
	}

	return 0;
}

