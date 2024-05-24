//https://codeforces.com/problemset/problem/1176/C
//C. Lose it!

#include <iostream>
#include <vector>

using namespace std;

int get_idx(int num)
{
	int order[6] = {4, 8, 15, 16, 23, 42};
	for(int i = 0; i < 6; ++i)
		if(num == order[i])
			return i;
	return -1;
}
int main(void)
{
	int count[6] = {0, 0, 0, 0, 0, 0};
	int n;
	cin >> n;
	int must_removed = 0;
	for(int i = 0; i < n; ++i){
		int num;
		cin >> num;
		int idx = get_idx(num);
		if(idx == -1){
			++must_removed;
			continue;
		}
		if(idx == 0)
			count[0]++;
		else if(idx > 0 && count[idx - 1] > 0){
			--count[idx - 1];
			++count[idx];
		}
		else
			must_removed++;
	}
	for(int i = 0; i < 5; ++i)
		must_removed += count[i] * (i + 1);
	cout << must_removed << endl;
	return 0;
}
