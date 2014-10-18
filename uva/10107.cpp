
#include <iostream>
using namespace std;

#define MAX_SIZE 10000

int a[ MAX_SIZE ], a_sz = 0;

void insert(int v) {
	if (a_sz == 0) {
		a[ a_sz++ ] = v;
		return;
	}

	int i;
	for (i = a_sz-1; (i >= 0) && (a[i] > v); --i)
		a[i+1] = a[i];
	a[i+1] = v;
	++a_sz;
}

int main() {
	int n;
	while (cin >> n) {
		insert(n);

		if (a_sz%2) {
			cout << a[ a_sz/2 ] << endl;
		} else {
			cout << (a[ a_sz/2-1 ]+a[ a_sz/2 ])/2 << endl;
		}
	}

	return 0;
}

