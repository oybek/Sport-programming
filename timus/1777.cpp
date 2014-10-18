#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

#define loop(n) for (int i = 0; i < n; ++i)

int coord {
	int oybek;
	int oleg;
	int frank;
	int bob;
};

int main(int argc, char ** argv) {
	vector<long long> stone(3);
	loop(3)
		cin >> stone[i];

	int count = 1;
	long long mindiff = LLONG_MAX;

	while (1) {
		sort(stone.begin(), stone.end());

		for (int i = 0; i < (stone.size()-1); ++i)
			if ((stone[i+1]-stone[i]) < mindiff)
				mindiff = stone[i+1]-stone[i];

		if (!mindiff)
			break;
		else {
			count++;
			stone.push_back(mindiff);
		}
	}

	cout << count << endl;

	return 0;
}

