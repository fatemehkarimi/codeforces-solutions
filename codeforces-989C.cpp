//https://codeforces.com/problemset/problem/989/C
//C. A Mist of Florescence

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	int a[4];
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	int m = min(50, 2 * max(a[0], max(a[1], max(a[2], a[3]))));
	--a[2], --a[3];
	vector <string> result;
	char cover = 'D';
	for(int i = 0; i < 4; ++i){
		while(a[i] > 0){
			string row(m, cover);
			for(int j = 0; j < m && a[i] > 0; ++j)
				if(j % 2 == 0){
					--a[i];
					row[j] = i + 'A';
				}

			result.push_back(row);
			row = string(m, cover);
			result.push_back(row);
		}

		if(i == 2){
			result.push_back(string(m, cover));
			cover = 'C';
			result.push_back(string(m, cover));
		}
	}

	cout << result.size() << ' ' << m << endl;
	for(auto a : result)
		cout << a << endl;
	return 0;
}
