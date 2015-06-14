
#include <string>
#include <iostream>
using namespace std;

class c_cube {
	private:
		char x1, x2;
		char y1, y2;
		char z1, z2;

		void shift_arg(char & a1, char & a2, char & a3, char & a4) {
			char t;
			t = a1;
			a1 = a2;
			a2 = a3;
			a3 = a4;
			a4 = t;
		}

	public:
		inline void rotate_xz() { shift_arg(x1, z1, x2, z2); }
		inline void rotate_yz() { shift_arg(y1, z1, y2, z2); }
		inline void rotate_xy() { shift_arg(x1, y1, x2, y2); }

		void set_config(const string & s) {
			z1 = s[0];
			x1 = s[1];
			y1 = s[2];
			y2 = s[3];
			x2 = s[4];
			z2 = s[5];
		}

		string get_config() {
			string s;
			return (s + z1 + x1 + y1 + y2 + x2 + z2);
		}
};

int main() {
	string s;
	c_cube cube;

	while (cin >> s) {
		bool is_a_solution = false;

		cube.set_config(s);

		for (int i = 0; i < 6; ++i)
			s[i] = s[i+6];
		s.resize(6);

		for (int i1 = 0; i1 < 4; ++i1) {
			for (int i2 = 0; i2 < 4; ++i2) {
				for (int i3 = 0; i3 < 4; ++i3) {
					if (cube.get_config() == s) {
						is_a_solution = true;
						i1 = i2 = 10;
						break;
					}
					cube.rotate_xz();
				}
				cube.rotate_yz();
			}
			cube.rotate_xy();
		}

		cout << (is_a_solution ? "TRUE": "FALSE") << endl;
	}

	return 0;
}

