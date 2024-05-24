// https://codeforces.com/problemset/problem/743/D
// D. Chloe and pleasant prizes

#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <set>

#define lld long long int

using namespace std;

void calculate_sum_pleaseness(vector <vector <int> > & Tree,
	vector <lld> & pleaseness, vector <lld> & max_pleaseness, int root, int parent)
{
	lld max_child_pleaseness = LLONG_MIN;

	for(auto a : Tree[root])
		if(a != parent){
			calculate_sum_pleaseness(Tree, pleaseness, max_pleaseness, a, root);
			pleaseness[root] += pleaseness[a];
			max_child_pleaseness = max(max_child_pleaseness, max_pleaseness[a]);
		}

	max_pleaseness[root] = max(pleaseness[root], max_child_pleaseness);
	return;
}

void get_value_from_pool(pair <lld, lld> & result, multiset <lld, std::greater<lld> > & pool)
{
	if(pool.size() < 2)
		return;

	if((result.first == LLONG_MIN && result.second == LLONG_MIN)
		|| (*(pool.begin()) + *(++pool.begin()) > result.first + result.second)){
		result.first = *(pool.begin());
		result.second = *(++pool.begin());
	}
}

void get_two_max(vector <vector <int> > & Tree, vector <lld> & max_pleaseness,
	vector <pair <lld, lld> > & dp, int root, int parent)
{
	multiset <lld, std::greater<lld> > max_please_pool;
	multiset <lld, std::greater<lld> > max_dp_pool;

	for(auto a : Tree[root])
		if(a != parent){
			get_two_max(Tree, max_pleaseness, dp, a, root);
			max_please_pool.insert(max_pleaseness[a]);

			if(dp[a].first != LLONG_MIN){
				max_dp_pool.insert(dp[a].first);
				max_dp_pool.insert(dp[a].second);
			}
		}

	get_value_from_pool(dp[root], max_please_pool);
	get_value_from_pool(dp[root], max_dp_pool);

	for(auto a : Tree[root])
		if(a != parent){
			if(dp[a].first == LLONG_MIN)
				continue;

			auto loc = max_dp_pool.find(dp[a].first);
			max_dp_pool.erase(loc);
			loc = max_dp_pool.find(dp[a].second);
			max_dp_pool.erase(loc);

			max_dp_pool.insert(max_pleaseness[a]);
			get_value_from_pool(dp[root], max_dp_pool);

			loc = max_dp_pool.find(max_pleaseness[a]);
			max_dp_pool.erase(loc);
		}
	return;
}

int main(void)
{
	int n;
	cin >> n;

	vector <lld> pleaseness(n);

	for(int i = 0; i < n; ++i)
		cin >> pleaseness[i];

	vector <vector <int> > Tree(n);

	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
		--u, --v;
		Tree[u].push_back(v);
		Tree[v].push_back(u);
	}

	vector <lld> max_pleaseness(n, LLONG_MIN);
	vector <pair <lld, lld> > dp(n, make_pair(LLONG_MIN, LLONG_MIN));
	calculate_sum_pleaseness(Tree, pleaseness, max_pleaseness, 0, -1);
	get_two_max(Tree, max_pleaseness, dp, 0, -1);

	if(dp[0].first != LLONG_MIN && dp[0].second != LLONG_MIN)
		cout << dp[0].first + dp[0].second << endl;
	else
		cout << "Impossible" << endl;
	return 0;
}
