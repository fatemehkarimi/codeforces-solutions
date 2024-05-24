//https://codeforces.com/problemset/problem/25/C
//C. Roads in Berland

#include <iostream>
#include <vector>

using namespace std;

void floyd_warshall(vector <vector <int> > & Graph, vector <int> modified_nodes)
{
	int n = Graph.size();
	for(auto k : modified_nodes)
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				Graph[i][j] = Graph[j][i] = min(Graph[i][j], Graph[i][k] + Graph[k][j]);
	return;
}

int main(void)
{
	int n;
	cin >> n;
	vector <vector <int> > arr(n, vector <int>(n, 0));

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> arr[i][j];

	int k;
	cin >> k;
	while(k--){
		int u, v, c;
		cin >> u >> v >> c;
		--u, --v;

		if(c < arr[u][v]){
			vector <int> nodes;
			nodes.push_back(u);
			nodes.push_back(v);
			arr[u][v] = arr[v][u] = c;
			floyd_warshall(arr, nodes);
		}

		long long int sum = 0;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				sum += arr[i][j];

		sum /= 2;
		cout << sum << ' ';
	}
	cout << endl;
	return 0;
}
