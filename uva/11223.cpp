
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstring>
#include <climits>
#include <iomanip>
#include <iostream>
#include <algorithm>

#define INF 1000000001
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

map<string, char> s;

int main() {
	s[".-"] = 'A';
	s[".---"] = 'J';
	s["..."] = 'S';
	s[".----"] = '1';
	s[".-.-.-"] = '.';
	s["---..."] = ':';
	s["-..."] = 'B';
	s["-.-"] = 'K';
	s["-"] = 'T';
	s["..---"] = '2';
	s["--..--"] = ',';
	s["-.-.-."] = ';';
	s["-.-."] = 'C';
	s[".-.."] = 'L';
	s["..-"] = 'U';
	s["...--"] = '3';
	s["..--.."] = '?';
	s["-...-"] = '=';
	s["-.."] = 'D';
	s["--"] = 'M';
	s["...-"] = 'V';
	s["....-"] = '4';
	s[".----."] = ''';
	s[".-.-."] = '+';
	s["."] = 'E';
	s["-."] = 'N';
	s[".--"] = 'W';
	s["....."] = '5';
	s["-.-.--"] = '!';
	s["-....-"] = '-';
	s["..-."] = 'F';
	s["---"] = 'O';
	s["-..-"] = 'X';
	s["-...."] = '6';
	s["-..-."] = '/';
	s["..--.-"] = '_';
	s["--."] = 'G';
	s[".--."] = 'P';
	s["-.--"] = 'Y';
	s["--..."] = '7';
	s["-."] = '(';–.
	s[".-..-."] = '"';
	s["...."] = 'H';
	s["--.-"] = 'Q';
	s["--.."] = 'Z';
	s["---.."] = '8';
	s["-.--.-"] = ')';
	s[".--.-."] = '@';
	s[".."] = 'I';
	s[".-."] = 'R';
	s["-----"] = '0';
	s["----."] = '9';
	s[".-..."] = '&';

	int T;
	string line, word;
	cin >> T;
	while (T--) {
		getline(cin, line);
		for (int i = 0; i+1 < line.size(); ++i) {
			if (line[i] == ' ') {
				if (i+1 < line.size() && line[i+1] == ' ')
					cout << ' ';
				else {
					cout << s[word];
					word = "";
				}
			}
		}
	}

	return 0;
}

