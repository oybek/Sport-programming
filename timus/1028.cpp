
#include <iostream>
using namespace std;

struct coord {
	uint32_t x, y;
	friend bool operator<= (const coord & o1, const coord & o2);
};

bool operator<= (const coord & o1, const coord & o2) {
	if ((o1.x <= o2.x) && (o1.y <= o2.y))
		return true;
	else
		return false;
}

int main() {
	uint32_t n;
	cin >> n;

	uint32_t		* level	= new uint32_t [n];
	coord			* star	= new coord [n];

	for (int i = 0; i < n; ++i)
		cin >> star[i].x >> star[i].y;

	level[0] = 1;
	for (int i = 0; i < n; ++i) {

		int lev = 0;
		bool flag = 0;

		for (int j = 0; j < n; ++j)
			if ((i != j) && star[j] <= star[i]) {
				++lev;
				flag = 1;
			}

		if (flag)
			++level[lev];
	}

	for (int i = 0; i < n; ++i)
		cout << level[i] << endl;

	return 0;
}

