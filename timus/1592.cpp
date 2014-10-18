
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		char c;
		int h, m, s;
		cin >> h >> c >> m >> c >> s;
		cout << h*3600+m*60+s << ' ' << h*60+m << endl;
	}

	return 0;
}

