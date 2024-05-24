//https://codeforces.com/problemset/problem/1167/C
//C. News Distribution

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int dfs(vector <vector <int> > & Graph, vector <int> & visited, int root, int group_no);

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector < vector <int> > Graph(n);
	for(int i = 0; i < m; ++i){
		int k;
		cin >> k;
		vector <int> k_group;
		for(int j = 0; j < k; ++j){
			int x;
			cin >> x;
			--x;
			k_group.push_back(x);
		}
		for(int j = 1; j < k; ++j){
			Graph[k_group[0]].push_back(k_group[j]);
			Graph[k_group[j]].push_back(k_group[0]);
		}
	}

	vector <int> visited(n, -1);
	map <int, int> components;

	for(int i = 0; i < n; ++i)
		if(visited[i] == -1){
			int size = dfs(Graph, visited, i, i);
			components[i] = size;
		}

	for(auto a : visited)
		cout << components[a] << ' ';
	cout << endl;
	return 0;
}

int dfs(vector <vector <int> > & Graph, vector <int> & visited, int root, int group_no)
{
	visited[root] = group_no;
	int size = 1;
	for(auto a : Graph[root])
		if(visited[a] == -1){
			size += dfs(Graph, visited, a, group_no);
		}
	return size;
}
