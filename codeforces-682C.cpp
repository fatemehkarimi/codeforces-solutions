//https://codeforces.com/contest/682/problem/C
//Alyona and the Tree

#include <iostream>
#include <vector>

using namespace std;

vector <int> value;
vector < pair <int, int> > Tree[100010];

long long int DFS(int start, long long int dis);

int main(void)
{
	int n = 0;
	cin >> n;

	value.resize(n + 1);

	for(int i = 1; i <= n; ++i)
		cin >> value[i];

	for(int i = 1; i < n; ++i){
		int x, y;
		cin >> x >> y;

		Tree[x].push_back(make_pair(i + 1, y));
	}

	cout << n - DFS(1, 0) << endl;

	return 0;
}

long long int DFS(int start, long long int dis)
{
	if(dis > value[start]) return 0;
	int count = 1;

	for(int i = 0; i < Tree[start].size(); ++i)
		count += DFS(Tree[start][i].first, max(dis, 0LL) + Tree[start][i].second);

	return count;
}
