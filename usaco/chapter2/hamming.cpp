
/*
ID: aybek.h2
PROG: hamming
LANG: C++
*/

#define PROB_NAME "hamming"

#include <cmath>
#include <vector>
#include <fstream>
//#include <iostream>
#include <algorithm>

std::ifstream cin	(PROB_NAME".in");
std::ofstream cout	(PROB_NAME".out");

/*
int bit_len(int n) {
	int len;
	for (len = 0; n; ++len)
		n >>= 1;
	return len;
}
*/

int hamming_distance(int a, int b) {
	int hd = 0;
	for (int i = 1; i; i <<= 1)
		if (a&i)
			{ if (!(b&i)) ++hd; }
		else
			{ if (b&i) ++hd; }
	return hd;
}

int main()
{
	using namespace std;

	int N, B, D, i, max_value;
	vector<int>::iterator it;
	vector<int> v; v.reserve(64);


	cin >> N >> B >> D;
	max_value = 1<<B;

	for (int i = 0; i < max_value; ++i) {

		for (it = v.begin(); it != v.end(); ++it)
			if (hamming_distance(*it, i) < D)
				break;

		if (it == v.end())
			v.push_back(i);

		if (v.size() == N)
			break;
	}

	sort(v.begin(), v.end());

	for (i = 0, it = v.begin(); it != v.end(); ++it) {
		cout << *it;
		if (++i == 10) {
			cout << endl;
			i = 0;
		} else {
			if (it != v.end()-1)
				cout << ' ';
			else
				cout << endl;
		}
	}

	return 0;
}

