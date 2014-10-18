
/*
ID: aybek.h2
PROG: runround
LANG: C++11
*/

#define PROB_NAME "runround"

#include <string>
//#include <cassert>
#include <cstdlib>
#include <cstdint>
#include <fstream>
//#include <iostream>

std::ifstream fin	(PROB_NAME".in");
std::ofstream fout	(PROB_NAME".out");

bool isRunround(std::string s) {

	bool set[10] = {};
	for (size_t i = 0; i < s.size(); ++i) {
		if (set[ s[i]-'0' ] == 0) set[ s[i]-'0' ] = 1;
		else return 0;
	}

	int i = 0, j, n = s.size();

	while (n--) {
		j = s[i]-'0';
		s[i] = '0';
		i = (i+j) % s.size();

		if (s[i] == '0') break;
	}

	if (n) return false;
	else if (i != 0) return false;
	else return true;
}

int M;

void handle(std::string s) {
	int n = atoi(s.c_str());

	if (n > M && isRunround(s)) {
		fout << n << std::endl;
		exit(0);
	}
}

void backtrack(std::string & s, size_t i, int used) {
	if (i == s.size()) {
		handle(s);
	}

	for (int d = 1; d <= 9; ++d)
		if (!(used & (1<<d))) {
			s[i] = static_cast<char>(d+'0');
			backtrack(s, i+1, used|(1<<d));
		}
}

int main() {
	fin >> M;

	int digNum, t;
	for (digNum = 0, t = M; t > 0; t /= 10) ++digNum;

	std::string s;
	s.reserve(9);
	s.resize(digNum);

	for (; s.size() < 8; s.push_back('0'))
		backtrack(s, 0, 0);

	return 0;
}

