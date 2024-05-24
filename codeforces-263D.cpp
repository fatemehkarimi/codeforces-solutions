// https://codeforces.com/problemset/problem/263/D
// D. Cycle in Graph

#include <iostream>
#include <vector>

using namespace std;

void find_cycle(
	vector <vector <int> > & Graph, vector <int> & parent,
		vector <int> & path, int root)
{
	int k = Graph[root].size();
	for(auto a : Graph[root]){
		if(!path.empty())
			break;

		if(parent[a] == -1){
			parent[a] = root;
			find_cycle(Graph, parent, path, a);
		}
		else if(a != parent[root]){//cicle found
			int node = root;
			while(node != a){
				path.push_back(node);
				node = parent[node];
			}
			path.push_back(a);
			if((int)path.size() <= k)
				path.clear();
		}
	}
}

int main(void)
{
	int n, m, k;
	cin >> n >> m >> k;
	vector <vector <int> > Graph(n);

	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		Graph[u].push_back(v);
		Graph[v].push_back(u);
	}

	vector <int> path;
	vector <int> parent(n, -1);
	parent[0] = 0;
	find_cycle(Graph, parent, path, 0);

	cout << path.size() << endl;
	for(auto a : path)
		cout << a + 1 << ' ';
	cout << endl;
	return 0;
}
