//https://codeforces.com/problemset/problem/690/C2
//C2. Brain Network (medium)

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void dfs(vector <vector <int> > & Graph, vector <int> & visited, int root, int level)
{
	visited[root] = level;
	for(auto a : Graph[root])
		if(visited[a] == -1)
			dfs(Graph, visited, a, level + 1);
	return;
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

	int result = 0;
	vector <int> visited1(n, -1);
	for(int i = 0; i < n; ++i)
		if(visited1[i] == -1){
			dfs(Graph, visited1, i, 0);
			int last = std::distance(visited1.begin(), max_element(visited1.begin(), visited1.end()));
			vector <int> visited2(n, -1);
			dfs(Graph, visited2, last, 0);
			result = max(*max_element(visited2.begin(), visited2.end()), result);
		}
	cout << result << endl;
	return 0;
}

