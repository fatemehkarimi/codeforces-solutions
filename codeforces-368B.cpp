//http://codeforces.com/problemset/problem/368/B
//B. Sereja and Suffixes

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(void)
{
	int n, m;

	cin >> n >> m;

	vector <int> arr(n);
	map <int, int> distinct;

	for (int i = 0; i < n; ++i){
		cin >> arr[i];
		++distinct[arr[i]];
	}

	vector <int> result(n);
	result[0] = distinct.size();

	for (int i = 1; i < n; ++i){
		--distinct[arr[i - 1]];

		if (distinct[arr[i - 1]] == 0)
			distinct.erase(arr[i - 1]);

		result[i] = distinct.size();
	}

	for (int i = 0; i < m; ++i){
		int bound;
		cin >> bound;

		if (bound > n)
			cout << 0 << endl;
		else
			cout << result[bound - 1] << endl;
	}

	return 0;
}
