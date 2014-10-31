
#include <set>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

void show_vector(vector<int> & a) {
	for (int i = 0; i < int(a.size()); ++i)
		cout << a[i] << endl;
}

void debug() {
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(4);

	vector<int>::iterator it = upper_bound(a.begin(), a.end(), 4);
	assert(it == a.end());

	it = lower_bound(a.begin(), a.end(), 5);
	assert(it == a.end());

	exit(0);
}

int main() {
	debug();

	set<int> s;
	vector<int> a, b;

	a.reserve(1001);
	b.reserve(1600);

	for (int i = 1; i <= 1000; ++i)
		a.push_back(i*i*i);

	for (int i = 0; i < int(a.size()); ++i)
		for (int j = i; j < int(a.size()); ++j) {
			int t = a[i] + a[j];
			if (t <= 1000100000) {
				if (s.find(t) != s.end())
					b.push_back(t);
				else
					s.insert(t);
			}
		}

	sort(b.begin(), b.end());

	int n1, rg;
	while (scanf("%d%d", &n1, &rg) != EOF) {
		vector<int>::iterator i = lower_bound(b.begin(), b.end(), n1);
		vector<int>::iterator j = upper_bound(b.begin(), b.end(), n1+rg);

		if (i == j)
			printf("None\n");
		while (i < j)
			printf("%d\n", *i++);
	}


	return 0;
}

