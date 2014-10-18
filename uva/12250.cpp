
#include <map>
#include <string>
#include <cassert>
#include <iterator>
#include <iostream>

int main()
{
	using namespace std;

	int i;
	string s;
	map<string, string> words;
	map<string, string>::iterator it;

	words[ "CIAO" ]				= "ITALIAN";
	words[ "HOLA" ]				= "SPANISH";
	words[ "HELLO" ]			= "ENGLISH";
	words[ "HALLO" ]			= "GERMAN";
	words[ "BONJOUR" ]			= "FRENCH";
	words[ "ZDRAVSTVUJTE" ]		= "RUSSIAN";

	for ( i = 1; cin >> s; ++i )
	{
		if (s == "#") break;
		cout	<< "Case " << i << ": "
				<< ((it = words.find(s)) != words.end() ? it->second : "UNKNOWN")
				<< endl;
	}

	return 0;
}

