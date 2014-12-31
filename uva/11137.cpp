
#include <cstdio>
#include <iostream>
using namespace std;

#define every(i, a, b) for (int i = (a); i <= int(b); ++i)
#define repeat(n) every (i, 1, n)

#define D_SZ 10000

int a[ 22 ], n;
int d[ D_SZ ];

int main()
{
	for (int i = 1; i <= 22; ++i)
		a[i] = i*i*i;

	d[0] = 1;
	for (int i = 1; i < D_SZ; ++i)
		for (int j = 1; j <= 21; ++j)
			d[i] += max(0, i - a[j]);

	int n;
	while (cin >> n)
	{
		cout << d[n] << endl;
	}

	return 0;
}

