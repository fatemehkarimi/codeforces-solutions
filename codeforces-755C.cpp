//https://codeforces.com/problemset/problem/755/C
//C. PolandBall and Forest

#include <iostream>
#include <vector>

using namespace std;

int find_parent(vector <int> & ufds, int x);
void _union(vector <int> & ufds, int x, int y);

int main(void)
{
	int n;
	cin >> n;
	vector <int> farthest(n);
	for(int i = 0; i < n; ++i){
		cin >> farthest[i];
		--farthest[i];
	}

	vector <int> ufds(n, -1);
	for(int i = 0; i < n; ++i)
		_union(ufds, i, farthest[i]);

	int result = 0;
	for(int i = 0; i < n; ++i)
		if(ufds[i] == -1)
			++result;
		
	cout << result << endl;
	return 0;
}

int find_parent(vector <int> & ufds, int x)
{
	int root = x;
	while(ufds[root] != -1)
		root = ufds[root];
	while(x != root){
		int next = ufds[x];
		ufds[x] = root;
		x = next;
	}
	return root;
}

void _union(vector <int> & ufds, int x, int y)
{
	int p1 = find_parent(ufds, x);
	int p2 = find_parent(ufds, y);
	if(p1 == p2)
		return;
	ufds[p2] = p1;
	return;
}
