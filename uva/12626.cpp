
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstring>
#include <climits>
#include <iomanip>
#include <iostream>
#include <algorithm>

#define INF INT_MAX-1
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

#define letter_num_SIZE 256

int main() {
	int N, letter_num[letter_num_SIZE];
	string s;

	cin >> N;
	while (N--) {
		/* prepare stage */
		fill(letter_num, letter_num+letter_num_SIZE, 0);

		/* input stage */
		cin >> s;
		for (string::iterator it = s.begin(); it != s.end(); ++it)
			letter_num[*it]++;

		/* solution stage */
		int ans = INF;
		ans = min(letter_num['M']  , ans);
		ans = min(letter_num['A']/3, ans);
		ans = min(letter_num['R']/2, ans);
		ans = min(letter_num['G']  , ans);
		ans = min(letter_num['I']  , ans);
		ans = min(letter_num['T']  , ans);

		/* output stage */
		cout << ans << endl;
	}

	return 0;
}

