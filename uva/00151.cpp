
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
#define for_(t, i, a, b) for (t i = t(a); i != t(b); ++i)
#define rep_(n) for_(int, i_, 0, n)

int ans[] = {
1, 18, 10, 11, 7, 17, 11, 15, 29, 5, 21, 13, 26, 14, 11, 23, 22, 9, 73, 17, 42, 7, 98, 15, 61, 22, 84, 24, 30, 9, 38, 15, 54, 27, 9, 61, 38, 22, 19, 178, 38, 53, 79, 68, 166, 20, 9, 22, 7, 21, 72, 133, 41, 10, 82, 92, 64, 129, 86, 73, 67, 19, 66, 115, 52, 24, 22, 176, 10, 57, 137, 239, 41, 70, 60, 116, 81, 79, 55, 102, 49, 5, 22, 54, 52, 113, 15, 66
};

int main()
{
	/*bitset<101> on;*/

	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (!n)
			break;

		printf("%d\n", ans[n-13]);
		/*for (int m = 1; m < 10000; ++m)*/
		/*{*/
			/*on.reset();*/
			/*for (int i = 1; i <= n; ++i)*/
				/*on[i] = 1;*/

			/*int i = 1;*/
			/*int prev_count = -1;*/
			/*while (on.count() > 1)*/
			/*{*/
				/*if (prev_count == int(on.count()))*/
				/*{*/
					/*on[13] = 0;*/
					/*break;*/
				/*}*/

				/*on[ i ] = 0;*/

				/*rep_(m)*/
				/*{*/
					/*if (++i > n)*/
						/*i = 1;*/
					/*while (!on[i])*/
						/*if (++i > n)*/
							/*i = 1;*/
				/*}*/
			/*}*/

			/*if (on[13] == 1)*/
			/*{*/
				/*printf("%d, ", m);*/
				/*break;*/
			/*}*/
		/*}*/
	}

	return 0;
}

