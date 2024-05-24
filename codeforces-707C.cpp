//https://codeforces.com/problemset/problem/707/C
//C. Pythagorean Triples

#include <iostream>
#include <cmath>

#define lld long long int
using namespace std;

int main(void)
{
	lld n;
	cin >> n;

	if(n == 1 || n == 2){
		cout << -1 << endl;
		return 0;
	}

	if(n % 2)
		cout << (n * n + 1) / 2 << ' ' << (n * n - 1) / 2 << endl;
	else
		cout << (n * n + 4) / 4 << ' ' << (n * n - 4) / 4 << endl;
	return 0;
}
