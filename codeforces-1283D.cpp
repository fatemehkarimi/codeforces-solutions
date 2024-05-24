//https://codeforces.com/problemset/problem/1283/D
// D. Christmas Trees

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;

	set <long long int> trees;
	set <long long int> human_locs;

	for(int i = 0; i < n; ++i){
		int loc;
		cin >> loc;
		trees.insert(loc);
	}

	queue <pair <int, int> > order;//loc, distance

	for(auto a : trees){
		if(trees.find(a - 1) == trees.end())
			order.push(make_pair(a - 1, 1));
		if(trees.find(a + 1) == trees.end())
			order.push(make_pair(a + 1, 1));
	}

	long long int min_distance = 0;
	while(m > 0){
		long long int loc = order.front().first;
		long long int dis = order.front().second;

		order.pop();

		if(trees.find(loc) != trees.end()
			|| human_locs.find(loc) != human_locs.end())
			continue;

		min_distance += dis;
		human_locs.insert(loc);
		--m;

		if(trees.find(loc - 1) == trees.end()
			&& human_locs.find(loc - 1) == human_locs.end())
			order.push(make_pair(loc - 1, dis + 1));

		if(trees.find(loc + 1) == trees.end()
			&& human_locs.find(loc + 1) == human_locs.end())
			order.push(make_pair(loc + 1, dis + 1));
	}

	cout << min_distance << endl;
	for(auto a : human_locs)
		cout << a << ' ';
	cout << endl;
	return 0;
}
