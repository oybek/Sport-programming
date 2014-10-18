
/*
http://acm.timus.ru/problem.aspx?space=1&num=1731
*/

#include <cassert>
#include <iostream>
#include <algorithm>

int main() {
	using namespace std;
	int n, m, i;
	cin >> n >> m;
	for (i = 1; i <= n; ++i)
		cout << i << ' ';
	cout << endl;
	for (i = 1; i <= m; ++i)
		cout << i*100 << ' ';
	cout << endl;

	return 0;
}

