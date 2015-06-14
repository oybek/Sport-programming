
#include <iostream>

int main() {
	using namespace std;
	for (char c; cin.get(c); cout.put((c == '\n' ? c: char(c-7))));
	return 0;
}

