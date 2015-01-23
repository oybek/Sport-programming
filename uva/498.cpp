
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

#define INF INT_MAX-1
#define SET_STREAM(ss, s) ss.clear(); ss.str(s)

int get_polynom(const vector<int> & c, int x)
{
	int y = 0;
	for (int i = 0; i < int(c.size()); ++i)
		y = y*x + c[i];
	return y;
}

string s;
vector<int> c;
stringstream ss;

int main()
{
	while (1)
	{
		int t;
		c.resize(0);

		/* input phase */
		getline(cin, s);
		if (cin.eof())
			break;

		/* reading c */
		SET_STREAM(ss, s);
		while (ss >> t)
			c.push_back(t);

		getline(cin, s);
		SET_STREAM(ss, s);

		for (bool f = true; ss >> t; )
		{
			if (f) f = false; else cout << ' ';
			cout << get_polynom(c, t);
		}
		cout << endl;
	}

	return 0;
}

