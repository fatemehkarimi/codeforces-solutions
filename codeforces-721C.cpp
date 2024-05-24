//https://codeforces.com/problemset/problem/721/C
//C. Journey

#include <iostream>
#include <climits>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
	int n, m, T;
	cin >> n >> m >> T;

	vector <vector <pair <int, int> > > Graph(n);
	for(int i = 0; i < m; ++i){
		int u, v, t;
		cin >> u >> v >> t;
		--u, --v;
		Graph[u].push_back(make_pair(v, t));
	}

	vector <vector <int> > max_city(n, vector <int> (n, T + 1));
	vector <vector <int> > parent(n, vector <int> (n, -1));

	max_city[0][0] = 0;
	for(int i = 1; i < n; ++i)
		for(int j = 0; j < n; ++j)
			if(max_city[i - 1][j] <= T){
				for(auto node : Graph[j])
					if(max_city[i - 1][j] + node.second < max_city[i][node.first]){
						max_city[i][node.first] = max_city[i - 1][j] + node.second;
						parent[i][node.first] = j;
					}
			}

	int idx = 0;
	for(int i = n - 1; i >= 0; --i)
		if(max_city[i][n - 1] <= T){
			idx = i;
			break;
		}

	cout << idx + 1 << endl;
	stack <int> Stack;
	int end = n - 1;
	while(end != -1 && idx >= 0){
		Stack.push(end);
		end = parent[idx--][end];
	}

	while(!Stack.empty()){
		cout << Stack.top() + 1 << ' ';
		Stack.pop();
	}
	cout << endl;
	return 0;
}
