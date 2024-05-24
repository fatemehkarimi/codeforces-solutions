// https://codeforces.com/contest/1337/problem/B
// B. Kana and Dragon Quest game

#include <iostream>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	while(T--){
		int x, n, m;
		cin >> x >> n >> m;

		while(n > 0 && x > 20){
			x = x / 2 + 10;
			--n;
		}

		x -= (10 * m);
		if(x <= 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}
	return 0;
}
