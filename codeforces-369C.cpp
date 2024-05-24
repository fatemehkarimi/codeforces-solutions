//https://codeforces.com/problemset/problem/369/C
//C. Valera and Elections

#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector <vector <pair <int, int> > > & Graph, vector <bool> & visited, vector <bool> & must_be, int root)
{
	visited[root] = true;
	bool is_leaf = true;
	bool forward = 0;
	bool problem_edge = false;

	for(auto a : Graph[root])
		if(!visited[a.first]){
			is_leaf = false;
			forward = forward | dfs(Graph, visited, must_be, a.first);
		}
		else if(visited[a.first] && a.second == 2)
			problem_edge = true;


	if(is_leaf){
		if (Graph[root][0].second == 2)
			must_be[root] = true;
		return must_be[root];
	}

	if(problem_edge && !forward)
		must_be[root] = true;

	return forward | must_be[root];
}

int main(void)
{
	int n;
	cin >> n;
	vector <vector <pair <int, int> > > Graph(n);

	for(int i = 1; i < n; ++i){
		int u, v, c;
		cin >> u >> v >> c;
		--u, --v;
		Graph[u].push_back(make_pair(v, c));
		Graph[v].push_back(make_pair(u, c));
	}

	vector <bool> must_be(n, false);
	vector <bool> visited(n, false);
	dfs(Graph, visited, must_be, 0);

	int count = 0;
	for(auto a : must_be)
		if(a)
			++count;
	cout << count << endl;
	for(int i = 0; i < n; ++i)
		if(must_be[i])
			cout << i + 1 << ' ';
	cout << endl;
	return 0;
}
