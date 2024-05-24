//https://codeforces.com/problemset/problem/363/C
//C. Fixing Typos

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
	string input;
	cin >> input;

	for(int i = 0; i < (int)input.size(); ++i){
		if(i + 1 < (int)input.size() && input[i + 1] != input[i])
			continue;

		int j = i + 2;
		for(j = i + 2; i < (int)input.size() && input[i] == input[j]; ++j)
			input[j] = ' ';
		i = j - 1;
	}

	bool is_typo = false;
	int n = input.size();

	for(int i = 0; i < n; ++i){
		if(input[i] == ' ')
			continue;

		bool is_curr_typo = false;
		int j = i + 1;
		while(j < n && input[j] == ' ')
			++j;

		if(j < n && input[j] == input[i])
			is_curr_typo = true;

		if(is_typo && is_curr_typo){
			input[i] = ' ';
			is_typo = false;
			i = j - 1;
		}
		else if(is_typo && !is_curr_typo)
			is_typo = false;
		else if(!is_typo && is_curr_typo){
			is_typo = true;
			i = j;
		}
	}
	for(int i = 0; i < n; ++i)
		if(input[i] != ' ')
			cout << input[i];
	cout << endl;
	return 0;
}
