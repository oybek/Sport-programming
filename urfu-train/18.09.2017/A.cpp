
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int main()
{
	ull n, m, a;
	cin >> n >> m >> a;
	cout << ( ((n/a)+(n%a ? 1 : 0)) * ((m/a)+(m%a ? 1 : 0 )) ) << endl;

	return 0;
}

