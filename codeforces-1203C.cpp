//https://codeforces.com/problemset/problem/1203/C
//C. Common Divisors

#include <iostream>
#include <vector>
#include <cmath>

#define lld long long int
using namespace std;

bool is_prime(lld a)
{
	if(a == 2)
		return true;
	if(a % 2 == 0)
		return false;
	for(lld i = 3; i <= sqrt(a); i += 2)
		if(a % i == 0)
			return false;
	return true;
}

lld gcd(lld a, lld b)
{
	while(b != 0){
		lld tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

int main(void)
{
	int n;
	cin >> n;
	vector <lld> nums(n);
	for(int i = 0; i < n; ++i)
		cin >> nums[i];

	lld _gcd = nums[0];
	for(int i = 1; i < n; ++i)
		_gcd = gcd(nums[i], _gcd);

	lld result = 0;
	for(lld i = 1; i * i <= _gcd; ++i)
		if(_gcd % i == 0){
			++result;
			if(i != (_gcd / i))
				++result;
		}

	cout << result << endl;
	return 0;
}
