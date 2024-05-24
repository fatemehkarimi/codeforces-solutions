//https://codeforces.com/problemset/problem/339/C
//C. Xenia and Weights

#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

bool BFS(string & weights, int level, stack <int> & result)
{
	map <pair <int, int>, pair <int, int> > visited;
	queue <pair < pair <int, int>, int> > Queue;
	for(int i = 0; i < (int)weights.size(); ++i)
		if(weights[i] == '1'){
			Queue.push(make_pair(make_pair(i + 1, 0), 1));
			visited[make_pair(i + 1, 0)] = make_pair(0, 0);
		}

	while(!Queue.empty()){
		pair <int, int> status = Queue.front().first;
		int status_level = Queue.front().second;
		int pre = status.first - visited[status].first + status.second - visited[status].second;
		Queue.pop();

		if(status_level == level){
			while(status.first != 0 || status.second != 0){
				pair <int, int> parent = visited[status];
				result.push(status.first - parent.first + status.second - parent.second);
				status = parent;
			}
			return true;
		}
		else if(status_level > level)
			break;

		++status_level;
		for(int i = 0; i < (int)weights.size(); ++i)
			if(weights[i] == '1' && (i + 1) != pre){
				pair <int, int> new_status = status;
				if(status_level % 2 == 1 && status.first + i + 1 > status.second)
					new_status.first += (i + 1);
				else if(status_level % 2 == 0 && status.first < status.second + i + 1)
					new_status.second += (i + 1);

				if(visited.find(new_status) == visited.end()){
					visited[new_status] = status;
					Queue.push(make_pair(new_status, status_level));
				}
			}
	}
	return false;
}

int main(void)
{
	string weights;
	cin >> weights;

	int m;
	cin >> m;
	stack <int> result;
	bool possible = BFS(weights, m, result);
	if(possible){
		cout << "YES" << endl;
		while(!result.empty()){
			cout << result.top() << ' ';
			result.pop();
		}
		cout << endl;
	}
	else
		cout << "NO" << endl;
	return 0;
}
