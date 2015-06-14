
/*
http://acm.timus.ru/problem.aspx?space=1&num=120
*/

#include <sstream>
#include <cassert>
#include <iostream>
#include <algorithm>

inline
void reverse(int * v, size_t a, size_t b) {
	while (a < b) 
		std::swap(v[a++], v[b--]);
}

inline
void show(int * v, size_t a, size_t b) {
	while (a <= b) {
		std::cout << v[a++] << ' ';
	}
	std::cout << std::endl;
}

int main() {
	using namespace std;

	size_t size, i, j, maxi;
	int v[ 31 ];

	string str;
	while (getline(cin, str)) {

		cout << str << endl;

		stringstream line(str);
		for (size = 0; line >> v[ size ]; ++size);
		reverse(v, 0, size - 1);

//		show(v, 0, size-1);

		for (i = 0; i < size - 1; ++i) {

			maxi = i;
			for (j = i+1; j < size; ++j) {
				if (v[ maxi ] < v[j])
					maxi = j;
			}

			if (maxi == i) {
			} else {
				if (maxi < size-1) {
					cout << maxi+1 << ' ';
					reverse(v, maxi, size-1);
				}
				if (i+1 < size-1) {
					cout << i+1 << ' ';
					reverse(v, i, size-1);
				}
			}
		}
		cout << 0 << endl;
	}

	return 0;
}

