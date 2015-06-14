
#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>

int find(const std::vector<std::string> & s, const std::string & p)
{
	size_t i, j;
	for (i = 1; i < s.size(); ++i) {
		for (j = 0; j < p.size(); ++j)
			if (p[j] != s[i][j])
				break;

		if (j == p.size())
			return i;
	}
	return -1;
}

int main() {
	using namespace std;

	vector<string> s;
	for (uint32_t i = 1; i != 0; i <<= 1)
		s.push_back(to_string(i));

	int i;
	string n;
	while (cin >> n) {
		if ((i = find(s, n)) == -1) {
			cout << "no power of 2\n";
		} else {
			cout << i << endl;
		}
	}

	return 0;
}

