//https://codeforces.com/problemset/problem/779/C
//Dishonest Sellers

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair <int, int> a, pair <int, int> b)
{
	return (a.first - a.second) < (b.first - b.second);
}

int main(void)
{
	int n, k;
	cin >> n >> k;

	vector < pair <int, int> > prices(n);

	for(int i = 0; i < n; ++i)
		cin >> prices[i].first;
	for(int i = 0; i < n; ++i)
		cin >> prices[i].second;

	sort(prices.begin(), prices.end(), compare);

	int total_money = 0;
	for(int i = 0; i < k; ++i)
		total_money += prices[i].first;

	for(int i = k; i < n; ++i)
		total_money += min(prices[i].first, prices[i].second);

	cout << total_money << endl;
	
	return 0;
}
