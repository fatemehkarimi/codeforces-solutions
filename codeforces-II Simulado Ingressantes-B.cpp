//http://codeforces.com/gym/101744/problem/B
//MaratonIME plays Cîrokime

#include <iostream>

using namespace std;

int lg(int n);

int main(void)
{
	int n = 0;
	cin >> n;

	for (int i = 0; i < n; ++i){
		int t = 0;
		cin >> t;
	}

	cout << lg(n) << endl;

	return 0;
}

int lg(int n)
{
	int count = 0;
	while (n != 0){
		n /= 2;
		++count;
	}

	return count;
}
