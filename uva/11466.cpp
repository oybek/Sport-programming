
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

typedef pair<long, long> ll;

void factorize(long long n, vector<ll> & v) {
	int i;
	long long c, lim;

#define add(n) \
	if (v.size() == 0 || v.back().first != n) \
		v.push_back(make_pair(n, 1)); \
	else ++v.back().second;

	if (!n) return;

	for (c = n; c%2==0; c >>=1) {
		add(2);
	}

	lim = (long long)(sqrt(c))+1;
	for (i = 3; i <= lim;) {
		if (c%i == 0) {
			add(i);
			lim = (long long)(sqrt(c /= i))+1;
		} else
			i += 2;
	}

	if (c > 1 && c != n) {
		add(c);
	}
}

int main() {
	vector<ll> v;
	v.reserve(100);

	while (1) {
		long long n;
		v.resize(0);

		cin >> n;
		n = abs(n);
		if (!n) break;

		factorize(n, v);

		if (v.size() == 0)
			cout <<-1<<endl;
		else
		if (v.size() == 1) //&& (v.back().second == 1))
			cout <<-1<<endl;
		else
			cout <<v.back().first<< endl;
	}

	return 0;
}

