//http://codeforces.com/contest/988/problem/B
//Substrings Sort

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct compare{
	bool operator()(const string & first, const string & second){
		if (first.size() == second.size())
			return (first < second);
		else
			return first.size() < second.size();
	}
};

int main(void)
{
	int n = 0;
	cin >> n;

	vector <string> Str;

	for (int i = 0; i < n; ++i){
		string s;
		cin >> s;

		Str.push_back(s);
	}

	compare c;
	sort(Str.begin(), Str.end(), c);

	bool possible = 1;

	for (int i = n - 2; i >= 0; --i)
		if (Str[i + 1].find(Str[i]) == string::npos){
			possible = 0;
			break;
		}


	if (possible){
		cout << "YES" << endl;
		for (auto a : Str)
			cout << a << endl;
	}
	else
		cout << "NO" <<endl;

	return 0;
}
