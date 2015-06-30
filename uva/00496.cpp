
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
#include <sstream>
#include <iostream>
#include <algorithm>

#define INF 1000000001
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

set<int> A, B;

void reset() {
	A.clear();
	B.clear();
}

bool read_test() {
	int n;
	string l;
	stringstream ss;

	if (!getline(cin, l)) return false;
	ss.clear();
	ss.str(l);
	while (ss >> n) A.insert(n);

	getline(cin, l);
	ss.clear();
	ss.str(l);
	while (ss >> n) B.insert(n);

	return true;
}

bool equal() {
	if (A.size() != B.size()) return false;
	for (set<int>::iterator it = A.begin(); it != A.end(); ++it)
		if (B.find(*it) == B.end())
			return false;
	return true;
}

bool A_subset_of_B() {
	if (A.size() >= B.size()) return false;
	for (set<int>::iterator it = A.begin(); it != A.end(); ++it)
		if (B.find(*it) == B.end())
			return false;
	return true;
}

bool B_subset_of_A() {
	if (B.size() >= A.size()) return false;
	for (set<int>::iterator it = B.begin(); it != B.end(); ++it)
		if (A.find(*it) == A.end())
			return false;
	return true;
}

bool disjoint() {
	for (set<int>::iterator it = B.begin(); it != B.end(); ++it)
		if (A.find(*it) != A.end())
			return false;
	return true;
}

void solve() {
	if (equal()) {
		cout << "A equals B\n";
	} else
	if (A_subset_of_B()) {
		cout << "A is a proper subset of B\n";
	} else
	if (B_subset_of_A()) {
		cout << "B is a proper subset of A\n";
	} else
	if (disjoint()) {
		cout << "A and B are disjoint\n";
	} else {
		cout << "I'm confused!\n";
	}
}

int main() {
	while (1) {
		reset();
		if (read_test() == false) break;
		solve();
	}

	return 0;
}

