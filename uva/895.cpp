
#include <set>
#include <map>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

typedef string::iterator si;

#define INF INT_MAX-1
#define for_(t, i, a, b) for (t i = t(a); i != t(b); ++i)
#define rep_(n) for_(int, i_, 0, n)

#define SIZE ('z'-'a'+1)

int let[SIZE],
	word_n = 0,
	word[1000][SIZE];

int main() {
	string s;

	while (1)
	{
		cin >> s;
		if (s[0] == '#')
			break;

		for_(si, it, s.begin(), s.end())
			++word[word_n][int(*it-'a')];
		++word_n;
	}

	getchar();

	while (1)
	{
		fill(let, let+SIZE, 0);

		getline(cin, s);
		if (s[0] == '#')
			break;

		for_(si, it, s.begin(), s.end())
			if (isalpha(*it))
				++let[ *it-'a' ];

		int ans = word_n;
		for_(int, i, 0, word_n)
		{
			for_(int, j, 0, SIZE)
				if (word[i][j] > let[j])
				{
					--ans;
					break;
				}
		}

		cout << ans << endl;
	}

	return 0;
}

