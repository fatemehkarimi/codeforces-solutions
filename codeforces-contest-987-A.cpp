//http://codeforces.com/contest/987/problem/A
//Infinity Gauntlet

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void)
{
	int n = 0;
	map <string , string> Map;
	Map["purple"] = "Power";
	Map["green"] = "Time";
	Map["blue"] = "Space";
	Map["orange"] = "Soul";
	Map["red"] = "Reality";
	Map["yellow"] = "Mind";

	while (cin >> n) {
	map <string , string> Map;
	Map["purple"] = "Power";
	Map["green"] = "Time";
	Map["blue"] = "Space";
	Map["orange"] = "Soul";
	Map["red"] = "Reality";
	Map["yellow"] = "Mind";


	for (int i = 0; i < n; ++i){
		string tmp;
		cin >> tmp;

		Map[tmp] = "find";
	}

	cout << 6 - n << endl;
	for (auto a : Map)
		if (a.second != "find")
			cout << a.second << endl;

	}
	return 0;
}

