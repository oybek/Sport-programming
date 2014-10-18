
#include <iostream>
using namespace std;

enum { PETYA, TAXI };

int main() {
	int x, dx, y, dy;
	bool who = TAXI, tfirst = true, pfirst = true;

	cin >> x >> dx >> y >> dy;

	while (1) {
		switch (who) {
			case PETYA:
				if (y < x) {
					cout << y << endl;
					return 0;
				} else {
					who = TAXI;
					if (pfirst) {
						pfirst = 0;
					} else {
						x += dx;
					}
				}
			break;

			case TAXI:
				if (x > y) {
					cout << x << endl;
					return 0;
				} else {
					who = PETYA;
					if (tfirst) {
						tfirst = 0;
					} else {
						y -= dy;
					}
				}
			break;
		}
	}

	return 0;
}

