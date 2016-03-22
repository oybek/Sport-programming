
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
#include <numeric>
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
	int i;
	string s;
	cin >> s;
	while ((i = s.find("WUB")) != string::npos) {
		s.erase(i, 3);
		s.insert(i, " ");
	}
	while (*s.begin() == ' ') s.erase(0, 1);
	while (*s.rbegin() == ' ') s.erase(s.size()-1, 1);
	cout << s;

	return 0;
}

