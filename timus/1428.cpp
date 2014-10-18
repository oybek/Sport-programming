
/*
http://acm.timus.ru/problem.aspx?space=1&num=1428
*/

#include <iostream>

int main() {
	using namespace std;
	int a, b, c;
	cin >> a >> b >> c;
	cout	<< (1ul<<((c-1)/a)) << endl
			<< (1ul<<((c-1)/b)) << endl
			<< 2 << endl;

	return 0;
}

