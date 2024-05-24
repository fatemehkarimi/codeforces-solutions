// https://codeforces.com/problemset/problem/771/A
// A. Bear and Friendship Condition

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector < vector <int> > & Graph, vector <int> & visited, int root, int g_id)
{
	visited[root] = g_id;
	for(auto a : Graph[root])
		if(visited[a] == -1)
			dfs(Graph, visited, a, g_id);
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector <vector <int> > Graph(n);

	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;

		--u, --v;

		Graph[u].push_back(v);
		Graph[v].push_back(u);
	}

	vector <int> visited(n, -1);
	for(int i = 0; i < n; ++i)
		if(visited[i] == -1)
			dfs(Graph, visited, i, i);

	vector <pair <long long int, long long int> > counts(n);
	for(int i = 0; i < n; ++i){
		counts[visited[i]].first++;
		counts[visited[i]].second += Graph[i].size();
	}

	for(auto a : counts)
		if(a.first * (a.first - 1) != a.second)
			return cout << "NO" << endl, 0;

	cout << "YES" << endl;
	return 0;
}
