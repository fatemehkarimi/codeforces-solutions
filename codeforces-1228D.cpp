//https://codeforces.com/contest/1228/problem/D
//D. Complete Tripartite

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector < set <int> > Graph(n);
	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;

		Graph[u].insert(v);
		Graph[v].insert(u);
	}

	vector <int> div_node(n, -1);
	vector < vector <int> > possible_divs(n, vector <int> (3, true));

	bool possible = true;
	for(int i = 0; i < 3; ++i){
		int node;
		for(int j = 0; j < n; ++j)
			if(div_node[j] == -1){
				node = j;
				break;
			}

		if(node == -1)
			return cout << "-1" << endl, 0;

		for(auto a : Graph[node])
			possible_divs[a][i] = false;

		for(int j = 0; j < n; ++j)
			if(possible_divs[j][i]){
				if(div_node[j] == -1)
					div_node[j] = i;
				else
					possible = false;
			}
	}

	vector <vector <int> > groups(3);
	for(int i = 0; i < n; ++i)
		if(div_node[i] == -1)
			possible = false;
		else
			groups[div_node[i]].push_back(i);

	if(!possible)
		return cout << -1 << endl, 0;

	int count = 0;
	for(int g1 = 0; g1 < 3; ++g1)
		for(int g2 = g1 + 1; g2 < 3; ++g2)
			for(auto a : groups[g1])
				for(auto b : groups[g2])
					if(Graph[a].find(b) == Graph[a].end())
						return cout << "-1" << endl, 0;
					else
						++count;
	if(count != m)
		return cout << "-1" << endl, 0;

	for(auto a : div_node)
		cout << a + 1 << ' ';
	cout << endl;
	return 0;
}
