
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

#define k_MAX 26

string s;
int count[k_MAX], k;

int main() {
	cin >> s;
	for (int i = 0; i < s.size(); ++i)
		count[s[i]-'a']++;
	cin >> k;

	sort(count, count+k_MAX);
	int sum = 0;
	for (int i = k_MAX-1; i >= 0 && k--; --i)
		sum += count[i];

	cout << sum << endl;

	return 0;
}

