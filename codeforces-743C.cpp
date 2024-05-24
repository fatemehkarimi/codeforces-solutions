//https://codeforces.com/problemset/problem/743/C
//C. Vladik and fractions

#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int x, y, z;
	x = n;
	y = -1;
	z = -1;

	for(int i = 2; i <= n; ++i)
		if(n % i == 0){
			y = (i + 1) * n;
			z = (i + 1) * n / (i);

			if(x != y && y != z && x != z)
				break;
			else
				y = z = -1;
		}

	if(y != -1 && z != -1)
		cout << x << ' ' << y << ' ' << z << endl;
	else
		cout << -1 << endl;
	return 0;
}
