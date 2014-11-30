
#include <cmath>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

#define SIZE 25000

void printer(vector<int> & a, vector<int> & b)
{
	/* a is sorted */
	for (int i = 0; i <= SIZE; ++i)
	{
		b.push_back(a.end() - upper_bound(a.begin(), a.end(), i));
		if (b.back() == 0)
		{
			b.pop_back();
			break;
		}
	}
}

int main()
{
	int size;
	vector<int> a, b;
	a.reserve(SIZE+1);
	b.reserve(SIZE+1);

	scanf("%d", &size);
	a.resize(size);
	for (int i = 0; i < size; ++i)
		scanf("%d", &a[i]);

	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());

	/*printer(a, b);*/

	/*for (int i = 0; i < int(b.size()); ++i)*/
		/*printf("%d\n", b[i]);*/
	/*puts("");*/

	/*sort(b.begin(), b.end());*/
	/*a.resize(0);*/
	/*printer(b, a);*/

	for (int i = 0; i < int(a.size()); ++i)
		printf("%d\n", a[i]);

	return 0;
}

