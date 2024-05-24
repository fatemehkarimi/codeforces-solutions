//http://codeforces.com/contest/990/problem/A

#include <iostream>

using namespace std;

int main(void)
{
	long long int n, m, a, b;
	while (cin >> n >> m >> a >> b) {
		long long int rem = n % m;
		long long int que = n / m;
		if (rem == 0)
			cout << "0" << endl;
		else {
			long long int pay1 = rem * b;
			long long int pay2 = ((que + 1) * m - n) * a;

			cout << (pay1 > pay2 ? pay2 : pay1) << endl;
		}
	}
	return 0;
}
