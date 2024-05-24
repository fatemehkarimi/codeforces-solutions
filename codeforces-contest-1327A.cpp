// https://codeforces.com/contest/1327/problem/A
// A. Sum of Odd Integers

#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	while(T--){
		int n, k;
		cin >> n >> k;

		if((n % 2 == 0 && k % 2) || (n % 2 && k % 2 == 0)){
			cout << "NO" << endl;
			continue;
		}

		int root = sqrt(n);
		if(k <= root)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
