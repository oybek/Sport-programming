#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_NUM 100000
#define SET_STREAM(ss, s) ss.clear(); ss.str(s)

int main()
{
	bool first = true;
	int t, ti, ind[ MAX_NUM ], ind_sz, str_sz, i;
	string tf, str[ MAX_NUM ], s;
	stringstream ss;

	cin >> t; cin.get();
	while (t--)
	{
		if (!first) cout << endl;
		else first = false;

		cin.get();
		getline(cin, s);
		SET_STREAM(ss, s);
		for (ind_sz = 0; ss >> ti; ++ind_sz)
		{
			ind[ ti-1 ] = ind_sz;
		}

		getline(cin, s);
		SET_STREAM(ss, s);
		for (str_sz = 0; ss >> tf; ++str_sz)
		{
			str[ str_sz ] = tf;
		}

		for (i = 0; i < ind_sz; ++i)
			cout << str[ ind[ i ] ] << endl;
	}

	return 0;
}

