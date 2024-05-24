//https://codeforces.com/problemset/problem/1003/C
//C. Intense Heat

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;
	vector <int> arr(n);
	vector <int> sums;
	double result = 0;
	int sum = 0;
	int idx = 0;
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
		++idx;
		sum += arr[i];
		if(idx == k){
			sums.push_back(sum);
			result = max((double)sum / (double)k, result);
			sum -= arr[i - k + 1];
			idx--;
		}
	}

	for(int l = k + 1; l <= n; ++l)
		for(int i = 0; i + l - 1 < n; ++i){
			sums[i] += arr[i + l - 1];
			result = max(result, (double)sums[i] / (double)l);
		}

	cout << fixed << setprecision(10) << result << endl;
	return 0;
}
