
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int main()
{
	int n, a, b;

	cin >> n >> a >> b;
	int t = a+b;
	cout << ( t < 1 ? n+t : t > n ? t%n : t ) << endl;

	return 0;
}

