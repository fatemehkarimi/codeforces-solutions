// https://codeforces.com/contest/1332/problem/C
// C. K-Complete Word

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	while(T--){
		int n, k;
		cin >> n >> k;
		string input;
		cin >> input;

		int min_change = 0;

		int limit = (k % 2 ? k / 2 + 1 : k / 2);

		for(int i = 0; i < limit; ++i){
			map <char, int> counts;
			for(int j = i; j < n; j += k)
				++counts[input[j]];

			if(k % 2 && i == limit - 1){
				if(counts.size() == 1)
					continue;

				int max_count = 0;
				for(auto a : counts)
					max_count = max(max_count, a.second);

				min_change +=(n / k - max_count);
				continue;
			}

			for(int j = k - 1 - i; j < n; j += k)
				++counts[input[j]];

			if(counts.size() == 1)
				continue;

			int max_count = 0;
			for(auto a : counts)
				max_count = max(max_count, a.second);

			min_change +=((2 * n) / k - max_count);
		}

		cout << min_change << endl;
	}
	return 0;
}
