// https://codeforces.com/problemset/problem/605/B
// B. Lazy Student

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;

	set <pair <int, int> > TreeEdges;
	set <pair <int, int> > NonTreeEdges;

	for(int i = 0; i < m; ++i){
		int val, in_tree;
		cin >> val >> in_tree;

		if(in_tree)
			TreeEdges.insert(make_pair(val, i));
		else
			NonTreeEdges.insert(make_pair(val, i));
	}

	vector <map <int, int> > Graph(n);
	vector <pair <int, int> > output_order(m);

	int idx = 1;
	for(auto a : TreeEdges){
		Graph[0][idx] = a.first;
		Graph[idx][0] = a.first;
		output_order[a.second] = make_pair(0, idx++);
	}

	bool possible = true;
	for(int i = 1; i < n && !NonTreeEdges.empty(); ++i)
		if(NonTreeEdges.begin()->first >= Graph[0][i]){
			for(int j = 1; j < n && !NonTreeEdges.empty(); ++j){
				if(i == j || Graph[i].find(j) != Graph[i].end())
					continue;

				if(NonTreeEdges.begin()->first < Graph[0][j])
					break;

				Graph[i][j] = Graph[j][i] = NonTreeEdges.begin()->first;
				output_order[NonTreeEdges.begin()->second] = make_pair(i, j);
				NonTreeEdges.erase(NonTreeEdges.begin());
			}
		}
		else
			possible = false;

	if(!possible)
		return cout << -1 << endl, 0;

	for(auto a : output_order)
		cout << a.first + 1 << ' ' << a.second + 1 << endl;
	return 0;
}
