
#include <iostream>

int main() {
	using namespace std;
	unsigned long long a, b;
	while (cin >> a >> b)
		cout << max(a, b) - min(a, b) << endl;
	return 0;
}

