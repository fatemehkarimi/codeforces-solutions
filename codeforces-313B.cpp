//http://codeforces.com/problemset/problem/313/B
//B. Ilya and Queries

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	string input;
	cin >> input;

	vector <int> count(input.size(), 0);
	for (int i = 1; i < input.size(); ++i)
		if (input[i - 1] == input[i])
			count[i] = count[i - 1] + 1;
		else
			count[i] = count[i - 1];

	int n = 0;
	cin >> n;
	for (int i = 0; i < n; ++i){
		int l, r;
		cin >> l >> r;
		--l;
		--r;

		cout << count[r] - count[l] << endl;

	}
	return 0;
}
