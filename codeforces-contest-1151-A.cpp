//https://codeforces.com/contest/1151/problem/A
//A. Maxim and Biology

#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int main(void)
{
	int n;
	string input;
	cin >> n >> input;

	vector < vector <int> > arr(26, vector <int> (4, 0));//A C T G

	for(int i = 0; i < 26; ++i){
		int _const = (int)'A';
		arr[i][0] = min(abs((int)'A' - _const - i), abs((int)'Z' - _const - i) + 1);
		arr[i][1] = min(abs((int)'C' - _const - i), abs((int)'Z' - _const - i) + 1 + abs((int)'A' - (int)'C'));
		arr[i][2] = min(abs((int)'T' - _const - i), abs((int)'A' - _const - i) + 1 + abs((int)'Z' - (int)'T'));
		arr[i][3] = min(abs((int)'G' - _const - i), abs((int)'Z' - _const - i) + 1 + abs((int)'A' - (int)'G'));
	}

	int min_cost = INT_MAX;
	for(int i = 0; i < n - 3; ++i){
		int cost = arr[input[i] - 'A'][0];
		cost += arr[input[i + 1] - 'A'][1];
		cost += arr[input[i + 2] - 'A'][2];
		cost += arr[input[i + 3] - 'A'][3];

		min_cost = min(min_cost, cost);
	}

	cout << min_cost << endl;
	return 0;
}
