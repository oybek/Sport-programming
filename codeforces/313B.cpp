
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
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

string s;
int sum[100001], m, a, b;

int main() {
	cin >> s;
	sum[0] = (s.size() > 1 && s[0]==s[1]);
	for (int i = 1; i < s.size(); ++i)
		sum[i] = sum[i-1] + (i+1 < s.size() && s[i]==s[i+1]);

#ifdef DEBUG
	cout << s << endl;
	for (int i = 0; i < s.size(); ++i)
		cout << sum[i] << ' ';
	cout << endl;
#endif

	cin >> m;
	while (m--) {
		cin >> a >> b; --a, --b;
		cout << (a == 0 ? sum[b-1] : sum[b-1]-sum[a-1]) << endl;
	}

	return 0;
}

