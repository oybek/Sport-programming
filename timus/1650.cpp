
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

#define MLRD 1000000000

#define m_MAX 50001

int n;

map<string, int> name2money, city2id;

void add_city(const string & city) {
	if (city2id.find(city) == city2id.end()) {
		if (city2id.size() == 0)
			city2id[city] = 0;
		else
			city2id[city] = city2id.rbegin()->second+1;
	}
}

string<string, string> move[m_MAX];

int main() {
	cin >> n;
	while (n--) {
		int64 money;
		string name, city;

		cin >> name >> city >> money;
		name2money[name] = money/MLRD;
		add_city(city);
	}

	return 0;
}

