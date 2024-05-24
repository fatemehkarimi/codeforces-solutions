//https://codeforces.com/problemset/problem/129/B
//B. Students and Shoelaces

#include <iostream>
#include <vector>
#include <set>

using namespace std;

void dfs(vector <set <int> > & Graph, vector <bool> & visited, vector <int> & must_deleted, int root);

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector < set <int> > Graph(n);
	for(int i = 0; i < m; ++i){
		int a, b;
		cin >> a >> b;
		--a, --b;

		Graph[a].insert(b);
		Graph[b].insert(a);
	}
	int result = 0;
	while(true){
		vector <int> must_deleted;
		vector <bool> visited(n,false);

		for(int i = 0; i < n; ++i)
			if(!visited[i])
				dfs(Graph, visited, must_deleted, i);
		
		if(must_deleted.size() == 0)
			break;
		
		for(auto a : must_deleted){
			Graph[a].clear();
			for(int i = 0; i < n; ++i)
				Graph[i].erase(a);
		}
		++result;
	}
	cout << result << endl;
	return 0;
}

void dfs(vector <set <int> > & Graph, vector <bool> & visited, vector <int> & must_deleted, int root)
{
	visited[root] = true;
	if(Graph[root].size() == 1)
		must_deleted.push_back(root);
	for(auto a : Graph[root])
		if(!visited[a])
			dfs(Graph, visited, must_deleted, a);
	return;
}
