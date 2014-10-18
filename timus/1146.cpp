
#include <map>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define MAX_SIZE 100

void make_prefix_sum_matrix(int a[][MAX_SIZE], int s[][MAX_SIZE], int size) {
	int i, j;

	s[0][0] = a[0][0];

	// count 1st column
	for (i = 1; i < size; ++i)
		s[i][0] = s[i-1][0] + a[i][0];

	// count 1st row
	for (j = 1; j < size; ++j)
		s[0][j] = s[0][j-1] + a[0][j];

	for (i = 1; i < size; ++i)
		for (j = 1; j < size; ++j)
			s[i][j] = s[i-1][j] + s[i][j-1] + a[i][j] - s[i-1][j-1];
}

void show(int s[][MAX_SIZE], int size) {
	int i, j;
	for (i = 0; i < size; ++i) {
		for (j = 0; j < size; ++j)
			std::cout << s[i][j] << ' ';
		std::cout << std::endl;
	}
}

int count_submatrix_sum(int s[][MAX_SIZE], int i, int j, int i2, int j2) {
	int sum;

	if (i == 0) {
		if (j == 0)
			sum = s[i2][j2];
		else
			sum = s[i2][j2] - s[i2][j-1];
	} else {
		if (j == 0)
			sum = s[i2][j2] - s[i-1][j2];
		else
			sum = s[i2][j2] - s[i-1][j2] - s[i2][j-1] + s[i-1][j-1];
	}

	return sum;
}

int main() {
	using namespace std;

	int size, i, j, i2, j2, maxsum;
	int a[MAX_SIZE][MAX_SIZE];
	int s[MAX_SIZE][MAX_SIZE];

	// input
	cin >> size;
	for (i = 0; i < size; ++i)
		for (j = 0; j < size; ++j)
			cin >> a[i][j];

	make_prefix_sum_matrix(a, s, size);

	// Bruteforce

	maxsum = s[0][0];

	for (i = 0; i < size; ++i)
	for (j = 0; j < size; ++j)
		for (i2 = i+1; i2 < size; ++i2)
		for (j2 = j+1; j2 < size; ++j2)
			maxsum = max(count_submatrix_sum(s, i, j, i2, j2) , maxsum);

	for (i = 0; i < size; ++i)
		for (j = 0; j < size; ++j)
			maxsum = max(maxsum, a[i][j]);

	cout << maxsum << endl;


	return 0;
}

