
#include <string>
#include <iostream>

#define RAM_SIZE		1000
#define REGISTER_NUM	10

void com(std::string * ram, size_t ram_size) {
	register int reg[ REGISTER_NUM ] = {};

	size_t p = 0;
	while (1) {
		switch (ram[p][0]) {
			case '1': return; break;
			case '2': reg[ ram[p][1]-'0' ] = ram[p][2]-'0'; break;
			case '3': reg[ ram[p][1]-'0' ] += ram[p][2]-'0'; break;
			case '4': reg[ ram[p][1]-'0' ] *= ram[p][2]-'0'; break;
			case '5': reg[ ram[p][1]-'0' ] = reg[ ram[p][2]-'0' ]; break;
			case '6': reg[ ram[p][1]-'0' ] += reg[ ram[p][2]-'0' ]; break;
			case '7': reg[ ram[p][1]-'0' ] *= reg[ ram[p][2]-'0' ]; break;
			case '8': reg[ ram[p][1]-'0' ] = ram[reg[ ram[p][2]-'0' ]]; break;
			case '9': ram[reg[ ram[p][2]-'0' ]] = reg[ ram[p][1]-'0' ]; break;
			case '0': if (ram[p][2] != '0') p = reg[ ram[p][1]-'0' ]; continue;
			break;
		}
	}
}

int main() {
	using namespace std;

	const int ram_size = 1000;
	string ram[ ram_size ];


	return 0;
}

