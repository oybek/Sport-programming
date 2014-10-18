#include <iostream>
#include <map>
using namespace std;

int main()
{
	int n, m, s = 0;
	long t;
	map<long, bool> prep;

	cin >> n;
	while (n--) {
		cin >> t;
		prep[t] = 1;
	}

	cin >> m;
	while (m--) {
		cin >> t;
		if (prep.find(t) != prep.end())
			++s;
	}
	cout << s << endl;

	return 0;
}

