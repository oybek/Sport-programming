
#include <iostream>
#include <string>

namespace {

	class keyboard_t {
		private:
			std::string keys;
			std::size_t map[256];
		public:
			keyboard_t():
				keys(
					"`1234567890-="
					"QWERTYUIOP[]\\"
					"ASDFGHJKL;'"
					"ZXCVBNM,./"
					" "
					)
			{
				for (size_t i = 0; i < keys.size(); ++i) {
					map[ keys[i] ] = i;
				}
			}

			char left(char c) {
				if (c == ' ') return c;
				return keys[ map[c]-1 ];
			}
	};
}

int main() {
	using namespace std;
	keyboard_t keyboard;

	string s;
	while (getline(cin, s)) {
		char c;
		for (auto e: s) { cout << keyboard.left(e); }
		cout << endl;
	}

	return 0;
}



























int main() {

	return 0;
}









