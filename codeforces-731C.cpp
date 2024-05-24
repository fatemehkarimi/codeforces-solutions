//https://codeforces.com/problemset/problem/731/C
//C. Socks

#include <iostream>
#include <vector>
#include <map>

using namespace std;

void dfs(vector <vector <int> > & Graph, vector <int> & colors, vector <bool> & visited, map <int, int> & freq, int root)
{
	visited[root] = true;
	freq[colors[root]]++;
	for(auto a : Graph[root])
		if(!visited[a])
			dfs(Graph, colors, visited, freq, a);
	return;
}

int main(void)
{
	int n, m, k;
	cin  >> n >> m >> k;
	vector <int> colors(n);
	for(int i = 0; i < n; ++i)
		cin >> colors[i];

	int min_color = 0;

	vector <vector <int> > Graph(n);
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		Graph[u].push_back(v);
		Graph[v].push_back(u);
	}

	vector <bool> visited(n, false);
	for(int i = 0; i < n; ++i)
		if(!visited[i]){
			map <int, int> freq;
			dfs(Graph, colors, visited, freq, i);

			int max_available_color = 0;
			int total_color = 0;

			for(auto a : freq){
				total_color += a.second;
				max_available_color = max(max_available_color, a.second);
			}

			min_color += total_color - max_available_color;
		}

	cout << min_color << endl;
	return 0;
}

