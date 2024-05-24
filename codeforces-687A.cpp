//https://codeforces.com/problemset/problem/687/A
//A. NP-Hard Problem

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs(vector <vector <int> > & Graph, vector <int> & group_id, int root)
{
	queue <int> Queue;
	group_id[root] = 0;
	Queue.push(root);

	while(!Queue.empty()){
		int u = Queue.front();
		Queue.pop();

		for(auto v : Graph[u])
			if(group_id[v] == -1){
				group_id[v] = (group_id[u] + 1) % 2;
				Queue.push(v);
			}
			else if(group_id[u] == group_id[v])
				return 0;
	}
	return 1;
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector < vector <int> > Graph(n);

	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;

		Graph[u].push_back(v);
		Graph[v].push_back(u);
	}

	vector <int> group_id(n, -1);
	for(int i = 0; i < n; ++i)
		if(group_id[i] == -1){
			int result = bfs(Graph, group_id, i);
			if(result == 0)
				return cout << -1 << endl, 0;
		}

	int count_0 = 0, count_1 = 0;
	for(auto a : group_id)
		if(a == 0)
			++count_0;
		else if(a == 1)
			++count_1;

	cout << count_0 << endl;
	for(int i = 0; i < n; ++i)
		if(group_id[i] == 0)
			cout << i + 1 << ' ';
	cout << endl;

	cout << count_1 << endl;
	for(int i = 0; i < n; ++i)
		if(group_id[i] == 1)
			cout << i + 1 << ' ';
	cout << endl;

	return 0;
}
