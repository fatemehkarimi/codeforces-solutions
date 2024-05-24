//https://codeforces.com/contest/1138/problem/C
//C. Skyscrapers

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int binary_search(vector <int> & nums, int left, int right, int value);

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);

	vector < vector <int> > _main(n, vector <int> (m));

	vector < vector <int> > rows(n);
	vector < vector <int> > columns(m);

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j){
			int x;
			scanf("%d", &x);
			_main[i][j] = x;
			rows[i].push_back(x);
			columns[j].push_back(x);
		}

	for(int i = 0; i < n; ++i){
		sort(rows[i].begin(), rows[i].end());
		rows[i].erase(std::unique(rows[i].begin(), rows[i].end()), rows[i].end());
	}
	for(int j = 0; j < m; ++j){
		sort(columns[j].begin(), columns[j].end());
		columns[j].erase(std::unique(columns[j].begin(), columns[j].end()), columns[j].end());
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			int idx_row = binary_search(rows[i], 0, rows[i].size(), _main[i][j]);
			int idx_col = binary_search(columns[j], 0, columns[j].size(), _main[i][j]);

 			cout << max(idx_row, idx_col) + max(rows[i].size() - idx_row, columns[j].size() - idx_col) << ' ';
		}
		cout << endl;
	}
	return 0;
}

int binary_search(vector <int> & nums, int left, int right, int value)
{
	if(left >= right)
		return -1;

	int middle = left + (right - left) / 2;

	if(value == nums[middle])
		return middle;

	else if(value < nums[middle])
		return binary_search(nums, left, middle, value);
	else
		return binary_search(nums, middle, right, value);
}
