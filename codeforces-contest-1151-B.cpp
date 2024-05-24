//https://codeforces.com/contest/1151/problem/B
//B. Dima and a Bad XOR

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector < vector <int> > arr(n, vector <int> (m));
	vector < vector <bool> > dp(n, vector <bool> (1024, 0));
	vector < vector <int> > pre(n, vector <int> (1024, -1));//for backtracking

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> arr[i][j];

	for(int j = 0; j < m; ++j){
		dp[0][arr[0][j]] = 1;
		pre[0][arr[0][j]] = j;
	}

	for(int i = 1; i < n; ++i)
		for(int j = 0; j < m; ++j)
			for(int k = 0; k < 1024; ++k)
				if(dp[i - 1][k]){
					dp[i][k ^ arr[i][j]] = 1;
					pre[i][k ^ arr[i][j]] = j;
				}

	int start = -1;
	for(int i = 1; i < 1024; ++i)
		if(dp[n - 1][i]){
			start = i;
			break;
		}

	if(start == -1)
		cout << "NIE" << endl;
	else{
		vector <int> result;
		int index = n - 1;
		while(index >= 0){
			result.push_back(pre[index][start]);
			start = start ^ arr[index][pre[index][start]];
			--index;
		}
		cout << "TAK" << endl;
		for(auto a = result.rbegin(); a != result.rend(); ++a)
			cout << (*a) + 1 << ' ';
		cout << endl;
	}

	return 0;
}
