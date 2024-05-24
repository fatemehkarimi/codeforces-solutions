//https://codeforces.com/problemset/problem/886/C
//C. Petya and Catacombs

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector <int> nums(n);

	for(int i = 0; i < n; ++i)
		cin >> nums[i];

	vector <int> minute_place(n + 1);
	vector <int> last_min_place(1, 0);
	int count_room = 0;

	for(int i = 0; i < n; ++i){
		int t = nums[i];
		if(last_min_place[minute_place[t]] == t){
			last_min_place[minute_place[t]] = i + 1;
			minute_place[i + 1] = minute_place[t];
		}
		else{
			++count_room;
			minute_place[i + 1] = count_room;
			last_min_place.push_back(i + 1);
		}
	}

	cout << count_room + 1 << endl;
	return 0;
}
