
#include <iostream>
using namespace std;

int main()
{
	int x, y, z, correctn = 0;
	char op, is, c;

	while ( cin >> x >> op >> y >> is ) {
		if ( (c = cin.get()) == '?' ) {
			continue;
		} else {
			cin.unget();
			cin >> z;
		}
		switch ( op ) {
			case '+': correctn += (x + y == z); break;
			case '-': correctn += (x - y == z); break;
		}
	}
	cout << correctn << endl;

	return 0;
}

