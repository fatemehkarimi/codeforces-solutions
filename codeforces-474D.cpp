// https://codeforces.com/problemset/problem/474/D
// D. Flowers

#include <iostream>
#include <vector>

#define MODULO 1000000007
#define lld long long int

using namespace std;

int main(void)
{
	int n = 100000;
	lld result[n + 1] = {};
	int t, k;
	cin >> t >> k;

	result[0] = 1;
	for(int i = 1; i <= n; ++i)
		result[i] = (result[i - 1] + (i >= k ? result[i - k] : 0)) % MODULO;
	for(int i = 1; i <= n; ++i)
		result[i] = (result[i] + result[i - 1]) % MODULO;

	while(t--){
		int x, y;
		cin >> x >> y;
		cout << (result[y] - result[x - 1] + MODULO) % MODULO << endl;
	}
	return 0;
}
