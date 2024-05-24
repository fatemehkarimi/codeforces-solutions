//http://codeforces.com/contest/1005/problem/C
//Summarize to the Power of Two

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool power2(long long int sum);
long long int p2(long long int limit);
int binarySearch(vector <long long int> & num, int start, int end, long long int key);

int main(void)
{
	int n = 0;
	while (cin >> n) {
		vector <long long int> num(n);

		for (int i = 0; i < n; ++i)
			cin >> num[i];

		sort(num.begin(), num.end());

		vector <bool> ok(n, false);

		for (int i = 0; i < n; ++i)
			if (!ok[i]) {
				long long int lim = p2(num[i] + num[n - 1]);
				while (lim - num[i] >= 0){
					int index1 = binarySearch(num, 0, i - 1, lim - num[i]);
					int index2 = binarySearch(num, i + 1, n - 1, lim - num[i]);

					if (index1 != -1){
						ok[i] = 1;
						ok[index1] = 1;
					}
					if (index2 != -1){
						ok[i] = 1;
						ok[index2] = 1;
					}

					lim /= 2;
				}
			}


		int count = 0;
		for (auto a : ok)
			if (a == false)
				++count;

		cout << count << endl;
	}

	return 0;
}

bool power2(long long int sum)
{
	while (sum % 2 == 0)
		sum /= 2;

	if (sum == 1)
		return true;

	return false;
}


long long int p2(long long int limit)
{
	long long int result = 1;

	while (result * 2 <= limit)
		result *= 2;

	return result;
}


int binarySearch(vector <long long int> & num, int start, int end, long long int key)
{
	if (end < start)
		return -1;

	int middle = start + (end - start) / 2;

	if (num[middle] == key)
		return middle;

	if (key > num[middle])
		return binarySearch(num, middle + 1, end, key);
	else
		return binarySearch(num, start, middle - 1, key);
}
