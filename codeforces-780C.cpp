//https://codeforces.com/problemset/problem/780/C
//C. Andryusha and Colored Balloons

#include <iostream>
#include <vector>

using namespace std;

int dfs(vector <vector <int> > & Graph, vector <int> & visited, int root, int color, int c_par, int c_gran)
{
	int result = color;
	visited[root] = color;
	int c = 1;
	for(auto a : Graph[root])
		if(visited[a] == 0){
			while(c == color || c == c_par)
				++c;
			result = max(dfs(Graph, visited, a, c, color, c_par), result);
			++c;//next available color
		}
	return result;
}

int main(void)
{
	int n;
	cin >> n;
	vector <vector <int> > Tree(n);

	for(int i = 1; i < n; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		Tree[u].push_back(v);
		Tree[v].push_back(u);
	}

	vector <int> visited(n, 0);
	int result = dfs(Tree, visited, 0, 1, -1, -1);
	cout << result << endl;
	for(auto a : visited)
		cout << a << ' ';
	cout << endl;
	return 0;
}
