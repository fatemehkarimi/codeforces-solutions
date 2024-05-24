//http://codeforces.com/contest/1013/problem/C

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int n = 0;
	cin >> n;

	vector <int> num(2 * n);

	for (int i = 0; i < 2 * n; ++i)
		cin >> num[i];

	sort(num.begin(), num.end());

	long long int result = (long long int)(num[2 * n - 1] - num[n]) * (num[n - 1] - num[0]);
	for (int i = 1; i < n; ++i)
		result = min(result, (long long int)(num[2 * n - 1] - num[0]) * (long long int)(num[n + i - 1] - num[i]));

	cout << result << endl;
	return 0;
}
