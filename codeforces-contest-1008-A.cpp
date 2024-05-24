//http://codeforces.com/contest/1008/problem/A
//Romaji

#include <iostream>
#include <string>

using namespace std;

bool isVowel(char a);

int main(void)
{
	string str;
	while (cin >> str) {
		bool ok = 1;

		for (int i = 0; i < str.size() - 1; ++i)
			if (str[i] != 'n' && !isVowel(str[i]) && !isVowel(str[i + 1])){
				ok = 0;
				break;
			}

		if (str[str.size() - 1] != 'n' && !isVowel(str[str.size() - 1]))
			ok = 0;

		if (ok)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}


bool isVowel(char a)
{
	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
		return true;
	return false;
}
