// https://codeforces.com/problemset/problem/1082/D
// D. Maximum Diameter Graph

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector <int> node_degree(n);
	vector <int> internals;
	vector <int> leaves;

	for(int i = 0; i < n; ++i){
		int d;
		cin >> d;
		node_degree[i] = d;
		
		if(d >= 2)
			internals.push_back(i);
		else
			leaves.push_back(i);
	}

	if(internals.empty())
		return cout << "NO" << endl, 0;

	int max_length = 0;
	vector <pair <int, int> > edges;

	for(int i = 1; i < (int)internals.size(); ++i){
		edges.push_back(make_pair(internals[i - 1], internals[i]));
		--node_degree[internals[i - 1]];
		--node_degree[internals[i]];
		++max_length;
	}

	if(leaves.size() >= 1){
		edges.push_back(make_pair(internals[0], leaves[0]));
		--node_degree[internals[0]];
		++max_length;
	}
	if(leaves.size() >= 2){
		edges.push_back(make_pair(internals.back(), leaves[1]));
		--node_degree[internals.back()];
		++max_length;
	}

	int curr_internal = 0;
	for(int i = 2; i < (int)leaves.size();)
		if(node_degree[internals[curr_internal]] > 0){
			edges.push_back(make_pair(internals[curr_internal], leaves[i]));
			--node_degree[internals[curr_internal]];
			++i;
		}
		else{
			++curr_internal;
			if(curr_internal >= (int)internals.size())
				return cout << "NO" << endl, 0;
		}

	cout << "YES " << max_length << endl;
	cout << edges.size() << endl;
	for(auto a : edges)
		cout << a.first + 1 << ' ' << a.second + 1 << endl;
	return 0;
}
