// https://codeforces.com/problemset/problem/1062/D
// D. Fun with Integers

#include <iostream>
#include <vector>

#define lld long long int

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	lld score = 0;
	for(int i = 2; i <= n; ++i){
		int last_factor = n / i;
		lld sum = (last_factor * (lld)(last_factor + 1)) / 2;
		sum -= 1;
		score += ((lld)sum * 4);
	}
	cout << score << endl;
	return 0;
}
