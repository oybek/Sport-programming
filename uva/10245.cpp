
#include <cmath>
#include <vector>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>

#define MAX_DIST_SQR 1 ## 0000 ## 0000 ## .0
using namespace std;
int main()
{

	size_t N, i, j;
	double x, y, a, b;
	vector<pair<double, double> > points;
	points.reserve(10000);

	while ( 1 )
	{
		cin >> N;
		if (!N) break;

		points.resize(0);
		while ( N-- ) {
			cin >> x >> y;
			points.push_back( make_pair(x, y) );
		}

		double mindist_sqr = MAX_DIST_SQR;

		for ( i = 0; i < points.size(); ++i ) {
			for ( j = i+1; j < points.size(); ++j ) {
				a = (points[i].first - points[j].first); a *= a;
				b = (points[i].second - points[j].second); b *= b;

				mindist_sqr = min( mindist_sqr, a + b );
		}	}

		if (mindist_sqr < MAX_DIST_SQR)
			cout << fixed << setprecision(4) << sqrt(mindist_sqr) << endl;
		else
			cout << "INFINITY\n";
	}

	return 0;
}

