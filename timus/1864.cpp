#include <iostream>
#include <cmath>

int main()
{
	int N;
	std::cin >> N;
	float * sok = new float [N];
	float sum = 0.0;

	for (int i = 0; i < N; ++i) {
		std::cin >> sok[i];
		sum += sok[i];
	}

	float sred = sum/(N+1);
	sum = 0.0;

	for (int i = 0; i < N; ++i) {
		sok[i] -= sred;

		if (sok[i] < 0.0)
			sok[i] = 0.0;

		sum += sok[i];
	}

	for (int i = 0; i < N; ++i)
		std::cout << floor((100*sok[i])/sum+0.0001) << ' ';
	std::cout << std::endl;
	
	return 0;
}

