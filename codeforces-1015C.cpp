//https://codeforces.com/problemset/problem/1015/C

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;

	long long int sumA = 0;
	vector <int> diffs;
	for(int i = 0; i < n; ++i){
		int a, b;
		cin >> a >> b;

		sumA += a;

		diffs.push_back(a - b);
	}

	sort(diffs.begin(), diffs.end());

	int count = 0;
	for(auto a = diffs.rbegin(); a != diffs.rend(); ++a){
		if(sumA <= m)
			break;

		sumA -= *a;
		++count;
	}

	if(sumA <= m)
		cout << count << endl;
	else
		cout << -1 << endl;
	return 0;
}
