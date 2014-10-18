
#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;

#define MAX_LEN				0x10000

#define DONT_PRINT			1
#define LEFT_APOS			96
#define RIGHT_APOS			39
#define DOUBLE_APOS			34

#define DOUBLE_LEFT_APOS	2
#define DOUBLE_RIGHT_APOS	3

#define UNSET -1

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	int last = UNSET;
	char c;

	char text[MAX_LEN]		= {};
	bool doprint[MAX_LEN]	= {};

	int i;
	for (i = 0; std::cin.get(c); ++i)
		text[i] = c;
	text[i] = '\0';

	for (int i = 0; text[i]; ++i) {
		doprint[i] = true;

		switch (text[i]) {

			case DOUBLE_APOS:
				if (last == UNSET)
					last = i;
				else {
					text[last] = DOUBLE_LEFT_APOS;
					text[i] = DOUBLE_RIGHT_APOS;
					last = UNSET;
				}
				break;

			case '\n':
				if (text[i+1] == '\n') {
					if (last != UNSET) {
						doprint[last] = false;
						last = UNSET;
					}
				}
				break;

			case '\\':
				if ((text[i+1] == 'p' && text[i+2] == 'a' && text[i+3] == 'r' && !isalpha(text[i+4]))
						||
					(text[i+1] == 'e' &&
						text[i+2] == 'n' &&
						text[i+3] == 'd' &&
						text[i+6] == 'i' &&
						text[i+7] == 'n' &&
						text[i+8] == 'p' &&
						text[i+9] == 'u' &&
						text[i+10]== 't'
					)
						) {
					if (last != UNSET) {
						text[last] = DONT_PRINT;
						last = UNSET;
					}
				}
				else if (text[i+1] == DOUBLE_APOS && isalpha(text[i+2])) {
					++i;
				}
				break;
		}
	}

	for (int i = 0; text[i]; ++i) {
		switch (text[i]) {
			case DOUBLE_LEFT_APOS:
				cout	<< static_cast<char>(LEFT_APOS)
						<< static_cast<char>(LEFT_APOS);
				break;

			case DOUBLE_RIGHT_APOS:
				cout	<< static_cast<char>(RIGHT_APOS)
						<< static_cast<char>(RIGHT_APOS);
				break;

			case DONT_PRINT:
				break;

			default:
				cout << text[i];
		}
	}
	

	return 0;
}

