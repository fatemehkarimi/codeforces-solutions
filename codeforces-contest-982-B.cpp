//http://codeforces.com/contest/982/problem/B
//B Bus of Characters

#include <iostream>
#include <string>
#include <climits>
#include <map>
#include <functional>

using namespace std;

int main(void)
{
	int n = 0;
	while (cin >> n) {
		map < int, int > empty;
		map < int, int, greater <int> > halfFilled;

		for (int i = 1; i <= n; ++i) {
			int w;
			cin >> w;

			empty.insert(make_pair(w, i));
		}

		string str;
		cin >> str;

		for (int i = 0; i < str.size(); ++i) 
			if (str[i] == '0') {
				auto a = empty.begin();
				cout << a->second << ' ';
				halfFilled.insert(*a);
				
				empty.erase(a);
			}
			else {
				auto a = halfFilled.begin();
				cout << a->second << ' ';

				halfFilled.erase(a);
			}


		cout << endl;

	}

	return 0;
}
