
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int N, a, d;

	cin >> N
		>> a >> d;

	char ** related = new char * [N];
	for (int i = 0; i < N; ++i)
		related[i] = new char [N];

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> related[i][j];




	return 0;
}

