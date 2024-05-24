//https://codeforces.com/problemset/problem/813/C
//C. The Tag Game

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector < vector <int> > & Graph, vector <int> & visited, int source)
{
	queue <int> Queue;
	visited[source] = 0;
	Queue.push(source);

	while(!Queue.empty()){
		int front = Queue.front();
		Queue.pop();

		for(auto a : Graph[front])
			if(visited[a] == -1){
				visited[a] = visited[front] + 1;
				Queue.push(a);
			}
	}
	return;
}

int main(void)
{
	int n, x;
	cin >> n >> x;
	--x;
	vector <vector <int> > Tree(n);

	for(int i = 1; i < n; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		Tree[u].push_back(v);
		Tree[v].push_back(u);
	}

	vector <int> visited_A(n, -1);
	vector <int> visited_B(n, -1);
	BFS(Tree, visited_A, 0);
	BFS(Tree, visited_B, x);

	int idx = 0;
	for(int i = 0; i < n; ++i)
		if(visited_B[i] < visited_A[i] && max(visited_B[idx], visited_A[idx]) < max(visited_B[i], visited_A[i]))
			idx = i;

	cout << max(visited_A[idx], visited_B[idx]) * 2 << endl;
	return 0;
}
