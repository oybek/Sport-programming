
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>

int main()
{
	using namespace std;

	int N, i, sum, average, mvn = 0;
	vector<int> v; v.reserve(50);

	for ( i = 1; 1; ++i )
	{
		cin >> N;
		if ( !N ) break;
		v.resize( N );

		for ( auto & e: v )
			cin >> e;

		sum = 0;
		for ( auto e: v )
			sum += e;
		average = sum / N;

		mvn = 0;
		for ( auto e: v )
			if ( e < average )
				mvn += (average - e);

		cout << "Set #" << i << endl;
		cout << "The minimum number of moves is " << mvn << '.' << endl << endl;
	}

	return 0;
}

