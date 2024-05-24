// https://codeforces.com/problemset/problem/1076/D
// D. Edge Deletion

#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <map>

#define lld long long int

using namespace std;

void build_tree(vector <vector <int> > & tree, vector <int> & dijkstra_parent)
{
	for(int i = 1; i < (int)dijkstra_parent.size(); ++i){
		tree[i].push_back(dijkstra_parent[i]);
		tree[dijkstra_parent[i]].push_back(i);
	}
	return;
}

void print_tree(map <pair <int, int>, int> & input_order,
	vector <vector <int> > & tree, int & edge_remain, int root, int parent)
{
	for(auto a : tree[root])
		if(a != parent && edge_remain){
			cout <<input_order[make_pair(root, a)] + 1 << ' ';
			--edge_remain;
			print_tree(input_order, tree, edge_remain, a, root);
		}
}

int main(void)
{
	int n, m, k;
	cin >> n >> m >> k;

	vector <map <int, lld> > Graph(n);
	map < pair <int, int>, int> input_order;

	for(int i = 0; i < m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;

		Graph[u][v] = Graph[v][u] = w;
		input_order[make_pair(u, v)] = i;
		input_order[make_pair(v, u)] = i;
	}

	vector <lld> min_distance(n, LLONG_MAX);
	vector <int> dijkstra_parent(n);
	set < pair <lld, int> > Queue;

	min_distance[0] = 0;
	Queue.insert(make_pair(0, 0));

	while(!Queue.empty()){
		int front = Queue.begin()->second;
		Queue.erase(Queue.begin());

		for(auto a : Graph[front])
			if(min_distance[front] == INT_MAX
				|| (min_distance[front] + a.second < min_distance[a.first])){
				Queue.erase(make_pair(min_distance[a.first], a.first));
				min_distance[a.first] = min_distance[front] + a.second;
				dijkstra_parent[a.first] = front;
				Queue.insert(make_pair(min_distance[a.first], a.first));
			}
	}

	vector <vector <int> > tree(n);
	build_tree(tree, dijkstra_parent);

	int edge_remain = min(k, n - 1);
	cout << edge_remain << endl;
	print_tree(input_order, tree, edge_remain, 0, -1);
	cout << endl;
	return 0;
}
