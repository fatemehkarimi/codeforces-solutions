//http://codeforces.com/problemset/problem/550/A
//A. Two Substrings

#include <iostream>
#include <string>

using namespace std;

bool findBA(string & str, int l, int r, string key);

int main(void)
{
	string input;
	cin >> input;

	bool yes = 0;

	int place = -1;

	for (int i = 0; i < input.size() - 1; ++i)
		if (input[i] == 'A' && input[i + 1] == 'B'){
			place = i;
			break;
		}

	if (place != -1){
		bool a1 = findBA(input, 0, place - 1, "BA");
		bool a2 = findBA(input, place + 2, input.size() - 1, "BA");

		if (a1 || a2)
			yes = 1;
	}

	place = -1;
	for (int i = 0; i < input.size() - 1; ++i)
		if (input[i] == 'B' && input[i + 1] == 'A'){
			place = i;
			break;
		}

	if (place != -1 && !yes){
		bool a1 = findBA(input, 0, place - 1, "AB");
		bool a2 = findBA(input, place + 2, input.size() - 1, "AB");

		if (a1 || a2)
			yes = 1;
	}

	if (yes)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}

bool findBA(string & str, int l, int r, string key)
{
	for (int i = l; i < r; ++i)
		if (str[i] == key[0] && str[i + 1] == key[1])
			return true;

	return false;
}
