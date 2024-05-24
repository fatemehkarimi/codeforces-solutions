// https://codeforces.com/problemset/problem/645/D
// D. Robot Rapping Results Report

#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>

using namespace std;

bool topSort(vector <set <int> > & Graph, stack <int> & order, vector <bool> & visited,
				vector <bool> & on_stack, int root)
{
	visited[root] = true;
	on_stack[root] = true;
	bool is_valid = true;

	for(auto a : Graph[root])
		if(!visited[a])
			is_valid = is_valid & topSort(Graph, order, visited, on_stack, a);
		else if(on_stack[a])
			is_valid = false;

	order.push(root);
	on_stack[root] = false;
	return is_valid;
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	vector <set <int> > Graph(n);
	vector <pair <int, int> > races(m);

	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		Graph[u].insert(v);
		races[i] = make_pair(u, v);
	}

	bool is_valid = true;
	stack <int> Stack;
	vector <bool> visited(n, false);
	vector <bool> on_stack(n, false);
	for(int i = 0; i < n; ++i)
		if(!visited[i])
			is_valid = is_valid & topSort(Graph, Stack, visited, on_stack, i);

	map <pair <int, int>, bool> edges;
	int pre = Stack.top();
	Stack.pop();

	while(!Stack.empty()){
		int curr = Stack.top();
		Stack.pop();
		if(Graph[pre].find(curr) == Graph[pre].end())
			is_valid = false;

		edges.insert(make_pair(make_pair(pre, curr), 0));
		pre = curr;
	}
	
	if(!is_valid)
		return cout << -1 << endl, 0;

	int result = 0;
	for(int i = 0; i < m; ++i)
		if(edges.find(races[i]) != edges.end() && !edges[races[i]]){
			edges[races[i]] = true;
			result = i + 1;
		}
	cout << result << endl;
	return 0;
}
