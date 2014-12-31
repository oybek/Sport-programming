
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

#define FOR(t, i, a, b) for (t i = t(a); i != t(b); ++i)

vector<string> words;
vector<vector<int> > G;

/* words are 'connected' if they has same length
 * and differs in single position */
bool is_connected(const string & s1, const string & s2)
{
	if (s1.size() != s2.size())
		return false;

	int count = 0;
	for (int i = 0; i < int(s1.size()); ++i)
		count += (s1[i] != s2[i]);
	return (count == 1);
}

void build_graph()
{
	G.resize(words.size());
	for (int i = 0; i < int(words.size()); ++i)
		G[i].resize(0);

	for (int i = 0; i < int(words.size()); ++i)
		for (int j = i+1; j < int(words.size()); ++j)
			if (is_connected(words[i], words[j]))
			{
				G[i].push_back(j);
				G[j].push_back(i);
			}
}

/* returns the length of shortest path from 'from' to 'to' ) */
int get_shortest(int from, int to)
{
	/* NOTE: not thinking about cycles */
	bitset<256> was; was.reset();

	queue<pair<int, int> > Q;
	Q.push(make_pair(from, 0));

	while (!Q.empty())
	{
		pair<int, int> t = Q.front(); Q.pop();
		was[t.first] = 1;
		if (t.first == to)
		{
			return t.second;
		}

		for (int i = 0; i < int(G[t.first].size()); ++i)
			if (!was[G[t.first][i]])
				Q.push(make_pair(G[t.first][i], t.second+1));
	}
	return -1;
}

void remove_trailing_spaces(char * s)
{
	s = s + strlen(s) - 1;
	while (*s == '\n' || *s == ' ' || *s == '\t') --s;
	*(s+1) = '\0';
}

const int s_sz_max = 32;
char s[s_sz_max], s1[s_sz_max], s2[s_sz_max];

int main()
{
	words.reserve(256);
	G.reserve(256);


	int test_n;
	bool f = true;


	scanf("%d", &test_n);

	while (getchar() != '\n');
	while (getchar() != '\n');

	while (test_n--)
	{
		/* read all strings into vector */

		words.resize(0);

		while (1)
		{
			fgets(s, s_sz_max, stdin);
			if (s[0] == '*')
				break;

			remove_trailing_spaces(s);
			words.push_back(string(s, s+strlen(s)));
		}

		sort(words.begin(), words.end());
		build_graph();

		if (f) f = false; else puts("");

		while (1)
		{
			if (fgets(s, s_sz_max, stdin) == NULL)
				break;
			if (s[0] == '\n' || s[0] == '\0')
				break;

			sscanf(s, "%s%s", s1, s2);

			int from = lower_bound(words.begin(), words.end(), string(s1, s1+strlen(s1))) - words.begin();
			int to   = lower_bound(words.begin(), words.end(), string(s2, s2+strlen(s2))) - words.begin();

			printf("%s %s %d\n", s1, s2, get_shortest(from, to));
		}
	}

	return 0;
}

