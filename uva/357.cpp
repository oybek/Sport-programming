
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

#define SIZE 30001

/*int main()*/
/*{*/
	/*int dp[SIZE];*/
	/*int i;*/

	/*for (i = 0; i < SIZE; ++i)  dp[i] = 1;*/
	/*for (i = 5; i < SIZE; ++i)  dp[i]+= dp[i-5];*/
	/*for (i = 10; i < SIZE; ++i) dp[i]+= dp[i-10];*/
	/*for (i = 25; i < SIZE; ++i) dp[i]+= dp[i-25];*/
	/*for (i = 50; i < SIZE; ++i) dp[i]+= dp[i-50];*/

	/*while ( cin >> i )*/
	/*{*/
		/*if (dp[i]==1)*/
			/*cout << "There is only 1 way to produce " << i << " cents  dp." << endl;*/
		/*else*/
			/*cout << "There are " <<  dp[i] << " ways to produce " << i << " cents change." << endl;*/
	/*}*/

	/*return 0;*/
/*}*/

/*1 5 10 25 50*/

typedef unsigned long long uint64;

uint64 dp[ SIZE ];
int a[] = { 1, 5, 10, 25, 50 };

/*uint64 backtrack(int change, int prev)*/
/*{*/
	/*if (change < 0)*/
		/*return 0;*/

	/*if (change == 0)*/
		/*return 1;*/

	/*if (dp[ change ][ prev ])*/
		/*return dp[ change ][ prev ];*/

	/*uint64 cw = 0;*/
	/*for (int i = prev; (i < 5) && (change >= a[i]); ++i)*/
		/*cw += backtrack(change - a[i], i);*/

	/*return dp[ change ][ prev ] = cw;*/
/*}*/

int main()
{
	dp[0] = 1;
	for (int j = 0; j < 5; ++j)
		for (int i = a[j]; i < SIZE; ++i)
			dp[i] += dp[ i-a[j] ];

	int i;
	while (scanf("%d", &i) != EOF)
	{
		if (dp[i] == 1)
			printf("There is only 1 way to produce %d cents change.\n", i);
		else
			printf("There are %llu ways to produce %d cents change.\n", dp[i], i);
	}

	return 0;
}

