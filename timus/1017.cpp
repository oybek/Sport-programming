#include <iostream>
#include <map>
using namespace std;

unsigned long long res[500][500] = {};

unsigned long long F(unsigned long long p, unsigned long long N)
{
	if (res[p][N] != 0)
		return res[p][N];

	unsigned long long s = 0ull;

	if (p < N)
		for (int i = p+1; (N-i) > i; ++i) {
			s++;
			s += F(i, N-i);
		}

	return (res[p][N] = s);
}

int main()
{
	unsigned long long n;
	cin >> n;
	cout << F(0ull, n) << endl;


	return 0;
}

