
#include <iostream>
using namespace std;

int x;
int count_5(int n) {
	int count = 0;
	for (; n%5 == 0; n /= 5)
		++count;
	return count;
}

int main() {
	cin >> x;
	int ans = 0;
	for (int n = 5; n <= x; n += 5)
		ans += count_5(n);
	cout << ans << endl;

	return 0;
}

