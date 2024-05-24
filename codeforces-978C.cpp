//https://codeforces.com/problemset/problem/978/C

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector <long long int> capacity(n);
	for(int i = 0; i < n; ++i)
		cin >> capacity[i];

	vector <long long int> totalCapacity(n);
	totalCapacity[0] = capacity[0];

	for(int i = 1; i < n; ++i)
		totalCapacity[i] = totalCapacity[i - 1] + capacity[i];

	int pointer = 0;
	for(int i = 0; i < m; ++i){
		long long int code;
		cin >> code;

		while(pointer < n){
			if(code <= totalCapacity[0]){
				cout << 1 << ' ' << code << endl;
				break;
			}
			else if(pointer + 1 < n && code > totalCapacity[pointer] && code <= totalCapacity[pointer + 1]){
				cout << pointer + 2 << ' ' << code - totalCapacity[pointer] << endl;
				break;
			}
			++pointer;
		}
	}

	return 0;
}
