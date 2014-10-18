#include <iostream>
#include <vector>
using namespace std;

void insert(vector<int> & a, int val) {
	a.push_back(val); // it is bad
	for (int i = a.size()-2; (i > 0) && (a[i] > val); --i)
		a[i+1] = a[i];
	a[i+1] = val;
}

int main(int argc, char ** argv) {
	int n, t;
	cin >> n;

	vector<int> a;

	while (n--) {
		cin >> t;
		a.push_back(t);
	}

	int sum = a[0];
	for (int i = 1; i < a.size(); ++i) {
		sum += max(a[i-1], a[i]);
	}
	sum += a[n-1];

	cout << sum << endl;


	return 0;
}
