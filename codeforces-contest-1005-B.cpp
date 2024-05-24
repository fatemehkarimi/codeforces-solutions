//http://codeforces.com/contest/1005/problem/B
//Delete from the Left

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str1, str2;

	getline(cin, str1);
	getline(cin, str2);

	int i = str1.size() - 1;
	int j = str2.size() - 1;

	while(i >= 0 && j >= 0)
		if (str1[i] != str2[j])
			break;
		else {
			--i;
			--j;
		}

	cout << i + 1 + j + 1 << endl;

	return 0;
}
