// https://codeforces.com/problemset/problem/623/A
// A. Graph and String

#include <iostream>
#include <vector>
#include <string>
#include <queue>
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

	vector <char> correspond_char(n, ' ');
	queue <int> order;

	for(int i = 0; i < n; ++i)
		if(Graph[i].size() < n - 1){
			for(int j = 0; j < n; ++j)
				if(Graph[i].find(j) == Graph[i].end()){
					correspond_char[i] = 'a';
					correspond_char[j] = 'c';
					order.push(i);
					order.push(j);
					break;
				}
			if(!order.empty())
				break;
		}

	if(order.empty()){//Graph is complete
		cout << "YES" << endl;
		cout << string(n, 'a') << endl;
		return 0;
	}

	while(!order.empty()){
		int front = order.front();
		order.pop();

		for(int i = 0; i < n; ++i)
			if(i != front && Graph[front].find(i) == Graph[front].end()){
				if(correspond_char[i] != ' '
					&& correspond_char[i] == correspond_char[front]){
					cout << "NO" << endl;
					return 0;
				}
				else if(correspond_char[i] == ' '){
					if(correspond_char[front] == 'a')
						correspond_char[i] = 'c';
					else
						correspond_char[i] = 'a';
					order.push(i);
				}
			}
	}

	for(int i = 0; i < n; ++i)
		if(correspond_char[i] == ' '){
			bool has_a = false, has_c = false;
			for(int j = 0; j < n; ++j)
				if(correspond_char[j] == 'a')
					has_a = true;
				else if(correspond_char[j] == 'c')
					has_c = true;

			if(has_a && has_c)
				correspond_char[i] = 'b';
			else if(has_a)
				correspond_char[i] = 'a';
			else if(has_c)
				correspond_char[i] = 'c';
			else{
				cout << "NO" << endl;
				return 0;
			}
		}

	//final check
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			if(i != j){
				if(Graph[i].find(j) == Graph[i].end()
					&& !((correspond_char[i] == 'a' && correspond_char[j] == 'c')
						|| (correspond_char[i] == 'c' && correspond_char[j] == 'a')))
					return cout << "NO" << endl, 0;
				else if(Graph[i].find(j) != Graph[i].end()
					&& ((correspond_char[i] == 'a' && correspond_char[j] == 'c')
						|| (correspond_char[i] == 'c' && correspond_char[j] == 'a')))
					return cout << "NO" << endl, 0;
			}

	cout << "YES" << endl;
	for(auto a : correspond_char)
		cout << a;
	cout << endl;
	return 0;
}
