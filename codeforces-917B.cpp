// https://codeforces.com/problemset/problem/917/B
// B. MADMAX


#include <iostream>
#include <vector>
#include <map>

using namespace std;

int dfs(vector <map <int, char> > & Graph,
			vector <vector <vector <int> > > & dp, int i, int j, int k)
{
	if(dp[i][j][k] >= 0) return dp[i][j][k];
	for(auto edge : Graph[i])
		if(edge.second - 'a' >= j && dfs(Graph, dp, k, edge.second - 'a', edge.first))
			return dp[i][j][k] = 0;

	return dp[i][j][k] = 1;
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector <map <int, char> > Graph(n);

	for(int i = 0; i < m; ++i){
		int u, v;
		char c;
		cin >> u >> v >> c;
		Graph[--u][--v] = c;
	}

	vector <vector <vector <int> > > dp(
		n, vector <vector <int> >('z' - 'a' + 1, vector <int>(n, -1)));

	for(int i = 0; i < n; ++i)
		for(int k = 0; k < n; ++k)
			dp[i][0][k] = dfs(Graph, dp, i, 0, k);
	
	for(auto arr : dp){
		for(int j = 0; j < n; ++j)
			cout << (arr[0][j] ? 'B' : 'A');
		cout << endl;
	}
	
	return 0;
}
