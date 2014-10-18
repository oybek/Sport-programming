
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>

int main()
{
	using namespace std;

	vector<int> side;
	int N, M, P, t, i1, i2, i3, i4;
	cin >> N;
	while ( N-- )
	{
		side.resize(0);

		cin >> M;
		for ( P = 0; M--; P += t ) {
			cin >> t;
			side.push_back(t);
		}

		if ( P%4 ) {
			cout << "no" << endl;
		} else {
			if ( !flag )
				cout << "yes" << endl;
		}
	}

	return 0;
}

