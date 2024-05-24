// https://codeforces.com/contest/1332/problem/A
// A. Exercising Walk

#include <iostream>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	while(T--){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int x, y, x1, y1, x2, y2;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;

		int left = x - x1;
		int right = x2 - x1;
		int down = y - y1;
		int up = y2 - y;

		bool possible = true;

		if(((a || b) && left == 0 && right == 0)
			|| ((c || d) && up == 0 && down == 0))
			possible = false;

		int p1 = b - a, p2 = d - c;
		x += p1, y += p2;
		if(x < x1 || x > x2 || y < y1 || y > y2)
			possible = false;

		if(possible)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
