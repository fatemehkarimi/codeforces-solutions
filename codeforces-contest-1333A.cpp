// https://codeforces.com/contest/1333/problem/A
// A. Little Artem

#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		cout << string(m, 'B') << endl;

		for(int i = 1; i < n; ++i)
			cout << 'B' + string(m - 1, 'W') << endl;
	}
	return 0;
}
