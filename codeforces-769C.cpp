//https://codeforces.com/problemset/problem/769/C
//C. Cycle In Maze

#include <iostream>
#include <string>
#include <climits>
#include <queue>
#define SIZE 1000
using namespace std;

char Graph[SIZE][SIZE];
int _distance[SIZE][SIZE];
char result[SIZE * SIZE];
const int x_r[] = {1, 0, 0, -1};
const int y_c[] = {0, -1, 1, 0};
char dir[] = {'D', 'L', 'R', 'U'};

int main(void)
{
	int n, m, k;
	pair <int, int> start;
	cin >> n >> m >> k;

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j){
			cin >> Graph[i][j];
			_distance[i][j] = INT_MAX;
		}

	if(k % 2)
		return cout << "IMPOSSIBLE" << endl, 0;

	queue <pair <int, int> > Queue;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(Graph[i][j] == 'X'){
				Queue.push(make_pair(i, j));
				start = Queue.front();
				_distance[i][j] = 0;
				break;
			}

	while(!Queue.empty()){
		int x = Queue.front().first;
		int y = Queue.front().second;
		Queue.pop();

		for(int i = 0; i < 4; ++i){
			int x_n = x + x_r[i];
			int y_n = y + y_c[i];

			if(x_n >= 0 && x_n < n && y_n >= 0 && y_n < m && Graph[x_n][y_n] != '*'
				&& _distance[x_n][y_n] > _distance[x][y] + 1){
				_distance[x_n][y_n] = _distance[x][y] + 1;
				Queue.push(make_pair(x_n, y_n));
			}
		}
	}

	int x_curr = start.first;
	int y_curr = start.second;
	int idx = 0;
	while(k){
		bool found = false;
		for(int i = 0; i < 4; ++i){
			int x_n = x_curr + x_r[i];
			int y_n = y_curr + y_c[i];

			if(x_n >= 0 && x_n < n && y_n >= 0 && y_n < m && Graph[x_n][y_n] != '*' && _distance[x_n][y_n] <= k){
				result[idx] = dir[i];
				found = true;
				x_curr = x_n;
				y_curr = y_n;
				break;
			}
		}

		if(!found)
			return cout << "IMPOSSIBLE" << endl, 0;
		++idx;
		--k;
	}

	for(int i = 0; i < idx; ++i)
		cout << result[i];
	cout << endl;
	return 0;
}
