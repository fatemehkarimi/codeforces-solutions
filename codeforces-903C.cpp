//https://codeforces.com/problemset/problem/903/C
//Boxes Packing

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
	int n = 0;
	cin >> n;

	vector <int> boxes(n);
	vector <bool> visible(n, true);
	vector <bool> contains(n, false);

	for(int i = 0; i < n; ++i)
		cin >> boxes[i];

	sort(boxes.begin(), boxes.end());

	for(int i = 0; i < n - 1; ++i){
		int j = i + 1;
		while(j < n && (boxes[j] == boxes[i] || (boxes[j] > boxes[i] && contains[j])))
			++j;

		if(j < n){
			visible[i] = false;
			contains[j] = true;
		}
	}

	int count = 0;
	for(auto a : visible)
		if(a)
			++count;

	cout << count << endl;
	return 0;
}
