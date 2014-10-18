
#include <cmath>
#include <vector>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, v_size, sum, highn;
	vector<int> v; v.reserve( 1000 );
	cin >> N;

	while ( N-- )
	{
		cin >> v_size;
		v.resize(v_size);

		sum = 0;
		for ( auto & e : v ) {
			cin >> e;
			sum += e;
		}

		highn = 0;
		for ( auto e : v )
			highn += (sum < e*v_size);

		cout << fixed << setprecision(3) << (float(highn) / v_size)*100 << "%\n";
	}

	return 0;
}

