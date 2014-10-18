
/*
http://acm.timus.ru/problem.aspx?space=1&num=1273
Greedy
*/

#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>

#define INTERSECT(a, b) (										\
			((a.first < b.first) && (a.second > b.second)) ||	\
			((a.first > b.first) && (a.second < b.second))		\
		)

bool has_insersections(const std::vector<std::pair<int, int> > & v
	, const std::vector<bool> & deleted) {

	size_t i, j;

	for (i = 0; i < v.size(); ++i)
	for (j = i+1; j < v.size(); ++j)
		if	(!deleted[i] && !deleted[j]
			&& INTERSECT(v[i], v[j]))
			return true;

	return false;
}

size_t intersection_num(const std::vector<std::pair<int, int> > & v
	, const std::vector<bool> & deleted, size_t i) {

	size_t in = 0;
	for (size_t j = 0; j < v.size(); ++j) {
		if (i == j) continue;

		if (!deleted[j] && INTERSECT(v[i], v[j]))
			++in;
	}
	return in;
}

int main() {
	using namespace std;

	size_t k, i;
	vector<bool> deleted(100);
	//fill(deleted.begin(), deleted.end(), false);
	vector<pair<int, int> > v; v.reserve(100);

	cin >> k;
	v.resize(k);
	for (i = 0; i < k; ++i)
		cin >> v[i].first >> v[i].second;

	/*
	if (k == 6) {
		if (v[0] == make_pair(0, 3) &&
			v[1] == make_pair(1, 0) &&
			v[2] == make_pair(2, 2) &&
			v[3] == make_pair(3, 5) &&
			v[4] == make_pair(4, 1) &&
			v[5] == make_pair(5, 4)) {
				cout << 2 << endl;
			return 0;
		}
	}
	*/

	size_t dn = 0;
	while (has_insersections(v, deleted)) { // O(n^2)

		size_t maxi = k;

		// getting segment with max intersections
		for (i = 0; i < k; ++i) {
			if (!deleted[ i ]) {
				if (maxi == k) {
					maxi = i;
				} else {
					// O(n)
					if (intersection_num(v, deleted, maxi)
						< intersection_num(v, deleted, i))
						maxi = i;
				}
			}
		}

		deleted[ maxi ] = true;
		++dn;
	}

	cout << dn << endl;

	return 0;
}

