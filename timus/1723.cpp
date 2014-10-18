#include <cstdio>
using namespace std;

int main()
{
	int maxi = 0, grid[0x100] = {}, c;

	while ((c = getchar()) != '\n') {
		if (++grid[c] > grid[maxi])
			maxi = c;
	}
	putchar(maxi);

	return 0;
}

