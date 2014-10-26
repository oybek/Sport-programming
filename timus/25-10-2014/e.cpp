
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	int m, n, ans = 0;
	unordered_set<int> teacher_list;

	cin >> n;
	while (n--) {
		int t;
		cin >> t;
		teacher_list.insert(t);
	}

	cin >> m;
	while (m--) {
		int t;
		cin >> t;
		if (teacher_list.find(t) != teacher_list.end())
			++ans;
	}

	cout << ans << endl;

	return 0;
}

