// https://codeforces.com/problemset/problem/150/B
// B. Quantity of Strings

#include <iostream>
#include <string>

#define lld long long int
#define MODULO 1000000007

using namespace std;

lld _power(int n, int m)
{
	lld result = 1;
	for(int i = 1; i <= m; ++i)
		result = (result * n) % MODULO;
	return result;
}

int main(void)
{
	int n, m, k;
	cin >> n >> m >> k;

	if(k == 1 || n < k)
		cout << _power(m, n) << endl;
	else if(n == k)
		cout << _power(m, (k % 2 ? k / 2 + 1 : k / 2)) << endl;
	else if(k % 2)
		cout << _power(m, 2) << endl;
	else
		cout << m << endl;
	return 0;
}
