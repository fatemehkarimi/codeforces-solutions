//GRAPH-CODEFORCES
//https://codeforces.com/problemset/problem/253/C
//C. Text Editor

#include <iostream>
#include <climits>
#include <vector>
#include <cstdio>
#include <queue>
#include <map>

using namespace std;

int main(void)
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector <int> lines(n);
	for(int i = 0; i < n; ++i){
		cin >> lines[i];
		++lines[i];
	}

	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	--r1, --r2;

	int result = INT_MAX;
	for(int i = 0; i < n; ++i){
		int forward = (r1 < i ? 1 : -1);
		int tmp_result = abs(i - r1);
		int min_c = c1;
		for(int j = r1;;){
			min_c = min(min_c, lines[j]);
			if(j == i)
				break;
			j += forward;
		}

		tmp_result += abs(i - r2);
		forward = (i < r2 ? 1 : -1);
		for(int j = i;;){
			min_c = min(min_c, lines[j]);
			if(j == r2)
				break;
			j += forward;
		}
		tmp_result += abs(c2 - min_c);
		result = min(result, tmp_result);
	}
	cout << result << endl;
	return 0;
}

