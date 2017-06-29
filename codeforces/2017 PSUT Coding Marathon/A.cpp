
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int main()
{
	int a, b, c;
	scanf( "%d %d %d", &a, &b, &c );
	printf( "%d", min( a/2+b, c ) );

	return 0;
}

