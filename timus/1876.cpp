
#include <cmath>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	int a, b;
	std::cin >> a >> b;
	std::cout << a+2*b+3*(a-40)+3*(b-40) << std::endl;

	return 0;
}

