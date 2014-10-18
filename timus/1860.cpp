
#include <iostream>

#define SIZE 10

int main() {
	using namespace std;
	uint64_t f[SIZE];

	f[0] = 1;
	f[1] = 1;

	for (int i = 2; i < SIZE; ++i) {
		f[i] = i*f[i-1]*f[i-2];
		cout << "f(" << i << ") " << f[i] << endl;
	}

	return 0;
}

