
/*
ID: aybek.h2
PROG: lamps
LANG: C++
*/

#define PROB_NAME "lamps"

#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

std::ifstream cin	(PROB_NAME".in");
std::ofstream cout	(PROB_NAME".out");

#define SWITCH(a) a = (a == '1' ? '0': '1')

#define SWITCH1(conf) for (int i = 0; i < conf.size(); i += 1) SWITCH(conf[i])
#define SWITCH2(conf) for (int i = 1; i < conf.size(); i += 2) SWITCH(conf[i])
#define SWITCH3(conf) for (int i = 0; i < conf.size(); i += 2) SWITCH(conf[i])
#define SWITCH4(conf) for (int i = 0; i < conf.size(); i += 3) SWITCH(conf[i])

inline
bool doesMatch(const std::string & s1, const std::string & s2) {
	for (int i = 0; i < s1.size(); ++i)
		if (s1[i] != '.' && s1[i] != s2[i])
			return false;
	return true;
}

/* returns number of switches made */
int makeSwitches(std::string & conf, int n) {
	int sn = 0;

	if (n&1) { SWITCH1(conf); ++sn; }
	if (n&2) { SWITCH2(conf); ++sn; }
	if (n&4) { SWITCH3(conf); ++sn; }
	if (n&8) { SWITCH4(conf); ++sn; }

	return sn;
}

int main() {
	using namespace std;

	string pattern;
	int n, c, t;

	/* input area */
	cin >> n >> c;

	pattern.resize(n);
	fill(pattern.begin(), pattern.end(), '.');

	for (;;) {
		cin >> t; if (t == -1) break;
		pattern[t-1] = '1';
	}
	for (;;) {
		cin >> t; if (t == -1) break;
		pattern[t-1] = '0';
	}

	
	vector<string> finalConf;
	string s; s.resize(n);
	for (int i = 0; i < 16; ++i) {

		fill(s.begin(), s.end(), '1');

		int switchn = makeSwitches(s, i);

		if (doesMatch(pattern, s) && switchn <= c)
			if ((c-switchn)%2 == 0)
				finalConf.push_back(s);
	}

	if (finalConf.size() == 0)
		cout << "IMPOSSIBLE" << endl;
	else {
		sort(finalConf.begin(), finalConf.end());
		for (int i = 0; i < finalConf.size(); ++i)
			cout << finalConf[i] << endl;
	}


	return 0;
}

