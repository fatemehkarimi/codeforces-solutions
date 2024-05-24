// https://codeforces.com/problemset/problem/1338/A
// A. Powered Addition

#include <iostream>
#include <vector>
#include <cmath>

#define lld long long int
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;

		vector <lld> numbers(n);
		for(int i = 0; i < n; ++i)
			cin >> numbers[i];

		int maxSecond = 0;
		for(int i = 1; i < (int)numbers.size(); ++i) {
			if(numbers[i] >= numbers[i - 1])
				continue;

			lld diff = std::abs(numbers[i] - numbers[i - 1]);
			int power = (int)std::log2(diff);

			maxSecond = max(maxSecond, power + 1);
			numbers[i] = numbers[i - 1];
		}

		cout << maxSecond << endl;
	}
	return 0;
}