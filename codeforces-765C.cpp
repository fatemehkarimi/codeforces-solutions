//https://codeforces.com/problemset/problem/765/C
//C. Table Tennis Game 2

#include <iostream>

using namespace std;

int main(void)
{
	int k, a, b;
	cin >> k >> a >> b;
	int set_a = (a / k);
	int set_b = (b / k);
	if(set_a + set_b == 0 || (a % k != 0 && set_b == 0) || (b % k != 0 && set_a == 0))
		cout << "-1" << endl;
	else
		cout << set_a + set_b << endl;
	return 0;
}
