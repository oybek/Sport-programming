#include <iostream>
using namespace std;

int main()
{
	char	dash[3][3], c;
	char *	p = &dash[0][0];
	while (cin.get(c))
		switch (c) {
			case 'X':
				*p++ = 2;
				break;
			case 'O':
				*p++ = 1;
				break;
			case '#':
				*p++ = 0;
				break;
		}

	for (int i = 0; i < 3; ++i)
	for (int j = 0; j < 3; ++j)
		cout << (int)dash[i][j] << endl;

	return 0;
}

