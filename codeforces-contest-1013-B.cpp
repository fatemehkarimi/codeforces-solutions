//http://codeforces.com/contest/1013/problem/B

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(void)
{
	int n = 0, x = 0;
	cin >> n >> x;

	set <int> num;
	bool solved = 0;

	for (int i = 0; i < n; ++i){
		int t;
		cin >> t;

		auto a = num.insert(t);
		if (!a.second){
			solved = 1;
			break;
		}
	}


	if (solved){
		cout << "0" << endl;
		return 0;
	}


	for (auto a = num.begin(); a != num.end(); ++a){
		int t = (*a) & x;

		auto found = num.find(t);

		if (found != num.end() && found != a){
			solved = 1;
			break;
		}
	}

	if (solved){
		cout << "1" << endl;
		return 0;
	}

	set <int> andNum;

	for (auto a : num){
		int t = a & x;

		auto tmp = andNum.insert(t);

		if (!tmp.second){
			solved = 1;
			break;
		}
	}

	if (solved)
		cout << "2" << endl;
	else
		cout << "-1" << endl;


	return 0;
}
