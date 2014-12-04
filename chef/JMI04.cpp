
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long uint64;

int main()
{
	vector<uint64> fib;
	fib.push_back(1);
	fib.push_back(1);
	while (1)
	{
		uint64 a = fib[ fib.size()-1 ];
		uint64 b = fib[ fib.size()-2 ];
		fib.push_back(a+b);
		if (fib.back() > 1ull<<32)
			break;
	}

	int test_n;
	scanf("%d", &test_n);
	while (test_n--)
	{
		int n;
		scanf("%d", &n);
		puts( binary_search(fib.begin(), fib.end(), n) ? "Yes" : "No" );
	}

	return 0;
}

