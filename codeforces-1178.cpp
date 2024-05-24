//https://codeforces.com/contest/1178/problem/D
//D. Prime Graph

#include <iostream>
#include <vector>
#include <cmath>
#include <cmath>
#include <set>

using namespace std;

bool isPrime(int n)
{
	if(n == 2)
		return true;
	if(n % 2 == 0)
		return false;
	int limit = sqrt(n);
	for(int i = 3; i <= limit; i += 2)
		if(n % i == 0)
			return false;
	return true;
}


int main(void)
{
	int n;
	cin >> n;

	vector < vector <int> > Graph(n);
	int count_edge = 0;
	for(int i = 0; i < n; ++i){
		Graph[i].push_back((i + 1) % n);
		Graph[(i + 1) % n].push_back(i);
		++count_edge;
	}

	int node = 0;
	while(!isPrime(count_edge) && node + 2 < n){
		if(Graph[node].size() == 2 && Graph[node + 2].size() == 2){
			Graph[node].push_back(node + 2);
			Graph[node + 2].push_back(node);
			++count_edge;
		}
		++node;
	}

	set <pair <int, int> > Edges;
	if(isPrime(count_edge)){
		for(int i = 0; i < n; ++i)
			for(auto j : Graph[i])
				if(Edges.find(make_pair(i, j)) == Edges.end() && Edges.find(make_pair(j, i)) == Edges.end())
					Edges.insert(make_pair(i, j));

		cout << count_edge << endl;
		for(auto a : Edges)
			cout << a.first + 1 << ' ' << a.second + 1 << endl;
	}
	else
		cout << -1 << endl;
	return 0;
}
