// https://codeforces.com/problemset/problem/1296/E1
// E1. String Coloring (easy version)

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector <pair <int, char> > input(n);
	vector <int> correspond_col(n, 2);

	for(int i = 0; i < n; ++i){
		char c;
		cin >> c;
		input[i] = make_pair(i, c);
	}

	for(int i = 0; i < n - 1; ++i){
		int j = i + 1;
		while(j >= 1 && input[j - 1].second > input[j].second){
			if(correspond_col[input[j - 1].first] == 2 
				&& correspond_col[input[j].first] == 2){
				correspond_col[input[j - 1].first] = 0;
				correspond_col[input[j].first] = 1;
			}
			else if(correspond_col[input[j - 1].first] == 2)
				correspond_col[input[j - 1].first] = 
					(correspond_col[input[j].first] + 1) % 2;
			else if(correspond_col[input[j].first] == 2)
				correspond_col[input[j].first] =
					(correspond_col[input[j - 1].first] + 1) % 2;
			else if(correspond_col[input[j - 1].first] == correspond_col[input[j].first])
				return cout << "NO" << endl, 0;

			pair <int, int> tmp = input[j - 1];
			input[j - 1] = input[j];
			input[j] = tmp;
			--j;
		}
	}

	if(correspond_col[n - 1] == 2)
		correspond_col[n - 1] = 0;

	for(int i = n - 2; i >= 0; --i)
		if(correspond_col[i] == 2)
			correspond_col[i] = correspond_col[i + 1];

	cout << "YES" << endl;
	for(auto a : correspond_col)
		cout << a;
	cout << endl;
	return 0;
}
