
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

string dec2ter(int n) {
	if (n == 0)
		return "0";
	string res;
	for (; n > 0; n /= 3)
		res.push_back(n%3+'0');
	reverse(res.begin(), res.end());
	return res;
}

int main() {
	int n;
	while (1) {
		cin >> n;
		if (n < 0)
			break;
		cout << dec2ter(n) << endl;
	}

	return 0;
}

