
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

#define INF 1000000001
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

int main() {
	char c;
	string s;

	while (cin >> c)
		if (c != '+')
			s.push_back(c);

	sort(s.begin(), s.end());

	cout << s[0];
	for (int i = 1; i < int(s.size()); ++i)
		cout << '+' << s[i];
	cout << endl;

	return 0;
}

