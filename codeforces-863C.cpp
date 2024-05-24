//https://codeforces.com/problemset/problem/863/C
//C. 1-2-3

#include <iostream>
#include <vector>
#include <map>

#define lld long long int

using namespace std;

int visited_before(vector <pair <int, int> > & visited, pair <int, int> state)
{
	for(int i = 0; i < (int)visited.size(); ++i)
		if(visited[i] == state)
			return i;
	return -1;
}

int identify_winner(pair <int, int> status)//withdraw: 0 A: 1 B: 2
{
	int a = min(status.first, status.second);
	int b = max(status.first, status.second);

	if(a == b)
		return 0;

	if(a == 0 && b == 1)
		return status.first == 1 ? 1 : 2;
	if(a == 1 && b == 2)
		return status.first == 2 ? 1 : 2;
	if(a == 0 && b == 2)
		return status.first == 0 ? 1 : 2;
}

pair <lld, lld> dfs(map <pair <int, int>, pair <int, int> > & Graph, pair <int, int> start, vector <pair <int, int> > & visited, lld k)
{
	int s_loop = visited_before(visited, start);
	if(s_loop == -1){
		visited.push_back(start);
		return dfs(Graph, Graph[start], visited, k);
	}

	//calculating scores
	lld loop_size = visited.size() - s_loop;
	lld score_a = 0, score_b = 0;
	for(int i = 0; i < min(k, (lld)s_loop); ++i){
		int winner = identify_winner(visited[i]);
		if(winner == 1)
			++score_a;
		else if(winner == 2)
			++score_b;
	}
	k -= min(k, (lld)s_loop);

	lld tmp_a = 0, tmp_b = 0;
	for(int i = s_loop; i < (int)visited.size(); ++i){
		int winner = identify_winner(visited[i]);
		if(winner == 1)
			++tmp_a;
		else if(winner == 2)
			++tmp_b;
	}

	score_a += (k / loop_size) * tmp_a;
	score_b += (k / loop_size) * tmp_b;

	for(int i = s_loop; i < s_loop + k % loop_size; ++i){
		int winner = identify_winner(visited[i]);
		if(winner == 1)
			++score_a;
		else if(winner == 2)
			++score_b;
	}

	return make_pair(score_a, score_b);
}

int main(void)
{
	lld k;
	cin >> k;
	int a, b;
	cin >> a >> b;
	--a, --b;//initial state

	vector <vector <int> > A_moves(3, vector <int> (3));
	vector <vector <int> > B_moves(3, vector <int> (3));

	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 3; ++j)
			cin >> A_moves[i][j];

	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 3; ++j)
			cin >> B_moves[i][j];

	map <pair <int, int>, pair <int, int> > Graph;
	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 3; ++j)
			Graph[make_pair(i, j)] = make_pair(A_moves[i][j] - 1, B_moves[i][j] - 1);

	vector <pair <int, int> > visited;
	pair <lld, lld> result = dfs(Graph, make_pair(a, b), visited, k);
	cout << result.first << ' ' << result.second << endl;
	return 0;
}
