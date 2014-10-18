
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

#define SIZE 256

int price[ SIZE ];
int amount[ SIZE ];

int main()
{
	string s;
	int N, K, M;

	cin >> N;
	while (N--)
	{
		fill(price, price+SIZE, 0);
		fill(amount, amount+SIZE, 0);

		cin >> K;
		while (K--)
		{
			unsigned char c;
			cin >> c;
			cin >> price[(unsigned int)(c)];
		}

		cin >> M;
		getline(cin, s);
		while (M--)
		{
			getline(cin, s);
			for (int i = 0; i < int(s.size()); ++i)
				++amount[(unsigned int)(s[i])];
		}

		double cash = 0.0;
		for (int i = 0; i < SIZE; ++i)
			cash += amount[i]*price[i];

		printf("%.2f$\n", cash/100);
	}

	return 0;
}

