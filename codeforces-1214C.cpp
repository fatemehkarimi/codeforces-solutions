//https://codeforces.com/problemset/problem/1214/C
//C. Bad Sequence

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	string input;
	cin >> input;
	int left = 0, right = 0;
	for(int i = 0; i < n; ++i)
		if(input[i] == '(')
			++left;
		else{
			if(left == 0)
				++right;
			else
				--left;
		}
	if(left == right && right < 2)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
