
#include <map>
#include <vector>
#include <iostream>

using namespace std;

const char day_name[7][4] = {
	"mon",
	"tue",
	"wed",
	"thu",
	"fri",
	"sat",
	"sun"
};

int getwday(int day, int month, int year) {
	int a = (14 - month)/12;
	int y = year - a;
	int m = month + 12*a - 2;
	return (7000 + (day + y + y/4 - y/100 + y/400 + (31*m)/12)) % 7;
}

int main()
{
	int d, m, y;
	cin >> d >> m >> y;

	map<int, vector<int> > day;

	cout << getwday(2, 2, 2014) << endl;


	return 0;
}

