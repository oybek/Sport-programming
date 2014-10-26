
#include <iostream>
using namespace std;

#define mod 1000000007

typedef unsigned long long ull;

ull pow_mod(ull x, ull y, ull m) {
	ull acc = 1, z = x % m;
	while (y) {
		if (y & 1)
			acc = (acc * z) % m;
		z = (z * z) % m;
		y >>= 1;
	}
	return acc;
}

/*uint64 pow_mod(uint64 a, uint64 b) {*/
	/*if (b == 0ull) return 1ull;*/
	/*else {*/
		/*if (b%2ull == 0ull) {*/
			/*int t = pow_mod(a%mod, b/2ull);*/
			/*return t*t % mod;*/
		/*} else {*/
			/*return (a * pow_mod(a, b-1ull))%mod;*/
		/*}*/
	/*}*/
/*}*/

int main() {
	ull a, b;
	cin >> a >> b;
	cout << pow_mod(a, b, mod) << endl;

	return 0;
}

