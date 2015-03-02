
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

int rown, coln;
vector<string> a;
vector<pair<int, char> > ans;

#define state_num_SIZE 256
int state_num[state_num_SIZE];

void kill_state(int x, int y, char c) {
	a[x][y] = ' ';
	if (x-1 >= 0	&& a[x-1][y] == c) kill_state(x-1, y, c);
	if (x+1 < rown	&& a[x+1][y] == c) kill_state(x+1, y, c);
	if (y-1 >= 0	&& a[x][y-1] == c) kill_state(x, y-1, c);
	if (y+1 < coln	&& a[x][y+1] == c) kill_state(x, y+1, c);
}

int main() {
	int test_n;

	cin >> test_n;
	for (int test_i = 1; test_i <= test_n; ++test_i) {
		/* prepare stage */
		ans.resize(0);
		fill(state_num, state_num+state_num_SIZE, 0);

		/* input stage */
		cin >> rown >> coln;
		a.resize(rown);
		for (vector<string>::iterator it = a.begin(); it != a.end(); ++it)
			cin >> *it;

		/* count number of each state */
		for (int i = 0; i < rown; ++i) {
			for (int j = 0; j < coln; ++j) {
				if (isalpha(a[i][j])) {
					state_num[a[i][j]]++;
					kill_state(i, j, a[i][j]);
				}
			}
		}

		for (int i = 'a'; i <= 'z'; ++i)
			if (state_num[i] > 0)
				ans.push_back(make_pair(-state_num[i], i));
		sort(ans.begin(), ans.end());

		cout << "World #" << test_i << endl;
		for (vector<pair<int, char> >::iterator it = ans.begin(); it != ans.end(); ++it) {
			cout << it->second << ": " << -it->first << endl;
		}
	}

	return 0;
}

