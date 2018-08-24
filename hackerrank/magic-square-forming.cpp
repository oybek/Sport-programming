
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define all(x) x.begin(), x.end()

vector<vector<int>> magic_squares;

bool is_magic(const vector<int>& a) {
	return a[0] + a[1] + a[2] == 15
		&& a[3] + a[4] + a[5] == 15
		&& a[6] + a[7] + a[8] == 15
		&& a[0] + a[3] + a[6] == 15
		&& a[1] + a[4] + a[7] == 15
		&& a[2] + a[5] + a[8] == 15
		&& a[0] + a[4] + a[8] == 15
		&& a[2] + a[4] + a[6] == 15;
}

void show(const vector<int>& a) {
	for (int i = 0; i < a.size(); ++i) {
		cout << a[i] << ((i+1)%3 == 0 ? '\n' : ' ');
	}
}

void generate_magic_squares() {
	vector<int> a { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	do {
		if (is_magic(a))
			magic_squares.push_back(a);
	} while (next_permutation(all(a)));
}

int dist(vector<int> a, vector<int> b) {
	int d = 0;
	for (int i = 0; i < a.size(); ++i) {
		d += abs(a[i]-b[i]);
	}
	return d;
}

int main() {
	generate_magic_squares();

	// read square
	vector<int> a;
	int t;
	while (cin >> t)
		a.push_back(t);

	int min_dist = 1000000009;
	for (int i = 0; i < magic_squares.size(); ++i) {
		min_dist = min(min_dist, dist(a, magic_squares[i]));
	}

	cout << min_dist << endl;

	return 0;
}

