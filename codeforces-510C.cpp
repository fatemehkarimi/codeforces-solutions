//https://codeforces.com/problemset/problem/510/C
//C. Fox And Names

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool topological_sort(vector <vector <int> > & Graph, vector <bool> & visited, vector <bool> & on_stack, int root, stack <int> & order)
{
	visited[root] = true;
	on_stack[root] = true;
	bool valid = true;
	for(auto a : Graph[root])
		if(!visited[a])
			valid = valid & topological_sort(Graph, visited, on_stack, a, order);
		else if(on_stack[a])
			valid = false;
	order.push(root);
	on_stack[root] = false;
	return valid;
}

int main(void)
{
	int n;
	cin >> n;
	vector <vector <int> > Graph(26);
	vector <vector <int> > TGraph(26);
	string pre;
	cin >> pre;
	for(int i = 1; i < n; ++i){
		string input;
		cin >> input;

		bool valid = false;
		for(int j = 0; j < (int)min(pre.size(), input.size()); ++j)
			if(input[j] != pre[j]){
				Graph[pre[j] - 'a'].push_back(input[j] - 'a');
				valid = true;
				break;
			}

		if(!valid && input.size() < pre.size()){
			cout << "Impossible" << endl;
			return 0;
		}
		
		pre = input;
	}

	stack <int> order;
	vector <bool> visited(26, false);
	vector <bool> on_stack(26, false);
	for(int i = 0; i < 26; ++i) 
			if(!visited[i]){
			bool valid = topological_sort(Graph, visited, on_stack, i, order);
			if(!valid){
				cout << "Impossible" << endl;
				return 0;
			}
		}

	while(!order.empty()){
		cout << (char)(order.top() + 'a');
		order.pop();
	}
	cout << endl;
	return 0;
}
