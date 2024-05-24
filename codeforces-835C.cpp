//https://codeforces.com/problemset/problem/835/C
//Star sky

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
	int n, q, c;
	cin >> n >> q >> c;

	vector < vector < vector <int> > > arr(11, vector < vector <int> > (100, vector <int> (100, 0)));

	for(int i = 0; i < n; ++i){
		int x, y, s;
		cin >> x >> y >> s;

		--x, --y;

		arr[s][x][y]++;
	}

	for(int i = 0; i < 11; ++i)
		for(int j = 0; j < 100; ++j)
			for(int k = 0; k < 100; ++k){
				if(j - 1 >= 0)
					arr[i][j][k] += arr[i][j - 1][k];

				if(k - 1 >= 0)
					arr[i][j][k] += arr[i][j][k - 1];

				if(j - 1 >= 0 && k - 1 >= 0)
					arr[i][j][k] -= arr[i][j - 1][k - 1];
			}

	for(int i = 0; i < q; ++i){
		int t, x1, y1, x2, y2;
		cin >> t >> x1 >> y1 >> x2 >> y2;

		--x1, --y1;
		--x2, --y2;

		long long int sum_s = 0;
		for(int j = 0; j < 11; ++j){
			long long int count = arr[j][x2][y2];
			if(y1 - 1 >= 0)
			 count -= arr[j][x2][y1 - 1];

			if(x1 - 1 >= 0)
			  count -= arr[j][x1 - 1][y2];

			if(x1 - 1 >= 0 && y1 - 1 >= 0)
			   count += arr[j][x1 - 1][y1 - 1];

			sum_s += (count * ((j + t) % (c + 1)));
		}

		cout << sum_s << endl;
	}

	return 0;
}
