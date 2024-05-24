//https://codeforces.com/problemset/problem/208/C
//Police Station

#include <iostream>
#include <iomanip>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

void bfsCount(vector <vector <int> > & Graph, vector <long long int> & nOfWays, vector <int> & level, int start);

int main(void)
{
	int n, e;
	cin >> n >> e;

	vector <vector <int> > Graph(n);

	for(int i = 0; i < e; ++i){
		int u, v;
		cin >> u >> v;

		--u, --v;

		Graph[u].push_back(v);
		Graph[v].push_back(u);
	}

	vector <int> level(n, INT_MAX);
	vector <long long int> nOfWaysToN(n, 0);

	bfsCount(Graph, nOfWaysToN, level, 0);

	long long int nOfPath = nOfWaysToN[n - 1];
	int level_n = level[n - 1];

	double ans = 1;

	for(int i = 1; i < n - 1; ++i){
		std::fill(level.begin(), level.end(), INT_MAX);
		nOfWaysToN.clear();

		bfsCount(Graph, nOfWaysToN, level, i);

		if(level[0] + level[n - 1] == level_n)
			ans = max(ans, 2 * (double)nOfWaysToN[0] * (double)nOfWaysToN[n - 1] / (double)nOfPath);
	}

	cout << setprecision(10) << fixed << ans << endl;

	return 0;
}

void bfsCount(vector <vector <int> > & Graph, vector <long long int> & nOfWays, vector <int> & level, int start)
{
	int n = Graph.size();
	vector <bool> visited(n, false);

	visited[start] = 1;
	nOfWays[start] = 1;
	level[start] = 0;

	queue <int> Queue;
	Queue.push(start);

	while(!Queue.empty()){
		int front = Queue.front();
		Queue.pop();

		for(auto a : Graph[front])
			if(!visited[a]){
				visited[a] = true;
				level[a] = level[front] + 1;
				nOfWays[a] = nOfWays[front];

				Queue.push(a);
			}
			else if(visited[a] && level[front] + 1 == level[a])
				nOfWays[a]+= nOfWays[front];
	}

	return;
}
