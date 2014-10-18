
/*
ID: aybek.h2
PROG: sort3
LANG: C++11
*/

#define PROB_NAME "sort3"

#include <cmath>
#include <vector>
#include <fstream>
#include <algorithm>

std::ifstream cin	(PROB_NAME".in");
std::ofstream cout	(PROB_NAME".out");

int main() {
	using namespace std;

	int swapn = 0;
	int v_size, i, j, n[4] = {};
	vector<int> v1;
	vector<int> v2;

	cin >> v_size;
	v1.resize(v_size);
	v2.resize(v_size);

	for (i = 0; i < v_size; ++i) {
		cin >> v1[i];
		v2[i] = v1[i];
	}

	sort(v1.begin(), v1.end());

	for (i = 0; i < v_size; ++i)
		for (j = i+1; j < v_size; ++j)
			if (v1[i] != v1[j] && v1[i] == v2[j] && v2[i] == v1[j]) {
	//			cout << v1[i] << ' ' << v1[j] << endl;
	//			cout << v2[i] << ' ' << v2[j] << endl;
				std::swap(v2[i], v2[j]);
				++swapn;
			}

	/*
	for (i = 0; i < v_size; ++i) {
		cout << v1[i] << ' ' << v2[i] << endl;
	}
	cout << endl;
	*/

	for (i = 0; i < v_size; ++i)
		for (j = v_size-1; j > i; --j)
			if (v2[i] > v2[j]) {
				std::swap(v2[i], v2[j]);
				++swapn;
			}

	cout << swapn << endl;

	return 0;
}

