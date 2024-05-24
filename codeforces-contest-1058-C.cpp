//http://codeforces.com/contest/1058/problem/C
//C. Vasya and Golden Ticket

#include <iostream>
#include <string>

using namespace std;

bool split(string & a, int start, int n);

int main(void)
{
	int n = 0;
	cin >> n;

	string str;
	cin >> str;

	bool ok = 0;
	int gnum = 0;
	for (int i = 0; i < str.size() - 1; ++i){
		gnum += (str[i] - '0');

		if (split(str, i + 1, gnum)){
			ok = 1;
			break;
		}
	}

	if (ok)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}

bool split(string & a, int start, int n)
{
	bool reset = 1;
	int sum = 0;
	for (int i = start; i < a.size(); ++i){
		sum += (a[i] - '0');
		reset = 0;

		while (i + 1 < a.size() && a[i + 1] == '0')
			++i;

		if (sum == n){
			reset = 1;
			sum = 0;
		}
		else if (sum > n)
			return false;
	}

	return reset;
}
