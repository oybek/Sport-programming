
/*
ID: aybek.h2
PROG: barn1
LANG: C++11
*/

#define PROB_NAME "barn1"

#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

#define segment(a, b)	((a)-(b)+1)
#define interval(a, b)	((a)-(b)-1)

class eject_queue {
	public:
		int		size;
		int *	buf;

		eject_queue(int n) : size(n)
		{
			buf = new int [size];
			for (int i = 0; i < size; ++i)
				buf[i] = 0;
		}
		void push(int val)
		{
			for (int i = 0; i < size; ++i)
				if (val > buf[i]) {
					for (int j = size-1; j > i; --j)
						buf[j] = buf[j-1];
					buf[i] = val;
					break;
				}
		}
};

int main()
{
	ifstream fin	(PROB_NAME".in");
	ofstream fout	(PROB_NAME".out");

	int maxBoard, stallNum, cowNum, currCow, prevCow, firstCow;
	fin >> maxBoard >> stallNum >> cowNum;

	eject_queue q(maxBoard-1);
	vector<int> cow(cowNum);

	for (int i = 0; i < cowNum; ++i)
		fin >> cow[i];

	sort(cow.begin(), cow.end());

	for (int i = 1; i < cowNum; ++i)
		q.push(interval(cow[i], cow[i-1]));

	int maxLen = segment(cow[cowNum-1], cow[0]);
	for (int i = 0; i < q.size; ++i)
		maxLen -= q.buf[i];

	fout << maxLen << '\n';


	return 0;
}

