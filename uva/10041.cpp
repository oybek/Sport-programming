
#include <iostream>

#define abs(a) ((a) < 0 ? -(a): (a))

template <class T>
void quick_sort(T* a, int begin, int end) {
	int i = begin, j = end;
	T x = a[ (i+j)/2 ];

	do {
		while (a[i] < x) ++i;
		while (a[j] > x) --j;

		if (i <= j) {
			if (i < j) {
				std::swap(a[i], a[j]);
			}

			++i;
			--j;
		}
	} while (i <= j);

	if (i < end)
		quick_sort(a, i, end);
	if (begin < j)
		quick_sort(a, begin, j);
}

int main() {
	using namespace std;

	int testn, a_size, c, sum, i;
	int a[30000];

	cin >> testn;
	while (testn--) {
		cin >> a_size;
		for (i = 0; i < a_size; ++i)
			cin >> a[i];

		quick_sort(a, 0, a_size-1);

		c = a[a_size/2];

		sum = 0;
		for (i = 0; i < a_size; ++i)
			sum += abs(a[i]-c);

		cout << sum << endl;
	}

	return 0;
}

