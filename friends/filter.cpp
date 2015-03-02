
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

namespace given {
	using std::map;
	using std::pair;
	using std::vector;
	using std::string;
	using std::unordered_map;

	typedef unordered_map<string, vector<string> > row;
	typedef row query;

	/*
	 * sets of rows
	 */
	row parameters;

	/*
	 * mapping ids to rows
	 */
	unordered_map<string, row> table;

	/*
	 * queries type
	 */
	query queries;

}

using namespace std;
using namespace given;

class informer_tree {
	private:
		unordered_map<string, vector<row*> > link;

		/*
		 * determines does field contains elements which are listed in filter
		 * filter and field must be sorted vectors
		 */
		bool does_field_match_filter(const vector<string> & filter, const vector<string> & field) {
			for (vector<string>::const_iterator it = filter.begin(); it != filter.end(); ++it) {
				if (binary_search(field.begin(), field.end(), *it) == false) {
					return false;
				}
			}
			return true;
		}
	public:

		vector<row*> filter(
			const vector<row*> & rows,
			const pair<string, vector<string> > & filter
		) {
			vector<row*> filtered_rows;
			for (vector<row*>::const_iterator it = rows.begin(); it != rows.end(); ++it) {
				/* check does exists such field in this row */
				if ((*it)->find(filter.first) == (*it)->end()) {
					continue;
				}
				/* if exists, than compare fields */
				if (does_field_match_filter((*it)->find(filter.first)->second, filter.second)) {
					filtered_rows.push_back(*it);
				}
			}
			return filtered_rows;
		}

		/*
		 * returns all elements which field "filter.first" contains "filter.second"
		 */
		vector<row*> get_filtered(const pair<string, vector<string> > & filter) {
			vector<row*> filtered_rows;
			return filtered_rows;
		}
};

int main() {

	return 0;
}

