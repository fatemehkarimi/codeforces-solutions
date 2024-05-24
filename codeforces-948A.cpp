//https://codeforces.com/problemset/problem/948/A
//A. Protect Sheep

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector <string> field(n);
	for(int i = 0; i < n; ++i)
		cin >> field[i];

	int i_ns[] = {-1, 0, 0, 1};
	int j_ns[] = {0, -1, 1, 0};
	bool possible = true;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			for(int k = 0; k < 4; ++k){
				int i_n = i + i_ns[k];
				int j_n = j + j_ns[k];

				if(i_n >= 0 && i_n < n && j_n >= 0 && j_n < m && field[i][j] == 'S'){
					if(field[i_n][j_n] == 'W')
						possible = false;
					else if(field[i_n][j_n] == '.')
						field[i_n][j_n] = 'D';
				}
			}


	if(possible){
		cout << "YES" << endl;
		for(auto a : field)
			cout << a << endl;
	}
	else
		cout << "NO" << endl;
	return 0;
}
