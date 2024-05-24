//https://codeforces.com/problemset/problem/404/C
//C. Restore Graph

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;
	set <pair <int, int> > distance;

	for(int i = 0; i < n; ++i){
		int d;
		cin >> d;
		distance.insert(make_pair(d, i));
	}

	vector <vector <int> > Graph(n);
	bool possible = true;
	int count_edge = 0;
	queue <pair <int, int> > Queue;

	if(distance.begin()->first != 0)
		possible = 0;
	else{
		Queue.push(make_pair(distance.begin()->second, 0));
		distance.erase(distance.begin());
	}

	while(!distance.empty() && possible){
		int node_l = distance.begin()->first;
		int node = distance.begin()->second;
		bool found = 0;
		distance.erase(distance.begin());

		while(!Queue.empty() && !found){
			int top = Queue.front().first;
			int top_l = Queue.front().second;

			if((int)Graph[top].size() >= k || top_l + 1 != node_l){
				Queue.pop();
				continue;
			}

			found = 1;
			++count_edge;
			Graph[top].push_back(node);	
			Graph[node].push_back(top);
			Queue.push(make_pair(node, node_l));
		}

		if(!found)
			possible = 0;
	}

	if(!possible)
		return cout << -1 << endl, 0;

	cout << count_edge << endl;
	for(int i = 0; i < n; ++i)
		for(auto j : Graph[i])
			if(i < j)
				cout << i + 1 << ' ' << j + 1 << endl;

	return 0;
}
