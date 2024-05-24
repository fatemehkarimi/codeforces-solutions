//https://codeforces.com/contest/1178/problem/B
//B. WOW Factor

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main(void)
{
	string input;
	cin >> input;
	map <int, long long int> before_o;
	map <int, long long int> after_o;
	vector <int> o_index;

	int count_w = 0;
	int len_v = 0;
	for(int i = 0; i < (int)input.size(); ++i) 
		if(input[i] == 'v')
			++len_v;
		else{
			o_index.push_back(i);
			if(len_v > 0)
				count_w += (len_v - 1);
			len_v = 0;
			before_o[i] = count_w;
		}

	if(len_v > 0)
		count_w += (len_v - 1);

	for(int i = (int)o_index.size() - 1; i >= 0; --i)
		after_o[o_index[i]] = count_w - before_o[o_index[i]];

	long long int result = 0;
	for(int i = 0; i < (int)o_index.size(); ++i)
		result += (before_o[o_index[i]] * after_o[o_index[i]]);
	cout << result << endl;
	return 0;
}
