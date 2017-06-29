
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int n, k, pl;
vector<int> a;

int main()
{
	//
	scanf( "%d%d", &n, &k );

	a.resize( n );
	for( int& x : a )
	{
		char s[ 105 ];
		scanf( "%s", s );
		x = strlen( s );
	}

	{
		char s[ 105 ];
		scanf( "%s", s );
		pl = strlen( s );
	}

	//
	sort( all(a) );

	int nbest = lower_bound( all(a), pl ) - a.begin() + 1;
	int nworst = upper_bound( all(a), pl ) - a.begin();

	printf( "%d %d", nbest+nbest/k*5 - 5*(nbest%k ? 0 : 1), nworst+nworst/k*5 - 5*(nworst%k ? 0 : 1) );

	return 0;
}

