//https://codeforces.com/problemset/problem/225/C

#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>

using namespace std;

int main(void)
{
	int n, m, x, y;
	cin >> n >> m >> x >> y;

	vector <int> white(m, 0);
	vector <int> black(m, 0);

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j){
			char tmp;
			cin >> tmp;

			if(tmp == '#')
				++white[j];
			else
				++black[j];
		}

	int row = min(m, y);
	int col = m;
	vector < vector <int> > blackEnd(row, vector <int> (col, INT_MAX));
	vector < vector <int> > whiteEnd(row, vector <int> (col, INT_MAX));

	blackEnd[0][0] = black[0];
	whiteEnd[0][0] = white[0];

	for(int j = 1; j < col; ++j){
		for(int p = x - 1; p < row; ++p)
			blackEnd[0][j] = min(blackEnd[0][j], whiteEnd[p][j - 1]);
		if(blackEnd[0][j] != INT_MAX)
			blackEnd[0][j] += black[j];

		for(int p = x - 1; p < row; ++p)
			whiteEnd[0][j] = min(whiteEnd[0][j], blackEnd[p][j - 1]);
		if(whiteEnd[0][j] != INT_MAX)
			whiteEnd[0][j] += white[j];

		for(int p = 1; p < row; ++p)
			if(blackEnd[p - 1][j - 1] != INT_MAX)
				blackEnd[p][j] = blackEnd[p - 1][j - 1] + black[j];

		for(int p = 1; p < row; ++p)
			if(whiteEnd[p - 1][j - 1] != INT_MAX)
				whiteEnd[p][j] = whiteEnd[p - 1][j - 1] + white[j];
	}

	int min_repaint = INT_MAX;
	for(int p = x - 1; p < row; ++p)
		min_repaint = min(min_repaint, min(whiteEnd[p][m - 1], blackEnd[p][m - 1]));

	if(min_repaint == INT_MAX)
		cout << "-1" << endl;
	else
		cout << min_repaint << endl;

	return 0;
}
