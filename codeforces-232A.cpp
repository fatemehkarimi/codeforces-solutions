// https://codeforces.com/problemset/problem/232/A
// A. Cycles

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	int k;
	cin >> k;

	vector <string> Graph(100, string(100, '0'));

	//contains 1 cycle at the begining
	Graph[0][1] = Graph[0][2] = Graph[1][0] = Graph[1][2] = Graph[2][0] = Graph[2][1] = '1';
	k -= 1;

	int n = 3;
	while(k > 0){
		bool no_edge_added = true;
		
		for(int i = 0; i < n && k > 0; ++i)
			for(int j = 0; j < n && k > 0; ++j)
				if(i != j && Graph[i][j] == '0'){
					int new_edges = 0;
					for(int k = 0; k < n; ++k)
						if(Graph[i][k] == Graph[j][k] && Graph[i][k] == '1')
							++new_edges;

					if(new_edges > 0 && new_edges <= k){
						k -= new_edges;
						Graph[i][j] = Graph[j][i] = '1';
						no_edge_added = false;
					}
				}
		
		if(no_edge_added){
			Graph[0][n] = Graph[n][0] = Graph[1][n] = Graph[n][1] = '1';
			--k;
			++n;
		}
	}

	cout << n << endl;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j)
			cout << Graph[i][j];
		cout << endl;
	}
	return 0;
}
