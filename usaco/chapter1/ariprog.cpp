
/*
ID: aybek.h2
PROG: ariprog
LANG: C++11
*/

#define PROB_NAME "ariprog"

#include <map>
#include <list>
#include <queue>
#include <string>
#include <fstream>
#include <cassert>
#include <iterator>
#include <iostream>
#include <algorithm>

#define repeat(a) for (size_t i_ = 0; i_ < (a); ++i_)
#define whole(a) a, a + a ## _size

using namespace std;

class solution_t {
	public:
		solution_t()
			: fin(PROB_NAME".in")
			, fout(PROB_NAME".out")
		{
			fin >> N >> M;
		}
		~solution_t() {}

		void run() {
			gen_bisquares();
			brute_force();
			print_solution();
		}

	private:
		ifstream fin;
		ofstream fout;

		int N, M;
		int bisquare_size;
		int bisquare[125001];
		bool isbisquare[125001];
		vector<pair<int, int> > solution;

		bool is_solution(int a0, int a1) {
			int b = a1-a0;
			if (a0 + (N-1)*b > bisquare[bisquare_size-1])
				return false;
			for (int i = 1; i < N; ++i) {
				if (isbisquare[a0 + i*b] == false)
					return false;
			}
			return true;
		}
		void gen_bisquares() {
			bisquare_size = 0;
			for (int p = 0; p <= M; ++p)
				for (int q = 0; q <= M; ++q) {
					int n = p*p + q*q;
					if (isbisquare[n] == false) {
						isbisquare[n] = true;
						bisquare[bisquare_size++] = n;
				} }
			sort(whole(bisquare));
		}
		void brute_force() {
			for (int i = 0; i < bisquare_size; ++i) {
				for (int j = i+1; j < bisquare_size; ++j) {
					if (is_solution(bisquare[i], bisquare[j]))
						solution.push_back(make_pair(
							bisquare[j]-bisquare[i],
							bisquare[i]));
			} }
			sort(solution.begin(), solution.end());
		}
		void print_solution() {
			int solution_size = solution.size();
			if (solution_size == 0) {
				fout << "NONE" << endl;
			} else {
				for (auto e: solution)
					fout << e.second << ' ' << e.first << endl;
			}
		}
};

int main() {
	solution_t solution;
	solution.run();

	return 0;
}

