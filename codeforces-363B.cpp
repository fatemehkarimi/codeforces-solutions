//http://codeforces.com/problemset/problem/363/B
//B. Fence

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;

	vector <int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int min_height = 0;
	int index = 0;
	for (int i = 0; i < k; ++i)
		min_height += arr[i];

	int ptr = 0;
	int pre_height = min_height;
	for (int i = k; i < n; ++i){
		int new_height = pre_height + arr[i] - arr[ptr];
		if (new_height < min_height){
			min_height = new_height;
			index = ptr + 1;
		}

		++ptr;
		pre_height = new_height;
	}

	cout << index + 1 << endl;
	return 0;
}
