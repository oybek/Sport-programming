#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	char c;
	bool isup = 1;
	while (cin.get(c)) {
		if (isalpha(c)) {
			cout << (char)(isup?c:tolower(c));
			isup = false;
		}
		else
			cout << (char)c;

		switch (c) {
			case '!': case '?': case '.':
				isup = true;
				break;
		}
	}

	return 0;
}

