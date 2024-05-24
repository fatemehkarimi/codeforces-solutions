//https://codeforces.com/problemset/problem/1102/C
//Doors Breaking and Repairing

#include <iostream>
#include <set>

using namespace std;

int main(void)
{
	int n, x, y;
	cin >> n >> x >> y;

	multiset <int> nums;
	for(int i = 0; i < n; ++i){
		int tmp;
		cin >> tmp;
		nums.insert(tmp);
	}

	if(x > y){
		cout << n << endl;
		return 0;
	}

	bool turn = 0;//0 for Slavik, 1 for his friend
	int c_door = 0;

	while(!nums.empty() && *nums.begin() <= x){
		if(!turn){
			auto door = nums.begin();
			for(auto a = nums.begin(); *a <= x && a != nums.end(); ++a)
				if(*a > *door)
					door = a;

			++c_door;
			turn = !turn;
			nums.erase(door);
		}
		else{
			auto door = nums.begin();
			for(auto a = nums.begin(); *a <= x && a != nums.end(); ++a)
				if(*a > * door)
					door = a;

			int tmp = *door;
			nums.erase(door);
			nums.insert(tmp + y);
			turn = !turn;
		}
	}
	cout << c_door << endl;
	return 0;
}
