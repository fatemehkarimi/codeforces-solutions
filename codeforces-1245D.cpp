//https://codeforces.com/contest/1245/problem/D
//D. Shichikuji and Power Grid

#include <iostream>
#include <climits>
#include <vector>
#include <set>
#define lld long long int

using namespace std;

lld calculate_wire_cost(pair <lld, lld> c1, pair <lld, lld> c2, int idx1, int idx2, vector <lld> & cost_wire)
{
	lld cost = abs(c1.first - c2.first) + abs(c1.second - c2.second);
	cost *= (cost_wire[idx1] + cost_wire[idx2]);
	return cost;
}

lld min_cost(vector <pair <lld, lld> > & coordinates, vector <lld> & cost_station, vector <lld> & cost_wire, vector <int> & parent)
{
	int n = coordinates.size();
	vector <lld> min_cost = cost_station;
	vector <bool> removed_from_heap(n, false);
	set <pair <lld, int> > Heap;

	for(int i = 0; i < n; ++i)
		Heap.insert(make_pair(min_cost[i], i));

	for(int i = 0; i < n; ++i)
		parent[i] = i;

	while(!Heap.empty()){
		int city_idx = Heap.begin()->second;
		Heap.erase(Heap.begin());
		removed_from_heap[city_idx] = true;

		for(int i = 0; i < n; ++i)
			if(!removed_from_heap[i]
				&& calculate_wire_cost(coordinates[city_idx], coordinates[i], city_idx, i, cost_wire) < min_cost[i]){
				Heap.erase(make_pair(min_cost[i], i));
				min_cost[i] = calculate_wire_cost(coordinates[city_idx], coordinates[i], city_idx, i, cost_wire);
				Heap.insert(make_pair(min_cost[i], i));
				parent[i] = city_idx;
			}
	}

	lld result = 0;
	for(int i = 0; i < n; ++i)
		result += min_cost[i];
	return result;
}

int main(void)
{
	int n;
	cin >> n;
	vector <pair <lld, lld> > coordinates(n);
	for(int i = 0; i < n; ++i)
		cin >> coordinates[i].first >> coordinates[i].second;

	vector <lld> cost_station(n);
	for(int i = 0; i < n; ++i)
		cin >> cost_station[i];

	vector <lld> cost_wire(n);
	for(int i = 0; i < n; ++i)
		cin >> cost_wire[i];

	vector <int> parent(n);
	lld result = min_cost(coordinates, cost_station, cost_wire, parent);

	vector <int> city_station;
	vector <pair <int, int> > city_wire;

	for(int i = 0; i < n; ++i)
		if(parent[i] == i)
			city_station.push_back(i);
		else
			city_wire.push_back(make_pair(i, parent[i]));

	//output
	cout << result << endl;
	cout << city_station.size() << endl;
	for(auto a : city_station)
		cout << a + 1 << ' ';
	cout << endl;
	cout << city_wire.size() << endl;
	if(!city_wire.empty())
		for(auto a : city_wire)
			cout << a.first + 1 << ' ' << a.second + 1 << endl;

	return 0;
}
