//https://codeforces.com/problemset/problem/580/C
//C. Kefa and Park

#include <iostream>
#include <vector>

using namespace std;

int dfs(vector <vector <int> > & Tree, vector <bool> & has_cat, vector <bool> & visited, int root, int k_value, int max_k);

int main(void)
{
	int n, k;
	cin >> n >> k;
	vector <bool> has_cat(n, false);
	for(int i = 0; i < n; ++i){
		int status;
		cin >> status;
		has_cat[i] = status;
	}

	vector <vector <int> > Tree(n);
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		Tree[u].push_back(v);
		Tree[v].push_back(u);
	}

	vector <bool> visited(n, false);
	int result = dfs(Tree, has_cat, visited, 0, k, k);
	cout << result << endl;
	return 0;
}

int dfs(vector <vector <int> > & Tree, vector <bool> & has_cat, vector <bool> & visited, int root, int k_value, int max_k)
{
	visited[root] = true;
	if(!has_cat[root])
		k_value = max_k;
	else
		--k_value;

	if(k_value < 0)
		return 0;

	bool is_leaf = true;
	int result = 0;
	for(auto a : Tree[root])
		if(!visited[a]){
			is_leaf = false;
			result += dfs(Tree, has_cat, visited, a, k_value, max_k);
		}

	if(is_leaf)
		return 1;
	return result;
}
