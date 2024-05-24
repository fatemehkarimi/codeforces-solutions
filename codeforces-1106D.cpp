// https://codeforces.com/problemset/problem/1106/D
// D. Lunar New Year and a Wander

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector <set <int> > Graph(n);

	for(int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;

		Graph[u].insert(v);
		Graph[v].insert(u);
	}

	vector <int> order;
	vector <bool> removed(n, false);
	set <int> Heap;
	Heap.insert(0);
	removed[0] = true;

	while(!Heap.empty()){
		int top = *Heap.begin();
		Heap.erase(Heap.begin());
		order.push_back(top);

		for(auto a : Graph[top])
			if(!removed[a]){
				removed[a] = true;
				Heap.insert(a);
			}
	}

	for(auto a : order)
		cout << a + 1 << ' ';
	cout << endl;

	return 0;
}
