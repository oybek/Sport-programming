
#include <iostream>

#define SCREEN_LEN 80

int main()
{
	char c;

	char a[ SCREEN_LEN ];
	for (int i = 0; i < SCREEN_LEN; ++i)
		a[i] = ' ';
	int pos = 0;

	while (std::cin.get(c)) {
		if (c == '\n')
			continue;

		if (c == '<') {
			--pos;
		} else
		if (c == '>') {
			++pos;
		} else {
			a[ pos++ ] = c;
		}

		if ((pos < 0) || (pos == SCREEN_LEN))
			pos = 0;
	}

	for (int i = 0; i < SCREEN_LEN; ++i)
		std::cout << a[i];
	std::cout << std::endl;

	return 0;
}

