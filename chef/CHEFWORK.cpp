
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

#define N_MAX 1001

#define TRANSLATOR 1
#define AUTHOR 2
#define AUTHOR_TRANSLATOR 3

class worker
{
	public:
		int type;
		int price;

		bool operator<( const worker& w ) const
		{
			return price < w.price;
		}
};

int main()
{
	int N;
	vector<worker> workers;

	cin >> N;

	workers.resize(N);
	for( worker& w : workers )
		cin >> w.price;

	for( worker& w : workers )
		cin >> w.type;

	// sort by price
	sort( all( workers ) );

	int cheapest_translator = 0;
	for( worker w : workers )
		if( w.type == TRANSLATOR )
		{
			cheapest_translator = w.price;
			break;
		}

	int cheapest_author = 0;
	for( worker w : workers )
		if( w.type == AUTHOR )
		{
			cheapest_author = w.price;
			break;
		}

	int cheapest_author_translator = 0;
	for( worker w : workers )
		if( w.type == AUTHOR_TRANSLATOR )
		{
			cheapest_author_translator = w.price;
			break;
		}

	if( cheapest_author_translator > 0 )
	{
		if( cheapest_author > 0 && cheapest_translator > 0 )
		{
			cout << min( cheapest_author_translator, cheapest_author+cheapest_translator) << endl;
		}
		else
		{
			cout << cheapest_author_translator << endl;
		}
	} else {
		if( cheapest_author > 0 && cheapest_translator > 0 )
		{
			cout << cheapest_author+cheapest_translator << endl;
		}
		else
		{
			assert(false);
		}
	}

	return 0;
}

