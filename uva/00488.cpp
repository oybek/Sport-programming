
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

typedef string::iterator si;

#define INF INT_MAX-1

void gen_wave(int amplitude)
{
	for (int i = 1; i < amplitude; ++i)
	{
		for (int j = 0; j < i; ++j)
			printf("%d", i);
		puts("");
	}
	for (int j = 0; j < amplitude; ++j)
		printf("%d", amplitude);
	puts("");
	for (int i = amplitude-1; i > 0; --i)
	{
		for (int j = 0; j < i; ++j)
			printf("%d", i);
		puts("");
	}
}

int main()
{
	int test_n;
	scanf("%d", &test_n);

	bool f1 = true;
	while (test_n--)
	{
		if (f1) f1 = false;
		else puts("");

		int amplitude, frequency;
		scanf("%d%d", &amplitude, &frequency);

		bool f2 = true;
		while (frequency--)
		{
			if (f2) f2 = false;
			else puts("");
			gen_wave(amplitude);
		}
	}

	return 0;
}

