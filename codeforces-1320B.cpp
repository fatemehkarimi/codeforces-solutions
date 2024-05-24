// https://codeforces.com/problemset/problem/1320/B
// B. Navigation System

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector <vector <int> > & Graph, vector <int> & visited, int s, int d)
{
	queue <int> Queue;
	visited[s] = 0;
	Queue.push(s);

	while(!Queue.empty()){
		int front = Queue.front();
		Queue.pop();

		for(auto a : Graph[front])
			if(visited[a] == -1){
				visited[a] = visited[front] + 1;
				Queue.push(a);
			}
	}
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector <vector <int> > Graph(n);
	vector <vector <int> > TGraph(n);

	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		Graph[u].push_back(v);
		TGraph[v].push_back(u);
	}

	int k;
	cin >> k;
	vector <int> path(k);
	for(int i = 0; i < k; ++i){
		int u;
		cin >> u;
		--u;
		path[i] = u;
	}

	vector <int> distances(n, -1);
	bfs(TGraph, distances, path.back(), path[0]);

	int min_rebuild = 0, max_rebuild = 0;
	for(int i = 0; i < k - 1; ++i){
		int is_unique = -1;//unknown state
		int min_dis = n + 1;
		for(auto a : Graph[path[i]])
			min_dis = min(min_dis, distances[a]);

		for(auto a : Graph[path[i]])
			if(distances[a] == min_dis){
				if(is_unique == -1)
					is_unique = 1;
				else
					is_unique = 0;
			}

		if(distances[path[i + 1]] == min_dis && is_unique == 0)
			++max_rebuild;

		if(distances[path[i + 1]] != min_dis)
			++min_rebuild, ++max_rebuild;
	}

	cout << min_rebuild << ' ' << max_rebuild << endl;
	return 0;
}
