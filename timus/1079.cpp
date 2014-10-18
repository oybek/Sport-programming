#include <iostream>

#define max(a, b) ((a) < (b) ? (b): (a))

int last = 1;
int mem[100000];
int max[100000];

int F(int n)
{
	for (int i = last+1; i <= n; ++i) {
		if (i%2)
			mem[i] = mem[i/2]+mem[i/2+1];
		else
			mem[i] = mem[i/2];

		max[i] = max(mem[i], max[i-1]);
	}

	return max[n];
}

int main()
{
	mem[0] = 0; mem[1] = 1;
	max[0] = 0; max[1] = 1;

	int n;
	while (1) {
		std::cin >> n;

		if (!n) break;
		
		std::cout << F(n) << std::endl;
	}


	return 0;
}

