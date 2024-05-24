//http://codeforces.com/contest/994/problem/A
//Fingerprints

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int n = 0;
	while (cin >> n) {
		int m = 0;
		cin >> m;

		vector <int> num(n);
		for (int i = 0; i < n; ++i)
			cin >> num[i];

		vector <int> code(m);
		for (int i = 0; i < m; ++i)
			cin >> code[i];

		for (int i = 0; i < n; ++i){
			auto a = find(code.begin(), code.end(), num[i]);

			if (a != code.end())
				cout << num[i] << ' ';
		}

		cout << endl;
	}
	return 0;
}
