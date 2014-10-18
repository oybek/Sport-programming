
#include <iostream>

int main() {
	using namespace std;

	long m, ln, in;

	int size;
	cin >> size;
	while (size--) {
		cin >> m;

		// number of lines
		ln = m*(m-1);
		// number of intersetions
		//in = ln-m;
		
		cout << ln+1 << endl;
	}

	return 0;
}

