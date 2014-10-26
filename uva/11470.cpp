
#include <iostream>
using namespace std;

#define MAX_N 10
int n;
int a[ MAX_N ][ MAX_N ];

int sum(int x, int y, int n) {
	int s = 0;
	for (int i = 0; i <= n; ++i) {
		s += a[x+i][y];		a[x+i][y] = 0;
		s += a[x][y+i];		a[x][y+i] = 0;
		s += a[x+n][y+i];	a[x+n][y+i] = 0;
		s += a[x+i][y+n];	a[x+i][y+n] = 0;
	}
	return s;
}

int main() {
	for (int tt = 1;; ++tt) {
		cin >>n;
		if (!n) break;

		for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >>a[i][j];

		cout <<"Case "<<tt<<':';
		for (int j = 0; n > 0; ++j) {
			cout <<' '<<sum(j, j, n-1);
			n -= 2;
		}
		cout <<endl;
	}

	return 0;
}

