
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int main()
{
	char c;
	int m = 0;
	int curm = 0;
	while( cin.get(c) )
	{
		if( isalpha(c) )
		{
			if( isupper(c) ) ++curm;
		}
		else
		{
			m = max( m, curm );
			curm = 0;
		}
	}
	cout << m << endl;

	return 0;
}

