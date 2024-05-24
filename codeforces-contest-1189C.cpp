//https://codeforces.com/contest/1189/problem/C
//C. Candies!

#include <iostream>
#include <vector>

using namespace std;


int main(void)
{
	int n;
	cin >> n;
	vector < vector <int> > dp(1, vector <int> (n));
	for(int i = 0; i < n; ++i)
		cin >> dp[0][i];

	for(int l = 2; l <= n; l *= 2){
		vector <int> tmp;
		dp.push_back(tmp);
		int idx = (int)dp.size() - 1;
		for(int i = 0; i < (int)dp[idx - 1].size() - l / 2; ++i)
			dp[idx].push_back(dp[idx - 1][i] + dp[idx - 1][i + l / 2]);
	}

	int q;
	cin >> q;
	for(int i = 0; i < q; ++i){
		int left, right;
		cin >> left >> right;
		--left;
		int length = right - left;
		int idx = 0;
		while(length != 0)
			length /= 2, ++idx;

		cout << dp[idx - 1][left] / 10 << endl;
	}
	return 0;
}
