#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main()
{
	char		a;
	size_t		i;
	uint8_t		radix;
	uint64_t	dig_sum;

	radix = 1;
	dig_sum = 0;

	while (cin.get(a)) {
		if (isdigit(a)) {
			dig_sum += a-'0';

			if (a-'0'+1 > radix)
				radix = a-'0'+1;
		}
		else
		if (isalpha(a)) {
			dig_sum += a -'A'+10;

			if (a-'A'+11 > radix)
				radix = a-'A'+11;
		}
	}

	if (radix == 1) {
		cout << 2 << endl;
		return 0;
	}

	for (i = radix; i < 37; ++i)
		/* Solution found */
		if (!(dig_sum%(i-1))) {
			cout << i << endl;
			return 0;
		}

	cout << "No solution." << endl;

	return 0;
}

