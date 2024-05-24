// https://codeforces.com/contest/1327/problem/C
// C. Game with Chips

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	int n, m, k;
	cin >> n >> m >> k;
	vector <pair <int, int> > points(n, make_pair(0, 0));

	int max_x = 0;
	int max_y = 0;
	for(int i = 0; i < k; ++i){
		int x, y;
		cin >> x >> y;
		--x, --y;
		max_x = max(max_x, x);
		max_y = max(max_y, y);
	}

	//trash data
	for(int i = 0; i < k; ++i){
		int x, y;
		cin >> x >> y;
	}

	string result(max_y, 'L');
	result = result + string(max_x, 'U');

	char action = 'R';
	for(int i = 0; i < n; ++i){
		result = result + string(m - 1, action);
		if(i != n - 1)
			result = result + 'D';
		if(action == 'L')
			action = 'R';
		else
			action = 'L';
	}
	cout << result.size() << endl;
	cout << result << endl;
	return 0;
}
