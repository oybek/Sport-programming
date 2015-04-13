
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

#define s_size_MAX 10
#define word_max_len 5

char ts[s_size_MAX];
string s;
vector<string> words;

bool cmp_words(const string & s1, const string & s2) {
	if (s1.size() != s2.size()) {
		return s1.size() < s2.size();
	} else {
		return s1 < s2;
	}
}

void backtrack(char * s, int i) {
	words.push_back(string(s, s+i));

	if (i == word_max_len)
		return;

	for (s[i] = s[i-1]+1; s[i] <= 'z'; ++s[i])
		backtrack(s, i+1);
}

int main() {
	words.reserve(83681);
	for (ts[0] = 'a'; ts[0] <= 'z'; ++ts[0])
		backtrack(ts, 1);

	sort(words.begin(), words.end(), cmp_words);

	while (cin >> s) {
		vector<string>::iterator it = lower_bound(words.begin(), words.end(), s, cmp_words);

		if ((it == words.end()) || (*it != s)) {
			cout << 0 << endl;
		} else {
			cout << it-words.begin()+1 << endl;
		}
	}

	return 0;
}

