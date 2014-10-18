
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>

#define MAX_SIZE 81

#define IN(i, a, b) ((a <= i) && (i <= b))

int left(int i)
{
	if ( IN(i,	0,	0)	) return i + 1;
	if ( IN(i,	1,	2)	) return i + 2;
	if ( IN(i,	3,	5)	) return i + 3;
	if ( IN(i,	6,	9)	) return i + 4;
	if ( IN(i,	10,	14)	) return i + 5;
	if ( IN(i,	15,	20)	) return i + 6;
	if ( IN(i,	21,	27)	) return i + 7;
	if ( IN(i,	28,	35)	) return i + 8;
	return -1;
}

#define right(i) (left(i) + 1)

int main()
{
	int a[ SIZE ];

	return 0;
}

