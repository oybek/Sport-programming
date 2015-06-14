
#include <ctype.h>
#include <stdio.h>

#define MAX_LEN 132

int main() {
	int n, c, i;
	char line[ MAX_LEN ];

	n = i = 0;
	while ( (c = getchar()) != EOF ) {
		if ( isdigit(c) ) {
			n += c - '0';
		} else
		if ( c == '!' ) {
			line[i] = '\0';
			i = 0;
			n = 0;
			printf("%s\n", line);
		} else {
			if ( c == 'b' )
				c = ' ';

			while ( n-- )
				line[ i++ ] = c;
		}
	}

	return 0;
}

