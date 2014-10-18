
#include <iostream>

struct coord {
	int x, y;
};

int main() {
	using namespace std;

	int dot_num;
	cin >> dot_num;

	coord * dot = new coord [dot_num];

	for (int i = 0; i < dot_num; ++i) {
		cin >> dot[i].x >> dot[i].y;
	}

	int max = 0;
	for (int i = 0; i < dot_num; ++i) {
		for (int j = i+1; j < dot_num; ++j) {
			int a = dot[i].y-dot[j].y;
			int b = dot[j].x-dot[i].x;
			int c = dot[i].x*dot[j].y-dot[j].x*dot[i].y;

			int num = 0;

			for (int k = 0; k < dot_num; ++k) {
				if ((a*dot[k].x + b*dot[k].y + c) == 0)
					++num;
			}

			if (num > max)
				max = num;
		}
	}

	cout << max << endl;

	return 0;
}

