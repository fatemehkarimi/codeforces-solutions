//https://codeforces.com/problemset/problem/893/C
//C. Rumor

#include <iostream>
#include <vector>

using namespace std;

long long int dfs(vector <vector <int> > & Graph, vector <bool> & visited, vector <int> & golds, int root);

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector <int> golds(n);
	for(int i = 0; i < n; ++i)
		cin >> golds[i];

	vector <vector <int> > Graph(n);
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		Graph[u].push_back(v);
		Graph[v].push_back(u);
	}

	long long int result = 0;
	vector <bool> visited(n, false);
	for(int i = 0; i < n; ++i)
		if(!visited[i])
			result += dfs(Graph, visited, golds, i);

	cout << result << endl;
	return 0;
}

long long int dfs(vector <vector <int> > & Graph, vector <bool> & visited, vector <int> & golds, int root)
{
	visited[root] = true;
	long long int min_gold = golds[root];
	for(auto a : Graph[root])
		if(!visited[a])
			min_gold = min(min_gold, dfs(Graph, visited, golds, a));
	return min_gold;
}
