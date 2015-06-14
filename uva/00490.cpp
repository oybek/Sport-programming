
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define SIZE 101
char text[ SIZE ][ SIZE ];

int main()
{
	int rown = 0, coln = 0;
	while (fgets(text[rown], SIZE, stdin) != NULL)
	{
		coln = max(coln, int(strlen(text[rown])));
		if (text[rown][coln-1] == '\n')
			text[rown][--coln] = '\0';
		++rown;
	}

	for (int j = 0; j < coln; ++j)
	{
		for (int i = rown-1; i >= 0; --i)
			switch (text[i][j])
			{
				case '\0':
				case '\t':
				case '\n':
					putchar(' ');
					break;

				default:
					putchar(text[i][j]);
					break;
			}
		puts("");
	}

	return 0;
}

