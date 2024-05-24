//https://codeforces.com/problemset/problem/1139/C
//C. Edgy Trees

#include <iostream>
#include <vector>
#define MODULO 1000000007

using namespace std;

long long int count_total(int a, int b)
{
	long long int result = 1;
	while(b--)
		result = (result * a) % MODULO;
	return result;
}

int dfs(vector <vector <int> > & Tree, vector <bool> & visited, int source)
{
	visited[source] = true;
	int result = 1;
	for(auto a : Tree[source])
		if(!visited[a])
			result += dfs(Tree, visited, a);
	return result;
}


int main(void)
{
	int n, k;
	cin >> n >> k;

	vector < vector <int> > Tree(n);

	for(int i = 1; i < n; ++i){
		int u, v, col;
		cin >> u >> v >> col;
		--u, --v;

		if(col == 1)
			continue;

		Tree[u].push_back(v);
		Tree[v].push_back(u);
	}

	long long int total = count_total(n, k);
	vector <bool> visited(n, false);

	for(int i = 0; i < n; ++i)
		if(!visited[i]){
			int cmp_size = dfs(Tree, visited, i);
			long long int ways = count_total(cmp_size, k);
			total -= ways;
			if(total < 0)
				total += MODULO;
		}

	cout << total << endl;
	return 0;
}

