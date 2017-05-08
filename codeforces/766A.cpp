
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long u64;
typedef long long i64;

using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;

	if( a == b )
		printf( "-1\n" );
	else
		printf( "%d\n", max( a.size(), b.size() ) );

	return 0;
}

