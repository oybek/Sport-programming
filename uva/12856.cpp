
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

#define INF INT_MAX-1

/*
 * Given:
 * String S with length up to 10^6 character
 *
 * Find:
 * number of substrings which are numbers and are divisible to 3
 *
 * Solution:
 * What we can use:
 * number is divisible to three if the sum of it's digits is divisible to three
 */

#define a_MAX 201

int cube[a_MAX];

int main()
{
	for (int i = 0; i < a_MAX; ++i)
		cube[i] = i*i*i;

	return 0;
}

