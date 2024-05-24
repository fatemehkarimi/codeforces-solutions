//https://codeforces.com/problemset/problem/436/C
//C. Dungeons and Candies

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;

int find_parent(vector <int> & ufds, int x)
{
	int root = x;
	while(ufds[root] != -1)
		root = ufds[root];

	while(ufds[x] != -1){
		int tmp = ufds[x];
		ufds[x] = root;
		x = tmp;
	}
	return root;
}

void _union(vector <int> & ufds, int x, int y)
{
	int p1 = find_parent(ufds, x);
	int p2 = find_parent(ufds, y);
	if(p1 == p2)
		return;
	ufds[p1] = p2;
}

int calc_diff_descript(vector <string> & d1, vector <string> & d2)
{
	int n = d1.size();
	int m = d1[0].size();
	int count = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(d1[i][j] != d2[i][j])
				++count;
	return count;
}

int MST(vector <pair <int, pair <int, int> > > & edge_pool, set <pair <int, int> > & actions, int n)
{
	int cost = 0;
	vector <int> ufds(n, -1);

	for(auto a : edge_pool){
		int u = a.second.first;
		int v = a.second.second;
		if(find_parent(ufds, u) != find_parent(ufds, v)){
			actions.insert(make_pair(u, v));
			_union(ufds, u, v);
			cost += a.first;
		}
	}
	return cost;
}

void dfs(vector <vector <int> > & Graph, vector <bool> & visited, int root)
{
	visited[root] = true;
	for(auto a : Graph[root])
		if(!visited[a])
			dfs(Graph, visited, a);
}

int main(void)
{
	int n, m, k, w;
	cin >> n >> m >> k >> w;

	vector <vector <string> > descripts(k, vector <string>(n));

	for(int i = 0; i < k; ++i)
		for(int j = 0; j < n; ++j)
			cin >> descripts[i][j];

	vector <pair <int, pair <int, int> > > edge_pool;
	vector <vector <int> > Graph(k);

	for(int i = 0; i < k; ++i)
		for(int j = 0; j < k; ++j)
			if(i != j){
				int diff = calc_diff_descript(descripts[i], descripts[j]) * w;
				if(diff >= m * n)
					continue;
				edge_pool.push_back(make_pair(diff, make_pair(i, j)));
				Graph[i].push_back(j);
				Graph[j].push_back(i);
			}

	sort(edge_pool.begin(), edge_pool.end());
	int total_cost = 0;
	set <pair <int, int> > actions;
	total_cost += MST(edge_pool, actions, k);

	int count_component = 0;
	vector <bool> visited(k, false);
	for(int i = 0; i < k; ++i)
		if(!visited[i]){
			++count_component;
			actions.insert(make_pair(i, -1));
			dfs(Graph, visited, i);
		}

	total_cost += (count_component * n * m);

	vector <pair <int, int> > order_action;
	std::fill(visited.begin(), visited.end(), false);

	for(auto it = actions.begin(); it != actions.end();)
		if(it->second == -1){
			order_action.push_back(*it);
			visited[it->first] = true;
			actions.erase(it++);
		}
		else
			++it;

	while(!actions.empty()){
		for(auto it = actions.begin(); it != actions.end();)
			if(visited[it->first]){
				visited[it->second] = true;
				order_action.push_back(make_pair(it->second, it->first));
				actions.erase(it++);
			}
			else if(visited[it->second]){
				visited[it->first] = true;
				order_action.push_back(make_pair(it->first, it->second));
				actions.erase(it++);
			}
			else
				++it;
	}

	cout << total_cost << endl;
	for(auto a : order_action)
		cout << a.first + 1 << ' ' << a.second + 1 << endl;

	return 0;
}
