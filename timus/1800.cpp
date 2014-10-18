
#include <cmath>
#include <iostream>

int main() {
	using namespace std;

	float l, h, T;
	cin >> l >> h >> T;
	int obor_num = round(2*(T*sqrt( abs(2.0*(h-l/2))/981.0 )));

	if (obor_num%2 == 0) {
		cout << "bread\n";
	} else {
		cout << "butter\n";
	}

	return 0;
}

