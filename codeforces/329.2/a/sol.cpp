
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define INF 1000000001
#define SQR(x) ((x)*(x))
#define ALL(a) a.begin(), a.end()
#define DIVC(a, b) (a/b+(a%b?1:0))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

template <class iteratorT>
void show(string s, iteratorT a, iteratorT b) {
	cout << s << ':';
	for (; a != b; ++a)
		cout << ' ' << *a;
	cout << endl;
}

int n;
vector<string> words;

bool good_word(string s, char c1, char c2) {
	for (char c : s) {
		if ((c != c1) && (c != c2))
			return false;
	}
	return true;
}

int get_count(char c1, char c2) {
	int ans = 0;
	for (int i = 0; i < words.size(); ++i)
		if (good_word(words[i], c1, c2))
			ans += words[i].size();
	return ans;
}

int main() {
	cin >> n;
	words.resize(n);
	for (auto & t : words)
		cin >> t;

	int ans = 0;
	for (char c1 = 'a'; c1 <= 'z'; ++c1)
		for (char c2 = c1+1; c2 <= 'z'; ++c2) {
			ans = max(ans, get_count(c1, c2));
		}

	cout << ans;

	return 0;
}

