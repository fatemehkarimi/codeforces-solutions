//http://codeforces.com/contest/1005/problem/A
Tanya and Stairways

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n = 0;
	while (cin >> n) {
		vector <int> result;
		vector <int> num(n);

		for (int i = 0; i < n; ++i)
			cin >> num[i];

		int count = 1;
		for (int i = 1; i < n; ++i)
			if (num[i] == 1){
				++count;
				result.push_back(num[i - 1]);
			}

		result.push_back(num[n - 1]);


		cout << count << endl;
		for (auto a : result)
			cout << a << ' ';
		cout << endl;


	}
	return 0;
}
