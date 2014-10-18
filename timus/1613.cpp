
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int n, q, l, r;
	long t;
	bool flag;
	map<long, vector<int> > stat;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		stat[t].push_back(i+1);
	}

	cin >> q;
	while (q--) {
		cin >> l >> r >> t;

		flag = 0;
		for (int i = 0; i < stat[t].size(); ++i) {
			if ((l <= stat[t][i]) && (stat[t][i] <= r))
				flag = 1;
		}
		cout << flag;
	}
	cout << endl;

	return 0;
}


