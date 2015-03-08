
#include <bitset>
#include <string>
#include <cassert>
#include <iostream>
using namespace std;

#define SIZE 30

typedef unsigned int uint32;

inline
bool bit(uint32 n, int i) {
	if (i < 0) i += 30;
	if (i >29) i %= 30;
	return n&(1<<i);
}

string int2bin(uint32 n) {
	string s;
	for (int i = 0; i < 30; ++i) {
		s += (n&1)+'0';
		n >>= 1;
	}
	return s;
}

int onebitn(uint32 n) {
	int count = 0;
	for (; n > 0; n >>= 1)
		count += n&1;
	return count;
}

bool is_good(uint32 conf) {
	int count;
	uint32 was = 0;

	/* there are 12 knights who have one lier neighbour */
	count = 0;
	for (int i = 0; i < 30; ++i) {
		if (bit(conf, i) == 0 && (bit(conf, i-1) + bit(conf, i+1) == 1)) {
			++count;
			was |= (1<<i);
		}
	}
	if (count == 12)
		return true;

	/* there are another 18 person who are liers or knights and say that both there neighbour are liers: */
	for (int i = 0; i < 30; ++i) {
		if (was&(1<<i))
			continue;
		/* if he is knight then both of his neighbours are liers */
		if (bit(conf, i) == 0) {
			count += (bit(conf, i-1) && bit(conf, i-1));
		}

		/* if current person is lier that doesn't matter what he says */
		if (bit(conf, i) == 1) {
			++count;
		}
	}
	if (count == 18)
		return true;

	return false;
}

int soln = 1;
void backtrack(uint32 conf, int i) {
	if (i >= SIZE) {
		if (i == SIZE && is_good(conf)) {
			cout << soln++ << ' ' << int2bin(conf) << ' ' << onebitn(conf) << " liers\n";
		}
		return;
	}

	if (i > 1) {
		if ((conf&(1<<(i-1))) == 0 &&
			(conf&(1<<(i-2))) == 0) {
			backtrack(conf|(1<<i)|(1<<(i+1)), i+2);
		}
		if ((conf&(1<<(i-1))) == 0) {
			backtrack(conf|(1<<i)|(1<<(i+1)), i+2);
		}
		if ((conf&(1<<(i-1))) != 0 &&
			(conf&(1<<(i-2))) != 0) {
			backtrack(conf&~(1<<i)&~(1<<(i+1)), i+2);
			backtrack(conf&~(1<<i), i+1);
		}
	} else {
		backtrack(conf|(1<<i)|(1<<(i+1)), i+2);
		backtrack(conf&~(1<<i)&~(1<<(i+1)), i+2);
		backtrack(conf&~(1<<i), i+1);
	}
}

int main() {
	backtrack(0, 0);

	return 0;
}

