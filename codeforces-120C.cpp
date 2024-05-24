//https://codeforces.com/problemset/problem/120/C

#include <iostream>

using namespace std;

int main(void)
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

	int n, k;
	cin >> n >> k;

	int total_give = 0;
	for(int i = 0; i < n; ++i){
		int honey;
		cin >> honey;

		if (honey >= 3 * k)
			honey -= 3 * k;
		else if(honey >= 2 * k)
			honey -= 2 * k;
		else if(honey >= k)
			honey -= k;

		total_give += honey;
	}

	cout << total_give << endl;
	return 0;
}
