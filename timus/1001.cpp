#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	vector<long long> v;
	long long temp;

	while (cin >> temp)
		v.push_back(temp);

	for (int i = v.size()-1; i >= 0; --i)
		printf("%.4lf\n", sqrt(v[i]));

	return 0;
}

