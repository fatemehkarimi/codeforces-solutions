//https://codeforces.com/problemset/problem/1155/C
//C. Alarm Clocks Everywhere

#include <iostream>
#include <vector>

#define lld long long int
using namespace std;

lld gcd(lld a, lld b)
{
	while(b != 0){
		lld tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

int main(void)
{
	lld n, m;
	cin >> n >> m;
	vector <lld> alarms(n);
	for(lld i = 0; i < n; ++i)
		cin >> alarms[i];

	lld common = 0;
	for(lld i = 1; i < n; ++i)
		common = gcd(common, alarms[i] - alarms[i - 1]);

	for(lld i = 0; i < m; ++i){
		lld p;
		cin >> p;
		if(common % p == 0){
			cout << "YES" << endl;
			cout << alarms[0] << ' ' << i + 1 << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
