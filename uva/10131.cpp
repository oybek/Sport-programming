
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

#define elephants_size_MAX 1001

struct elephant {
	int i, w, iq;

	elephant(int ai, int aw, int aiq)
		: i(ai), w(aw), iq(aiq)
	{}

	bool operator < (const elephant & a) const {
		return w < a.w;
	}
};

vector<elephant> elephants;
vector<int> l, p;

int main() {
	elephants.reserve(elephants_size_MAX);
	l.reserve(elephants_size_MAX);
	p.reserve(elephants_size_MAX);

	int i, w, iq;
	for (i = 0; cin >> w >> iq; ++i)
		elephants.push_back(elephant(i+1, w, iq));

	l.resize(elephants.size());
	p.resize(elephants.size());
	sort(elephants.begin(), elephants.end());
	reverse(elephants.begin(), elephants.end());

	/* longest decreasing subsequence by field iq */

	fill(l.begin(), l.end(), 1);
	fill(p.begin(), p.end(), -1);

	for (int i = 1; i < int(elephants.size()); ++i)
		for (int j = 0; j < i; ++j)
			if (elephants[i].iq > elephants[j].iq &&
				elephants[i].w < elephants[j].w &&
				l[i] < l[j]+1) {
				l[i] = l[j]+1;
				p[i] = j;
			}

	i = 0;
	for (int j = 1; j < int(elephants.size()); ++j)
		if (l[i] < l[j])
			i = j;

	cout << l[i] << endl;
	for (; i != -1; i = p[i])
		cout << elephants[i].i << endl;

	return 0;
}

