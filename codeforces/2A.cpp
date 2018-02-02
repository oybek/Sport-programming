
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int main()
{
	int n;
	vector< pair< string, int > > game;
	map< string, int > scores;

	int m = 0;

	cin >> n;
	game.resize( n );
	for( auto& x : game )
		cin >> x.first >> x.second;

	string s;
	log( game.begin(), game.end(), s );

	std::cerr << s << std::endl;

	for( auto x : game )
		scores[ x.first ] += x.second;

	return 0;
}

