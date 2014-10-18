
/*
ID: aybek.h2
PROG: zerosum
LANG: C++
*/

#define PROB_NAME "zerosum"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

std::ifstream fin	(PROB_NAME".in");
std::ofstream fout	(PROB_NAME".out");

int makeOperations(std::string s) {
	int val;
	unsigned int i;
	std::vector<int> v(s.size()+1);

	for (i = 0; i < v.size(); ++i)
		v[i] = i+1;

	for (i = 0; i < s.size();)
		if (s[i] == ' ') {
			s.erase(s.begin()+i);
			v[i] = v[i+1] = v[i]*10+v[i+1];
			v.erase(v.begin()+i+1);
		} else {
			++i;
		}

	val = v[0];
	for (i = 0; i < s.size(); ++i)
		switch (s[i]) {
			case '+': val += v[i+1]; break;
			case '-': val -= v[i+1]; break;
		}

	return val;
}

void backtrack(std::string s, unsigned int i) {
	using namespace std;

	if (i == s.size()) {
		int val = makeOperations(s);

		if (val == 0) {
			fout << 1;
			for (unsigned int i = 0; i < s.size(); ++i)
				fout << s[i] << i+2;
			fout << std::endl;
		}
		return;
	}

	s[i] = ' '; backtrack(s, i+1);
	s[i] = '+'; backtrack(s, i+1);
	s[i] = '-'; backtrack(s, i+1);
}

int main() {
	int n;
	std::string s;

	fin >> n;
	s.resize(n-1);
	backtrack(s, 0);

	return 0;
}

