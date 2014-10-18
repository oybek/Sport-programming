#include <iostream>
using namespace std;

int main()
{
	long N;
	cin >> N;

	int * o1 = new int [N];
	int * o2 = new int [N];
	int * sum = new int [N];

	for (int i = N-1; i >= 0; --i)
		cin >> o1[i] >> o2[i];

	int toup = 0;
	for (int i = 0; i < N; ++i) {
		sum[i]	= (o1[i]+o2[i]+toup)%10;
		toup	= (o1[i]+o2[i]+toup)/10;
	}

	for (int i = N-1; i >= 0; --i)
		cout << sum[i];
	cout << endl;


	return 0;
}

