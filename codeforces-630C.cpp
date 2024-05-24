//https://codeforces.com/problemset/problem/630/C

#include <iostream>

using namespace std;

int main(void)
{
	int n = 0;
	cin >> n;

	long long int result = 0;
	long long int pre = 1;
	for(int i = 1; i <= n; ++i){
		pre *= 2;
		result += pre;
	}

	cout << result << endl;
	
	return 0;
}
