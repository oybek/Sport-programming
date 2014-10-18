#include <iostream>
using namespace std;
int main()
{
	int s = 0;
	char tmp;

	while (cin >> tmp) s += tmp - '0';
	if (s % 3 == 0) cout << 2;
	else cout << 1 << '\n' << s % 3;

	return 0;
}
