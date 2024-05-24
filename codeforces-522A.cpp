// https://codeforces.com/problemset/problem/522/A
// A. Reposts

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;
void lower(string & input)
{
	for(auto & a : input)
		if(a >= 'A' && a <= 'Z')
			a = a - 'A' + 'a';
}

int dfs(map <string, vector <string> > & Graph, map <string, bool> & visited, string root, int len)
{
	int max_length = len + 1;
	visited[root] = true;

	for(auto a : Graph[root])
		if(!visited[a])
			max_length = max(max_length, dfs(Graph, visited, a, len + 1));

	return max_length;
}

int main(void)
{
	int n;
	cin >> n;
	string x, t, y;

	map <string, vector <string> > Graph;
	map <string, bool> visited;

	for(int i = 0; i < n; ++i){
		cin >> x >> t >> y;
		lower(x);
		lower(y);
		Graph[y].push_back(x);
		visited[x] = visited[y] = false;
	}

	int result = dfs(Graph, visited, "polycarp", 0);
	cout << result << endl;

	return 0;
}
