#include <iostream>
#include <map>
using namespace std;

struct user_t {
	string pass;
	bool online;
};

int main()
{
	size_t n; cin >> n;
	map<string, user_t> user;
	string command, name, pass;

	while (n--) {
		cin >> command;

		if (command == "register") {
			cin >> name >> pass;

			if (user.find(name) != user.end()) {
				cout << "fail: user already exists" << endl;
			}
			else {
				user[name].pass = pass;
				user[name].online = 0;
				cout << "success: new user added" << endl;
			}
		}
		else
		if (command == "login") {
			cin >> name >> pass;

			if (user.find(name) == user.end()) {
				cout << "fail: no such user" << endl;
			}
			else if (user[name].pass != pass) {
				cout << "fail: incorrect password" << endl;
			}
			else if (user[name].online) {
				cout << "fail: already logged in" << endl;
			}
			else {
				user[name].online = 1;
				cout << "success: user logged in" << endl;
			}
		}
		else
		if (command == "logout") {
			cin >> name;

			if (user.find(name) == user.end()) {
				cout << "fail: no such user" << endl;
			}
			else if (!(user[name].online)) {
				cout << "fail: already logged out" << endl;
			}
			else {
				user[name].online = 0;
				cout << "success: user logged out" << endl;
			}
		}
	}

	return 0;
}

