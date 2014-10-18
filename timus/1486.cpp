
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool SqrCmp(const vector<string> & m,
		int x1, int y1,
		int x2, int y2,
		int size)
{
	int i1, j1, i2, j2;

	for (i1 = 0; i1 < size; ++i1)
	for (j1 = 0; j1 < size; ++j1)
		for (i2 = 0; i2 < size; ++i2)
		for (j2 = 0; j2 < size; ++j2)
			if (m[ x1+i1 ][ y1+j1 ] != m[ x2+i2 ][ y2+j2 ])
				return false;
	return true;
}

int main()
{
	using namespace std;

	int size, s_len;
	cin >> size >> s_len;

	int i1, j1, i2, j2;
	vector<string> a(size);

	for (i1 = 0; i1 < size; ++i1)
		cin >> a[i1];
	
	for (i1 = 0; i1 < size; ++i1)
	for (j1 = 0; j1 < size; ++j1)
		for (i2 = i1+1; i2 < size; ++i2)
		for (j2 = j1; j2 < size; ++j2)


	return 0;
}

