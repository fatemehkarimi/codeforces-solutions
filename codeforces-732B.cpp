//http://codeforces.com/problemset/problem/732/B
//B. Cormen — The Best Friend Of a Man

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector <int> days(n);
	for (int i = 0; i < n; ++i)
		cin >> days[i];

	int added = 0;
	for (int i = 1; i < n; ++i)
		if (days[i - 1] + days[i] < m){
			added += (m - days[i - 1] - days[i]);
			days[i] += (m - days[i - 1] - days[i]);
		}

	cout << added << endl;
	cout << days[0];
	for (int i = 1; i < n; ++i)
		cout << ' ' << days[i];

	cout << endl;
	return 0;
}
