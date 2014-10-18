
/*
ID: aybek.h2
PROG: numtri
LANG: C++
*/

#define PROB_NAME "numtri"

#include <cmath>
#include <fstream>

#define MAX_SIZE 1000

int trig_h;
int trig[MAX_SIZE][MAX_SIZE] = {};

void descend() {
	for (int i = trig_h-2; i >= 0; --i) {
		for (int j = 0; j <= i; ++j) {
			trig[i][j] += std::max(trig[i+1][j], trig[i+1][j+1]);
		}
	}
}

int main() {
	using namespace std;

	ifstream cin	(PROB_NAME".in");
	ofstream cout	(PROB_NAME".out");

	cin >> trig_h;
	for (int i = 0; i < trig_h; ++i) {
		for (int j = 0; j <= i; ++j)
			cin >> trig[i][j];
	}
	descend();
	cout << trig[0][0] << endl;

	return 0;
}

