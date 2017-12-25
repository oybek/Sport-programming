
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
	vector<int> x;
	vector<int> y;

	cin >> n;
	x.resize(n);
	y.resize(n);

	for( int i = 0; i < n; ++i )
		cin >> x[i];

	for( int i = 0; i < n; ++i )
		cin >> y[i];

	sort( all(x) );
	sort( all(y) );

	int count = 0;
	for( int i = 0; i < n; ++i )
		for( int j = i; j < n; ++j )

	return 0;
}

