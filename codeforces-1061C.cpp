//https://codeforces.com/problemset/problem/1061/C
//C. Multiplicity

#include <iostream>
#include <algorithm>
#include <vector>

#define MODULO 1000000007

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector <int> dp(n + 1, 0);
	dp[0] = 1;
	for(int x = 0; x < n; ++x){
		int num;
		cin >> num;

		vector <int> divisors;
		for(int i = 1; i * i <= num; ++i)
			if(num % i == 0){
				if(i <= n)
					divisors.push_back(i);
				if(num / i <= n && num / i != i)
					divisors.push_back(num / i);
			}

		sort(divisors.begin(), divisors.end());
		std::reverse(divisors.begin(), divisors.end());
		
		for(auto d : divisors){
			dp[d] += dp[d - 1];
			dp[d] %= MODULO;
		}
	}

	long long int sum = 0;
	for(int i = 1; i <= n; ++i){
		sum += dp[i];
		sum %= MODULO;
	}
	cout << sum << endl;
	return 0;
}
