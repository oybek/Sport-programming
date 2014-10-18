#include <iostream>
using namespace std;

void printan(int n)
{
	int i;
	bool sign = 1;
	for (i = 1; i <= n; ++i, sign = !sign) {
		cout << "sin(" << i;
		if (i < n)
			cout << (sign?'-':'+');
	}
	for (i = 1; i <= n; ++i) cout << ')';
}

void printsn(int n)
{
	int i;
	for (i = 1; i < n; ++i)
		cout << '(';
	for (i = 1; i < n; ++i) {
		printan(i);
		cout << "+" << n-i+1 << ')';
	}
	printan(n);
	cout << "+1" << endl;
}

int main()
{
	int n;
	cin >> n;
	printsn(n);

	return 0;
}

