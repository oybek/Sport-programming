
#include <cmath>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

struct container {
	int i;
	int date;
	int earn;

	friend bool operator < (const container & a1, const container & a2) {
		return a1.earn < a2.earn;
	}

	friend bool operator > (const container & a1, const container & a2) {
		return a1.earn > a2.earn;
	}
};

template <class T>
void quick_sort(T * a, int begin, int end) {
	int i = begin, j = end;
	T x = a[(i+j)/2];

	do {
		while (a[i] < x) ++i;
		while (a[j] > x) --j;

		if (i <= j) {
			if (i < j)
				std::swap(a[i], a[j]);

			++i, --j;
		}
	} while (i <= j);

	if (i < end)
		quick_sort(a, i, end);
	if (begin < j)
		quick_sort(a, begin, j);
}

int main() {
	using namespace std;

	vector<bool> day(100001);
	vector<pair<int, int> > work;

	int cont_size;
	cin >> cont_size;

	container * cont = new container [cont_size];
	for (int i = 0; i < cont_size; ++i) {
		cont[i].i = i+1;
		cin >> cont[i].date >> cont[i].earn;
	}

	// O(n log n)
	quick_sort(cont, 0, cont_size-1);

	// Detect number of delivered containers
	int n = 0;
	for (int i = 0; i < cont_size; ++i) {
		if (day.at(cont[i].date) == 1) {
			while (day.at(cont[i].date) == 1) {
				--i;
				if (i < 0) break;
			}

			if (i < 0);
		} else {
			day.at(cont[i].date) = 1;
			work.push_back(make_pair(cont[i].date, cont[i].i));
		}
	}

	cout << n << endl << cont[0].i << ' ';
	for (int i = 1; i < cont_size; ++i) {
		if (cont[i].date != cont[i-1].date)
			cout << cont[i].i << ' ';
	}
	cout << endl;


	return 0;
}

