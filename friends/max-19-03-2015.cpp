
#include <iostream>
using namespace std;

bool bin_pal(int n) {
	int i = 0, j = 0;
	for (int m = n; m > 1; m >>= 1) ++j;
	for (; i < j; --j, ++i)
		if ((n&(1<<i)) && !(n&(1<<j)) || !(n&(1<<i)) && (n&(1<<j)))
			return false;
	return true;
}

int main() {

	return 0;
}

