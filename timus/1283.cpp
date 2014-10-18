
#include <iostream>
using namespace std;

int main() {
	float money, sense, per;
	cin >> money >> sense >> per;

	unsigned int year = 0;
	while (money > sense) {
		money -= (per*money)/100;
		++year;
	}
	cout << year << endl;

	return 0;
}

