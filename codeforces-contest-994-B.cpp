//http://codeforces.com/contest/994/problem/B
//Knights of a Polygonal Table

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	long long int n = 0, k = 0;

	while (cin >> n >> k) {
		vector <long long int> knight(n);
		vector <long long int> coin(n);
		for (long long int i = 0; i < n; ++i)
			cin >> knight[i];

		for (long long int i = 0; i < n; ++i)
			cin >> coin[i];


		map <long long int, long long int> Map;

		for (long long int i = 0; i < n; ++i)
			Map.insert(make_pair(knight[i], coin[i]));

		map <long long int, long long int> code;
		for (long long int i = 0; i < n; ++i)
			code.insert(make_pair(knight[i], i));

		vector <long long int> maxCoin(k, 0);
		vector <long long int> result(n);

		result[code[Map.begin()->first]] = Map.begin()->second;

		auto a = Map.begin();
		++a;
		for (; a != Map.end(); ++a){
			--a;
			sort(maxCoin.begin(), maxCoin.end());
			for (int i = 0; i < k; ++i)
				if (a->second > maxCoin[i]){
					maxCoin[i] = a->second;
					break;
				}

			++a;
			long long int sum = a->second;
			for (auto b : maxCoin)
				sum += b;

			result[code[a->first]] = sum;
		}

		for (auto a : result)
			cout << a << ' ';

		cout << endl;

	}

	return 0;
}
