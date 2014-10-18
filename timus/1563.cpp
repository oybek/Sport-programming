#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(int argc, char ** argv) {
	int n;
	
	cin >> n;
	cin.get();
	map<string, bool> shop;

	string strin;
	int nmet = 0;

	while (n--) {
		getline(cin, strin);

		if (shop.find(strin) != shop.end())
			++nmet;

		shop[strin] = true;
	}

	cout << nmet << endl;

	return 0;
}