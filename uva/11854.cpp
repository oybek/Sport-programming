
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>

int main()
{
	using namespace std;

	int a, b, c;
	while ( cin >> a >> b >> c )
	{
		if (!a && !b && !c)
			break;

		if ( a > b ) swap(a, b);
		if ( b > c ) swap(b, c);

		if ( c*c == a*a + b*b )
			cout << "right\n";
		else
			cout << "wrong\n";
	}

	return 0;
}

