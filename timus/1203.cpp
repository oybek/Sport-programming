
#include <iostream>
#include <algorithm>
using namespace std;

struct interval {
	int a, b;

	bool operator < (interval i1, interval i2) {
		return i1.b < i2.b;
	}
};

int main() {

	return 0;
}

