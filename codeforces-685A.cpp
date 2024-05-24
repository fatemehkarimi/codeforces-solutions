//https://codeforces.com/problemset/problem/685/A
//A. Robbers' watch

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int size_in_base_7(int n)
{
	vector <int> result;
	do{
		result.push_back(n % 7);
		n /= 7;
	}while(n != 0);

	return result.size();
}

void add_to_num(vector <int> & num)
{
	int n = (int)num.size() - 1;
	++num[n];

	for(int i = n; i > 0; --i){
		int tmp = num[i];
		num[i] = tmp % 7;
		num[i - 1] += tmp / 7;
	}
	return;
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector <int> num_n(size_in_base_7(n - 1), 0);
	vector <int> num_m(size_in_base_7(m - 1), 0);

	if(num_n.size() + num_m.size() > 7)
		return cout << "0" << endl, 0;

	int count = 0;

	for(int i = 0; i < n; ++i){
		bool valid_combin_n = true;
		vector <bool> used_n(7, false);
		for(auto a : num_n)
			if(!used_n[a])
				used_n[a] = true;
			else
				valid_combin_n = false;

		std::fill(num_m.begin(), num_m.end(), 0);
		for(int j = 0; j < m && valid_combin_n; ++j){
			bool valid_combin_m = true;

			vector <bool> used_m(7, false);
			for(auto a : num_m)
				if(!used_m[a])
					used_m[a] = true;
				else
					valid_combin_m = false;

			for(int i = 0; i < 7; ++i)
				if(used_n[i] && used_m[i])
					valid_combin_m = false;

			if(valid_combin_m)
				++count;
			add_to_num(num_m);
		}
		add_to_num(num_n);
	}
	cout << count << endl;
	return 0;
}

