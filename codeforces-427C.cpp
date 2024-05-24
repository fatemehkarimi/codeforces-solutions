//https://codeforces.com/problemset/problem/427/C
//C. Checkposts

#include <iostream>
#include <climits>
#include <vector>
#include <stack>
#include <map>

#define MODULO 1000000007

using namespace std;


void dfs(vector <vector <int> > & Graph, vector <bool> & visited, stack <int> & Stack, int root)
{
	visited[root] = true;
	for(auto a : Graph[root])
		if(!visited[a])
			dfs(Graph, visited, Stack, a);
	Stack.push(root);
	return;
}

int main(void)
{
	int n, m;
	cin >> n;
	vector <int> costs(n);
	for(int i = 0; i < n; ++i)
		cin >> costs[i];

	vector <vector <int> > Graph(n);
	vector <vector <int> > Tgraph(n);
	cin >> m;
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		Graph[u].push_back(v);
		Tgraph[v].push_back(u);
	}

	long long int sum_cost = 0, n_ways = 1;
	stack <int> Stack;
	vector <bool> visited(n, false);
	for(int i = 0; i < n; ++i)
		if(!visited[i])
			dfs(Graph, visited, Stack, i);

	std::fill(visited.begin(), visited.end(), false);
	while(!Stack.empty()){
		int front = Stack.top();
		Stack.pop();

		stack <int> component;

		if(!visited[front])
			dfs(Tgraph, visited, component, front);
		else
			continue;

		map <int, int> min_cost;
		while(!component.empty()){
			++min_cost[costs[component.top()]];
			component.pop();
		}
		sum_cost += min_cost.begin()->first;
		n_ways *= min_cost.begin()->second;
		n_ways %= MODULO;
	}

	cout << sum_cost << ' ' << n_ways << endl;
	return 0;
}
