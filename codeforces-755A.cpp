//https://codeforces.com/problemset/problem/755/A
//A. PolandBall and Hypothesis

#include <iostream>

using namespace std;

bool isPrime(int num);

int main(void)
{
	int n = 0;
	cin >> n;

	int counterExample = 1;
	for(; counterExample <= 1000; ++counterExample)
		if(!isPrime(n * counterExample + 1))
			break;

	cout << counterExample << endl;
	return 0;
}

bool isPrime(int num)
{
	for(int i = 2; i <= num / 2; ++i)
		if(num % i == 0)
			return false;
	return true;
}
