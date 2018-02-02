
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int get_sum( int n )
{
	int sum = 0;
	for( ; n > 0; n /= 10 )
	{
		sum += n%10;
	}
	return sum;
}

int main()
{
	int k;
	cin >> k;

	int n = 0;
	int i = 0;
	while( 1 )
	{
		if( get_sum(n) == 10 )
		{
			if( ++i == k )
			{
				cout << n << endl;
				return 0;
			}
		}
		++n;
	}

	return 0;
}

