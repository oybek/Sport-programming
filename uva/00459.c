
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PSET_MAX_SIZE 'Z'-'A'+1

int pset_sz, pset[ PSET_MAX_SIZE ];

void init(int _size) {
	pset_sz = _size;
	int i;
	for (i = 0; i < pset_sz; ++i)
		pset[i] = i;
}

int set_of(int i) {
	return (pset[i] == i) ? i: (pset[i] = set_of(pset[i]));
}

void union_set(int i, int j) {
	pset[ set_of(i) ] = set_of(j);
}

int is_in_same_set(int i, int j) {
	return set_of(i) == set_of(j);
}

int number_of_sets() {
	int n = 0, i;
	for (i = 0; i < pset_sz; ++i)
		n += (pset[i] == i);
	return n;
}

int size_of_set(int i) {
	int n = 0, j;
	for (j = 0; j < pset_sz; ++j)
		n += is_in_same_set(i, j);
	return n;
}

int main() {
	int N, first = 1;
	char c, s[8];

	scanf("%d", &N);
	getchar();
	getchar();
	while (N--) {
		c = getchar();
		getchar();

		init(c-'A'+1);

		while (1) {
			if (!fgets(s, 8, stdin))
				break;

			if (s[0] == '\n')
				break;
			union_set(s[0]-'A', s[1]-'A');
		}

		if (first) first = 0;
		else putchar('\n');
		printf("%d\n", number_of_sets());
	}

	return 0;
}

