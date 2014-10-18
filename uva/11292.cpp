#include <cmath>
#include <vector>
#include <climits>
#include <cassert>
#include <iostream>
#include <algorithm>
int main()
{
	using namespace std;

	int n, m, i, j;
	long long s, t;
	vector<long long> heads; heads.reserve(20000);
	vector<long long> knights; knights.reserve(20000);

	while ( cin >> n >> m )
	{
		if ( !n && !m )
			break;

		heads.resize(0);
		knights.resize(0);

		while ( n-- )
		{
			cin >> t;
			heads.push_back(t);
		}

		while ( m-- )
		{
			cin >> t;
			knights.push_back(t);
		}

		sort(knights.begin(), knights.end());
		sort(heads.begin(), heads.end());

		s = 0;
		for ( i = 0, j = 0; i < (int) heads.size(); ) {

			if (j >= (int) knights.size()) {
				s = -1;
				break;
			}

			if ( heads[i] <= knights[j] )
			{
				s += knights[ j ];
				++i;
				++j;
			} else
			{
				++j;
			}
		}

		if (s == -1) cout << "Loowater is doomed!\n";
		else cout << s << endl;
	}

	return 0;
}

