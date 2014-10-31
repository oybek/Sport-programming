
#include <cctype>
#include <cstdio>
#include <iostream>
using namespace std;

const char * s[] = {
	"`1234567890-=",
	"qwertyuiop[]\\",
	"asdfghjkl;'",
	"zxcvbnm,./"
};

int main() {
	int c;
	while ((c = getchar()) != EOF) {
		if (isgraph(c)) {
			for (int i = 0; i < 4; ++i)
				for (int j = 0; s[i][j] != '\0'; ++j) {
					if (isalpha(c))
						c = tolower(c);
					if (s[i][j] == c)
						putchar(s[i][j-2]);
				}
		} else {
			putchar(c);
		}
	}

	return 0;
}

