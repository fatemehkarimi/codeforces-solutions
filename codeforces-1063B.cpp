// https://codeforces.com/problemset/problem/1063/B
// B. Labyrinth

#include <iostream>
#include <climits>
#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;

int main(void)
{
	
	int n, m, r, c, x, y;

	cin >> n >> m >> r >> c >> x >> y;
	--r, --c;

	vector <string> Grid(n);
	for(int i = 0; i < n; ++i)
		cin >> Grid[i];

	vector <vector <pair <int, int> > > visited(
		n, vector <pair <int, int> >(m, make_pair(INT_MAX, INT_MAX)));

	queue < pair <int, int> > top_down_queue;
	queue < pair <int, int> > left_right_queue;

	top_down_queue.push(make_pair(r, c));
	visited[r][c] = make_pair(0, 0);

	int x_next[] = {0, -1, 0, 1};//left up right down
	int y_next[] = {-1, 0, 1, 0};
	
	while(!top_down_queue.empty() || !left_right_queue.empty()){
		while(!top_down_queue.empty()){
			int r_t = top_down_queue.front().first;
			int c_t = top_down_queue.front().second;
			int x_t = visited[r_t][c_t].first;
			int y_t = visited[r_t][c_t].second;

			left_right_queue.push(top_down_queue.front());
			top_down_queue.pop();

			for(int i = 1; i < 4; i += 2){
				int r_n = r_t + x_next[i];
				int c_n = c_t + y_next[i];

				if(r_n >= 0 && r_n < n && c_n >= 0 && c_n < m
					&& Grid[r_n][c_n] != '*'
					&& visited[r_n][c_n] == make_pair(INT_MAX, INT_MAX)){
					visited[r_n][c_n] = make_pair(x_t, y_t);
					top_down_queue.push(make_pair(r_n, c_n));
				}
			}
		}

		int r_t = left_right_queue.front().first;
		int c_t = left_right_queue.front().second;
		int x_t = visited[r_t][c_t].first;
		int y_t = visited[r_t][c_t].second;

		left_right_queue.pop();

		for(int i = 0; i < 4; i += 2){
			int r_n = r_t + x_next[i];
			int c_n = c_t + y_next[i];

			if(r_n >= 0 && r_n < n && c_n >= 0 && c_n < m
				&& Grid[r_n][c_n] != '*'
				&& visited[r_n][c_n] == make_pair(INT_MAX, INT_MAX)){
				if(i == 0)
					visited[r_n][c_n] = make_pair(x_t + 1, y_t);
				else
					visited[r_n][c_n] = make_pair(x_t, y_t + 1);

				top_down_queue.push(make_pair(r_n, c_n));
			}
		}
	}

	int counter = 0;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(visited[i][j].first <= x && visited[i][j].second <= y)
				++counter;

	cout << counter << endl;
	return 0;
}
