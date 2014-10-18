
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a, n;
	cin >> n;

	int sum = 0, maxp = 0;

	while (n--) {
		cin >> a;
		sum += a;

		if (sum < 0)
			sum = 0;

		maxp = max(sum,maxp);
	}
	cout << maxp << endl;

	return 0;
}

