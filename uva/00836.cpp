
#include <cmath>
#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> a;

bool is_full_one(int x1, int y1, int x2, int y2) {
	int i, j;
	for ( i = x1; i <= x2; ++i )
		for ( j = y1; j <= y2; ++j )
			if ( a[i][j] != '1' )
				return false;
	return true;
}

#define area(x1, y1, x2, y2) (x2 - x1 + 1) * (y2 - y1 + 1)

int main() {
	bool first = true;
	int N, i, max_area, x1, y1, x2, y2;
	string tmp;

	cin >> N;
	while ( N-- ) {
		cin >> tmp;

		a.resize(tmp.size());
		a[0] = tmp;
		for ( i = 1; i < (int) a.size(); ++i )
			cin >> a[i];

		/*
		for ( i = 0; i < (int) a.size(); ++i )
			cout << a[i] << endl;
			*/

		max_area = 0;
		for ( x1 = 0; x1 < (int) a.size(); ++x1 )
		for ( y1 = 0; y1 < (int) a.size(); ++y1 )
			for ( x2 = x1; x2 < (int) a.size(); ++x2 ) {
				y2 = (x2 == x1 ? y1: 0);
				for ( ; y2 < (int) a.size(); ++y2 ) {
					if ( is_full_one(x1, y1, x2, y2) ) {
						max_area = max(area(x1, y1, x2, y2), max_area);
					}
				}
			}

		if (first == true) first = false;
		else cout << endl;
		cout << max_area << endl;
	}

	return 0;
}

