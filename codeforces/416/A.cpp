
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int main()
{
	int a, b;
	scanf( "%d%d", &a, &b );

	int n1 = trunc( sqrt( a ) );
	int n2 = trunc( ( sqrt( 1+4*b )-1 ) / 2 );
	
	printf( "%s\n", ( n1 <= n2 ? "Vladik" : "Valera" ) );

	return 0;
}

