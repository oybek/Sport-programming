
#include <ctype.h>
#include <stdio.h>

int f(int n) {
	if (n < 10) return n;

	int s = 0;
	for (s = 0; n > 0; n /= 10)
		s += n%10;

	return f(s);
}

int main() {
	int c;
	while ((c = getchar()) != EOF) {
		int s1 = 0, s2 = 0;

		do {
			if (isalpha(c)) {
				s1 += tolower(c)-'a'+1;
			}
		} while ((c = getchar()) != '\n');

		do {
			if (isalpha(c)) {
				s2 += tolower(c)-'a'+1;
			}
		} while ((c = getchar()) != '\n');

		s1 = f(s1);
		s2 = f(s2);

		if (s1 < s2) {
			printf("%.2f %\n", s1*100.0/s2);
		} else {
			printf("%.2f %\n", s2*100.0/s1);
		}
	}

	return 0;
}

