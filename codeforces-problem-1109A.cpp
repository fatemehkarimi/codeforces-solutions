//https://codeforces.com/problemset/problem/1109/A
//A. Sasha and a Bit of Relax

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n = 0;
	cin >> n;

	vector <int> nums(n);
	for(int i = 0; i < n; ++i)
		cin >> nums[i];

	vector <int> xors(n, 0);
	xors[0] = nums[0];

	int limit = (1 << 20) + 3;
	vector < vector <int> > cnt(2, vector <int>(limit, 0));

	cnt[1][0] = 1;
	long long int result = 0;
	int x = 0;

	for(int i = 0; i < n; ++i){
		x ^= nums[i];
		result += cnt[i % 2][x];
		++cnt[i % 2][x];
	}

	cout << result << endl;
	return 0;
}
