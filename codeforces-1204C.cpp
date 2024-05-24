//GRAPH-CODEFORCES
//https://codeforces.com/problemset/problem/1204/C
//C. Anna, Svyatoslav and Maps

#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector <vector <int> > min_dist(n, vector <int>(n, INT_MAX));

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			char c;
			cin >> c;
			if(c == '1')
				min_dist[i][j] = 1;
		}
		min_dist[i][i] = 0;
	}

	int m;
	cin >> m;
	vector <int> nodes(m);
	for(int i = 0; i < m; ++i)
		cin >> nodes[i], --nodes[i];

	for(int k = 0; k < n; ++k)
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				if(min_dist[i][k] != INT_MAX && min_dist[k][j] != INT_MAX)
					min_dist[i][j] = min(min_dist[i][j], min_dist[i][k] + min_dist[k][j]);

	vector <int> path;
	int last = 0;
	path.push_back(nodes[0]);
	for(int i = 1; i < m; ++i)
		if(min_dist[path.back()][nodes[i]] < i - last){
			path.push_back(nodes[i - 1]);
			last = i - 1;
		}

	path.push_back(nodes[m - 1]);
	cout << path.size() << endl;

	for(auto a : path)
		cout << a + 1 << ' ';
	cout << endl;
	return 0;
}

