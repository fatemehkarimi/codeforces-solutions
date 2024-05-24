//https://codeforces.com/problemset/problem/242/C
//C. King's Path

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

bool is_in_allowed(vector <pair <int, pair <int, int> > > & divs, int xd, int yd, int left, int right)
{
	if(left >= right)
		return false;

	int middle = left + (right - left) / 2;
	if(xd == divs[middle].first && yd >= divs[middle].second.first && yd <= divs[middle].second.second)
		return true;

	if(xd < divs[middle].first)
		return is_in_allowed(divs, xd, yd, left, middle);
	else if(xd > divs[middle].first)
		return is_in_allowed(divs, xd, yd, middle + 1, right);
	else{
		if(yd < divs[middle].second.first)
			return is_in_allowed(divs, xd, yd, left, middle);
		else
			return is_in_allowed(divs, xd, yd, middle + 1, right);
	}
}

int BFS(vector <pair <int, pair <int, int> > > & divs, int xs, int ys, int xd, int yd)
{
	map <pair <int, int>, int> min_cost;
	queue <pair <int, int> > Queue;
	min_cost[make_pair(xs, ys)] = 0;
	Queue.push(make_pair(xs, ys));

	int x_n[] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int y_n[] = {-1, 0, 1, -1, 1, -1, 0, 1};

	while(!Queue.empty()){
		pair <int, int> front = Queue.front();
		Queue.pop();

		if(front.first == xd && front.second == yd)
			return min_cost[front];
		else if(min_cost[front] > 100000)
			return -1;

		for(int i = 0; i < 8; ++i){
			int x = front.first + x_n[i];
			int y = front.second + y_n[i];

			if(min_cost.find(make_pair(x, y)) == min_cost.end() && is_in_allowed(divs, x, y, 0, divs.size())){
				min_cost[make_pair(x, y)] = min_cost[front] + 1;
				Queue.push(make_pair(x, y));
			}
		}
	}
	return -1;
}

int main(void)
{
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int n;
	cin >> n;
	vector <pair <int, pair <int, int> > > divs(n);

	for(int i = 0; i < n; ++i)
		cin >> divs[i].first >> divs[i].second.first >> divs[i].second.second;
	sort(divs.begin(), divs.end());

	int result = BFS(divs, x1, y1, x2, y2);
	cout << result << endl;
	return 0;
}
