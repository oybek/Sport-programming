#include <iostream>
using namespace std;

int main() {
	int in[6];
	for (int i = 0; i < 6; ++i) cin >> in[i];
	cout << in[5]-in[1] << ' ' << in[2]-in[0] << endl;

	return 0;
}

