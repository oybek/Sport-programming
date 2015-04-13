
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#define SIZE 50
int ans, n, a[SIZE][SIZE],kaban=0;

/*void backtrack(int x, int y, int i) {*/
	/*if (i == n) {*/
		/*if (was[x][y] == 0) {*/
			/*was[x][y] = 1;*/
			/*++ans;*/
		/*}*/
		/*return;*/
	/*}*/

	/*backtrack(x-2, y-1, i+1);*/
	/*backtrack(x-2, y+1, i+1);*/

	/*backtrack(x-1, y-2, i+1);*/
	/*backtrack(x+1, y-2, i+1);*/

	/*backtrack(x+2, y-1, i+1);*/
	/*backtrack(x+2, y+1, i+1);*/

	/*backtrack(x-1, y+2, i+1);*/
	/*backtrack(x+1, y+2, i+1);*/
/*}*/

	struct hod {
		int x,y,i;
		hod(int ax, int ay, int ai)
		{
			x=ax; y=ay; i=ai;
		}
	};
void backtrack() {

	queue<hod> Q;
	Q.push(hod(20,20,0));
	while (!Q.empty())
	{
		hod t=Q.front();
		Q.pop();

		if (t.i==n)
		{
			if (a[t.x][t.y]==0)
			{
				a[t.x][t.y]=1;
				++kaban;
			}
			continue;
		}

		Q.push(hod(t.x-2,t.y-1,t.i+1));
		Q.push(hod(t.x-2,t.y+1,t.i+1));
		Q.push(hod(t.x+2,t.y-1,t.i+1));
		Q.push(hod(t.x+2,t.y+1,t.i+1));

		Q.push(hod(t.x-1,t.y-2,t.i+1));
		Q.push(hod(t.x-1,t.y+2,t.i+1));
		Q.push(hod(t.x+1,t.y-2,t.i+1));
		Q.push(hod(t.x+1,t.y+2,t.i+1));
		
	}
}

/*int n, ans[] = {*/
/*1*/
/*, 8*/
/*, 33*/
/*, 76*/
/*, 129*/
/*, 196*/
/*, 277*/
/*, 372*/
/*, 481*/
/*, 604*/
/*, 741*/
/*};*/

int main() {
	cin >> n;
	backtrack();
	cout << kaban << endl;

	return 0;
}

