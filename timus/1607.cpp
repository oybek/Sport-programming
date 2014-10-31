
#include <iostream>
using namespace std;

enum { PETYA, TAXI };

int main() {
	int x, dx, y, dy;
	int taxi = true;
	/*bool tfirst = true, pfirst = true;*/

	bool tf = true, pf = true;
	cin >> x >> dx >> y >> dy;

	while (1) {
		if (taxi) {
			if (x >= y) {
				cout << x;
				return 0;
			} else {
				if (tf) tf = false;
				else y -= dy;
			}
		} else {
			if (y <= x) {
				cout << y;
				return 0;
			} else {
				if (pf) pf = false;
				else x += dx;
			}
		}
		taxi = !taxi;
	}

	return 0;
}

