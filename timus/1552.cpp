
/*
http://acm.timus.ru/problem.aspx?space=1&num=1552
*/

#include <cassert>
#include <iostream>
#include <algorithm>

template <const int memo_size = 30000>
class brainfuck_machine {
	public:
		brainfuck_machine() : p(0) {}
		~brainfuck_machine() {}

		inline void incp() { p = (p + 1) % memo_size; }
		inline void decp() { p = (p ? memo_size-1: p-1); }

		inline void inc() { ++memo[p]; }
		inline void dec() { --memo[p]; }

		inline void out() { std::cout << memo[p]; }

	private:
		size_t p;
		char memo[ memo_size ];
};

int main() {
	using namespace std;

	return 0;
}

