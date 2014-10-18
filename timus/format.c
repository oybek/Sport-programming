
#include <ctype.h>
#include <stdio.h>

int main() {
	int i, c, ind = 0;
	char id[4];
	const char * ts = "References";

	for (;;) {
		c = getchar();
		if (isdigit(c)) {
			id[ind] = c;
			if (++ind == 4)
				break;
		} else {
			ind = 0;
		}
	}

	putchar(id[0]);
	putchar(id[1]);
	putchar(id[2]);
	putchar(id[3]);

	for (i = 0;;) {
		c = getchar();
		putchar(c);

		if (c == ts[i]) {
			if (ts[++i] == '\0')
				break;
		} else {
			i = 0;
		}
	}

	return 0;
}

