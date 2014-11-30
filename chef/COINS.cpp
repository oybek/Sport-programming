#include <map>
#include <cstdio>
#include <iostream>
using namespace std;

typedef long long int64;

map<int, int64> D;

int64 get_max(int n)
{
	if (D.find(n) != D.end())
		return D.find(n)->second;

	int64
		a1 = get_max(n/2),
		a2 = get_max(n/3),
		a3 = get_max(n/4);

	int64 s = a1 + a2 + a3;
	if (s > n)
	{
		D.insert(make_pair(n, s));
		return s;
	}
	else
	{
		D.insert(make_pair(n, n));
		return n;
	}
}

int main()
{
	D.insert(make_pair(0, 0));
	int n;
	while ( scanf("%d", &n) != EOF )
		printf("%lld\n", get_max(n));

	return 0;
}

