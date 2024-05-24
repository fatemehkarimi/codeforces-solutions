// https://codeforces.com/problemset/problem/977/E
// E. Cyclic Components

#include <iostream>
#include <vector>
#include <map>

using namespace std;

void dfs(vector <vector <int> > & Graph, vector <int> & visited, int root, int g_id)
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

	int count = 0;
	map <int, bool> groups;
	vector <int> visited(n, -1);

	for(int i = 0; i < n; ++i)
		if(visited[i] == -1){
			groups[i] = true;
			dfs(Graph, visited, i, i);
		}

	for(int i = 0; i < n; ++i)
		if(Graph[i].size() != 2)
			groups[visited[i]] = false;
		
	for(auto a : groups)
		if(a.second)
			++count;
	cout << count << endl;
	return 0;
}
