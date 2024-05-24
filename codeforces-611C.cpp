//https://codeforces.com/problemset/problem/611/C
//C. New Year and Domino

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector <string> _map(n);
	for(int i = 0; i < n; ++i)
		cin >> _map[i];

	vector < vector <int> > dp(n, vector <int> (m, 0));

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j){
			if(i - 1 >= 0){
				dp[i][j] += dp[i - 1][j];
				if(_map[i][j] == '.' && _map[i - 1][j] == '.')
					++dp[i][j];
			}

			if(j - 1 >= 0){
				dp[i][j] += dp[i][j - 1];
				if(_map[i][j] == '.' && _map[i][j - 1] == '.')
					++dp[i][j];
			}

			if(i - 1 >= 0 && j - 1 >= 0)
				dp[i][j] -= dp[i - 1][j - 1];
		}

	int Q;
	cin >> Q;
	for(int i = 0; i < Q; ++i){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		--x1, --y1;
		--x2, --y2;

		int count = dp[x2][y2];

		if(x1 - 1 >= 0){
			count -= dp[x1 - 1][y2];
			for(int q = y1; q <= y2; ++q)
				if(_map[x1][q] == '.' && _map[x1 - 1][q] == '.')
					--count;
		}

		if(y1 - 1 >= 0){
			count -= dp[x2][y1 - 1];
			for(int p = x1; p <= x2; ++p)
				if(_map[p][y1] == '.'  && _map[p][y1 - 1] == '.')
					--count;
		}

		if(x1 - 1 >= 0 && y1 - 1 >= 0)
			count += dp[x1 - 1][y1 - 1];

		cout << count << endl;
	}

	return 0;
}
