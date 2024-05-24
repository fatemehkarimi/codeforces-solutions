//https://codeforces.com/problemset/problem/939/A
//A. Love Triangle

#include <iostream>
#include <vector>

using namespace std;

bool findTriangle(vector <int> & love, vector <bool> & visited, vector <int> & level, int start);

int main(void)
{
	int n = 0;
	cin >> n;

	vector <int> love(n);
	for(int i = 0; i < n; ++i){
		cin >> love[i];
		--love[i];
	}

	int result = 0;
	for(int i = 0; i < n; ++i){
		vector <bool> visited(n, false);
		vector <int> level(n, -1);
		level[i] = 0;
		result |= findTriangle(love, visited, level, i);
	}

	if(result)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}

bool findTriangle(vector <int> & love, vector <bool> & visited, vector <int> & level, int start)
{
	visited[start] = 1;
	if(visited[love[start]]){
		if(abs(level[start] - level[love[start]]) == 2)
			return true;
	}
	else{
		level[love[start]] = level[start] + 1;
		return findTriangle(love, visited, level, love[start]);
	}
	return false;
}
