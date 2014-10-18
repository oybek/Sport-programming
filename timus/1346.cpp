
#include <cmath>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define UNDEF 2
#define DOWN 1
#define UP 0

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	int8_t		dir = 2;
	int32_t		a, b, size, cur, prv, n = 1;

	std::cin >> a >> b;

	std::cin >> prv;
	std::cin >> cur;

	while () {
		yold = y;
		std::cin >> y;

		if (dir == UNDEF) {
			if (y < yold) {
				dir = DOWN;
			} else 
			if (y > yold) {
				dir = UP;
			}
		} else {
			if (y < yold) {
				if (dir == UP) {
					++n;
					dir = DOWN;
				}
			} else
			if (y > yold) {
				if (dir == DOWN) {
					++n;
					dir = UP;
				}
			}
		}
	}

	std::cout << n << std::endl;


	return 0;
}

