// https://codeforces.com/problemset/problem/505/B
// B. Mr. Kitayuta's Colorful Graph

#include <iostream>
#include <vector>
#include <set>

using namespace std;

void dfs(vector < vector <pair <int, int> > > & Graph, vector <vector <int> > & counts,
	vector <bool> & visited, int color, int source, int node)
{
	visited[node] = true;
	++counts[source][node];
	++counts[node][source];

	for(auto a : Graph[node])
		if(!visited[a.first] && a.second == color)
			dfs(Graph, counts, visited, color, source, a.first);
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector <vector <pair <int, int> > > Graph(n);
	vector <vector <int> > counts(n, vector <int>(n, 0));
	set <int> colors;

	for(int i = 0; i < m; ++i){
		int u, v, c;
		cin >> u >> v >> c;
		--u, --v;
		Graph[u].push_back(make_pair(v, c));
		Graph[v].push_back(make_pair(u, c));

		colors.insert(c);
	}

	for(auto c : colors){
		for(int i = 0; i < n; ++i){
			vector <bool> visited(n, false);
			dfs(Graph, counts, visited, c, i, i);
		}
	}

	int Q;
	cin >> Q;
	while(Q--){
		int u, v;
		cin >> u >> v;
		--u, --v;

		cout << counts[u][v] / 2 << endl;
	}
	return 0;
}
