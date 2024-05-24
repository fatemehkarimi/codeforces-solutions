//https://codeforces.com/problemset/problem/659/C
//Tanya and Toys

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;

	vector <bool> toys(1000000000, false);

	for(int i = 0; i < n; ++i){
		int tmp;
		cin >> tmp;
		--tmp;
		toys[tmp] = true;
	}

	vector <int> bought;
	for(int i = 0; i < toys.size(); ++i)
		if(toys[i])
			continue;
		else if(!toys[i] && m - (i + 1) >= 0){
			m -= (i + 1);
			toys[i] = true;
			bought.push_back(i);
		}
		else if(m - (i + 1) < 0)
			break;

	cout << bought.size() << endl;
	for(auto a : bought)
		cout << a + 1 << ' ';
	cout << endl;

	return 0;
}
