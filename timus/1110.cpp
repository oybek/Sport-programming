
#include <iostream>
#include <map>

inline int f(int x, int n, int m) {
	if (n == 0)
		return 1%m;
	else
		return f(x, n-1, m)*x%m;
}

int main() {
	using namespace std;

	bool flag = 0;
	int n, m, y;
	cin >> n >> m >> y;

	for (int x = 0; x < m; ++x) {
		if (f(x, n, m) == y) {
			cout << x << ' ';
			flag = 1;
		}
	}
	if (!flag)
		cout << -1;
	cout << endl;

	return 0;
}

