//https://codeforces.com/problemset/problem/431/C
//C. k-Tree

#include <iostream>
#include <vector>

#define module 1000000007
#define lld long long int

using namespace std;

lld solve(lld n, lld d);

int main(void)
{
	lld n, k, d;
	cin >> n >> k >> d;
	lld result1 = solve(n, d - 1);
	lld result2 = solve(n, k);
	cout << (result2 - result1 + module) % module << endl;
	return 0;
}

lld solve(lld n, lld d)
{
	vector <lld> dp(n + 1, 0);
	dp[0] = 1;
	for(lld i = 1; (unsigned lld)i < dp.size(); ++i)
		for(lld j = 1; j <= d; ++j)
			if(j > i)
				break;
			else{
				dp[i] += dp[i - j];
				dp[i] %= module;
			}

	return dp[n];
}
