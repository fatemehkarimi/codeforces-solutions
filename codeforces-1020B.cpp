//https://codeforces.com/problemset/problem/1020/B
//B. Badge

#include <iostream>
#include <vector>

using namespace std;

int dfs(vector <int> & Graph, vector <bool> & visited, int start);

int main(void)
{
	int n;
	cin >> n;
	vector <int> Garph(n);
	for(int i = 0; i < n; ++i){
		cin >> Garph[i];
		--Garph[i];
	}

	for(int i = 0; i < n; ++i){
		vector <bool> visited(n, false);
		int result = dfs(Garph, visited, i);
		cout << result + 1 << ' ';
	}
	cout << endl;
	return 0;
}

int dfs(vector <int> & Graph, vector <bool> & visited, int start)
{
	visited[start] = true;
	if(visited[Graph[start]])
		return Graph[start];
	else
		return dfs(Graph, visited, Graph[start]);
}
