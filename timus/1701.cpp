
#include <cstring>
#include <iostream>

struct note_t {
	int a, b, d;

	friend bool operator < (const note_t & a, const note_t & b) {
		return a.a < b.a;
	}
};

int main() {
	using namespace std;

	int man_size, note_size;
	cin >> man_size >> note_size;

	int * man = new int [man_size];
	memset(man, 0, man_size*sizeof(int));

	note_t * note = new note_t [note_size];
	for (int i = 0; i < note_size; ++i) {
		cin >> note[i].a >> note[i].b >> note[i].d;
	}


	return 0;
}

