
/*
ID: aybek.h2
PROG: preface
LANG: C++11
*/

#define PROB_NAME "preface"

#include <map>
//#include <cassert>
#include <fstream>
//#include <iostream>

std::ifstream cin	(PROB_NAME".in");
std::ofstream cout	(PROB_NAME".out");

std::string decToRom(int decNum) {
	/* if (decNum > 3999) OR (decNum < 1) roman = "N/A" return endif */
	std::string romNum;

	for (; decNum > 999; decNum -= 1000) romNum += "M";
	if (decNum > 899) { romNum += "CM"; decNum -= 900; }
	if (decNum > 499) { romNum += "D"; decNum -= 500; }
	if (decNum > 399) { romNum += "CD"; decNum -= 400; }
	for (; decNum > 99; decNum -= 100) romNum += "C";
	if (decNum > 89) { romNum += "XC"; decNum -= 90; }
	if (decNum > 49) { romNum += "L"; decNum -= 50; }
	if (decNum > 39) { romNum += "XL"; decNum -= 40; }
	for (; decNum > 9; decNum -= 10) romNum += "X";
	if (decNum > 8) { romNum += "IX"; decNum -= 9; }
	if (decNum > 4) { romNum += "V"; decNum -= 5; }
	if (decNum > 3) { romNum += "IV"; decNum -= 4; }
	for (; decNum > 0; --decNum) romNum += "I";
	return romNum;
}

int main() {
	int n, charNum['Z'] = {};
	const std::string s("IVXLCDM");

	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (auto e : decToRom(i))
			++charNum[e];

	for (auto e : s)
		if (charNum[ e ] != 0)
			cout << e << ' ' << charNum[ e ] << std::endl;

	return 0;
}

