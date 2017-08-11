
/*
ID: aybek.h2
PROG: heritage
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

string inorder;
string preorder;

void post_order( string inorder, string preorder )
{
}

int main()
{
#ifndef LOCAL
	freopen( "heritage.in", "rt", stdin );
	freopen( "heritage.out", "wt", stdout );
#endif

	cin >> inorder >> preorder;
	post_order( inorder );

	return 0;
}

