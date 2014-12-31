
#include <vector>
#include <string>
#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(t, i, a, b) for (t i = t(a); i != t(b+1); ++i)
#define REP(n) FOR(int, i_, 1, n)

int main()
{
	int tt, max_rel, rel;
	string s;
	vector<pair<string, int> > a;
	a.reserve(10);

	cin >> tt;

	FOR(int, i, 1, tt)
	{
		a.resize(0);
		max_rel = INT_MIN;

		REP(10)
		{
			cin >> s >> rel;
			a.push_back(make_pair(s, rel));
			max_rel = max(rel, max_rel);
		}

		cout << "Case #" << i << ":\n";
		FOR(int, j, 0, a.size()-1)
			if (a[j].second == max_rel)
				cout << a[j].first << endl;
	}

	return 0;
}

