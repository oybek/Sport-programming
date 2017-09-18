
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int main()
{
	vector<string> rats;
	vector<string> woman_children;
	vector<string> men;
	vector<string> captains;

	int n;
	cin >> n;
	for( int i = 0; i < n; ++i )
	{
		string name;
		string type;
		cin >> name >> type;

		if( type == "rat" )
		{
			rats.push_back( name );
		}
		else
		if( type == "woman" || type == "child" )
		{
			woman_children.push_back( name );
		}
		else
		if( type == "man" )
		{
			men.push_back( name );
		}
		else
		if( type == "captain" )
		{
			captains.push_back( name );
		}
	}

	for( auto s : rats ) cout << s << endl;
	for( auto s : woman_children ) cout << s << endl;
	for( auto s : men ) cout << s << endl;
	for( auto s : captains ) cout << s << endl;

	return 0;
}

