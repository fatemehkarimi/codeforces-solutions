//https://codeforces.com/problemset/problem/402/C

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	while(T--){
		int n, p;
		cin >> n >> p;

		vector <vector <bool> > Graph(n, vector <bool> (n, 0));

		for(int i = 0; i < n; ++i)
			Graph[i][(i + 1) % n] = Graph[(i + 1) % n][i] = 1;

		for(int i = 0; i < n; ++i)
			Graph[i][(i + 2) % n] = Graph[(i + 2) % n][i] = 1;

		int k = 3;
		while(p > 0){
			for(int i = 0; i < n && p > 0; ++i){
				Graph[i][(i + k) % n] = Graph[(i + k) % n][i] = 1;
				--p;
			}
			++k;
		}

		for(int i = 0; i < n; ++i)
			for(int j = 0; j < i; ++j)
				if(Graph[i][j])
					cout << i + 1 << ' ' << j + 1 << endl;
	}
	return 0;
}
