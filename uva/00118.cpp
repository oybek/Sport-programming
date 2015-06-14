
#include <cstdio>
#include <iostream>
using namespace std;

#define MAX_SIZE 150

const char s[] = "NESW";

int rown, coln;
int a[ MAX_SIZE ][ MAX_SIZE ];
char com[ 128 ];

struct robot {
	int x, y, dir;
};

int main() {
	char t;
	bool lost;
	robot rob;

	scanf("%d%d", &rown, &coln);
	while (scanf("%d%d%c", &rob.x, &rob.y, &t) != EOF) {
		lost = false;

		scanf("%s", com);

		for (rob.dir = 0; s[ rob.dir ] != t; ++rob.dir);
		for (char * c = com; *c; ++c) {
			if (*c == 'F') {
				if (a[ rob.x ][ rob.y ]) {
					switch (s[ rob.dir ]) {
						case 'N':
							if (++rob.x >= rown) --rob.x;
							break;
						case 'S':
							if (--rob.x <  0) ++rob.x;
							break;
						case 'E':
							if (++rob.y >= coln) --rob.y;
							break;
						case 'W':
							if (--rob.y <  0) ++rob.y;
							break;
					}
				} else {
					switch (s[ rob.dir ]) {
						case 'N':
							if (++rob.x >= rown) lost = 1, --rob.x;
							break;
						case 'S':
							if (--rob.x <  0) lost = 1, ++rob.x;
							break;
						case 'E':
							if (++rob.y >= coln) lost = 1, --rob.y;
							break;
						case 'W':
							if (--rob.y <  0) lost = 1, ++rob.y;
							break;
					}
					if (lost) {
						a[ rob.x ][ rob.y ] = 1;
						printf("%d %d %c LOST\n", rob.x, rob.y, s[ rob.dir ]);
						break;
					}
				}
			} else {
				rob.dir = (*c == 'R' ? rob.dir+1 : rob.dir-1);
				if (rob.dir >= 4) rob.dir -= 4;
				if (rob.dir <  0) rob.dir += 4;
			}
		}

		if (!lost) {
			printf("%d %d %c\n", rob.x, rob.y, s[ rob.dir ]);
		}
	}

	return 0;
}

