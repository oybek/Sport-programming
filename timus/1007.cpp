
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX_N 1000

int count_sum(char * s)
{
	int ans = 0;
	for (char * c = s; *c; ++c)
		if (*c == '1')
			ans += (s-c)+1;
	return ans;
}

int main() {
	int N, s_sz, sum;
	char s[ MAX_N+1+1 ];

	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		scanf("%s", s);
		s_sz = strlen(s);

		if (s_sz > N)
		{
		}
		else if (s_sz < N)
		{
		}
		else
		{
			sum = count_sum(s);
			if (sum%(N+1) != 0)
			{
				int j;
				for (j = sum%(N+1); j < N && s[j] == '0'; j += (N+1));
				s[j] = '0';
			}
		}
	}

	return 0;
}

