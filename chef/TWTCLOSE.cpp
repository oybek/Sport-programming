
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int a[1001];

int main()
{
	int N, K;
	cin >> N >> K;
	while( K-- )
	{
		string action;
		cin >> action;

		if( action == "CLICK" )
		{
			int i;
			cin >> i;

			a[i-1] = !a[i-1];
			cout << accumulate( a, a+N, 0 ) << endl;
		}
		else
		{
			fill( a, a+N, 0 );
			cout << accumulate( a, a+N, 0 ) << endl;
		}
	}

	return 0;
}

