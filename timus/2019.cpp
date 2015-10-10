
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

#define n_MAX 5001

string s;
int n, ans[2*n_MAX];

#define is_ghost islower

void check(vector<pair<char, int> > & st) {
	pair<char, int> a = st[st.size()-1];
	pair<char, int> b = st[st.size()-2];

	if (is_ghost(a.first) && !is_ghost(b.first) && tolower(b.first) == a.first) {
		ans[b.second] = a.second;
		st.pop_back();
		st.pop_back();
	} else
	if (!is_ghost(a.first) && is_ghost(b.first) && tolower(a.first) == b.first) {
		ans[a.second] = b.second;
		st.pop_back();
		st.pop_back();
	}
}

int main() {
	vector<pair<char, int> > st; st.reserve(2*n_MAX);
	int cur_hunter = 1, cur_ghost = 1;

	cin >> n
		>> s;

	for (int i = 0; i < s.size(); ++i) {
		if (is_ghost(s[i])) {
			st.push_back(make_pair(s[i], cur_ghost++));
		} else {
			st.push_back(make_pair(s[i], cur_hunter++));
		}

		if (st.size() >= 2) {
			check(st);
		}
	}

	if (st.size() > 0) {
		cout << "Impossible";
	} else {
		for (int i = 0; i < n; ++i)
			cout << ans[i+1] << ' ';
	}
	cout << endl;

	return 0;
}

