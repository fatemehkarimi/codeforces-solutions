//https://codeforces.com/problemset/problem/766/C
//C. Mahmoud and a Message

#include <iostream>
#include <vector>
#include <string>

#define MODULO 1000000007

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	string input;
	cin >> input;

	vector <int> max_len(26);
	for(int i = 0; i < 26; ++i)
		cin >> max_len[i];

	vector <long long int> dp(n, 0);

	for(int i = 0; i < n; ++i){
		int limit = max_len[input[i] - 'a'];

		for(int j = i; j >= max(0, i - max_len[input[i] - 'a']); --j){
			limit = min(limit, max_len[input[j] - 'a']);
			if(i - j + 1 > limit)
				break;
			if(j - 1 < 0)
				++dp[i];
			else
				dp[i] = (dp[i] + dp[j - 1]) % MODULO;
		}
	}

	int max_len_split = 0;
	int min_count_split = 0;

	for(int i = 0; i < n; ++i){
		int limit = max_len[input[i] - 'a'];
		for(int j = i; j < n; ++j){
			limit = min(limit, max_len[input[j] - 'a']);
			if(j - i + 1 > limit)
				break;
			max_len_split = max(max_len_split, j - i + 1);
		}
	}

	//findig min_count_split
	for(int i = 0; i < n;){
		int limit = max_len[input[i] - 'a'];
		int j = i + 1;
		for(; j < i + max_len[input[i] - 'a'] && j < n; ++j){
			limit = min(max_len[input[j] - 'a'], limit);
			if(j - i + 1 > limit)
				break;
		}
		++min_count_split;
		i = j;
	}

	cout << dp[n - 1] << endl << max_len_split << endl << min_count_split << endl;
	return 0;
}
