#include <iostream>
#include <string>
using namespace std;

#define loop(n) for (int i = 0; i < (n); ++i)

int main() {
	int n;
	string str;
	cin >> n >> str;
	long long t = 1;

	while (n > 0) {
		t *= n;
		n -= str.size();
	}

	cout << t << endl;

	return 0;
}

