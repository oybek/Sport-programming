#include <iostream>
using namespace std;

class ticket_t {
	private:
		int l[3];
		int c[3];

	public:

		ticket_t()
		{
			cin >> l[0] >> l[1] >> l[2];
			cin >> c[0] >> c[1] >> c[2];
		}

		int cost(int d)
		{
			if ((0 < d) && (d <= l[0]))
				return c[0];
			else if ((l[0] < d) && (d <= l[1]))
				return c[1];
			else if ((l[1] < d) && (d <= l[2]))
				return c[2];
			else
				return 0xFFFFFFFF;
		}
};

struct station_t {
	long s; // distance between 1st and current station
	long minc; // min cost between some and current station
};

int main() {
	ticket_t tick;
	station_t * stat;

	int n, start, finish;
	cin >> n;
	cin >> start >> finish;

	stat = new station_t [n+1];

	stat[1].s = 0;
	for (int i = 2; i <= n; ++i)
		cin >> stat[i].s;

	for (int i = finish-1; i >= start; --i) {
		stat[i].minc = 0xFFFFFFFF;
		for (int j = finish; j > i; --j)
			stat[i].minc = min
	}

	return 0;
}

